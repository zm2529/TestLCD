//
//  Tools.hpp
//  TestLCD
//
//  Created by zm on 2021/3/25.
//

#ifndef Tools_hpp
#define Tools_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tool {
public:
    void printVector(vector<int>& vec)
    {
        vector<int>::iterator it = vec.begin();
        while (it != vec.end()) {
            cout<<*it<<",";
            it++;
        }
        cout<<endl;
    }

    void printMatrix(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < matrix.size(); i++) {
            cout<<"[";
            for (int j = 0; j < matrix[i].size(); j++) {
                cout<<matrix[i][j];
                if (j != matrix[i].size() - 1) {
                    cout<<",";
                }
            }
            cout<<"]"<<endl;
        }

        cout<<endl;
    }

    void printList(ListNode *head) {
        ListNode *temp = head;
        while (temp != nullptr) {
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    ListNode *createList(vector<int>& arr, int cyclePos) {
        ListNode *cyclePtr = nullptr;
        ListNode *head = nullptr;
        ListNode *current = nullptr;
        for (int i = 0; i < arr.size(); i++) {
            if (head == nullptr) {
                head = new ListNode(arr[i]);
                current = head;
            }
            else {
                ListNode *node = new ListNode(arr[i]);
                current->next = node;
                current = node;
            }

            if (i == cyclePos) {
                cyclePtr = current;
            }
        }

        if (current != nullptr) {
            current->next = cyclePtr;
        }

        return head;
    }

    void printBT(TreeNode *node) {//层先
        deque<TreeNode *> deque;
        deque.push_back(node);
        deque.push_back(new TreeNode(-999));
        while (deque.empty() == false) {

            while (deque.front() != nullptr && deque.front()->val != -999) {
                TreeNode *temp = deque.front();
                deque.pop_front();

                if (temp->val == -1) {
                    cout<<"N ";
                }
                else if (temp->val == -2) {
                    cout<<"N ";
                }
                else {
                    cout<<temp->val<<" ";
                }

                if (temp->left != nullptr || temp->right != nullptr) {
                    if (temp->left != nullptr) {
                        deque.push_back(temp->left);
                    }
                    else {
                        deque.push_back(new TreeNode(-1));
                    }

                    if (temp->right != nullptr) {
                        deque.push_back(temp->right);
                    }
                    else {
                        deque.push_back(new TreeNode(-2));
                    }
                }
            }
            deque.pop_front();
            cout<<endl;
            if (deque.empty() == false) {
                deque.push_back(new TreeNode(-999));
            }
        }
        cout<<endl;
    }

    TreeNode *createBT(vector<int>& arr) {// 层先
        deque<TreeNode *> deque;
        TreeNode *root = nullptr;

        int i = 0;
        while (i < arr.size()) {
            if (root == nullptr) {
                root = new TreeNode(arr[i++]);
                deque.push_back(root);
            }
            else {
                if (i < arr.size()) {
                    int tempVal = arr[i++];
                    if (tempVal != -1) {
                        TreeNode *tempRoot = deque.front();
                        tempRoot->left = new TreeNode(tempVal);
                        deque.push_back(tempRoot->left);
                    }
                }

                if (i < arr.size()) {
                    int tempVal = arr[i++];
                    if (tempVal != -1) {
                        TreeNode *tempRoot = deque.front();
                        tempRoot->right = new TreeNode(tempVal);
                        deque.push_back(tempRoot->right);
                    }
                }

                deque.pop_front();
            }
        }

        return root;
    }

    void DLRTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        cout<<node->val<<"->";
        DLRTraversal(node->left);
        DLRTraversal(node->right);
    }

    void LDRTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        LDRTraversal(node->left);
        cout<<node->val<<"->";
        LDRTraversal(node->right);
    }

    void LRDTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        LRDTraversal(node->left);
        LRDTraversal(node->right);
        cout<<node->val<<"->";
    }

};

#endif /* Tools_hpp */
