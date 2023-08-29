#include<iostream>
#include<iomanip>
using namespace std;
//defining NODE type datatype using class
class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
     ~Node()
    {
        int value = this-> data;
        if(this->next != NULL)
        {
             this-> next =NULL;
             delete next;

            //lecture logic
            // delete next; 
            // this-> next =NULL; 
        }
        cout<<"memory is free with data " << value<<endl;
    }
};
void InsertNode(Node* &tail, int element , int data)
{
    if(tail == NULL)
    {
        Node* temp = new Node(data);
        tail = temp;
        tail -> next =tail;
    }
    else
    {
        //currpos = current position
        Node* currpos = tail; //checking if element is already at tail
        if(currpos -> data == element){
            // cout<<"data at currpos and actually at tail = "<<currpos->data<<endl;
            Node* temp = new Node(data);
            temp -> next = currpos -> next;
            currpos -> next = temp;
            return;
        } 
        //if not
        else{
            currpos = currpos->next;
            /*
            travesring through whole linked list to search element and 
            second condition will break the loop just before reaching the
            tail again as we allready checked at tail for element 
            and we did not found so if loop is trying to get back to tail again
            means element does not exist soo we must break the loop
            */ 
            while (currpos -> data != element && currpos != tail)
            {
                currpos = currpos -> next;
            }
            // cout<<"data at currpos = "<<currpos->data<<endl;
            
            if(currpos -> data == element)//if found the element
            {
                Node* temp = new Node(data);
                temp -> next = currpos -> next;
                currpos -> next = temp;
            }
            else
            {
                cout<<"WARNING : Given element "<<element<<" does not exist So Node insertion with data -> "<<data<<" Aborted !!"<<endl;
            }
        }
    }
}

void DeleteNodeByValue(Node* &tail ,int  element)
{
    if (tail == NULL)
    {
        cout<<"WARNING : list is empty nothing to delete !!"<<endl;
        return;
    }
    // else if(tail -> next == tail && tail -> data == element) //if only one node exist but element is on that
    // {
    //     Node* temp = tail;
    //     tail -> next = NULL;
    //     tail = NULL;
    //     delete temp;
    // }
    // else if(tail -> next == tail && tail -> data != element)//if only one node exist but element is not on that
    // {
    //     cout<<"WARNING : Node with data "<<element<<" does not exist !!"<<endl;
    // }
    // else
        //checking if element even exist or not
        bool exist;
        Node* currpos = tail;
        do{
            if(currpos -> data == element){
                exist = true;
                cout<<"element find at "<<currpos<<endl;
            }
        currpos = currpos -> next;
        }while(currpos != tail);

        if(exist == true)
        {
        //now we have verified that given element exist
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr -> data != element )
        {
            prev = curr;
            curr = curr->next;
        }
        if(prev == curr) //single node condition
        {
            tail = NULL;
            delete curr;
        }
        else
        {if(curr == tail)
        {
            tail = tail->next;
        }
        Node* temp = curr;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;}
        }
        else
        {
            cout<<"WARNING : Node with given data not found"<<endl;
        }
    }
void Print(Node* tail)
{
   if(tail != NULL)
   {
    Node* currpos = tail;
    do{
        cout<<currpos -> data << "\t";
        currpos = currpos -> next;
    }while(currpos != tail);

    cout<<endl;
   }
   else{
    cout<<"WARNING : There is nothing to print try again after creating at least one Node !! "<<endl;
   }
}

int main()
{
    Node* tail = NULL;
    DeleteNodeByValue(tail,1000);
    Print(tail);
    InsertNode(tail,8,2);
    Print(tail);
    DeleteNodeByValue(tail , 2);
    Print(tail);
    InsertNode(tail,8,2);
    DeleteNodeByValue(tail , 4);
    Print(tail);
    InsertNode(tail,2,3);
    Print(tail);
    InsertNode(tail,3,4);
    Print(tail);
    InsertNode(tail,3,5);
    Print(tail);
    InsertNode(tail,13,5);
    DeleteNodeByValue(tail ,5);
    Print(tail);
    return 0;
}