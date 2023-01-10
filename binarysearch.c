#include <stdio.h>

int binarySearch(int arr[], int element, int size)
{
    int start, mid, end;
    start = 0, end = size-1;

    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            start = mid + 1;
        }
        else if (arr[mid] > element)
        {
            end = mid - 1;
        }
    }
    return -1;
};
int main()
{
    int arr[10] = {11, 22, 32, 44, 65, 66, 77, 95}; // sorted array
    int size = sizeof(arr)/sizeof(int);
    int element = 77;
    int searched_ind = binarySearch(arr,element,size);
    printf("The Element was founded at index %d \n", searched_ind);

    return 0;
}