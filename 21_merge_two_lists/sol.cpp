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
        ListNode* rootNode = list1;
        while(list1 && list2) {
            // while(list2) {
            if (list1->val <= list2->val) {
                insertAfterListNode(list1, list2);
            } else {
                insertBeforeListNode(findListNodeBefore(rootNode, list1), list1, list2);
            }
            // break;
            list1 = rootNode;
            list2 = list2->next;
        }
        return rootNode;
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

    ListNode* insertBeforeListNode(ListNode* listNodeBeforeTarget, ListNode* targetListNode,  ListNode* insertedNode) {
            if(insertedNode->next) {
                ListNode* nodeAfterInsertedNode = insertedNode->next;
                listNodeBeforeTarget = insertedNode;
                insertedNode->next = targetListNode;
                return nodeAfterInsertedNode;
            }
            listNodeBeforeTarget->next = insertedNode;
            // cout << listNodeBeforeTarget->next->val << endl;
            insertedNode->next = targetListNode;
            return nullptr;
    }

    ListNode* findListNodeBefore(ListNode* rootNode, ListNode* targetListNode) {
        while(rootNode) {
            if (rootNode->next == targetListNode) {
                return rootNode;
            }
            rootNode = rootNode->next;
        }
        return nullptr;
    }
    
    ListNode* initNode(int val = 0, ListNode* nextListNode = nullptr) {
        ListNode* newNode = new ListNode(val, nextListNode);
        return newNode;
    }
};

int main()
{
    // list 1
    Solution* sol = new Solution();
    ListNode* ln1 = sol->initNode(2);
    ListNode* ln2 = sol->initNode(1, ln1);
    ListNode* rootNode = sol->initNode(0, ln2);

    // ListNode* insertedNode = sol->initNode();

    // list 2
    ListNode* l2n1 = sol->initNode(2);
    ListNode* l2n2 = sol->initNode(1, l2n1);
    ListNode* rootNode2 = sol->initNode(0, l2n2);

    // ListNode* insertedNode = sol->initNode();

    // sol->insertBeforeListNode(rootNode, ln2, insertedNode);

    while(rootNode) {
        cout << rootNode->val << endl;
        rootNode = rootNode->next;

    };
    while(rootNode2) {
        cout << rootNode2->val << endl;
        rootNode2 = rootNode2->next;

    };
    ListNode* mergedRoot = sol->mergeTwoLists(rootNode, rootNode2);
    while(mergedRoot) {
        cout << mergedRoot->val << endl;
        mergedRoot = mergedRoot->next;

    };
    // cout << rootNode->val << endl;

    return 0;
}

