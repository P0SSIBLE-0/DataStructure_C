#include <stdio.h>

int main()
{
    int n;
    printf("size of the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in array\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int counter = 1; // counter will be incremented if array's elements are sorted;
    while (counter < n){
        for (int i = 0; i < n - counter; i++){
            if (arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}