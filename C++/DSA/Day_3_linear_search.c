#include <stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int arr[100];

    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    int key,comparison=0,found=0;
    scanf("%d",&key);

    //Linear Search Operation
    for(int i = 0;i < n; i++){

        comparison++;
        
        if(arr[i] == key){
            printf("Element found at index: %d",i);
            found = 1;
            break;
        }

    }

    if(found == 0){
        printf("Element Not Found!");
    }

    printf("\nComparisons = %d",comparison);

    return 0;
}