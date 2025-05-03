#include <iostream>
using namespace std; 
//Creation of the node here :-
class node{
  public: 
  int value; 
  node* next;
  node(int v){
      value = v;
      next = NULL;
  }
};
//Insert at the end of the Linked list :- 
void InsertAtEnd(node* &head,int value){
    node* node1 = new node(value);
    //Here the condition is if there is no node present in the list then what to do 
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
//insert at head 
void InsertAtHead(node* &head, int value){
    node* node1 = new node(value);
    node1 -> next = head; 
    head = node1;
}
//Insert at middle by getting the postion (index value)
void InsertAtMiddle(node* &head, int position, int value){
    
    if(position == 1){
     InsertAtHead(head, value);   
     return;
    }
    node* node1 = new node(value);
    node* prev = head; 
    int count = 1; 
    while(count<(position-1)){
        prev = prev -> next;
        count ++;
    }
    node1 -> next = prev->next; 
    prev -> next = node1; 
}
//Display the Linked List 
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
    InsertAtMiddle(head,2,66);
    InsertAtHead(head,5);
    display(head);
    return 0;
}