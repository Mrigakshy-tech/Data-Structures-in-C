#include <stdio.h>
#include <stdlib.h>

// Stack creation
    struct stack{
        int size;
        int top; 
        int *arr;   
    };
// To check stack is full
    int isFull(struct stack* ptr){
        if(ptr->top == ptr->size - 1){
            return 1;
        }
        else{
            return 0;
        }
    }
// To check stack is empty
    int isEmpty(struct stack* ptr){
         if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }
// Push operation
    void push(struct stack* ptr, int val){ // val is to be pushed onto the stack
      if(isFull(ptr)){
        printf("Stack overflow! Cannot push %d to the stack\n", val);

      }
      else{
        ptr->top ++;
        ptr->arr[ptr->top] = val;
      }
    }

    // Pop operation
    int pop(struct stack* ptr){ 
      if(isEmpty(ptr)){
        printf("Stack underflow! Cannot pop from the stack\n");
        return -1;
      }
      else{
       int val = ptr->arr[ptr->top];
       ptr-> top--;
      return val;
      }
    }

    int peek(struct stack* sp, int i){ // i is the position of the element
       int arrayInd = sp->top - i + 1;
       if(arrayInd < 0){
        printf("Nota valid position for the stack\n");
        return -1;
       }
       else{
        return sp->arr[arrayInd];
       }
    }

    int stackTop(struct stack* sp){
        return sp->arr[sp->top];
    }

    int stackBottom(struct stack* sp){
        return sp->arr[0];
    }

int main(){ 
    
    /* struct stack *sp;   Structure pointer that points to stack and stores the address of the stack which is of type struct.
    struct stack instance ko point karta hai.

    Creating actual struct stack type ka instance dynamically :- */
    
    struct stack *sp = (struct stack *) malloc (sizeof(struct stack));
    // I can use the above variables of the struct stack using arrow operation once its instance is created.
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sizeof(int));
    printf("Stack has been created successfully!\n");

    push(sp, 56);
    push(sp, 60);
    push(sp, 98);
    push(sp, 76);
    push(sp, 48);
    push(sp, 97);
    push(sp, 99);
    push(sp, 23);
    push(sp, 64);  // --> It will be popped first.
    push(sp, 73); // --> 10 elements pushed 
    push(sp, 38);
    push(sp, 46);
     
    printf("The topmost value of this stack is %d\n", stackTop(sp));
    printf("The bottom most value of this stack is %d\n", stackBottom(sp));
    
   return 0;

}