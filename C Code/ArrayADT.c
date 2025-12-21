#include <stdio.h>
#include <stdlib.h>
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

// function to update total size, used size and ptr of myArray structure 
void createArray(struct myArray * a, int tSize, int uSize){
    /* (*a) is used to deference. It is a structure instance.
    (*a).total_size = tSize; we call members of the structure using (*a)
    (*a).used_size = uSize;
    int * ptr = (int *)malloc(tSize*sizeof(int));
    structure ke ptr ko set kar do malloc memory ke barabar
    (*a).ptr = (int *)malloc(tSize*sizeof(int));
    in c++ it can be done using constructor.

    structure ke address se structure chahiye -> *
    structure se address chahiye -> &
                       OR
    */
   a->total_size = tSize;
   a->used_size = uSize;
   a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a){
    for(int i = 0; i< a->used_size; i++){
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a){
    int n;
    for(int i = 0; i< a->used_size; i++){
        printf("Enter element %d\t", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main(){
    struct myArray marks;   // instance of myArray ADT.  
    createArray(&marks, 10, 2); 
    printf("we are running setVal now\n");
    setVal(&marks); // takes address of marks
    printf("we are running show now\n");
    show(&marks);

    return 0;

}