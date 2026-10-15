#include <stdio.h>

int main()
{
    int arr[] = {5, 2, 4, 1, 3};
    int n = 5;

    // First element ko already sorted maan rahe hain
    // Isliye i = 1 se start karenge
    for(int i = 1; i < n; i++)
    {
        // Current element ko key me store karo
        int key = arr[i];

        // Key ke just left wale element ka index
        int j = i - 1;

        // Jab tak left element key se bada hai,
        // usko ek position right shift karte rahenge
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Empty position par key ko insert karo
        arr[j + 1] = key;
    }

    // Sorted array print karo
    printf("Sorted Array: ");

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}