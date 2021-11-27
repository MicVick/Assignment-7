//Write a program to count the number of nodes

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

void count(){
    int numberOfNodes=0;
    struct Node *temp1;
    temp1=head;
    while(temp1->next!=NULL){
        numberOfNodes++;
        temp1=temp1->next;
    }
    cout<<numberOfNodes<<endl;
}

int main(){
    insert(1);
    insert(4);    
    insert(5);    
    insert(9);    
    insert(0);    
    insert(3);    
    
    count();
    return 0;
}