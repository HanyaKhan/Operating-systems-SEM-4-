#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MSG_SIZE 100

void reverse_case(char *str) {
    for (int i = 0; str[i]; i++) {
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        else if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    char msg[MSG_SIZE] = "Hi There";
    char buffer[MSG_SIZE];


    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        // Parent process
        close(pipe1[0]); 
        close(pipe2[1]); 

       
        write(pipe1[1], msg, strlen(msg) + 1);

  
        read(pipe2[0], buffer, MSG_SIZE);
        printf("Parent received modified message: %s\n", buffer);

       
        close(pipe1[1]);
        close(pipe2[0]);
    } else {
        
        close(pipe1[1]); 
        close(pipe2[0]); 
        
        read(pipe1[0], buffer, MSG_SIZE);

        
        reverse_case(buffer);

       
        write(pipe2[1], buffer, strlen(buffer) + 1);

      
        close(pipe1[0]);
        close(pipe2[1]);
    }

    return 0;
}
