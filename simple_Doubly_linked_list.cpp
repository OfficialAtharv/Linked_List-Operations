#include<iostream> 
using namespace std; 
class Node{
    public:
    int value; 
    Node* next;
    Node* prev;
    
    Node(int val){
        value = val; 
        next = NULL; 
        prev = NULL;
    }
};
void backword_display(Node* head){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        cout<<temp->value<<" <--> ";
        temp = temp->prev;
    }cout<<"NULL"<<endl;
}
void display(Node* head){
    Node*temp  = head; 
    while(temp != NULL){
        cout<<temp->value<<" <--> ";
        temp = temp-> next ; 
        
    }cout<<"NULL"<<endl;
}
int main(){
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1 -> next = node2; 
    node2 -> next = node3; 
    node3 -> next = node4;
    node2 -> prev = node1;
    node3 -> prev = node2;
    node4 -> prev = node3; 
    
   
    Node* head = node1;
    display(head);
    backword_display(head);
    return 0;
}