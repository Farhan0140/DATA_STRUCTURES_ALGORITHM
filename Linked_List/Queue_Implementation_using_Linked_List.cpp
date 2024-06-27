#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Node{
    public:
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void Enqueue(int value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if(head==NULL && tail==NULL){
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void Dequeue(){
    Node *temp = head;

    head = head->next;
}

void Print(){
    Node *current = head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//_______________________________________________________________________________________________


int main(){
    cout << "After Enqueue some value: ";
    Enqueue(12);
    Enqueue(90);
    Enqueue(67);
    Enqueue(100);
    Enqueue(99);
    Enqueue(1000);
    Print();

    Dequeue();
    Dequeue();
    Dequeue();
    Print();
    return 0;
}


//_______________________________________________________________________________________________