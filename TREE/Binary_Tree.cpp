#include <bits/stdc++.h>
using namespace std;

#define ll long long int

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));


//_______________________________________________________________________________________________

/*
                                2               //! Root
                               / \
                              /   \
                             /     \
                            /       \           //! Left     Right 
                           7         9               7         9  
                          / \         \             1 6         8
                         /   \         \             5 10      3 4
                        /     \         \
                       /       \         \
                      1         6         8        
                               / \       / \
                              /   \     /   \
                             /     \   /     \
                            5      10 3       4
                      //* Left              Right       
*/

//_______________________________________________________________________________________________

class Node{
    public:                     
        int data;              
        Node *left;
        Node *right;
};

//_______________________________________________________________________________________________

Node *create_tree();

//_______________________________________________________________________________________________

/* 1 */ Node *create_Node(int value);
/* 2 */ void add_left_child(Node *parent, Node *child);
/* 3 */ void add_right_child(Node *parent, Node *child);

//____________________Tree_Traversal_____________________________________________________________

/* Pre_Order */ void pre_order(Node *root);
/* Post_Order */ void post_order(Node *root);
/* In_Order */ void in_order(Node *root);

//_______________________________________________________________________________________________


int main(){
    fast_read();

    Node *root = create_tree();

    pre_order(root);
    // post_order(root);
    // in_order(root);
    
    cout << endl;
    return 0;
}


//_______________________________________________________________________________________________

/* 1 */ Node *create_Node(int value){
    Node *new_node = new Node();

    if(new_node == NULL){
        cout << "Error! " << endl;
        exit(1);
    }

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//_______________________________________________________________________________________________

/* 2 */ void add_left_child(Node *parent, Node *child){
    parent->left = child;
}


/* 3 */ void add_right_child(Node *parent, Node *child){
    parent->right = child;
}

//_______________________________________________________________________________________________

Node *create_tree(){
    Node *two = create_Node(2);      // Root
    Node *seven = create_Node(7);    // Left Child
    Node *nine = create_Node(9);     // Right Child

    add_left_child(two, seven);      //-|
    add_right_child(two, nine);      //-|
                                     //-|
    Node *one = create_Node(1);      //-|
    Node *six = create_Node(6);      //-|
                                     //-|
    add_left_child(seven, one);      //- >   Left Sub Tree of Root Node 2
    add_right_child(seven, six);     //-|
                                     //-|
    Node *five = create_Node(5);     //-|
    Node *ten = create_Node(10);     //-|
                                     //-|
    add_left_child(six, five);       //-|
    add_right_child(six, ten);       //-|

    
    Node *eight = create_Node(8);    //-|
    add_right_child(nine, eight);    //-|
                                     //-|
    Node *three = create_Node(3);    //- >   Right Sub Tree of Root Node 2
    Node *four = create_Node(4);     //-|
                                     //-|
    add_left_child(eight, three);    //-|   
    add_right_child(eight, four);    //-|

    return two;
}

//____________________________Pre_Order__________________________________________________________

void pre_order(Node *root){
    cout << root->data << " ";

    if(root->left != NULL){
        pre_order(root->left);
    }

    if(root->right != NULL){
        pre_order(root->right);
    }
}

//____________________________Post_Order_________________________________________________________

void post_order(Node *root){

    if(root->left != NULL){
        pre_order(root->left);
    }

    if(root->right != NULL){
        pre_order(root->right);
    }

    cout << root->data << " ";
}

//____________________________In_Order___________________________________________________________

void in_order(Node *root){

    if(root->left != NULL){
        pre_order(root->left);
    }
    
    cout << root->data << " ";

    if(root->right != NULL){
        pre_order(root->right);
    }
}

//_______________________________________________________________________________________________