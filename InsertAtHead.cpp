#include <iostream>
using namespace std; 
class node{
  public: 
  int value; 
  node* next;
  node(int v){
      value = v;
      next = NULL;
  }
};
void InsertAtEnd(node* &head,int value){
    node* node1 = new node(value);
    if(head==NULL){
        head = node1;
        return;
    }
    node* temp = head; 
    while(temp->next!=NULL){
        temp = temp->next;
        
    }
    temp -> next = node1;
}
void InsertAtHead(node* &head, int value){
    node* node1 = new node(value);
    node1 -> next = head; 
    head = node1;
}


void display(node* &head){
    node*temp= head; 
    while(temp!=NULL){
        cout<<temp->value<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
}
int main(){
    node* head = NULL; 
    InsertAtEnd(head,10);
    InsertAtHead(head,3);
    InsertAtEnd(head,20);
   
    InsertAtHead(head,5);
    display(head);
    return 0;
}