//Problem: Write a C program to insert an element x at a 
//given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include <stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int arr[100];

    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    int pos,x;

    scanf("%d",&pos);

    scanf("%d",&x);

    //arr[5] -> arr[5-1] means arr[5] kp arr[4] assign kardiya.
    for(int i = n;i >= pos;i--){
        arr[i] = arr[i - 1];
    }

    //insert new column
    arr[pos - 1] = x;

    //increase the size of array
    n++;

    for(int i = 0;i < n;i++){
        printf("%d",arr[i]);
    }


    return 0;
}