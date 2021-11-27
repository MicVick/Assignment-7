
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

int count(){
    int numberOfNodes=0;
    struct Node *temp1=head;
    while(temp1->next!=NULL){
        numberOfNodes++;
        temp1=temp1->next;
    }
    
    return numberOfNodes;
}

void midElement(){
    int n=count();
    int i=1;
    struct Node *temp=head;
    if(n % 2 == 0){
        while(i <= (n/2) + 1 ){
            temp=temp->next;
            i++;
        }
        cout<< temp->data <<endl;
    }
    else{
        while(i <= (n+1)/2 ){
            temp=temp->next;
            i++;
        }
        cout<< temp->data <<endl;
    }
}

int main(){
    insert(1);
    insert(4);    
    insert(5);    
    insert(9);    
    insert(0);    
    insert(3);    
    insert(8);    
    
    count();
    midElement();
    return 0;
}