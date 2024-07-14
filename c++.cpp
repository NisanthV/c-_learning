#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
};
 
void printList(Node* n){

    while(n!=NULL){
        cout<<n->value<<endl;
        n=n->next;
    }
}



void insertAtBegin(Node**head,int value){
    Node* newNode = new Node();
    newNode->value=value;
    newNode->next=*head;
    *head= newNode;
        
}

void inserAtLast(Node** head,int value){

    Node* newNode = new Node();
    newNode->value=value;
    newNode->next=NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node* last = *head;
    cout<<(*head)->next<<endl;
    while (last->next != NULL) 
    {
        last=last->next;
        cout<<last<<endl;
    }
    last->next=newNode;
    
    

}
void tempinsert(Node* &head,int value){
    Node* temp=new Node();
    cout<<head<<endl;
    temp->next=head;
    temp->value=value;
    head = temp;
}

void insertAtSpecificLocation(Node** head,int Value,int posValue){
    
    if (*head == NULL)
    {
        cout<<endl<<"list is empty can't insert";
        return;
    }

    Node* newNode = new Node();
    Node* temp;

    newNode->value=Value;
    temp=*head;
    while (posValue != temp->value)
    {
        if (temp->next == NULL)
        {
            cout << "There is no node with value " << posValue << ". Please check your input." << endl;
            delete newNode;
            return;
        }
        temp=temp->next;
    }
    
    newNode->next=temp->next;
    temp->next=newNode;

}



int main(){
    
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    
    head->value = 1;
    head->next=second;
    
    second->value=2;
    second->next=third;

    third->value=3;
    third->next=NULL;
    insertAtSpecificLocation(&head,4,13);
    printList(head);
    return 0;
}

