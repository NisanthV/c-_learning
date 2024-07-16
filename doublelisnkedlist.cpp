#include <iostream>
using namespace std;

class Node
{

public:
    int value;
    Node *next;
    Node *prev;
};

void deleteAtBegin(Node** head){

    if(*head == NULL){
        cout<<"list was empty";
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    cout<<"status code: 200"<<endl;
    delete temp;
}

void deleteAtEnd(Node** head){
    Node* temp = *head;

    if(temp == NULL){
        cout<<"list was empty";
        return;
    }
    if(temp->next == NULL){
        *head = NULL;
        delete temp;
        cout<<"status code: 200"<<endl;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp=temp->next;
    }

    delete temp->next;
    temp->next=NULL;
    cout<<"status code: 200"<<endl;
    return;

}

void deleteAtSpecificLocation(Node** head,int value){

    Node* temp = *head;
    if(temp == NULL){

        cout<<"list was empty";
        return;
    }
    if((temp->next == NULL) && (temp->value == value)){
        delete temp;
        *head = NULL;
        cout<<"status code: 200"<<endl;
        return;
    }
    while (temp->value != value)
    {
        if(temp->next == NULL){
            cout << "entered value not in the list : "<<value<<endl;
            return;
        }
        temp = temp->next;
    }
    if(temp->prev == NULL){

        *head = temp->next;
        delete temp;
        cout << "entered value not in the list : "<<value<<endl;
        return;
    }
    temp->prev->next = temp->next;
    delete temp;
    return;
}

void insertAtBegin(Node **head, int value)
{

    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = *head;
    newNode->prev = NULL;

    if(*head != NULL){
        (*head)->prev = newNode; 
    }

    *head = newNode;
}

void insertAtLast(Node **head, int value)
{
    Node *newNode = new Node();
    Node *temp = *head;
    if ((*head) == NULL)
    {
        cout << "list was empty.  Now provided input taken as head and it also point to upcomming nodes" << endl;
        insertAtBegin(head, value);
        return;
    }

    if (temp->next == NULL)
    {

        newNode->value = value;
        newNode->next = NULL;
        newNode->prev = temp;
        temp->next = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = temp;
    temp->next = newNode;

    return;
}

void inserAtSpecificLocation(Node **head, int value, int posValue)
{

    if (*head == NULL)
    {
        cout << "list was empty.  Now provided input taken as head and it also point to upcomming nodes" << endl;
        insertAtBegin(head, value);
        return;
    }
    if ((*head)->next == NULL && (*head)->value == posValue)
    {
        insertAtLast(head, value);
        return;
    }
    Node *temp = *head;
    Node *newNode = new Node();
    while (posValue != temp->value)
    {
        if (temp->next == NULL)
        {

            cout << "entered value not in the list : "<<posValue<<endl;
            return;
        }
        temp = temp->next;
    }

    newNode->value = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    return;
}

void print(Node *n)
{

    while (n != NULL)
    {
        cout << "->" << n->value;
        n = n->next;
    }
}

int main()
{

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->value=1;
    head->prev=NULL;
    head->next=NULL;

    // second->value=2;
    // second->prev=head;
    // second->next=third;

    // third->value=3;
    // third->prev=second;
    // third->next=NULL;
    //insertAtBegin(&head, 0);
    // insertAtLast(&head,4);
    //inserAtSpecificLocation(&head, 4, 0);
    //deleteAtEnd(&head);
    deleteAtSpecificLocation(&head,1);
    print(head);

    return 0;
}