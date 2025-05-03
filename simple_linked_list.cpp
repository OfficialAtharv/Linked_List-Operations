#include<iostream>
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
    node* temp= head; 
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp -> next;
    }
    cout<<"NULL";
}
int main(){
    node* node1 = new node(10);
    node* node2 = new node(20);
    node* node3 = new node(30);
    node* node4 = new node(40);
    
    node1 -> next = node2;
    node2 -> next = node3; 
    node3 -> next = node4; 
    
    display(node1);
    return 0;
}
