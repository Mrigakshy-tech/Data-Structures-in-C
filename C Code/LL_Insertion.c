#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Return head pointer
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    
    return ptr;
}

struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head; // p pointer is pointing to the head node.

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertInBetween(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;  // We don't want to move head, and will keep it fixed. So, we will make another pointer named p that points to head at the beginning and then it traverses the linked list.
    int i = 0;

    while(i!=index-1) // jis index par insert karna hai, usse ek index pehle wale node par p ko khada kar rha hu
    {
        p = p->next; // p will move forward 
        i++;
    }
    ptr->data = data; // setting the data part of the ptr pointer
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Insert at a index next to a given index(node)
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main(){
     struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;
    // Link second and third nodes
    second->data = 11;
    second->next = third;
    // Terminate the list at the third node
    third->data = 66;
    third->next = NULL;
    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head,56);  o/p - 56,7,11,66
    // head = insertInBetween(head,56,1); o/p - 7,56,11,66
   //  head = insertAtEnd(head,56); o/p - 7,11,66,56
   head = insertAfterNode(head, second, 45); // o/p - 7,11,45,66
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    return 0;
}