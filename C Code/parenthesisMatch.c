#include <stdio.h>
#include <stdlib.h>

// Stack creation
    struct stack{
        int size;
        int top; 
        char *arr;   
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
    void push(struct stack* ptr, char val){ // val is to be pushed onto the stack
      if(isFull(ptr)){
        printf("Stack overflow! Cannot push %d to the stack\n", val);

      }
      else{
        ptr->top ++;
        ptr->arr[ptr->top] = val;
      }
    }

    // Pop operation
    char pop(struct stack* ptr){ 
      if(isEmpty(ptr)){
        printf("Stack underflow! Cannot pop from the stack\n");
        return -1;
      }
      else{
       char val = ptr->arr[ptr->top];
       ptr-> top--;
      return val;
      }
    }

    int parenthesisMatch(char* exp){
        // create and initialized the stack
        struct stack* sp;
        sp->size = 100;
        sp->top = -1;
        sp->arr = (char *) malloc(sp->size * sizeof(char));


        for(int i = 0; exp[i]!='\0';i++){
            if(exp[i]=='('){
                push(sp, '(');
            }
            else if(exp[i]==')'){
                if(isEmpty(sp)){
                    return 0;
                }
                pop(sp);
           }
        }
        if(isEmpty(sp)){
            return 1;
        }
        else
        {
             return 0;
        }
    }

int main(){ 
    char *exp = "8*(9)";
   if(parenthesisMatch(exp)){
            printf("The parenthesis is matching");
        }
        else{
            printf("Parenthesis not matching.");
        }

    return 0;

}