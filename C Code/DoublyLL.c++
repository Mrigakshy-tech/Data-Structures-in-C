#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prevNode;
};
void traversal(Node* N1){ 
    Node* p = N1;
    while (p != NULL)
    {
        cout<< p->data <<endl;
        p = p->next;
    }
}
void reverse(Node * N4){
    Node* p = N4;
    while (p->prevNode != NULL)
    {
        cout<< p->data <<endl;
        p = p->prevNode;
    }
        cout<< p->data <<endl;        
}
main()
{
        Node * N1;
        Node * N2;
        Node * N3;
        Node * N4;


        N1 =    (Node*)malloc(sizeof (Node));
        N2 =    (Node*)malloc(sizeof (Node));
        N3 =    (Node*)malloc(sizeof (Node));
        N4 =    (Node*)malloc(sizeof (Node));

        
        N1->prevNode = NULL;
        N1->data = 10;
        N1->next = N2;
        
        N2->prevNode = N1;
        N2->data = 14;
        N2->next = N3;
        
        N3->prevNode = N2;
        N3->data = 20;
        N3->next = N4;

        N4->prevNode = N3;
        N4->data = 35;
        N4->next = NULL;

        cout<<"In Order List:"<<endl;
        traversal(N1);
        cout<<"Reverse Order List:"<<endl;
        reverse(N4);

   return 0;
}