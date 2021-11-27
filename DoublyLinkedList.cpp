/* Implement the following operations w.r.t. doubly linked list:

● Insertion at any position given by the user 
● Deletion at any position given by the user 
● Display the list 
● Search for a specific element 
● Find maximum and minimum elements.

*/


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}*head=0, *tail=0;


void create(int value){
    struct Node *newnode, *temp;
    if(head==NULL){
        newnode=(struct Node*)malloc(sizeof(struct Node));
        head=newnode;
        head->data=value;
        head->next=NULL;
        head->prev=NULL;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newnode;
    temp->next->prev=temp;
    newnode->data=value;
    newnode->next=0;
    tail=newnode;
}

void insertAtRandomPosition(){
    int pos;
    cout<<endl<<"Enter position of Insertion : ";
    cin>>pos;
    struct Node *temp;
    temp=head;
    int i=1;
    while(i < pos){
        temp=temp->next;
        i++;
    }
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    int value;
    cout<<"Enter value : ";
    cin>>value;
    newnode->data=value;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
}


void deleteAtRandomPosition(){
    int pos;
    cout<<endl<<"Enter position of Deletion : ";
    cin>>pos;
    struct Node *temp, *temp1;
    temp=head;
    int i=1;
    while(i < pos){
        temp=temp->next;
        i++;
    }
    temp1=temp->next;
    temp1->next->prev=temp;
    temp->next=temp1->next;
    free(temp1);
}


void printLinkedList(){
    struct Node *temp;
    temp=head;
    while(temp->next != NULL){
        temp=temp->next;
        cout<<temp->data<<" <=> ";
    }
    cout<<"NULL"<<endl;
    /*(Printing in Reverse Order)
    temp=tail;
    while(temp->prev != NULL){
        cout<<temp->data<<" <=> ";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
    */
}

bool search(){
    int x;
    cout<<endl<<"Enter element to search : ";
    cin>>x;
    struct Node *temp;
    temp=head;
    while(temp->next!=NULL){
        if(temp->data==x)
            return 1;
        temp=temp->next;
    }
    return 0;
}

void maxAndMin(){
    struct Node *temp;
    temp=head;
    int min=head->data;
    int max=head->data;
    while(temp!=NULL){
        if(temp->data > max)
            max=temp->data;
        if(temp->data < min)
            min=temp->data;
        temp=temp->next;
    }
    cout<<endl<<"max = "<<max<<endl;
    cout<<"min = "<<min<<endl;
}

int main(){
    create(1);
    create(4);    
    create(5);    
    create(9);    
    create(0);    
    create(3);    
    create(8);    
    cout<<"Intial Nodes :"<<endl;
    printLinkedList();
    
    insertAtRandomPosition();
    printLinkedList();
    
    deleteAtRandomPosition();
    printLinkedList();
    
    cout<<endl;
    printLinkedList();
    
    if(search())
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    
    maxAndMin();
    
    return 0;
}