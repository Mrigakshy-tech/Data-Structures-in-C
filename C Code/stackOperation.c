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

    printf("%d\n", isFull(sp));   // 0
    printf("%d\n", isEmpty(sp));  // 1

    push(sp, 56);

    printf("Before pushing, Full: %d\n", isFull(sp));   // 0
    printf("Before pushing, Empty:%d\n", isEmpty(sp));  // 0

    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);
    push(sp, 56);  // --> It will be popped first.
    push(sp, 56); // --> 10 elements pushed 
    push(sp, 36);
    push(sp, 46);
    printf("After pushing, Full: %d\n", isFull(sp));   // Stack overflow 
                                  // 1
    printf("After pushing, Empty: %d\n", isEmpty(sp));  // 0
    
    printf("Popped %d from the stack\n", pop(sp));  // %d is showing garbage value?
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    printf("Popped %d from the stack\n", pop(sp));
    

    return 0;

}