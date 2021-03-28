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

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
            for (int j = 0; j < matrix[i].size(); j++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
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

};

#endif /* Tools_hpp */
