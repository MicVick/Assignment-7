// Write a program to count the number of nodes having a) odd data element b) even data element.

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
    int oddNumberOfNodes=0;
    struct Node *temp1;
    int evenNumberOfNodes=0;
    temp1=head;
    while(temp1->next!=NULL){
        if(temp1->data % 2 ==0)
            evenNumberOfNodes++;
        else
            oddNumberOfNodes++;
        temp1=temp1->next;
    }
    
    cout<<evenNumberOfNodes<<endl;
    cout<<oddNumberOfNodes<<endl;
    
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