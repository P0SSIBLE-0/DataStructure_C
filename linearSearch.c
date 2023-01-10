#include<stdio.h>

int linearSearch(int arr[], int size , int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
    
}
int main(){
    int Arr[10] = {12,44,32,444,67,45,32,9,1,2};
    int size = sizeof(Arr)/sizeof(int);
    int element = 67;
    int findindex = linearSearch(Arr, size ,element);
    printf("Your Element %d was found at index of %d", element, findindex);
    return 0;
}