#include<stdio.h>

// funtion for removing element from the array:-
int intDelete(int arr[] ,int index, int n ){
    if (index>n)
    {
        printf("\nThere is no such element in the Array\n");
    }
    else{
        for (int j = index; j < n; j++)
        {
        arr[j] = arr[j+1];
        }
    }
    printf("\nAfter removing the element from array:\n");
}

// function for display the array
void display(int arr[] , int tsize){
    for (int i = 0; i < tsize ; i++)
    {
        printf(" %d |", arr[i]);
    }
}

int main(){
    int myArr[5] = {1 ,3, 5, 7, 9}; 
    int index = 3;
    int size = sizeof(myArr)/sizeof(int); // total element of the array
    display(myArr,size);
   
    intDelete(myArr, index, size ); // removing the element through index
    size-=1;
    
    display(myArr,size);
    return 0;
}