#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void  creatarr(struct myArray *a, int tsize, int usized){
    a->total_size = tsize; // (*a).total_size == a->total_size; they both are the same.
    a->used_size = usized;
    a->ptr = (int *)malloc(tsize * sizeof(int)); // malloc allocate the memory in heap.
} 
void put(struct myArray *a){
    for (int j = 0; j < a->used_size; j++)
    {
        int n;
        printf("Enter The value of %d:\n",j+1);
        scanf("%d", &(a->ptr)[j]);
    }
}
void show(struct myArray *a){
    for (int j = 0; j < a->used_size; j++)
    {
        printf("%d\t", (a->ptr)[j]);
    }
}
// Insert the Element in the array
int insert(struct myArray *a ,int index , int value){
    if (index>a->total_size)
    {
        printf("we can't Insert %d\n", value);
    }
    
    // here we insert the element by there given index
    for (int j = a->used_size-1; j >= index; j--)
    {
        a->ptr[j+1] = a->ptr[j];
    }
    a->ptr[index] = value;
    return 1;
}
int main(){
    struct myArray arr;
    creatarr(&arr,10,5);
    put(&arr);
    show(&arr);
    insert(&arr,4,200);
    printf("\n after Insertion the elements:-\n");
    arr.used_size = arr.used_size+1;
    show(&arr);
    return 0;
}