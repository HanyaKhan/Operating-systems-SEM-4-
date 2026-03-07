#include <unistd.h> 
#include <stdio.h> 
#include <string.h> 
 
int main()  
{ 
    int pdes[2]; 
    char buf[100]; 
     
    pipe(pdes);  // Create pipe 
 
    if (fork() == 0)  // Child 
    { 
        close(pdes[1]);  // Close unused write end 
        read(pdes[0], buf, sizeof(buf));  // Read from parent 
        printf("Child received: %s\n", buf); 
        close(pdes[0]);  // Close read end 
    }  
    else  // Parent 
    { 
        close(pdes[0]);  // Close unused read end 
        const char *msg = "Hello from parent!"; 
        write(pdes[1], msg, strlen(msg) + 1);  // Write to child 
        close(pdes[1]);  // Close write end 
    } 
 
    return 0; }
