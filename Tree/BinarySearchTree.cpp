#include<bits/stdc++.h>
using namespace std;

//Creating a node for a tree
class node{
    public:
    int data;
    node* left;
    node* right;

    //contructor to initialise the initial value
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

//Insertion in a Binary Search Tree ____ Time Complexity:O(h) === O(logn)  Space Complexity: O(h)
//Recursive method
node* insert(node* root, int key){
    if(root==NULL){
        return new node(key);
    }

    if(root->data > key){
        root->left=insert(root->left,key);
    }
    else{
        root->right=insert(root->right,key);
    }
    return root;
}

//Iterative Method ___  Time Complexity: O(h)   Space Complexity is O(1)   h==log n
node* insertIterative(node* root,int key){
    node* newNode=new node(key);
    node* curr=root;
    node* parent=NULL;

    //this loop will update the parent node and we will reach to the position where the node needs to be inserted with the help of curr pointer
    while(curr!=NULL){
        parent=curr;
        if(key>curr->data){
            curr=curr->right;
        }
        else{
            curr=curr->left;
        }
    }

    //once we reach the correct position, we simply check whether the data of the given node is greater or less than its parent node
    if(parent==NULL){
        parent=newNode;
    }
    else if(parent->data > key){
        parent->left=newNode;
    }
    else{
        parent->right=newNode;
    }
    return parent;
}

//Driver Program
int main(){
    node* root=NULL;
    root=insert(root,21);
    insert(root,14);
    insert(root,8);
    insert(root,25);
    insert(root,22);
    return 0;
}