/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return nullptr;
    }
    
    ListNode* insertAfterListNode(ListNode* listNode, ListNode* insertedNode) {
        if(listNode->next) {
            ListNode* nodeAfterListNode = listNode->next;
            if(insertedNode->next) {
                ListNode* nodeAfterInsertedNode = insertedNode->next;
                listNode->next = insertedNode;
                insertedNode->next = nodeAfterListNode;
                return nodeAfterInsertedNode;
            }
            listNode->next = insertedNode;
            insertedNode->next = nodeAfterListNode;
            return nullptr;
        }
        listNode->next = insertedNode;
        return nullptr;
    }
    
    ListNode* initNode(int val = 0, ListNode* nextListNode = nullptr) {
        ListNode* newNode = new ListNode(val, nextListNode);
        return newNode;
    }
};

int main()
{
    Solution* sol = new Solution();
    ListNode* ln1 = sol->initNode();
    ListNode* ln2 = sol->initNode(1, ln1);
    ListNode* rootNode = sol->initNode(2, ln2);

    ListNode* insertedNode = sol->initNode();

    sol->insertAfterListNode(rootNode, insertedNode);

    while(rootNode) {
        cout << rootNode->val << endl;
        rootNode = rootNode->next;

    };
    // cout << rootNode->val << endl;

    return 0;
}

