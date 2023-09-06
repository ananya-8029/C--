#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans;
        if (head == NULL && k > 1)
        {
            while (k--)
            {
                ListNode *node = NULL;
                ans.push_back(node);
            }
            return ans;
        }

        if (head == NULL)
        {
            return ans;
        }

        if (k == 1)
        {
            ans.push_back(head);
            return ans;
        }

        ListNode *temp = head;
        // size of the linked list
        int n = 0;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }

        // Case1: When k is greater than or equal to the size of the linked list
        //We can simply split all the nodes of the list individually and store them in the answer
        if (k >= n)
        {
            temp = head;
            while (temp != NULL)
            {
                ListNode *node = new ListNode(temp->val);
                ans.push_back(node);
                temp = temp->next;
            }

            if (k == n)
            {
                return ans;
            }
            else
            {
                int leftParts = k - n;
                while (leftParts)
                {
                    ans.push_back(NULL);
                    leftParts--;
                }
            }
        }
        // Case: when k is less than the size of the linked list
        //Here we need to have n/k size of linked lists
        else
        {
            temp = head;
            //array to store all the size of sub linked list possible from the k
            vector<int> sizeOfPartitions;
            while (k != 0)
            {
                sizeOfPartitions.push_back(n / k);
                n = n - (n / k);
                k--;
            }
            //Ques asked to place the greater size at the front so we reversed the array
            reverse(sizeOfPartitions.begin(), sizeOfPartitions.end());

            //here we create the sub linked lists
            for (int i = 0; i < sizeOfPartitions.size(); i++)
            {
                int j = 1;
                ListNode *subHead = new ListNode(temp->val);
                ListNode *subTemp = subHead;
                temp = temp->next;

                while (j < sizeOfPartitions[i] && temp != NULL)
                {
                    ListNode *node = new ListNode(temp->val);
                    subTemp->next = node;
                    j++;
                    temp = temp->next;
                    subTemp = subTemp->next;
                }
                subTemp->next = NULL;
                ans.push_back(subHead);
            }
        }
        
        return ans;
    }
};