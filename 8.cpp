#include <iostream>
using namespace std;

/******************************singly linked list*********************************/

class node
{
public:
    int data;
    node *next;

    node(int n)
    {
        this->data = n;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout << "memory is free up for " << value << endl;
    }
};

void insertathead(node *&head, node* &tail, int n)
{   
    if(head==NULL){
        node* temp=new node(n);
        head=temp;
        tail=temp;
    }
    else{
    node *temp = new node(n);
    temp->next = head;
    head = temp;
    }
}

void insertattail(node* &head, node *&tail, int n)
{
    if(tail==NULL){
        node* temp=new node(n);
        tail=temp;
        head=temp;
    }
    else{
    node *temp = new node(n);
    tail->next = temp;
    tail = temp;
    }
}

void insertatposition(node *&head, node *&tail, int position, int n)
{

    if (position == 1)
    {
        insertathead(head,tail,n);
        return;
    }

    node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertattail(head, tail, n);
        return;
    }

    node *newposi = new node(n);
    newposi->next = temp->next;
    temp->next = newposi;
}

void print(node *&head)
{
    node *temp = head;

    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deletenode(node *&head, int position)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    node *node1 = new node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    node *head = node1;
    node *tail = node1;
    /* insertathead(head,20);
     print(head);

     insertathead(head,30);
     print(head);*/

    insertattail(head,tail, 40);
    //  print(head);

    insertattail(head,tail, 60);
    //  print(head);

    insertatposition(head, tail, 3, 50);
    print(head);

    cout << head->data << endl;
    cout << tail->data << endl;

    deletenode(head, 4 );
    print(head);

    cout << head->data << endl;
    cout << tail->data << endl;

    return 0;
}