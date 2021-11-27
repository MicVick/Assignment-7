// Write a program to insert a node at the end of the linked list with value as total of all its previous node values.


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head=0;

void insert(int value){
    struct Node *newnode, *temp;
    if(head==NULL){
        newnode=(struct Node*)malloc(sizeof(struct Node));
        head=newnode;
        head->data=value;
        head->next=NULL;
    }
    newnode=(struct Node*)malloc(sizeof(struct Node));
    temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newnode;
    newnode->data=value;
    newnode->next=0;
}

int cummulativeAddition(){
    int sum=0;
    struct Node *temp1=head;
    while(temp1->next!=NULL){
        sum+=temp1->data;
        temp1=temp1->next;
    }
    sum+=temp1->data;
    return sum;
}

void insertLastElement(){
    int n=cummulativeAddition();
    
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=n;
    newnode->next=NULL;
    temp->next=newnode;
}

void printLinkedList(){
    struct Node *temp;
    temp=head;
    while(temp->next != NULL){
        temp=temp->next;
        cout<<temp->data<<" -> ";
    }
    cout<<"NULL"<<endl;
}

int main(){
    insert(1);
    insert(4);    
    insert(5);    
    insert(9);    
    insert(0);    
    insert(3);    
    insert(8);    
    cout<<"Before inserting last Node :"<<endl;
    printLinkedList();
    cout<<endl<<"After inserting last Node :"<<endl;
    insertLastElement();
    printLinkedList();
    return 0;
}