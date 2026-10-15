#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
        *a = *b;
        *b = temp;
}

int main(){

    int arr[]={10,49,50,22,13};

    int n=5;
    
    for(int i = 0;i < n-1;i++){

        for(int j = 0;j < n-1-i;j++){

            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

    //Sorted Array:
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}