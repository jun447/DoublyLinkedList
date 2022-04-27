#include <iostream>
using namespace std;
//Doubly linked list
class Node {
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node() {
        int value = this->data;
        //memory free code
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void print(Node* head,Node* tail){
    Node* temp = head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
}
int getlength(Node* head){
    Node* temp = head;
    int count=0;
    while(temp !=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
void InsertAtHead(Node* &head,Node* &tail,int data){
//    doing some correction
    if(head == NULL){
        Node* temp =new Node(data);
        head=temp;
        tail=temp;
    }else{
        Node* temp =new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
int InsertAtTail(Node* &head,Node* &tail,int data){
    if(tail == NULL){
        Node* temp =new Node(data);
        tail=temp;
        head=temp;
    }else{
    Node* temp =new Node(data);
    tail->next=temp;
    tail=temp;
    temp->prev=tail;
    tail=temp;
    }
}
void InsertAtPosition(Node* head,Node* tail,int position,int data){
    if(position==1){
//        no need to update head
        InsertAtHead(head,tail,data);
        return;
    }
    Node* temp =head;
    int count =1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }
//    Insertig at last position so we need to update tail
    if (temp->next==NULL){
        InsertAtTail(head,tail,data);
        return;
    }
//    create new node for data
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}
void deleteNode(int position,Node* &head,Node* &tail){
//    deleting first and start node
    if(position==1){
        Node* temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next= NULL;
        delete temp;
    }else{// deleting middle and last node
        Node* curr = head;
        Node* prev =NULL;//because first node ke prev NULL hota hai
        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }
       curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        tail=head->next;
    }
    Node* temp = head;
    while(temp !=NULL){
        tail=temp;
        temp=temp->next;
    }
}
int main() {

    Node* head=NULL;
    Node* tail=NULL;
//    print(head,tail);
    InsertAtHead(head,tail,2);
    print(head,tail);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,4);
    print(head,tail);
    InsertAtPosition(head,tail,2,78);
    print(head,tail);

    deleteNode(1,head,tail);
//    deleteNode(4,head);
    print(head,tail);


}
