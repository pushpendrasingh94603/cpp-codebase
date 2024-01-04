#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Stack{
    Node* top;
    public:

    Stack(){
        this -> top = NULL;
    }

    void push(int data){
        Node* newnode = new Node(data);
        newnode -> next = top;
        top = newnode;
    }

    bool isEmpty(){
        return top == NULL;
    }

    void pop(){
        if(!isEmpty()){
            Node* todelete = top;
            cout<<"stack entry with data -> "<<top->data<<" is deleted \n";
            top=top->next;
            delete todelete;
        }
        else
        {
            cout<<"/nnothing to delete !!/n";   
        }
    }

    void display(){
        if(!isEmpty()){
            cout<<"\nHere are the stack elements listed bellow \n";
            Node* curr = top;
            while(curr!= NULL)
            {
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            cout<<endl;
        }
        else{
            cout<<"\nnothing to show come back later after pushhing some data !!\n";
        }
    }

    int peek(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    return top->data;
    }
};

int main(){
    Stack stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}