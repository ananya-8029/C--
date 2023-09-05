#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

//Approach1: Used a hash map of key->node of original list and value->node of copied list
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }

        //Creating head of the copy
        Node* headCopy=new Node(head->val);

        Node* temp=head->next;
        Node* tempCopy=headCopy;
        unordered_map<Node*,Node*>map;

        map[head]=headCopy;
        while(temp!=NULL){
            Node* node=new Node(temp->val);
            tempCopy->next=node;
            tempCopy=tempCopy->next;
            map[temp]=tempCopy;
            temp=temp->next;
        }

        tempCopy->next=NULL;

        temp=head;
        tempCopy=headCopy;
        while(temp!=NULL && tempCopy!=NULL){
            if(temp->random==NULL){
                tempCopy->random=NULL;
            }
            else{
                tempCopy->random=map[temp->random];
            }
            temp=temp->next;
            tempCopy=tempCopy->next;
        }

        return headCopy;
    }
};