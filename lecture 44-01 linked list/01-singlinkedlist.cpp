#include<iostream>
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
    //this destructor is useless we are not  deleting the current node at all from this code and also not managed the condition for last node
    //overwall we dont even need a manuall destructor at least not this one which is not even actually freeing or deleting the current node
    ~Node()
    {
        int value = this-> data;
        if(this->next != NULL)
        {
             this-> next =NULL; //this line is only looks like usefull as it make the next to null of the node which we are deleting which is good
             delete next;

            //lecture logic
            // delete next; 
            // this-> next =NULL; //we already have deleted the next so what the meaning of pointing it to NULL
        }
        
        cout<<"memory is free with data " << value<<endl;
    }
};

void InsetAtHead(Node* &head, Node* &tail , int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &head, Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void InsertAtPosition(Node* &head, Node* &tail, int position , int data)
{
    // inserting at first position i.e head
    if(position == 1)
    {
        InsetAtHead(head,tail,data);
        return;
    }
    
    // traversing to the required position
    Node* curposition = head;
    int count = 1;
    while(count < position-1)
    {
        curposition = curposition -> next ;
        count++;
    }

    // inserting at last postion i.e tail

    if(curposition -> next ==  NULL)
    {
        InsertAtTail(head,tail,data);    
        return;
    }
    Node* temp = new Node(data);
    temp -> next = curposition -> next;
    curposition -> next =  temp;
}

void deleteNodeByPosition(Node* &head, Node* &tail, int position)
{
    // deleting first node
    if(position == 1)
    {
        Node* todelete = head;
        head = head -> next;
        // deleting memory 
        delete todelete;
    }
    else //for middle and last node
    {
        Node* prev = head;
        int count = 1;
        // traversing to previvous position of last node 
        while(count < position -1)
        {
            prev = prev -> next;
            count++;
        }

        // creating a temp pointer for to point to the  node i have to delete

        Node* todelete = prev -> next;

        //deleting last node
        // if (todelete -> next == NULL)
        // {
        //     prev -> next = NULL;
        //     delete todelete;
        //     return;
        // }

        // deleting any middle node or last node
        prev -> next = todelete -> next;
        //detecting last node and handeling the tail
        if(todelete -> next == NULL){ tail = prev;}
        delete todelete;
    }
}
void deleteNodeByPositionByLecture(Node* &head, Node* &tail, int position) 
{
    if (position == 1)
    {
        Node*temp = head;
        head = head -> next;
        //temp -> next = NULL;
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
        //handeling last node ->
        if(prev->next == tail){ tail = prev;} // or curr->next == NULL
        prev -> next = curr -> next;
         
        //curr-> next = NULL; 
        delete curr; //not pointting the cuur -> next as i have done this in destructor by line this->next =null and also if i do it the if condition will be false and it never going to run the destructor code;
                     // still not utilizing his destructor logic which make thing more complex
    }
    
}

void print(Node* &head)
{
    //storing adrress of current starting node in temp
    Node* temp = head;
    while (temp != NULL)
    {   
        cout<< temp -> data <<" ";
        temp = temp->next;
    }   
    cout<<endl;
    delete temp; //deleting variable created in heap dynamically
}

int main()
{
    // Node* node1 = new Node(10);

    // Node* head = node1; //pointing at first node which is created in above line
    // Node* tail = node1; //pointing at first node which is created in above line as it is the only node available

    // cout << node1 -> data <<endl;
    // cout << node1 -> next <<endl;
    Node* head = NULL;
    Node* tail = NULL;
    // print(head);

    // InsetAtHead(head, tail ,20); // head pointer is updated to latest first node
    // print(head);

    // InsertAtTail(head, tail,13); //tail pointer is updated to latest last node
    // print(head);

    // InsertAtTail(head ,tail,130);
    // print(head);

    
    // InsertAtTail(head ,tail,133);
    // print(head);

    // InsertAtPosition(head , tail , 6  , 160);
    // print(head);
    
    // deleteNodeByPositionByLecture(head , tail , 6);
    // print(head);

    // InsertAtTail(head, tail,135);
     int size;
     cin>>size;
     int data;
    for(int i=0; i<size; i++)
    {
    cin>>data;
    InsertAtTail(head, tail, data);
    }
    print(head);
    
    return 0;
}
