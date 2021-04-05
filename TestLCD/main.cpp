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
#include <utility>

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
//class Solution {
//public:
//    vector<int> largestValues(TreeNode* root) {
//        //层先 找最大值
//        vector<int> result;
//
//        deque<TreeNode*> deque;
//
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.empty() == false) {
//            int size = (int)deque.size();
//
//            int max = deque.front()->val;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//
//                if (max < node->val) {
//                    max = node->val;
//                }
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
//            result.push_back(max);
//        }
//
//        return result;
//    }
//
//    vector<int> largestValues2(TreeNode* root) {
//        //前序 递归 记层
//
//        vector<int> result;
//
//        DLRTraversal(root, 0, result);
//
//        return result;
//    }
//
//    void DLRTraversal(TreeNode* node, int level, vector<int>& arr) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (level >= arr.size()) {
//            arr.push_back(node->val);
//        }
//        else {
//            arr[level] = max(arr[level], node->val);
//        }
//
//        DLRTraversal(node->left, level + 1, arr);
//        DLRTraversal(node->right, level + 1, arr);
//
//    }
//
//    vector<int> largestValues3(TreeNode* root) {
//        //LDR 迭代 记层 未完成
//        vector<int> result;
//
//        unordered_map<int, int> map;
//
//        stack<TreeNode*> stackNode;
//        stack<int> stackDepth;
//
//        TreeNode* curr = root;
//
//        int currLevel = -1;
//
//        while (stackNode.empty() == false || curr != nullptr) {
//
//            while (curr != nullptr) {
//                stackNode.push(curr);
//                stackDepth.push(currLevel + 1);
//                curr = curr->left;
//            }
//
//            TreeNode *node = stackNode.top();
//            stackNode.pop();
//
//            int depth = stackDepth.top();
//            stackDepth.pop();
//
//            if (map.count(depth) != 0) {
//                map[depth] = node->val;
//            }
//            else {
//                map[depth] = max(map[depth], node->val);
//            }
//
//            currLevel = depth;
//
//            curr = node->right;
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {1,3,2,5,3,-1,9};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<int> result = largestValues3(root);
//        tool.printVector(result);
//    }
//};

#pragma mark - 101
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
//    bool isSymmetric(TreeNode* root) {
//        //层先 头尾遍历
//        deque<TreeNode*> deque;
//
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.empty() == false) {
//            int size = (int)deque.size();
//            if (size != 1 && size % 2 != 0) {
//                return false;
//            }
//            vector<TreeNode*> levelVec;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//
//                if (node->left != nullptr) {
//                    deque.push_back(node->left);
//                }
//                levelVec.push_back(node->left);
//
//                if (node->right != nullptr) {
//                    deque.push_back(node->right);
//                }
//                levelVec.push_back(node->right);
//            }
//
//            int l = 0, r = (int)levelVec.size() - 1;
//            while (l < r) {
//                if (levelVec[l] != nullptr && levelVec[r] != nullptr) {
//                    if (levelVec[l]->val != levelVec[r]->val) {
//                        return false;
//                    }
//                }
//                else if (levelVec[l] != levelVec[r]) {
//                    return false;
//                }
//                l++;
//                r--;
//            }
//        }
//
//        return true;
//    }
//
//    bool isSymmetric2(TreeNode* root) {
//        //队列
//        deque<TreeNode*> deque;
//
//        if (root != nullptr) {
//            deque.push_back(root->left);
//            deque.push_back(root->right);
//        }
//
//        while (deque.empty() == false) {
//
//            TreeNode *leftNode = deque.front();
//            deque.pop_front();
//
//
//            TreeNode *rightNode = deque.front();
//            deque.pop_front();
//
//            if (leftNode == nullptr && rightNode == nullptr) {
//                continue;
//            }
//
//            if (leftNode != nullptr && rightNode != nullptr) {
//                if (leftNode->val != rightNode->val) {
//                    return false;
//                }
//            }
//            else if (leftNode != rightNode) {
//                return false;
//            }
//
//            deque.push_back(leftNode->left);
//            deque.push_back(rightNode->right);
//            deque.push_back(rightNode->left);
//            deque.push_back(leftNode->right);
//
//        }
//
//        return true;
//    }
//
//    bool isSymmetric3(TreeNode* root) {
//        //递归
//
//        if (root == nullptr) {
//            return true;
//        }
//
//        return isLeftSameRight(root->left, root->right);
//    }
//
//    bool isLeftSameRight(TreeNode *left, TreeNode *right) {
//        if (left != nullptr && right != nullptr) {
//            if (left->val != right->val) {
//                return false;
//            }
//        }
//        else if (left != right) {
//            return false;
//        }
//        else {
//            return true;
//        }
//
//        bool leftTree = isLeftSameRight(left->left, right->right);
//        bool rightTree = isLeftSameRight(left->right, right->left);
//
//        return leftTree && rightTree;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,2,-1,4,4,3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        bool result = isSymmetric3(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 104
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
//    int maxDepth(TreeNode* root) {
//        //层先
//        int depth = 0;
//        queue<TreeNode*> queue;
//        if (root != nullptr) {
//            queue.push(root);
//        }
//
//        while (queue.empty() == false) {
//            int size = (int)queue.size();
//            depth++;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = queue.front();
//                queue.pop();
//
//                if (node->left != nullptr) {
//                    queue.push(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    queue.push(node->right);
//                }
//            }
//        }
//
//        return depth;
//    }
//
//    int maxDepth2(TreeNode* root) {
//        //递归
//        return DLRTraversal(root, 1);
//    }
//
//    int DLRTraversal(TreeNode *node, int depth) {
//        if (node == nullptr) {
//            return depth - 1;
//        }
//
//        return max(DLRTraversal(node->left, depth + 1), DLRTraversal(node->right, depth + 1));
//    }
//
//    void test() {
//        vector<int> arr = {1,2,2,-1,4,4,3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        int result = maxDepth2(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 559

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
//    int maxDepth(Node* root) {
//        //层先
//        int depth = 0;
//        queue<Node*> que;
//        if (root != nullptr) {
//            que.push(root);
//        }
//
//        while (que.empty() == false) {
//            depth++;
//
//            int size = (int)que.size();
//
//            for (int i = 0; i < size; i++) {
//                Node *node = que.front();
//                que.pop();
//                for (int j = 0; j < node->children.size(); j++) {
//                    if (node->children[j] != nullptr) {
//                        que.push(node->children[j]);
//                    }
//                }
//            }
//        }
//
//        return depth;
//    }
//
//    int maxDepth2(Node* root) {
//        //递归
//
//        return DLRTraversal(root);
//    }
//
//    int DLRTraversal(Node *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//
//        int maxDepth = 0;
//        for (int i = 0; i < node->children.size(); i++) {
//            maxDepth = max(maxDepth, DLRTraversal(node->children[i]));
//        }
//        return maxDepth + 1;
//    }
//
//
//    void test() {
//
//    }
//};

#pragma mark - 111
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
//    int minDepth(TreeNode* root) {
//        //层先
//        int depth = 0;
//
//        queue<TreeNode*> que;
//        if (root != nullptr) {
//            que.push(root);
//        }
//
//        while (que.empty() == false) {
//            int size = (int)que.size();
//            depth++;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = que.front();
//                que.pop();
//
//                if (node->left == nullptr && node->right == nullptr) {
//                    return depth;
//                }
//
//                if (node->left != nullptr) {
//                    que.push(node->left);
//                }
//
//
//                if (node->right != nullptr) {
//                    que.push(node->right);
//                }
//            }
//        }
//
//        return depth;
//    }
//
//    int minDepth2(TreeNode* root) {
//        //递归
//
//        if (root == nullptr) {
//            return 0;
//        }
//        return DLRTraversal(root, 1);
//    }
//
//    int DLRTraversal(TreeNode *node, int depth) {
//        if (node == nullptr) {
//            return INT_MAX;
//        }
//
//        if (node->left == nullptr && node->right == nullptr) {
//            return depth;
//        }
//
//        return  min(DLRTraversal(node->left, depth + 1), DLRTraversal(node->right, depth + 1));
//    }
//
//    void test() {
//        vector<int> arr = {2,-1,3,-1,4,-1,5,-1,6};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        int result = minDepth2(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 222
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
//    int countNodes(TreeNode* root) {
//        //层先
//        int count = 0;
//        queue<TreeNode*> que;
//        if (root != nullptr) {
//            que.push(root);
//        }
//
//        while (que.empty() == false) {
//            int size = (int)que.size();
//            count += size;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = que.front();
//                que.pop();
//
//                if (node->left != nullptr) {
//                    que.push(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    que.push(node->right);
//                }
//            }
//        }
//
//        return count;
//    }
//
//    int countNodes2(TreeNode* root) {
//        //递归
//        int count = 0;
//
//        DLRTraversal(root, count);
//
//        return count;
//    }
//
//    void DLRTraversal(TreeNode* node, int& count) {
//        if (node == nullptr) {
//            return;
//        }
//        count++;
//
//        DLRTraversal(node->left, count);
//        DLRTraversal(node->right, count);
//    }
//
//    void test() {
//        vector<int> arr = {2,-1,3,-1,4,-1,5,-1,6};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        int result = countNodes2(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 110
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
//    bool isBalanced(TreeNode* root) {
//        //层先，最小叶节点和最大叶节点差<2,未完成
//
//        queue<TreeNode*> que;
//        if (root != nullptr) {
//            que.push(root);
//        }
//
//        int minDepth = 0, maxDepth = 0;
//        bool isGetMinDepth = false;
//        while (que.empty() == false) {
//
//            int size = (int)que.size();
//
//            if (isGetMinDepth == false) {
//                minDepth++;
//            }
//            maxDepth++;
//
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = que.front();
//                que.pop();
//
//                if (isGetMinDepth == false) {
//                    if (node->left == nullptr || node->right == nullptr) {
//                        isGetMinDepth = true;
//                    }
//                }
//
//                if (node->left != nullptr) {
//                    que.push(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    que.push(node->right);
//                }
//            }
//
//            if (maxDepth - minDepth > 1) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    bool isBalanced2(TreeNode* root) {
//        //递归
//
//        int height = treeHeight(root);
//
//        if (height != -1) {
//            return true;
//        }
//
//        return false;
//    }
//
//    int treeHeight(TreeNode* node) {
//        if (node == nullptr) {
//            return 0;
//        }
//
//        int leftHeight = treeHeight(node->left);
//        int rightHeight = treeHeight(node->right);
//
//        if (abs(leftHeight - rightHeight) > 1) {
//            return -1;
//        }
//
//        if (leftHeight == -1 || rightHeight == -1) {
//            return -1;
//        }
//
//        return max(leftHeight, rightHeight) + 1;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,2,3,3,-1,-1,4,4};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        bool result = isBalanced2(root);
//        cout<<result<<endl;
//    }
//};

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
//    vector<string> binaryTreePaths(TreeNode* root) {
//        //递归 前序
//
//        vector<string> paths;
//
//        DLRTraversal(root, paths, "");
//
//        return paths;
//    }
//
//    void DLRTraversal(TreeNode* node, vector<string>& paths, string path) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (node->left == nullptr && node->right == nullptr) {
//            path += to_string(node->val);
//            paths.push_back(path);
//        }
//        else {
//            path += (to_string(node->val) + "->");
//        }
//
//
//        DLRTraversal(node->left, paths, path);
//        DLRTraversal(node->right, paths, path);
//    }
//
//    vector<string> binaryTreePaths2(TreeNode* root) {
//        //迭代
//        vector<string> result;
//
//        stack<TreeNode*> stackNode;
//        stack<string> stackPath;
//
//        if (root != nullptr) {
//            stackNode.push(root);
//            stackPath.push(to_string(root->val));
//        }
//
//        string path;
//        while (stackNode.empty() == false) {
//            TreeNode *node = stackNode.top();
//            stackNode.pop();
//
//            string path = stackPath.top();
//            stackPath.pop();
//
//
//            if (node->left == nullptr && node->right == nullptr) {
//                result.push_back(path);
//            }
//
//            if (node->left != nullptr) {
//                stackNode.push(node->left);
//                string leftPath = path + "->" + to_string(node->left->val);
//                stackPath.push(leftPath);
//            }
//
//            if (node->right != nullptr) {
//                stackNode.push(node->right);
//                string rightPath = path + "->" + to_string(node->right->val);
//                stackPath.push(rightPath);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,-1,5};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<string> result = binaryTreePaths2(root);
//
//        for (int i = 0; i < result.size(); i++) {
//            cout<<result[i]<<endl;
//        }
//    }
//};

#pragma mark - 100
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
//    bool isSameTree(TreeNode* p, TreeNode* q) {
//        //递归
//
//        if (p == nullptr && q == nullptr) {
//            return true;
//        }
//        else if (p != nullptr && q != nullptr) {
//            if (p->val != q->val) {
//                return false;
//            }
//        }
//        else {
//            return false;
//        }
//
//        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//    }
//
//    bool isSameTree2(TreeNode* p, TreeNode* q) {
//        //迭代
//        queue<TreeNode*> pQue;
//        queue<TreeNode*> qQue;
//
//        pQue.push(p);
//        qQue.push(q);
//
//
//        while (pQue.empty() == false || qQue.empty() == false) {
//            TreeNode *pNode = pQue.front();
//            pQue.pop();
//
//            TreeNode *qNode = qQue.front();
//            qQue.pop();
//
//            if (pNode == nullptr && qNode == nullptr) {
//                continue;
//            }
//            else if (pNode != nullptr && qNode == nullptr) {
//                return false;
//            }
//            else if (pNode == nullptr && qNode != nullptr) {
//                return false;
//            }
//            else if (pNode->val != qNode->val) {
//                return false;
//            }
//
//            pQue.push(pNode->left);
//            pQue.push(pNode->right);
//
//            qQue.push(qNode->left);
//            qQue.push(qNode->right);
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> arr1 = {};
//        vector<int> arr2 = {0};
//        TreeNode *root1 = tool.createBT(arr1);
//        TreeNode *root2 = tool.createBT(arr2);
////        tool.printBT(root1);
//        bool result = isSameTree2(root1, root2);
//        cout<<result<<endl;
//    }
//};

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
//    bool isSubtree(TreeNode* s, TreeNode* t) {
//
//        if (s == nullptr && t != nullptr) {
//            return false;
//        }
//        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
//    }
//
//    bool isSameTree(TreeNode* p, TreeNode* q) {
//        //递归
//
//        if (p == nullptr && q == nullptr) {
//            return true;
//        }
//        else if (p != nullptr && q != nullptr) {
//            if (p->val != q->val) {
//                return false;
//            }
//        }
//        else {
//            return false;
//        }
//
//        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//    }
//
//    void test() {
//        vector<int> arr1 = {3,4,5,1,2};
//        vector<int> arr2 = {4,1,3};
//        TreeNode *root1 = tool.createBT(arr1);
//        TreeNode *root2 = tool.createBT(arr2);
//        //        tool.printBT(root1);
//        bool result = isSubtree(root1, root2);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 404
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    int sumOfLeftLeaves(TreeNode* root) {
//        //递归 dlr
//        int count = 0;
//        DLRTraversal(root, count, false);
//        return count;
//    }
//
//    void DLRTraversal(TreeNode* node, int& count, bool isLeft) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (node->left == nullptr && node->right == nullptr) {
//            if (isLeft) {
//                count += node->val;
//            }
//        }
//
//        DLRTraversal(node->left, count, true);
//        DLRTraversal(node->right, count, false);
//    }
//
//    int sumOfLeftLeaves2(TreeNode* root) {
//        //层先
//        int count = 0;
//
//        queue<TreeNode*> que;
//
//        if (root != nullptr) {
//            que.push(root);
//        }
//
//        while (que.empty() == false) {
//            int size = (int)que.size();
//
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = que.front();
//                que.pop();
//
//
//                if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
//                    count += node->left->val;
//                }
//
//                if (node->left != nullptr) {
//                    que.push(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    que.push(node->right);
//                }
//            }
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<int> arr = {3,9,20,-1,-1,15,7};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        int count = sumOfLeftLeaves2(root);
//        cout<<count<<endl;
//    }
//};

#pragma mark - 513
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
//    int findBottomLeftValue(TreeNode* root) {
//        //层先
//
//        int value = 0;
//
//        queue<TreeNode*> que;
//
//        if (root != nullptr) {
//            que.push(root);
//        }
//
//        while (que.empty() == false) {
//            int size = (int)que.size();
//
//            value = que.front()->val;
//
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = que.front();
//                que.pop();
//
//                if (node->left != nullptr) {
//                    que.push(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    que.push(node->right);
//                }
//            }
//        }
//
//        return value;
//    }
//
//    int findBottomLeftValue2(TreeNode* root) {
//        //递归
//
//        int value = 0;
//        int maxDepth = 0;
//
//        DLRTraversal(root, value, 1, maxDepth);
//
//        return value;
//    }
//
//    void DLRTraversal(TreeNode* node, int& result, int depth, int& maxDepth) {
//        if (node == nullptr) {
//            return;
//        }
//        if (node != nullptr && node->left == nullptr && node->right == nullptr) {
//            if (maxDepth < depth) {
//                result = node->val;
//                maxDepth = depth;
//            }
//        }
//
//        DLRTraversal(node->left, result, depth + 1, maxDepth);
//        DLRTraversal(node->right, result, depth + 1, maxDepth);
//
//    }
//
//    void test() {
//        vector<int> arr = {3,9,20,-1,-1,-1,15,7};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        int count = findBottomLeftValue2(root);
//        cout<<count<<endl;
//    }
//};

#pragma mark - 112
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
//    bool hasPathSum(TreeNode* root, int targetSum) {
//
//        return DLRTraversal(root, 0, targetSum);
//    }
//
//    bool DLRTraversal(TreeNode *node, int count, int target) {
//        if (node == nullptr) {
//            return false;
//        }
//
//        count += node->val;
//
//        if (node->left == nullptr && node->right == nullptr) {
//            if (target == count) {
//                return true;
//            }
//            else {
//                return false;
//            }
//        }
//
//        return DLRTraversal(node->left, count, target) || DLRTraversal(node->right, count, target);
//    }
//
//    bool hasPathSum2(TreeNode* root, int targetSum) {
//        //迭代
//        typedef pair<TreeNode *, int> NodePair;
//        stack<NodePair> stack;
//        if (root != nullptr) {
//            stack.push(NodePair(root, root->val));
//        }
//
//        while (stack.empty() == false) {
//            NodePair pair = stack.top();
//            stack.pop();
//
//            TreeNode *node = pair.first;
//            int sum = pair.second;
//
//            if (node->left == nullptr && node->right == nullptr) {
//                if (sum == targetSum) {
//                    return true;
//                }
//            }
//
//            if (node->left != nullptr) {
//                stack.push(NodePair(node->left, sum + node->left->val));
//            }
//
//            if (node->right != nullptr) {
//                stack.push(NodePair(node->right, sum + node->right->val));
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        vector<int> arr = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        bool result = hasPathSum2(root, 22);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 113
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
//    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//        //递归
//
//        vector<vector<int>> result;
//
//        if (root == nullptr) {
//            return result;
//        }
//        vector<int> arrPath;
//        arrPath.push_back(root->val);
//        DLRTraversal(root, targetSum, root->val, arrPath, result);
//
//        return result;
//    }
//
//    void DLRTraversal(TreeNode *node, int targetSum, int count, vector<int> arrPath, vector<vector<int>>& result) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (node->left == nullptr && node->right == nullptr) {
//            if (count == targetSum) {
//                result.push_back(arrPath);
//            }
//            return;
//        }
//
//        if (node->left != nullptr) {
//            arrPath.push_back(node->left->val);
//            DLRTraversal(node->left, targetSum, count + node->left->val, arrPath, result);
//            arrPath.pop_back();
//        }
//
//        if (node->right != nullptr) {
//            arrPath.push_back(node->right->val);
//            DLRTraversal(node->right, targetSum, count + node->right->val, arrPath, result);
//            arrPath.pop_back();
//        }
//    }
//
//    void test() {
//        vector<int> arr = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        vector<vector<int>> result = pathSum(root, 22);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 106
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
//    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//
//        if (inorder.size() == 0 || postorder.size() == 0) {
//            return nullptr;
//        }
//
//        return buildTreeRoot(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
//    }
//
//    TreeNode *buildTreeRoot(vector<int>& inorder, int leftInorder, int rightInorder, vector<int>& postorder, int leftPostorder, int rightPostorder) {
//        if (leftPostorder > rightPostorder) {
//            return nullptr;
//        }
//        int lastPostorder = postorder[rightPostorder];
//
//        TreeNode *tempRoot = new TreeNode(lastPostorder);
//
//        if (leftPostorder == rightPostorder) {
//            return tempRoot;
//        }
//
//        int dev = 0;
//        for (int i = leftInorder; i <= rightInorder; i++) {
//            if (inorder[i] == lastPostorder) {
//                dev = i - leftInorder;
//                break;
//            }
//        }
//
//        tempRoot->left = buildTreeRoot(inorder, leftInorder, leftInorder + dev - 1, postorder, leftPostorder, leftPostorder + dev - 1);
//        tempRoot->right = buildTreeRoot(inorder, leftInorder + dev + 1, rightInorder, postorder, leftPostorder + dev, rightPostorder - 1);
//
//
//        return tempRoot;
//    }
//
//    void test() {
//        vector<int> inorder = {9,3,15,20,7};
//        vector<int> postorder = {9,15,7,20,3};
//        TreeNode *root = buildTree(inorder, postorder);
//        tool.printBT(root);
//    }
//};

#pragma mark - 105
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
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        return buildTreeTraversal(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
//    }
//
//    TreeNode *buildTreeTraversal(vector<int>& preorder, int leftPreorder, int rightPreorder, vector<int>& inorder, int leftInorder, int rightInorder) {
//        if (leftPreorder > rightPreorder) {
//            return nullptr;
//        }
//
//        int rootVal = preorder[leftPreorder];
//        TreeNode *root = new TreeNode(rootVal);
//
//        if (leftPreorder == rightPreorder) {
//            return root;
//        }
//
//        int dev = leftPreorder;
//        for (int i = leftInorder; i <= rightInorder; i++) {
//            if (inorder[i] ==  rootVal) {
//                dev = i - leftInorder;
//            }
//        }
//
//        root->left = buildTreeTraversal(preorder, leftPreorder + 1, leftPreorder + dev, inorder, leftInorder, leftInorder + dev - 1);
//        root->right = buildTreeTraversal(preorder, leftPreorder + dev + 1, rightPreorder, inorder, leftInorder + dev + 1, rightInorder);
//
//
//        return root;
//    }
//
//
//    void test() {
//        vector<int> arr1 = {3,9,20,15,7};
//        vector<int> arr2 = {9,3,15,20,7};
//
//        TreeNode *root = buildTree(arr1, arr2);
//        tool.printBT(root);
//    }
//};

#pragma mark - 654
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
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        //桶确定大小顺序
//        vector<int> arrBucket(1000, -1);
//        for (int i = 0; i < nums.size(); i++) {
//            arrBucket[nums[i]] = i;
//        }
//
//        return buildTree(arrBucket, (int)arrBucket.size() - 1, nums, 0, (int)nums.size() - 1);
//    }
//
//    TreeNode *buildTree(vector<int>& bucket, int bucketRight, vector<int>& nums, int left, int right) {
//        if (left > right) {
//            return nullptr;
//        }
//
//        while (bucket[bucketRight] == -1 && bucketRight >= 0) {
//            bucketRight--;
//        }
//
//        int rootIndex = 0;
//        for (int i = bucketRight; i >= 0; i--) {
//            if (bucket[i] != -1 && bucket[i] <= right && bucket[i] >= left) {
//                rootIndex = bucket[i];
//                break;
//            }
//        }
//
//
//        TreeNode *root = new TreeNode(nums[rootIndex]);
//        if (left == right) {
//            return root;
//        }
//
//        root->left = buildTree(bucket, bucketRight - 1, nums, left, rootIndex - 1);
//        root->right = buildTree(bucket, bucketRight - 1, nums, rootIndex + 1, right);
//
//        return root;
//    }
//
//    TreeNode* constructMaximumBinaryTree2(vector<int>& nums) {
//        //每次直接比较最大
//
//        return buileTree2(nums, 0, (int)nums.size() - 1);
//    }
//
//    TreeNode *buileTree2(vector<int>& nums, int left, int right) {
//        if (left > right) {
//            return nullptr;
//        }
//
//        int maxIndex = left;
//        for (int i = left; i <= right; i++) {
//            if (nums[i] > nums[maxIndex]) {
//                maxIndex = i;
//            }
//        }
//
//
//        TreeNode *root = new TreeNode(nums[maxIndex]);
//        if (left == right) {
//            return root;
//        }
//
//        root->left = buileTree2(nums, left, maxIndex - 1);
//        root->right = buileTree2(nums, maxIndex + 1, right);
//
//        return root;
//    }
//
//    void test() {
//        vector<int> nums = {3,2,1,6,0,5};
//        TreeNode *root = constructMaximumBinaryTree2(nums);
//        tool.printBT(root);
//    }
//};

#pragma mark - 617
//class Solution {
//public:
//    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//        //层先 同时遍历两棵树
//        if (root1 == nullptr && root2 == nullptr) return nullptr;
//        if (root2 == nullptr) return root1;
//        if (root1 == nullptr) return root2;
//
//        queue<TreeNode *> que1, que2;
//
//        que1.push(root1);
//        que2.push(root2);
//
//        while (que1.empty() == false || que2.empty() == false) {
//            int size = (int)que1.size();
//
//            for (int i = 0; i < size; i++) {
//
//                TreeNode * node1 = que1.front();
//                que1.pop();
//
//                TreeNode *node2 = que2.front();
//                que2.pop();
//
//                if (node2 != nullptr) {
//
//                    node1->val += node2->val;
//
//                    if (node2->left != nullptr) {
//                        if (node1->left == nullptr) {//对应2的1位置没有节点，把2的节点赋值给1,不加入遍历队列
//                            node1->left = node2->left;
//                        }
//                        else {
//                            que2.push(node2->left);
//                            que1.push(node1->left);
//                        }
//                    }
//
//                    if (node2->right != nullptr) {
//                        if (node1->right == nullptr) {//对应2的1位置没有节点，把2的节点赋值给1,不加入遍历队列
//                            node1->right = node2->right;
//                        }
//                        else {
//                            que2.push(node2->right);
//                            que1.push(node1->right);
//                        }
//                    }
//
//                }
//                else {//2节点是空，1节点不再遍历
//                }
//            }
//        }
//
//        return root1;
//    }
//
//    TreeNode* mergeTrees2(TreeNode* root1, TreeNode* root2) {
//        //DLR同时遍历
//        if (root1 == nullptr && root2 == nullptr) {
//            return nullptr;
//        }
//
//        if (root1 == nullptr) {
//            return root2;
//        }
//
//        if (root2 == nullptr) {
//            return root1;
//        }
//
//        root1->val += root2->val;
//
//        root1->left = mergeTrees(root1->left, root2->left);
//        root1->right = mergeTrees(root1->right, root2->right);
//
//        return root1;
//    }
//
//    void test() {
//
//        vector<int> arr1 = {1,3,2,5};
//        TreeNode *root1 = tool.createBT(arr1);
//        tool.printBT(root1);
//
//        vector<int> arr2 = {2,1,3,-1,4,-1,7};
//        TreeNode *root2 = tool.createBT(arr2);
//        tool.printBT(root2);
//
//        TreeNode *result = mergeTrees2(root1, root2);
//        tool.printBT(result);
//    }
//};

#pragma mark - 700
//class Solution {
//public:
//    TreeNode* searchBST2(TreeNode* root, int val) {
//        TreeNode *currNode = root;
//        while (currNode != nullptr && currNode->val != val) {
//            if (currNode->val > val) {
//                currNode = currNode->left;
//            }
//            else {
//                currNode = currNode->right;
//            }
//        }
//        return currNode;
//    }
//
//    TreeNode* searchBST(TreeNode* root, int val) {
//        //递归
//
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        if (root->val == val) {
//            return root;
//        }
//
//        if (root->val > val) {
//            return searchBST(root->left, val);
//        }
//        else {
//            return searchBST(root->right, val);
//        }
//    }
//
//    void test() {
//        vector<int> arr = {4,2,7,1,3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = searchBST2(root, 2);
//        tool.printBT(result);
//    }
//};

#pragma mark - 98
//class Solution {
//public:
//    TreeNode *lastNode;
//    bool isValidBST(TreeNode* root) {
//        //递归
//
//        return LDRTraversal(root);
//    }
//
//    bool LDRTraversal(TreeNode* node) {
//        if (node == nullptr) {
//            return true;
//        }
//
//        bool isLeftBST = LDRTraversal(node->left);
//
//        if ( lastNode == nullptr || (lastNode)->val < node->val) {
//            lastNode = node;
//        }
//        else {
//            return false;
//        }
//
//        bool isRightBST = LDRTraversal(node->right);
//
//        return isLeftBST && isRightBST;
//    }
//
//    bool isValidBST2(TreeNode* root) {
//        //迭代 stack
//        if (root == nullptr) {
//            return true;
//        }
//
//        stack<TreeNode *> stack;
//        TreeNode* node = root;
//
//        while (stack.empty() == false || node != nullptr) {
//
//            while (node != nullptr) {
//                stack.push(node);
//                node = node->left;
//            }
//
//            node = stack.top();
//            stack.pop();
//
////            cout<<node->val<<"->";
//            if (lastNode == nullptr || lastNode->val < node->val) {
//                lastNode = node;
//            }
//            else {
//                return false;
//            }
//
//            node = node->right;
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> arr = {1,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        bool result = isValidBST2(root);
//        cout<<endl<<result<<endl;
//    }
//};

#pragma mark - 530
//class Solution {
//public:
//    TreeNode *lastNode;
//    int getMinimumDifference(TreeNode* root) {
//        //递归 中序遍历 差
//        if (root == nullptr) {
//            return INT_MAX;
//        }
//
//        int minVal = getMinimumDifference(root->left);
//
//        if (minVal == 1) {
//            return 1;
//        }
//
//
//        if (lastNode != nullptr) {
//            minVal = min(minVal, root->val - lastNode->val);
//        }
//        lastNode = root;
//
//        if (minVal == 1) {
//            return 1;
//        }
//
//
//        minVal = min(minVal, getMinimumDifference(root->right));
//
//        return minVal;
//    }
//
//    int getMinimumDifference2(TreeNode* root) {
//        //最左 最右差
//
//        if (root == nullptr) {
//            return 0;
//        }
//
//        int minVal = 0, maxVal = 0;
//        TreeNode* node = root;
//        while (node != nullptr) {
//            minVal = node->val;
//            node = node->left;
//        }
//
//        node = root;
//        while (node != nullptr) {
//            maxVal = node->val;
//            node = node->right;
//        }
//
//        return maxVal - minVal;
//    }
//
//    void test() {
//        vector<int> arr = {543,384,652,-1,445,-1,699};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//        int result = getMinimumDifference(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 501
//class Solution {
//public:
//    int modeCount;
//    int currCount;
//    int currVal;
//    vector<int> findMode(TreeNode* root) {
//        //递归 中序
//        if (root == nullptr) {
//            return {};
//        }
//
//        currVal = root->val;
//        modeCount = 0;
//        currCount = 0;
//
//        vector<int> modeValVec;
//
//        traveral(root, modeValVec);
//
//        return modeValVec;
//    }
//
//    void traveral(TreeNode *node, vector<int>& modeValVec) {
//        if (node == nullptr) {
//            return;
//        }
//
//        traveral(node->left, modeValVec);
//
//        if (currVal == node->val) {
//            currCount++;
//        }
//        else {
//            currCount = 1;
//            currVal = node->val;
//        }
//
//        if (currCount > modeCount) {
//            modeCount = currCount;
//            modeValVec.clear();
//            modeValVec.push_back(currVal);
//        }
//        else if (currCount == modeCount) {
//            modeValVec.push_back(currVal);
//        }
//
//        traveral(node->right, modeValVec);
//    }
//
//    void test() {
//        vector<int> arr = {1,-1,2,2};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<int> result = findMode(root);
//        tool.printVector(result);
//    }
//};

#pragma mark - 236
//class Solution {
//public:
//    TreeNode *ancstor = nullptr;
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//
//        LRDTraversal(root, p, q);
//
//        return ancstor;
//    }
//
//    bool LRDTraversal(TreeNode *node, TreeNode* p, TreeNode *q) {
//        if (node == nullptr) {
//            return false;
//        }
//
//        if (ancstor != nullptr) {
//            return true;
//        }
//
//        bool left = LRDTraversal(node->left, p, q);
//
//        bool right = LRDTraversal(node->right, p, q);
//
//        if (left && right) {
//            if (ancstor == nullptr) {
//                ancstor = node;
//            }
//            return true;
//        }
//
//        if (node == p || node == q) {
//            if (left || right) {
//                ancstor = node;
//            }
//            return true;
//        }
//        else {
//            return left || right;
//        }
//
//    }
//    void test() {
//        vector<int> arr = {};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
////        TreeNode *result = lowestCommonAncestor(root, <#TreeNode *p#>, <#TreeNode *q#>)
//    }
//};

#pragma mark - 235
class Solution {
public:
    TreeNode *ancestor;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归
        
        LRDTraversal(root, p, q);
        return ancestor;
    }
    
    bool LRDTraversal(TreeNode *node, TreeNode* p, TreeNode *q) {
        if (node == nullptr) {
            return false;
        }
        
        if (ancestor != nullptr) {
            return true;
        }
        
        bool left = LRDTraversal(node->left, p, q);
        bool right = LRDTraversal(node->right, p, q);
        
                
        if (left && right) {
            if (ancestor == nullptr) {
                ancestor = node;
            }
            return true;
        }
        
        if (node == p || node == q) {
            if (left || right) {
                if (ancestor == nullptr) {
                    ancestor = node;
                }
            }
            return true;
        }
        
        return left || right;
    }
    
    void test() {
        vector<int> arr = {6,2,8,0,4,7,9,-1,-2,3,5};
        TreeNode *root = tool.createBT(arr);
        tool.printBT(root);
        
        int pVal = 3, qVal = 9;
        TreeNode *curr = root;
        TreeNode *p = nullptr, *q = nullptr;
        while (p == nullptr) {
            
            if (curr->val == pVal) {
                p = curr;
                break;
            }
            if (curr->val < pVal) {
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        
        curr = root;
        while (q == nullptr) {
            
            if (curr->val == qVal) {
                q = curr;
                break;
            }
            if (curr->val < qVal) {
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        
        TreeNode *node = lowestCommonAncestor(root, p, q);
        if (node != nullptr) {
            cout<<endl<<node->val<<endl;
        }
        else {
            cout<<endl<<"NULL"<<endl;
        }
        
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
