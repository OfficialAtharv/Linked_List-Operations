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
  if(head==NULL){
    cout<<"Linked List is empty "<<endl;
    return;
  }
  node*temp= head; 
  while(temp!=NULL){
      cout<<temp->value<<" -> ";
      temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

int main(){
  node* head = NULL; 
  cout<<"Operations on Linked List :- "<<endl;
  cout<<"1.Display Linked List "<<endl;
  cout<<"2.Insert at Head "<<endl;
  cout<<"3.Insert at Middle "<<endl;
  cout<<"4.Insert at End "<<endl;
  cout<<"5.Delete at Head "<<endl;
  cout<<"6.Delete at Middle "<<endl;
  cout<<"7.Delete at End "<<endl;
  cout<<endl;
 
  
  while(true){
    cout<<"Enter Your Choice: ";
    int choice; 
    cin>>choice;
    if(choice == 1){
      display(head); 
    }
    else if(choice == 2){
      int value;
      cout<<"Enter Value to add : ";
      cin>>value;
      InsertAtHead(head,value);
      display(head);
    }
    else if(choice == 3){
      int value; 
      int postion; 
      cout<<"Enter the value space separted by position";
      cin>>value>>postion;
      InsertAtMiddle(head,value,postion);
      display(head);
    }
    else if(choice == 4){
      int value;
      cout<<"Enter the value to insert at end: ";
      cin>>value;
      InsertAtEnd(head,value); 
      display(head);
    }
    else if(choice==5){
      DeleteAtHead(head);
      display(head);
    }
    else if(choice ==6){
      cout<<"Enter the Position to be deleted";
      int Position;
      cin>>Position;
      DeleteAtMiddle(head,Position);
      display(head);
    }
    else if(choice == 7){
      DeleteAtEnd(head); 
      display(head);
    }
   
    else{
      cout<<"Enter correct choice :";
      break;
    }
  }
}
