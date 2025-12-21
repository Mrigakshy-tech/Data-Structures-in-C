#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}


void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This queue is full");
    }
    else{
        q->r++;
        q->arr[q->r] =  val;
         printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This queue is empty");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 5;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size * sizeof(int));
    
    if(isEmpty(&q)){
       printf("Queue is empty\n");
    }
    // Enqueue few elements
    enqueue(&q, 12);  // & is used as q is a pointer, it stores address
    enqueue(&q, 62);  // 12, 62 is dequeued acc to FIFO

    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    /* if(isEmpty(&q)){
       printf("Queue is empty");    -> This statement is not displayed as queue is not empty now.
    } */                       
    if(isFull(&q)){
       printf("Queue is full");  // queue is not full. It is partially filled.
    }

    enqueue(&q, 72);
    enqueue(&q, 82);
    enqueue(&q, 92);

    if(isFull(&q)){
       printf("Queue is full");  
    }

    return 0;
}