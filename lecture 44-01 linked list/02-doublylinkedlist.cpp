#include<iostream>
#include<iomanip>
using namespace std;
//defining NODE type datatype using class
class Node
{
    public:

    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node(){ //a useless destructor wriiten even i dont know why i have written this
        int val = this -> data;
        if(this -> next != NULL){
            this->next = NULL;
            delete next;
            //lecture logic
            // delete next; 
            // next =NULL;
        }
        cout<<"memory free for node with data : "<< val<<endl;
    }  
};
int GetLength(Node* &head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        length++;
        temp = temp -> next;
    }
    return length;
}
void InsertAtHead(Node* &head ,Node* &tail, int data ){
    //what if node exist uptu now so head = NULL
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}
void InsertAtTail(Node* &head , Node* &tail , int data){
    if(tail == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    Node* temp = new Node(data);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp; 
}
void Print(Node* &head){
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<setfill('0')<<setw(2)<< temp -> data <<"\t"; //to bea able to print leading 0 i have passed in tail
        temp = temp -> next;
    }
    cout<<endl;
}
void PrintReverse(Node* &tail){
    Node* temp = tail;
    while(temp != NULL)
    {
        cout<<setfill('0')<<setw(2)<< temp -> data <<"\t";
        temp = temp -> prev;
    }
    cout<<endl;
}
void InsertAtPosition(Node* &head, Node* &tail, int position, int data)
{
    if(position == 1){
        InsertAtHead(head,tail,data);
        return; 
    }

    //handeling any middle and last node

    Node* nextpos = NULL; //pointing to the node which is going to shift to next postion
    Node* prevpos = head; //pointing to the node after which we are going to insert our new node

    Node* temp = new Node(data); //new node creation

    int count = 1;
    while(count < position -1)
    {
        prevpos = prevpos -> next;
        nextpos = prevpos -> next;
        count++;
    }
    //handeling last node
    if(prevpos->next == NULL) // prevpos == tail
    {
        cout<<"inserted at tail";
        InsertAtTail(head,tail,data);
        return;
    }
    else // handeling any middle node
    {
        prevpos -> next = temp;
        temp -> prev = prevpos;
        temp -> next = nextpos;
        nextpos -> prev = temp;
    }
}
void deleteNodeByPositionByLecture(Node* &head, Node* &tail, int position) 
{
    if (position == 1)
    {
        Node*temp = head;
        head = head -> next;
        head -> prev = NULL; 
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt =1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        // handeling last node ->
        if(curr->next == NULL){ 
            tail = prev;
            prev -> next = NULL;
            delete curr;
            }
        else{
        //any middle node
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next -> prev = prev; 
        curr -> next = NULL;
        delete curr; 
        }
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    Print(head);
    InsertAtHead(head, tail , 20);
    Print(head);
    InsertAtHead(head ,tail ,30);
    Print(head);
    // cout<<GetLength(head)<<endl;
    InsertAtTail(head, tail , 01);
    Print(head);
    InsertAtTail(head, tail , 03);
    //cout<<GetLength(head)<<endl;
    Print(head);
    InsertAtPosition(head ,tail , 5 , 02);
    Print(head);
    cout<<GetLength(head)<<endl;
    deleteNodeByPositionByLecture(head,tail,6);
    Print(head);
    PrintReverse(tail);
    return 0;
}