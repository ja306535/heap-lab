/*
Lab #10: Heaps
COP3502C Section 4, Spring 2024 Semester @UCF - Dr. Tanvir Ahmed
Code Written by Jalil Fountain
The purpose of this program is for us to practice writing a program involving a
heap. In this program, the user will enter n numbers, which will be put into an
array. The program will test with a recursive and iterative approach to see if the
program is a min heap or not.
*/
//START OF PROGRAM
#include "main.h"//include our personal library, which includes the function
//headers and library declarations for this program
int main()
{
int n;//integer for the number of values the user will enter
int *arr;//integer pointer that will point to our dynamically allocated array
//of integers
printf("How many entries? ");
scanf("%d", &n);//take in the number of values the user wants to enter
printf("Enter %d entries: ", n);
arr = malloc(sizeof(int) * n);//allocate memory for the integer array!
for(int i = 0; i < n; i++){//loop that cycles through the number of values the
//user wants to enter and gets the value for each element from the user
scanf("%d", &arr[i]);
}
int x = isHeap_recursive(arr, 0, n);//check to see if the array is a heap based
//on recursion and store the returned value. Afterward, used the stored value to
//determine if the array is a min heap and tell the user
if(x == 1){
printf("Recursive says Yes!\n");
} else{
printf("Recursive says No!\n");
}
int y = isHeap_iter(arr, n);//check to see if the array is a heap based on
//iteration and store the returned value. Afterward, used the stored value to
//determine if the array is a min heap and tell the user
if(y == 1){
printf("Iterative says Yes!\n");
} else{
printf("Iterative says No!\n");
}
free(arr);//free the memory for the integer array since we are done with it!
return 0;//return an integer since this is an integer function
}
int isHeap_recursive(int arr[], int i, int n)
{
    if(i>=n|| n<=0){
        return 1;
    }

    if(2*i+1<n){
 if(arr[2*i+1]<arr[i]){
    return 0;
 }        
 if(2*i+2<n){
    if(arr[2*i+2]<arr[i]){
       return 0;
    }        
    }

    return isHeap_recursive(arr,2*i+1,n) && isHeap_recursive(arr,2*i+2,n);


//check to see if the array has 1 element or if the current index is outside the
//size of the array. If either of these are true, then the array must be a min heap!
//Return 1 to indicate this
}
//if the index of the left child of the current element is within the array,
//check to see if the current element is smaller than its left child. If it isn't the
//array must not be a min heap. Return 0 to indicate this
}
//if the index of the right child of the current element is within the array,
//check to see if the current element is smaller than its right child. If it isn't
//the array must not be a min heap. Return 0 to indicate this
//if we've made it here, continue checking the array with the current elements
//left and right children!

int isHeap_iter(int arr[], int n)
{
    int i;
//loop that cycles through the array up to the last internal node. This is done to
//ensure both its left and right children are in the array
for(int i=0;i<(n-2)/2;i++){
if(arr[2*i+1]<arr[i]){
    return 0;
}

}
if(2*i+2<n&&arr[2*i+2]<arr[i]){
    return 0;
}

return 1;




//if the current element's left child is smaller than the current element,
//then the array must not be a min heap. Return 0 to indicate this
}
//if the current element's right child is smaller than the current element,
//then the array must not be a min heap. Return 0 to indicate this


//if we've made it here, then the array must be a min heap! Return 1 to indicate
//this

//END OF PROGRAM