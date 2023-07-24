#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    //Contructor used to fill the data in the node
    node(int d){
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
};

//Creating a tree
/* 1
  3 5
7 11 17 */
node* buildTree(node* root){

    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;

    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"For insertion in left of "<<data<<":"<<endl;
    root->left=buildTree(root->left);

    cout<<"For insertion in right of "<<data<<":"<<endl;
    root->right=buildTree(root->right);  
      
    return root;
}

void inOrder(node* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preorder(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOfTraversing(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//Driver Code
int main(){  

    node* root=NULL;

    //Creation of Tree
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    //level of Traversal
    cout<<"LevelOrder Traversal"<<endl;
    levelOfTraversing(root);

    //Inorder traversal
    cout<<"Inorder Traversal"<<endl;
    inOrder(root);
    cout<<endl;
    //Preorder traversal
    cout<<"Preorder Traversal"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder Traversal"<<endl;
    postorder(root);
    return 0;
}