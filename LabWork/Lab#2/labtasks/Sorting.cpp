#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter the no of elements in a list : ";
	cin>>size;
	int arr[size];
	cout<<"enter the elements :";
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	cout<<"Unsorted array :";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	for (int j = 0; j < size - 1; j++) { // Outer loop for passes
        for (int i = 0; i < size - j - 1; i++){
		
			if(arr[i]>arr[i+1]){	
		int temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
	}
	}
	}
		cout<<"sorted array   :";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
		
	return 0;	
}
