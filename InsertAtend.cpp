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

void display(node* &head){
  node* temp = head; 
  while (temp!=NULL)
  {
    cout<<temp->value<<" -> ";
    temp = temp->next;
  } 
}
void insertatend(node* &head,int value){
  node* node1 = new node(value);
  if(head==NULL){
    head = node1; 
  }
  node* temp = head; 
  while(temp->next!= NULL){
    temp =temp->next;
  }
  temp->next =node1; 
}
int main(){
  node* head = NULL;
 insertatend(head,10);
 insertatend(head,10);
 insertatend(head,10);
  return 0;
}
