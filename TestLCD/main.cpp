//
//  main.cpp
//  TestLCD
//
//  Created by zm on 2021/3/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <queue>
#include <list>
#include <functional>

#include "Tools.hpp"
#include "Sort.hpp"
#include "LeaZCY.hpp"
#include "LeaSTT.hpp"

using namespace std;

Tool tool;

#define string(x) #x

#pragma mark - 150
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        stack<int> stack;
//        for (int i = 0; i < tokens.size(); i++) {
//            if (stack.empty() == true) {
//                stack.push(stoi(tokens[i]));
//            }
//            else {
//                string op = tokens[i];
//                if (op == "+" || op == "-" || op == "*" || op == "/") {
//                    int val2 = stack.top();  stack.pop();
//                    int val1 = stack.top();  stack.pop();
//
//                    if (op == "+") {
//                        stack.push((val1 + val2));
//                    }
//
//                    if (op == "*") {
//                        stack.push((val1 * val2));
//                    }
//
//                    if (op == "-") {
//                        stack.push((val1 - val2));
//                    }
//
//                    if (op == "/") {
//                        stack.push((val1 / val2));
//                    }
//                }
//                else {
//                    stack.push(stoi(op));
//                }
//            }
//        }
//        return stack.top();
//    }
//
//    void test() {
//        vector<string> tokens = {"4","13","5","/","+"};
//        int result = evalRPN(tokens);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 239
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        if (nums.size() < k) {
//            int num = *max_element(nums.begin(), nums.end());
//            return {num};
//        }
//        //O(n2) 循环查找
//        vector<int> result(nums.size() - k + 1);
//        int maxIndex = (int)(max_element(nums.begin(), nums.begin() + k) - nums.begin());
//
//        for (int i = 0; i <= nums.size() - k; i++) {
//            if (maxIndex >= i) {
//                if (nums[i + k - 1] > nums[maxIndex]) {
//                    maxIndex = i + k - 1;
//                }
//            }
//            else {
//                maxIndex = (int)(max_element(nums.begin() + i, nums.begin() + i + k) - nums.begin());
//            }
//            result[i] = nums[maxIndex];
//        }
//
//        return result;
//    }
//
//    //获取最大值index [s,e)
//    int getMaxIndex(vector<int>& nums, int s, int e) {
//        int maxIndex =s;
//        for (int i = s; i < e; i++) {
//            if (nums[i] > nums[maxIndex]) {
//                maxIndex = i;
//            }
//        }
//        return maxIndex;
//    }
//
//    vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
//
//        if (nums.size() <= k) {
//            return {*max_element(nums.begin(), nums.end())};
//        }
//
//        //单调队列
//        vector<int> result(nums.size() - k + 1);
//
//        deque<int> deque;
//        for (int i = 0; i < nums.size(); i++) {
//
//            dequeAddSomeone(deque, nums[i]);
//            if (i >= k - 1) {
//                //0 - k-1开始窗口满，开始写入
//                int frontVal = deque.front();
//                result[i - k + 1] = frontVal;
//
//                //窗口开始滑动，将要滑出的元素为i - k + 1
//                dequeRemoveSomeone(deque, nums[i - k + 1]);
//            }
//        }
//
//        return result;
//    }
//
//    void dequeRemoveSomeone(deque<int>& deque, int num) {
//        //移除的值==队列前段的值时才移除
//        if (deque.empty() == false && deque.front() == num) {
//            deque.pop_front();
//        }
//    }
//
//    void dequeAddSomeone(deque<int>& deque, int num) {
//        //添加的值大于back的值，把back弹出，知道back>=num
//        while (deque.empty() == false && deque.back() < num) {
//            deque.pop_back();
//        }
//        deque.push_back(num);
//    }
//
//    void test() {
//        vector<int> nums = {1,3,1,2,0,5};
//        vector<int> result = maxSlidingWindow2(nums, 3);
//        tool.printVector(result);
//    }
//};

#pragma mark - 347
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        //计数排序
//        unordered_map<int, int> map;
//        int maxCount = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            map[nums[i]]++;
//            maxCount = max(map[nums[i]], maxCount);
//        }
//
//        vector<vector<int>> arrCount;
//        arrCount.resize(maxCount + 1);
//        unordered_map<int, int>::iterator it = map.begin();
//        while (it != map.end()) {
//            arrCount[it->second].push_back(it->first);
//            it++;
//        }
//
//        vector<int> result;
//        int num = 0;
//        for (int i = (int)arrCount.size() - 1; i >= 0 && num < k; i--) {
//            vector<int>::iterator it = arrCount[i].begin();
//            while (it != arrCount[i].end() && num < k) {
//                result.push_back(*it);
//                it++;
//                num++;
//            }
//        }
//
//        return result;
//    }
//
//    vector<int> topKFrequent2(vector<int>& nums, int k) {
//        //单调队列
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); i++) {
//            map[nums[i]]++;
//        }
//
//        deque<vector<vector<int>>> deque;
//        unordered_map<int, int>::iterator it = map.begin();
//        while (it != map.end()) {
////            dequeAddSomeone(deque, {{it->first}, {it->second}}, k);
//            stack<vector<vector<int>>> stack;
//            while (deque.empty() == false && deque.back()[1][0] < it->second) {//把小于当前值的都弹出，用stack存储
//                stack.push(deque.back());
//                deque.pop_back();
//            }
//
//            deque.push_back({{it->first}, {it->second}});
//
//            while (stack.empty() == false && deque.size() < k) {//把stack存储的数据移动到deque中
//                deque.push_back(stack.top());
//                stack.pop();
//            }
//
//
//            it++;
//        }
//        vector<int> result;
//        int num = 0;
//        while (num < k && deque.empty() == false) {
//            result.push_back(deque.front()[0][0]);
//            num++;
//            deque.pop_front();
//        }
//
//        return result;
//    }
//
//    // 小顶堆
//    class mycomparison {
//    public:
//        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
//            return lhs.second > rhs.second;
//        }
//    };
//
//    vector<int> topKFrequent3(vector<int>& nums, int k) {
//        //优先队列
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); i++) {
//            map[nums[i]]++;
//        }
//
//        // 对频率排序
//        // 定义一个小顶堆，大小为k
//        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
//
//        // 用固定大小为k的小顶堆，扫面所有频率的数值
//        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
//            pri_que.push(*it);
//            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
//                pri_que.pop();
//            }
//        }
//
//        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
//        vector<int> result(k);
//        for (int i = k - 1; i >= 0; i--) {
//            result[i] = pri_que.top().first;
//            pri_que.pop();
//        }
//        return result;
//
//    }
//
//    void test() {
//        vector<int> nums = {1,1,1,2,2,3,4,4,4};
//        vector<int> result = topKFrequent3(nums, 2);
//        tool.printVector(result);
//    }
//};

#pragma mark - 144
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//
//        //递归
//        vector<int> result;
//
//        DLRTraversal(root, result);
//
//        return result;
//    }
//
//    void DLRTraversal(TreeNode *node, vector<int>& arr) {
//        if (node == nullptr) {
//            return;
//        }
//        arr.push_back(node->val);
//
//        DLRTraversal(node->left, arr);
//        DLRTraversal(node->right, arr);
//    }
//
//    vector<int> preorderTraversal2(TreeNode* root) {
//
//        //非递归 stack
//        vector<int> result;
//        stack<TreeNode *> stack;
//        stack.push(root);
//        while (stack.empty() == false) {
//            TreeNode *node = stack.top();
//            stack.pop();
//            if (node != nullptr) {
//                result.push_back(node->val);
//                stack.push(node->right);
//                stack.push(node->left);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//
//    }
//};

#pragma mark - 94
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//
//        //递归
//        vector<int> result;
//
//        LDRTraversal(root, result);
//
//        return result;
//    }
//
//    void LDRTraversal(TreeNode* node, vector<int>& arr) {
//        if (node == nullptr) {
//            return;
//        }
//
//        LDRTraversal(node->left, arr);
//        arr.push_back(node->val);
//        LDRTraversal(node->right, arr);
//    }
//
//    vector<int> inorderTraversal2(TreeNode* root) {
//        //非递归 stack
//        vector<int> result;
//        stack<TreeNode *> stack;
//        TreeNode *node = root;
//
//        while (stack.empty() == false || node != nullptr) {
//
//            while (node != nullptr) {
//                stack.push(node);
//                node = node->left;
//            }
//
//            TreeNode *temp = stack.top();
//            stack.pop();
//            result.push_back(temp->val);
//            node = temp->right;
//
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {1,-1,2,3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        inorderTraversal2(root);
//    }
//
//};

#pragma mark - 145
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root) {
//        //递归
//        vector<int> result;
//
//        LRDTraversal(root, result);
//
//        return result;
//    }
//
//    void LRDTraversal(TreeNode* node, vector<int>& arr) {
//        if (node == nullptr) {
//            return;
//        }
//
//        LRDTraversal(node->left, arr);
//        LRDTraversal(node->right, arr);
//        arr.push_back(node->val);
//    }
//
//    vector<int> postorderTraversal2(TreeNode* root) {
//        //非递归 stack 前序中左右，变为中右左前序，然后整体反转为左右中
//        vector<int> result;
//        stack<TreeNode*> stack;
//        stack.push(root);
//
//        while (stack.empty() == false) {
//            TreeNode *node = stack.top();
//            stack.pop();
//            if (node != nullptr) {
//                result.push_back(node->val);
//                stack.push(node->left);
//                stack.push(node->right);
//            }
//        }
//
//        reverse(result.begin(), result.end());
//
//        return result;
//    }
//
//    vector<int> postorderTraversal3(TreeNode* root) {
//        //非递归 标记set
//        unordered_set<TreeNode*> set;
//
//        vector<int> result;
//
//        stack<TreeNode*> stack;
//
//        stack.push(root);
//
//        while (stack.empty() == false) {
//            TreeNode *node = stack.top();
//            if (node != nullptr) {
//                if ( (set.find(node->left) != set.end() && set.find(node->right) != set.end()) ||
//                    (node->left == nullptr && node->right == nullptr)) {
//                    result.push_back(node->val);
//                    set.insert(node);
//                    stack.pop();
//                }
//                else {
//                    stack.push(node->right);
//                    stack.push(node->left);
//                }
//            }
//        }
//
//        return result;
//    }
//
//    vector<int> postorderTraversal4(TreeNode* root) {
//        //非递归 标记NULL
//        vector<int> result;
//
//        stack<TreeNode*> stack;
//
//        if (root != nullptr) {
//            stack.push(root);
//        }
//
//        while (stack.empty() == false) {
//            TreeNode *node = stack.top();
//
//            if (node != NULL) {
//
//                stack.push(NULL);
//
//                if (node->right != nullptr) {
//                    stack.push(node->right);
//                }
//
//                if (node->left != nullptr) {
//                    stack.push(node->left);
//                }
//            }
//            else {
//                stack.pop();
//                TreeNode *temp = stack.top();
//                stack.pop();
//                result.push_back(temp->val);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {3,1,2};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<int> result = postorderTraversal4(root);
//        tool.printVector(result);
//    }
//};

#pragma mark - 102
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        //队列
//        vector<vector<int>> result;
//
//        deque<TreeNode*> deque;
//        if (root != nullptr) {
//            deque.push_back(root);
//            deque.push_back(NULL);
//        }
//        while (deque.empty() == false && deque.front() != NULL) {
//            vector<int> temp;
//            while (deque.front() != NULL) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//                temp.push_back(node->val);
//                if (node->left != nullptr) {
//                    deque.push_back(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(node->right);
//                }
//            }
//            result.push_back(temp);
//            deque.pop_front();
//            deque.push_back(NULL);
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {3,1,2};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<vector<int>> result = levelOrder(root);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 107
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        //队列 反转普通层先
//        vector<vector<int>> result;
//        deque<TreeNode*> deque;
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.empty() == false) {
//            int size = (int)deque.size();
//            vector<int> temp;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//                temp.push_back(node->val);
//                if (node->left != nullptr) {
//                    deque.push_back(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(node->right);
//                }
//            }
//
//            result.push_back(temp);
//        }
//
//        reverse(result.begin(), result.end());
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {3,1,2};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<vector<int>> result = levelOrderBottom(root);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 199
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<int> rightSideView(TreeNode* root) {
//        // 队列 层先遍历输出每层的最后一个节点
//        vector<int> result;
//        deque<TreeNode*> deque;
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.empty() == false) {
//            int size = (int)deque.size();
//
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//
//                if (node->left != nullptr) {
//                    deque.push_back(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(node->right);
//                }
//
//                if (i == size - 1) {//最后一个节点
//                    result.push_back(node->val);
//                }
//            }
//        }
//
//        return result;
//    }
//
//    vector<int> rightSideView2(TreeNode* root) {
//        //DRL 先右续，记录每层第一个节点
//
//        vector<int> result;
//
//        stack<TreeNode*> stackNode;
//        stack<int> stackDepth;
//
//        if (root != nullptr) {
//            stackNode.push(root);
//            stackDepth.push(0);
//        }
//
//        while (stackNode.empty() == false) {
//            TreeNode *node = stackNode.top();
//            stackNode.pop();
//
//            int depth = stackDepth.top();
//            stackDepth.pop();
//
//            if (result.size() <= depth) {
//                result.push_back(node->val);
//            }
//
//            if (node->left) {
//                stackNode.push(node->left);
//                stackDepth.push(depth + 1);
//            }
//
//            if (node->right) {
//                stackNode.push(node->right);
//                stackDepth.push(depth + 1);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,4};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<int> result = rightSideView2(root);
//        tool.printVector(result);
//    }
//};

#pragma mark - 637
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    vector<double> averageOfLevels(TreeNode* root) {
//        //层先遍历 每层求平均值
//        vector<double> result;
//
//        deque<TreeNode*> deque;
//
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.empty() == false) {
//
//            int size = (int)deque.size();
//
//            double sum = 0;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//
//                sum += (double)node->val;
//
//                if (node->left != nullptr) {
//                    deque.push_back(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(node->right);
//                }
//            }
//
//            result.push_back(sum / (double)size);
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,4};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<double> result = averageOfLevels(root);
//        for (int i = 0; i < result.size(); i++) {
//            cout<<result[i]<<",";
//        }
//    }
//};

#pragma mark - 429
///*
// Definition for a Node.
// */
//class Node {
//public:
//    int val;
//    vector<Node*> children;
//
//    Node() {}
//
//    Node(int _val) {
//        val = _val;
//    }
//
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//};
//
//class Solution {
//public:
//    vector<vector<int>> levelOrder(Node* root) {
//        //队列 层先
//        vector<vector<int>> result;
//
//        deque<Node*> deque;
//
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.empty() == false) {
//            int size = (int)deque.size();
//
//            vector<int> levelVec;
//            for (int i = 0; i < size; i++) {
//                Node *node = deque.front();
//                deque.pop_front();
//                levelVec.push_back(node->val);
//
//                for (int j = 0; j < node->children.size(); j++) {
//                    if (node->children[j] != nullptr) {
//                        deque.push_back(node->children[j]);
//                    }
//                }
//            }
//            result.push_back(levelVec);
//        }
//
//        return result;
//    }
//
//    void test() {
//
//    }
//
//};

#pragma mark - 589
// Definition for a Node.
//class Node {
//public:
//    int val;
//    vector<Node*> children;
//
//    Node() {}
//
//    Node(int _val) {
//        val = _val;
//    }
//
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//};
//
//
//class Solution {
//public:
//    vector<int> preorder(Node* root) {
//        //递归
//        vector<int> result;
//
//        DLRTraversal(root, result);
//
//        return result;
//    }
//
//    void DLRTraversal(Node *root, vector<int>& arr) {
//        if (root == nullptr) {
//            return;
//        }
//
//        arr.push_back(root->val);
//        for (int i = 0; i < root->children.size(); i++) {
//            DLRTraversal(root->children[i], arr);
//        }
//    }
//
//    vector<int> preorder2(Node* root) {
//        //迭代 stack
//        vector<int> result;
//
//        stack<Node*> stack;
//
//        if (root != nullptr) {
//            stack.push(root);
//        }
//
//        while (stack.empty() == false) {
//            Node *node = stack.top();
//            stack.pop();
//
//            result.push_back(node->val);
//
//            int childrenCount = (int)node->children.size();
//            for (int i = childrenCount - 1; i >= 0; i--) {
//                if (node->children[i] != nullptr) {
//                    stack.push(node->children[i]);
//                }
//            }
//        }
//
//        return result;
//    }
//};

#pragma mark - 226
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    TreeNode* invertTree(TreeNode* root) {
//        //层先遍历时 翻转
//        deque<TreeNode*> deque;
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.empty() == false) {
//            int size = (int)deque.size();
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//
//                TreeNode *temp = node->left;
//                node->left = node->right;
//                node->right = temp;
//
//                if (node->left != nullptr) {
//                    deque.push_back(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(node->right);
//                }
//            }
//        }
//
//        return root;
//    }
//
//    TreeNode* invertTree2(TreeNode* root) {
//        //DLR
//        stack<TreeNode*> stack;
//        if (root != nullptr) {
//            stack.push(root);
//        }
//
//        while (stack.empty() == false) {
//            TreeNode *node = stack.top();
//            stack.pop();
//
//            TreeNode *temp = node->left;
//            node->left = node->right;
//            node->right = temp;
//
//            if (node->left != nullptr) {
//                stack.push(node->left);
//            }
//
//            if (node->right != nullptr) {
//                stack.push(node->right);
//            }
//        }
//
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,4};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        TreeNode *node = invertTree(root);
//        tool.printBT(node);
//    }
//};

#pragma mark - 590

// Definition for a Node.
//class Node {
//public:
//    int val;
//    vector<Node*> children;
//
//    Node() {}
//
//    Node(int _val) {
//        val = _val;
//    }
//
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//};
//
//
//class Solution {
//public:
//    vector<int> postorder(Node* root) {
//        //DRL 翻转
//        vector<int> result;
//
//        stack<Node*> stack;
//
//        if (root != nullptr) {
//            stack.push(root);
//        }
//
//        while (stack.empty() == false) {
//            Node *node = stack.top();
//            stack.pop();
//            result.push_back(node->val);
//            int count = (int)node->children.size();
//            for (int i = 0; i < count; i++) {
//                if (node->children[i] != nullptr) {
//                    stack.push(node->children[i]);
//                }
//            }
//        }
//
//        reverse(result.begin(), result.end());
//        return result;
//    }
//
//    void test() {
//
//    }
//};

#pragma mark - 515
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        //层先 找最大值
        vector<int> result;

        deque<TreeNode*> deque;

        if (root != nullptr) {
            deque.push_back(root);
        }

        while (deque.empty() == false) {
            int size = (int)deque.size();

            int max = deque.front()->val;
            for (int i = 0; i < size; i++) {
                TreeNode *node = deque.front();
                deque.pop_front();

                if (max < node->val) {
                    max = node->val;
                }

                if (node->left != nullptr) {
                    deque.push_back(node->left);
                }

                if (node->right != nullptr) {
                    deque.push_back(node->right);
                }
            }

            result.push_back(max);
        }

        return result;
    }

    vector<int> largestValues2(TreeNode* root) {
        //前序 递归 记层

        vector<int> result;

        DLRTraversal(root, 0, result);

        return result;
    }

    void DLRTraversal(TreeNode* node, int level, vector<int>& arr) {
        if (node == nullptr) {
            return;
        }

        if (level >= arr.size()) {
            arr.push_back(node->val);
        }
        else {
            arr[level] = max(arr[level], node->val);
        }

        DLRTraversal(node->left, level + 1, arr);
        DLRTraversal(node->right, level + 1, arr);

    }

    vector<int> largestValues3(TreeNode* root) {
        //LDR 迭代 记层 未完成
        vector<int> result;

        unordered_map<int, int> map;

        stack<TreeNode*> stackNode;
        stack<int> stackDepth;

        TreeNode* curr = root;

        int currLevel = -1;

        while (stackNode.empty() == false || curr != nullptr) {

            while (curr != nullptr) {
                stackNode.push(curr);
                stackDepth.push(currLevel + 1);
                curr = curr->left;
            }

            TreeNode *node = stackNode.top();
            stackNode.pop();

            int depth = stackDepth.top();
            stackDepth.pop();

            if (map.count(depth) != 0) {
                map[depth] = node->val;
            }
            else {
                map[depth] = max(map[depth], node->val);
            }

            currLevel = depth;

            curr = node->right;
        }

        return result;
    }

    void test() {
        vector<int> arr = {1,3,2,5,3,-1,9};
        TreeNode *root = tool.createBT(arr);
        tool.printBT(root);
        vector<int> result = largestValues3(root);
        tool.printVector(result);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...

//    int i = -8;
//    i = i >> 5;
//    cout<<i<<endl;

    Solution solution;
    solution.test();

//    Sort sort;
//    sort.test();

//    LeaZcy zcy;
//    zcy.test();

//    LeaStt stt;
//    stt.test();

    return 0;
}
