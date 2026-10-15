#include <stdio.h>

int main(){

    int n;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int arr[100];

    for(int i = 0;i < n;i++){
        scanf("%d",&arr[i]);
    }

    int pos;

    printf("Enter pos: ");

    scanf("%d",&pos);

    int index = pos - 1;

    for(int i = index;i < n - 1;i++){
        arr[i] = arr[i + 1];
    }

    n--;

    for(int i = 0;i < n;i++){
        printf("%d",arr[i]);
    }

    return 0;
}