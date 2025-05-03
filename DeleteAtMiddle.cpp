#include<iostream>
using namespace std; 
class node{
  public:
  int value; 
  node* next; 

  node(int val){
    value = val;
    next = NULL;
  }

};
void InsertAtHead(node* &head , int value){
  node* node1 = new node(value);
  node1 -> next = head;
  head = node1;
}
void InsertAtEnd(node* &head,int value){
  node* node1 = new node(value);
  if(head == NULL){
    head = node1; 
    return;
  }
  node* temp = head; 
  while(temp->next != NULL){
    temp = temp->next; 
  }
  temp->next= node1; 
}
void InsertAtMiddle(node* &head, int value, int position){
  
  
  if(position == 1){
    InsertAtHead(head,value); 
    return;
  }
  node* node1 = new node(value);
  node* prev = head; 
  int count =1; 
  while(position<(count-1)){
    prev= prev ->next;
    count++;
  }
  node1 -> next = prev->next; 
  prev-> next = node1;
}
void DeleteAtEnd(node* &head){
  if(head==NULL){
    cout<<"No node found";
    return;
  }
  node* second_last= head;
  while(second_last->next->next!=NULL){
    second_last= second_last->next;
  }
  node* last_node = second_last->next; 
  second_last->next=NULL; 
  delete(last_node);
}
void DeleteAtHead(node* &head){
  if(head == NULL){
    cout<<"no node found";
    return;
  }
  node* temp=head;
  head = head->next;;
  delete(temp);
}

void DeleteAtMiddle(node* &head, int position){
    if(position==1){
    DeleteAtHead(head);
    return;
  }
  node*prev= head;
  int count = 1; 
  while(count<(position-1)){
      prev= prev->next;
      count++; 
  }
  node* current = prev->next; 
  prev->next= current ->next; 
  delete(current);
  
    
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
  InsertAtHead(head,10);
  InsertAtEnd(head,20);
  InsertAtMiddle(head,15,2);
  DeleteAtMiddle(head,2);
//   DeleteAtEnd(head);
//   DeleteAtHead(head);
display(head);
}
