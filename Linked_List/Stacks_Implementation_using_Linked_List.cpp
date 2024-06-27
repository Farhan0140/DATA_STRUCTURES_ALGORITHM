#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Node{
    public:
    int data;
    Node *next;
};

Node *top = NULL;

//_______________________________________________________________________________________________

void Push(int value){
    Node *new_node = (Node *)malloc( sizeof(Node));

    if(new_node == NULL){ cout << "Stack Overflow...." << endl; exit(1); }

    new_node->data = value;

    if(top == NULL){ 
        top = new_node; 
        new_node->next = NULL;
    } else { 
        new_node->next = top;
        top = new_node;
    }
}


void Pop(){
    Node *temp = top;

    if(temp == NULL){
        cout << "Stack is empty!" << endl;
        exit(1);
    }

    top = top->next;
}


void Print(){
    Node *temp_top = top;

    while(temp_top != NULL){
        cout << temp_top->data << " ";
        temp_top = temp_top->next;
    }
    cout << endl;
}

//_______________________________________________________________________________________________


int main(){
    Push(12);
    Push(9);
    Push(99);
    Print();
    Pop();
    Pop();
    Pop();
    Print();
    return 0;
}


//_______________________________________________________________________________________________