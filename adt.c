#include<stdio.h>
#include<stdlib.h>
// ATD--> abstract data type
struct myArray
{
   int total_size;
   int used_size;
   int *ptr;

};
// method for creating array
void  creatarr(struct myArray *a, int tsize, int usized){
    a->total_size = tsize; // (*a).total_size == a->total_size; they both are the same.
    a->used_size = usized;
    a->ptr = (int *)malloc(tsize * sizeof(int)); // malloc allocate the memory in heap.
}
// method for adding elements in array
void put(struct myArray *a){
    for (int j = 0; j < a->used_size; j++)
    {
        int n;
        printf("Enter The value of %d\n",j+1);
        scanf("%d", &(a->ptr)[j]);
    }
}
//method to show array 
void show(struct myArray *a){
    for (int j = 0; j < a->used_size; j++)
    {
        printf("%d\n", (a->ptr)[j]);
    }
}

int main(){
    struct myArray myArr;
    creatarr(&myArr, 10,5);

    put(&myArr);
    show(&myArr);
    return 0;
}