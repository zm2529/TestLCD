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
#include <numeric>

#include "Tools.hpp"
#include "Sort.hpp"
#include "LeaZCY.hpp"
#include "LeaSTT.hpp"

using namespace std;

Tool tool;

#define string(x) #x

#pragma mark - 669
//class Solution {
//public:
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        while (root != nullptr && (root->val > high || root->val < low)) {
//            if (root->val > high) {
//                root = root->left;
//                continue;
//            }
//
//            if (root->val < low) {
//                root = root->right;
//                continue;
//            }
//        }
//
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        root->left = trimBST(root->left, low, high);
//        root->right = trimBST(root->right, low, high);
//
//        return root;
//    }
//
//    void test() {
//        /**
//         [45,30,46,10,36,null,49,8,24,34,42,48,null,4,9,14,25,31,35,41,43,47,null,0,6,null,null,11,20,null,28,null,33,null,null,37,null,null,44,null,null,null,1,5,7,null,12,19,21,26,29,32,null,null,38,null,null,null,3,null,null,null,null,null,13,18,null,null,22,null,27,null,null,null,null,null,39,2,null,null,null,15,null,null,23,null,null,null,40,null,null,null,16,null,null,null,null,null,17]
//         32
//         44
//         */
//        //[3,0,4,null,2,null,null,1], low = 1, high = 3
////        vector<int> arr = {45,30,46,10,36,-1,49,8,24,34,42,48,-1,4,9,14,25,31,35,41,43,47,-1,0,6,-1,-1,11,20,-1,28,-1,33,-1,-1,37,-1,-1,44,-1,-1,-1,1,5,7,-1,12,19,21,26,29,32,-1,-1,38,-1,-1,-1,3,-1,-1,-1,-1,-1,13,18,-1,-1,22,-1,27,-1,-1,-1,-1,-1,39,2,-1,-1,-1,15,-1,-1,23,-1,-1,-1,40,-1,-1,-1,16,-1,-1,-1,-1,-1,17};
//        vector<int> arr = {3,0,4,-1,2,-1,-1,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = trimBST(root, 1, 3);
//        tool.printBT(result);
//    }
//};

#pragma mark - 108
//class Solution {
//public:
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        //递归
//
//        TreeNode *root = createBST(nums, 0, nums.size() - 1);
//
//        return root;
//    }
//
//    TreeNode *createBST(vector<int>& nums, int l, int r) {
//        if (l > r) {
//            return nullptr;
//        }
//
//        int mid = l + ((r - l) >> 1);
//
//        TreeNode *root = new TreeNode(nums[mid]);
//        root->left = createBST(nums, l, mid - 1);
//        root->right = createBST(nums, mid + 1, r);
//
//        return root;
//    }
//
//    TreeNode* sortedArrayToBST2(vector<int>& nums) {
//        //迭代
//
//        if (nums.size() == 0) {
//            return nullptr;
//        }
//
//        stack<TreeNode *> stackTreeNode;
//        stack<int> stackLeftNums;
//        stack<int> stackRightNums;
//
//        TreeNode *root = new TreeNode(0);
//        stackTreeNode.push(root);
//        stackLeftNums.push(0);
//        stackRightNums.push((int)nums.size() - 1);
//
//
//        while (stackTreeNode.empty() == false) {
//            TreeNode *node = stackTreeNode.top();
//            stackTreeNode.pop();
//
//            int l = stackLeftNums.top();
//            stackLeftNums.pop();
//
//            int r = stackRightNums.top();
//            stackRightNums.pop();
//
//            int mid = l + ((r - l) >> 1);
//            node->val = nums[mid];
//
//            if (l <= mid - 1) {
//                node->left = new TreeNode(0);
//                stackTreeNode.push(node->left);
//                stackLeftNums.push(l);
//                stackRightNums.push(mid - 1);
//            }
//
//            if (r >= mid + 1) {
//                node->right = new TreeNode(0);
//                stackTreeNode.push(node->right);
//                stackLeftNums.push(mid + 1);
//                stackRightNums.push(r);
//            }
//        }
//
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {-10,-3,0,5,9};
//        TreeNode *root = sortedArrayToBST2(arr);
//
//        tool.printBT(root);
//    }
//};

#pragma mark - 538
//class Solution {
//public:
//    int lastCount = 0;
//    TreeNode* convertBST(TreeNode* root) {
//        //递归 反中序 RDL
//
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        convertBST(root->right);
//        root->val += lastCount;
//        lastCount = root->val;
//        convertBST(root->left);
//
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = convertBST(root);
//        tool.printBT(result);
//    }
//};

#pragma mark - 77
//class Solution {
//public:
//
//    vector<vector<int>> combine(int n, int k) {
//
//        vector<vector<int>> result;
//        vector<int> path;
//
//        backtracking(1, n, k, result, path);
//
//        return result;
//    }
//
//    void backtracking(int s, int n , int k, vector<vector<int>>& result, vector<int>& path) {
//        if (path.size() == k) {
//            result.push_back(path);
//            return;
//        }
//
//        for (int i = s; i <= n - (k - path.size()) + 1; i++) {
//            path.push_back(i);
//            backtracking(i + 1, n, k, result, path);
//            path.pop_back();
//        }
//    }
//
//    void test() {
//        vector<vector<int>> result = combine(4, 2);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 216
//class Solution {
//public:
//    vector<vector<int>> combinationSum3(int k, int n) {
//
//        vector<vector<int>> result;
//        vector<int> path;
//        backtracking(1, k, n, result, path, 0);
//
//        return result;
//    }
//
//    void backtracking(int s, int n, int k , vector<vector<int>>& result, vector<int>& path, int count) {
//
//        if (count > k) {
//            return;
//        }
//
//        if (path.size() == n) {
//            if (count == k) {
//                result.push_back(path);
//            }
//            return;
//        }
//
////        n - size <= 9 - i + 1
//        for (int i = s; i <= 9 - (n - path.size()) + 1; i++) {
//            path.push_back(i);
//            backtracking(i + 1, n, k, result, path, count + i);
//            path.pop_back();
//        }
//    }
//
//    void test() {
//        vector<vector<int>> result = combinationSum3(3, 7);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 17
//class Solution {
//public:
//    unordered_map<char, string> map;
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0) {
//            return {};
//        }
//
//        map['2'] = "abc";
//        map['3'] = "def";
//        map['4'] = "ghi";
//        map['5'] = "jkl";
//        map['6'] = "mno";
//        map['7'] = "pqrs";
//        map['8'] = "tuv";
//        map['9'] = "wxyz";
//
//        vector<string> result;
//
//        string path;
//
//        backtracking(0, result, path, digits);
//
//        return result;
//    }
//
//    void backtracking(int s, vector<string> &result, string &path, string digits) {
//        if (path.size() == digits.size()) {
//            result.push_back(path);
//            return;
//        }
//
//        if (s >= digits.size()) {
//            return;
//        }
//
//        char c = digits[s];
//        string str = map[c];
//
//        for (int j = 0; j < str.size(); j++) {
//            path.push_back(str[j]);
//            backtracking(s + 1, result, path, digits);
//            path.pop_back();
//        }
//    }
//
//    void test() {
//        vector<string> result = letterCombinations("2");
//
//        vector<string> :: iterator it = result.begin();
//        while (it != result.end()) {
//            cout<<*it<<endl;
//            it++;
//        }
//    }
//};

#pragma mark - 39
//class Solution {
//public:
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> result;
//        vector<int> path;
//
//        sort(candidates.begin(), candidates.end());
//
//        backtrack(0, target, candidates, result, path, 0);
//
//        return result;
//    }
//
//    void backtrack(int s, int target, vector<int>& candidates, vector<vector<int>>& result, vector<int>path, int count) {
//        if (count >= target) {
//            if (count == target) {
//                result.push_back(path);
//            }
//            return;
//        }
//
//        for (int i = s; i < candidates.size() && count + candidates[i] <= target; i++) {
//            path.push_back(candidates[i]);
//            backtrack(i, target, candidates, result, path, count + candidates[i]);
//            path.pop_back();
//        }
//    }
//
//    void test() {
//        vector<int> arr = {};
//        vector<vector<int>> result = combinationSum(arr, 0);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 40
//class Solution {
//public:
//
//    int lastNum = 0;
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        //回溯
//        vector<vector<int>> result;
//        vector<int> path;
//        vector<bool> used(candidates.size(), false);
//
//        sort(candidates.begin(), candidates.end());
//        backtrack(0, target, candidates, result, path, 0, used);
//
//        return result;
//    }
//
//    void backtrack(int s, int target, vector<int>& candiates, vector<vector<int>>& result, vector<int>& path, int count, vector<bool>& used) {
//        if (count >= target) {
//            if (count == target) {
//                result.push_back(path);
//            }
//            return;
//        }
////https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247485360&idx=1&sn=2256a0f01a304d82a2b59252327f3edb&chksm=f9a234e1ced5bdf72f4f27d55618fdb185f324260a2776a266b497956b28c9f317a83b1bf36a&cur_album_id=1485825793120387074&scene=189#rd
//        for (int i = s; i < candiates.size() && count + candiates[i] <= target; i++) {
//
//            if (i > 0 && candiates[i] == candiates[i - 1] && used[i - 1] == false) {
//                continue;
//            }
//
//            used[i] = true;
//
//            path.push_back(candiates[i]);
//            backtrack(i + 1, target, candiates, result, path, count + candiates[i], used);
//            path.pop_back();
//
//            used[i] = false;
//
//        }
//    }
//
//    void test() {
//        vector<int> arr = {2,5,2,1,2,4,3};
//        vector<vector<int>> result = combinationSum2(arr, 5);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 131
//class Solution {
//public:
//    vector<vector<string>> partition(string s) {
//        //回溯
//
//        vector<vector<string>> result;
//        vector<string> path;
//        backtrack(0, s, result, path);
//
//        return result;
//    }
//
//    void backtrack(int l, string s, vector<vector<string>>& result, vector<string>& path) {
//        if (l >= s.size()) {
//            result.push_back(path);
//            return;
//        }
//
//        for (int i = l; i < s.size(); i++) {
//            if (checkIsPalindromic(s, l, i)) {
//                path.push_back(s.substr(l, i - l + 1));
//                backtrack(i + 1, s, result, path);
//                path.pop_back();
//            }
//        }
//
//    }
//
//    bool checkIsPalindromic(string s, int l, int r) {
//        while (l < r) {
//            if (s[l++] != s[r--]) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<vector<string>> result = partition("aabb");
//        vector<vector<string>> :: iterator it = result.begin();
//        while (it != result.end()) {
//            vector<string>::iterator it2 = it->begin();
//            while (it2 != it->end()) {
//                cout<<*it2<<" ";
//                it2++;
//            }
//            cout<<endl;
//            it++;
//        }
//    }
//};

#pragma mark - 93
//class Solution {
//public:
//    vector<string> restoreIpAddresses(string s) {
//        //回溯
//
//        vector<string> result;
//        vector<int> path;
//
//        backtrack(0, s, path, result);
//
//        return result;
//    }
//
//    void backtrack(int l, string s, vector<int>& path, vector<string>& result) {
//        if (path.size() == 4) {
//            string temp;
//            for (int i = 0; i < path.size(); i++) {
//                if (temp.size() == 0) {
//                    temp += to_string(path[i]);
//                }
//                else {
//                    temp += ("." + to_string(path[i]));
//                }
//            }
//            result.push_back(temp);
//            return;
//        }
//
//        for (int i = l; i < s.size(); i++) {
//            string str = s.substr(l, i - l + 1);
//
//            if (str.size() > 1 && str[0] == '0') {
//                continue;
//            }
//
//            if (str.size() > 3) {
//                return;
//            }
//            int ip = (int)stol(str);
//            if (ip <= 255) {
//                path.push_back(ip);
//                if ((s.size() - i - 1) <= (4 - path.size()) * 3) {
//                    backtrack(i + 1, s, path, result);
//                }
//                path.pop_back();
//            }
//        }
//    }
//
//    void test() {
//        //000010101010100
//        vector<string> result = restoreIpAddresses("2736786374048");
//        vector<string> :: iterator it = result.begin();
//        while (it != result.end()) {
//            cout<<*it<<endl;
//            it++;
//        }
//    }
//};

#pragma mark - 78
//class Solution {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        //回溯
//        vector<vector<int>> result;
//        vector<int> path;
//
//        result.push_back(path);
//
//        backtrack(0, nums, result, path);
//
//        return result;
//    }
//
//    void backtrack(int s, vector<int>& nums, vector<vector<int>>& result, vector<int>& path) {
//        if (s >= nums.size()) {
//            return;
//        }
//
//        for (int i = s; i < nums.size(); i++) {
//            path.push_back(nums[i]);
//            result.push_back(path);
//            backtrack(i + 1, nums, result, path);
//            path.pop_back();
//        }
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3};
//        vector<vector<int>> result = subsets(arr);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 90
//class Solution {
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        vector<vector<int>> result;
//        vector<int> path;
//        vector<bool> used(nums.size(), false);
//
//        result.push_back(path);
//        sort(nums.begin(), nums.end());
//        backtrack(0, nums, result, path, used);
//
//        return result;
//    }
//
//    void backtrack(int s, vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& used) {
//
//        for (int i = s; i < nums.size(); i++) {
//            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
//                continue;
//            }
//
//            path.push_back(nums[i]);
//            result.push_back(path);
//            used[i] = true;
//            backtrack(i + 1, nums, result, path, used);
//            used[i] = false;
//            path.pop_back();
//        }
//    }
//
//    void test() {
//        vector<int> arr = {4,4,4,1,4};
//        vector<vector<int>> result = subsetsWithDup(arr);
//
//        tool.printMatrix(result);
//    }
//
//    /**
//     [[],[1],[1,4],[1,4,4],[1,4,4,4],[1,4,4,4,4],[4],[4,4],[4,4,4],[4,4,4,4]]
//     */
//};

#pragma mark - 491
//class Solution {
//public:
//
//    vector<vector<int>> findSubsequences(vector<int>& nums) {
//        //回溯
//        vector<vector<int>> result;
//        vector<int> path;
//
//        backtrack(0, nums, result, path);
//
//        return result;
//    }
//    void backtrack(int s, vector<int>& nums, vector<vector<int>>& result, vector<int>& path) {
//        //优化使用桶计数
//
//        vector<bool> used = vector<bool>(201, false);
//        for (int i = s; i < nums.size(); i++) {
//            int last = INT_MIN;
//            if (path.size() > 0) {
//                last = path.back();
//            }
//            if (last <= nums[i]) {
//
//                if (i > 0 && (used[nums[i] + 100] == true)) {
//                    continue;
//                }
//                path.push_back(nums[i]);
//                if (path.size() > 1) {
//                    result.push_back(path);
//                }
//                used[nums[i] + 100] = true;
//                backtrack(i + 1, nums, result, path);
//                path.pop_back();
//            }
//        }
//    }
//
//    void backtrack2(int s, vector<int>& nums, vector<vector<int>>& result, vector<int>& path) {
//        if (s >= nums.size()) {
//            return;
//        }
//
//        unordered_map<int, bool> map;
//        for (int i = s; i < nums.size(); i++) {
//            int last = INT_MIN;
//            if (path.size() > 0) {
//                last = path.back();
//            }
//            if (last <= nums[i]) {
//
//                if (i > 0 && (map.find(nums[i]) != map.end()) && map[nums[i]] == true) {
//                    continue;
//                }
//                path.push_back(nums[i]);
//                if (path.size() > 1) {
//                    result.push_back(path);
//                }
//                map[nums[i]] = true;
//                backtrack(i + 1, nums, result, path);
//                path.pop_back();
//            }
//        }
//    }
//
//    void test() {
//        vector<int> arr = {-100,-99,-98,-97,-96,-96};
//        vector<vector<int>> result = findSubsequences(arr);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 46
//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        //回溯
//
//        vector<vector<int>> result;
//        vector<int> path;
//
//        vector<bool> used(nums.size(), false);
//
//        backtrack(-1, nums, result, path, used);
//
//        return result;
//    }
//
//    void backtrack(int s, vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& used) {
//        if (path.size() == nums.size()) {
//            result.push_back(path);
//            return;
//        }
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (used[i] == false) {
//                used[i] = true;
//                path.push_back(nums[i]);
//                backtrack(i, nums, result, path, used);
//                path.pop_back();
//                used[i] = false;
//            }
//        }
//    }
//
//    void test() {
//        vector<int> arr = {};
//        vector<vector<int>> result = permute(arr);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 47
//class Solution {
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        //回溯
//
//        vector<vector<int>> result;
//        vector<int> path;
//        vector<bool> used(nums.size(), false);
//
//        sort(nums.begin(), nums.end());
//
//        backtrack(nums, result, path, used);
//
//        return result;
//    }
//
//    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, vector<bool>& used) {
//        if (path.size() == nums.size()) {
//            result.push_back(path);
//            return;
//        }
//
//        int last = -99;
//        for (int i = 0; i < nums.size(); i++) {
//            if (last == nums[i]) {
//                continue;
//            }
//
//            if (used[i] == false) {
//                used[i] = true;
//                path.push_back(nums[i]);
//                last = nums[i];
//                backtrack(nums, result, path, used);
//                path.pop_back();
//                used[i] = false;
//            }
//        }
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3};
//
//        vector<vector<int>> result = permuteUnique(arr);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 332
//class Solution {
//public:
//
//    vector<string> findItinerary(vector<vector<string>>& tickets) {
//
//        vector<string> result;
//        vector<bool> used(tickets.size(), false);
//        result.push_back("JFK");
//        sort(tickets.begin(), tickets.end(), [](const vector<string>& a, const vector<string>& b){
//            return a[1] < b[1];
//        });
//        backtrack(tickets, result, used, "JFK");
//
//        if (result.size() == 1) {
//            return {};
//        }
//
//        return result;
//    }
//
//    bool backtrack(vector<vector<string>>& tickets, vector<string>& result, vector<bool>& used, string target) {
//
//        if (result.size() == tickets.size() + 1) {
//            return true;
//        }
//        for (int i = 0; i < tickets.size(); i++) {
//            if (used[i] == false) {
//                if (target == tickets[i][0]) {
//                    result.push_back(tickets[i][1]);
//                    used[i] = true;
//                    bool isSuccess = backtrack(tickets, result, used, tickets[i][1]);
//                    if (isSuccess) {
//                        return true;
//                    }
//                    used[i] = false;
//                    result.pop_back();
//                }
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        vector<vector<string>> arr = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
//
//        vector<string> result = findItinerary(arr);
//
//        vector<string>::iterator it = result.begin();
//        while (it != result.end()) {
//            cout<<*it<<",";
//            it++;
//        }
//        cout<<endl;
//    }
//};

#pragma mark - 51
//class Solution {
//public:
//    vector<vector<string>> solveNQueens(int n) {
//
//        vector<vector<string>> result;
//        string line(n, '.');
//        vector<string> uesd(n, line);
//
//        backtrack(0, n, result, uesd);
//
//        return result;
//    }
//
//    bool checkIsSafe(vector<string>& used, int i, int j) {
//        for (int m = 0; m <= i; m++) {
//            for (int n = 0; n < used.size(); n++) {
//                if (abs(m - i) == abs(n - j) || n == j) {
//                    if (used[m][n] != '.') {
//                        return false;
//                    }
//                }
//            }
//        }
//        return true;
//    }
//
//    void backtrack(int cur, int n, vector<vector<string>>& result,vector<string>& used) {
//        if (cur >= n) {
//            result.push_back(used);
//            return;
//        }
//
//        for (int i = 0; i < n; i++) {
//            if (checkIsSafe(used, cur, i)) {
//                used[cur][i] = 'Q';
//                backtrack(cur + 1, n, result, used);
//                used[cur][i] = '.';
//            }
//        }
//    }
//
////    void createSafeMap(vector<vector<int>>& used, int i, int j) {
////        int mStart = i > 7 ? i - 7 : 0;
////        int nStart = j > 7 ? j - 7 : 0;
////        int end = used.size() > 7 ? (int)used.size() - 7 : (int)used.size();
////
////        for (int m = mStart; m < end; m++) {
////            for (int n = nStart; n < end; n++) {
////                if (abs(m - i) == abs(n - j) || m == i || n == j) {
////                    used[m][n]++;
////                }
////            }
////        }
////    }
//
////    void removeSafeMap(vector<vector<int>>& used, int i, int j) {
////        int mStart = i > 7 ? i - 7 : 0;
////        int nStart = j > 7 ? j - 7 : 0;
////        int end = used.size() > 7 ? (int)used.size() - 7 : (int)used.size();
////
////        for (int m = mStart; m < end; m++) {
////            for (int n = nStart; n < end; n++) {
////                if (abs(m - i) == abs(n - j) || m == i || n == j) {
////                    used[m][n]--;
////                }
////            }
////        }
////    }
////
//
//    void test() {
//        vector<vector<string>> result = solveNQueens(4);
//
//        vector<vector<string>>::iterator resultIT = result.begin();
//        while (resultIT != result.end()) {
//            cout<<endl<<"{"<<endl;
//            vector<string>::iterator lineIT = resultIT->begin();
//            while (lineIT != resultIT->end()) {
//                cout<<*lineIT<<endl;
//                lineIT++;
//            }
//            cout<<"}"<<endl;
//            resultIT++;
//        }
//    }
//};

#pragma mark - 37
//class Solution {
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//
//        backtrack(board);
//    }
//
//    bool checkIsValid(vector<vector<char>>& board, int row, int line, char num) {
//        for (int i = 0; i < 9; i++) {
//            if (board[i][line] == num) {
//                return false;
//            }
//        }
//
//        for (int i = 0; i < 9; i++) {
//            if (board[row][i] == num) {
//                return false;
//            }
//        }
//
//        int sRow = (row / 3) * 3;
//        int sLine = (line / 3) * 3;
//        for (int i = sRow; i < sRow + 3; i++) {
//            for (int j = sLine; j < sLine + 3; j++) {
//                if (board[i][j] == num) {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }
//
//    bool backtrack(vector<vector<char>>& board) {
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[0].size(); j++) {
//                if (board[i][j] == '.') {
//                    for (char k = '1'; k <= '9'; k++) {
////                        if (isValid(i, j, k, board)) {
//                        if (checkIsValid(board, i, j, k)) {
//                            board[i][j] = k;
//                            bool isSuccess = backtrack(board);
//                            if (isSuccess) {
//                                return true;
//                            }
//                            board[i][j] = '.';
//                        }
//                    }
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }
//
//    bool backtracking(vector<vector<char>>& board) {
//        for (int i = 0; i < board.size(); i++) {        // 遍历行
//            for (int j = 0; j < board[0].size(); j++) { // 遍历列
//                if (board[i][j] != '.') continue;
//                for (char k = '1'; k <= '9'; k++) {     // (i, j) 这个位置放k是否合适
//                    if (checkIsValid(board, i, j, k)) {
//                        board[i][j] = k;                // 放置k
//                        if (backtracking(board)) return true; // 如果找到合适一组立刻返回
//                        board[i][j] = '.';              // 回溯，撤销k
//                    }
//                }
//                return false;                           // 9个数都试完了，都不行，那么就返回false
//            }
//        }
//        return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
//    }
//    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
//        for (int i = 0; i < 9; i++) { // 判断行里是否重复
//            if (board[row][i] == val) {
//                return false;
//            }
//        }
//        for (int j = 0; j < 9; j++) { // 判断列里是否重复
//            if (board[j][col] == val) {
//                return false;
//            }
//        }
//        int startRow = (row / 3) * 3;
//        int startCol = (col / 3) * 3;
//        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
//            for (int j = startCol; j < startCol + 3; j++) {
//                if (board[i][j] == val ) {
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//
//    void solveSudoku2(vector<vector<char>>& board) {
//        vector<vector<char>> vecUnusedNum(9, {'1','2','3','4','5','6','7','8','9'});
//        vector<vector<int>> vecBlockIndex(9);
//
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board.size(); j++) {
//                char temp = board[i][j];
//                if (temp == '.') {
//                    vecBlockIndex[i].push_back(j);
//                }
//                else {
//                    vector<char>::iterator pos = find(vecUnusedNum[i].begin(), vecUnusedNum[i].end(), temp);
//                    vecUnusedNum[i].erase(pos);
//                }
//            }
//        }
//
////        int i = 0;
//        backtrack2(vecUnusedNum, vecBlockIndex, board, 0, 0, 0);
//    }
//
//    bool backtrack2(vector<vector<char>>& vecUnusedNum,
//                   vector<vector<int>>& vecBlockIndex,
//                   vector<vector<char>>& board,
//                   int row, int numIndex, int blockIndex){
//
//        if (blockIndex >= vecBlockIndex.size()) {
//            return true;
//        }
//
//        for (int i = 0; i < vecUnusedNum[row].size(); i++) {
//            if (blockIndex < vecBlockIndex[row].size()) {
//                int line = vecBlockIndex[row][blockIndex];
//                char num = vecUnusedNum[row][i];
//                if (checkIsValid(board, row, line, num)) {
//                    board[row][line] = num;
//                    //                        printBoard(board);
//                    bool isSuccess = backtrack2(vecUnusedNum, vecBlockIndex, board, row, i + 1, blockIndex + 1);
//                    cout<<"row:"<<row<<"line:"<<blockIndex + 1<<endl;
//                    if (isSuccess) {
//                        printBoard(board);
//                        bool nextSuccess = backtrack2(vecUnusedNum, vecBlockIndex, board, row + 1, 0, 0);
//                        if (nextSuccess == true) {
//                            return true;
//                        }
//                    }
//                    board[row][line] = '.';
//                }
//            }
//        }
//
//
//        return false;
//    }
//
//    void test() {
//        vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
//
//        solveSudoku(board);
//
//        printBoard(board);
//    }
//
//    void printBoard(vector<vector<char>>& board) {
//        vector<vector<char>>::iterator boardIt = board.begin();
//        while (boardIt != board.end()) {
//            vector<char>::iterator lineIt = boardIt->begin();
//            while (lineIt != boardIt->end()) {
//                cout<<*lineIt<<" ";
//                lineIt++;
//            }
//            boardIt++;
//            cout<<endl;
//        }
//        cout<<endl;
//    }
//};

#pragma mark - 455
//class Solution {
//public:
//    int findContentChildren(vector<int>& g, vector<int>& s) {
//        sort(g.begin(), g.end());
//        sort(s.begin(), s.end());
//
//        int gCount = 0;
//        int sizeIndex = 0;
//        for (int i = 0; i < g.size(); i++) {
//            while (sizeIndex < s.size()) {
//                if ( g[i] <= s[sizeIndex++]) {
//                    gCount++;
//                    break;
//                }
//            }
//        }
//
//        return gCount;
//    }
//
//    void test() {
//        vector<int> g = {1,2};
//        vector<int> s = {1,2,3};
//
//        int result = findContentChildren(g, s);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 376
//class Solution {
//public:
//    int wiggleMaxLength(vector<int>& nums) {
//
//        if (nums.size() <= 1) return (int)nums.size();
//
//        int count = 1;
//        cout<<nums[0]<<" ";
//
//        int start = 1;
//        bool isUp = false;
//        while (start < nums.size()) {//获取初始趋势
//            if (nums[start - 1] == nums[start]) {
//                start++;
//            }
//            else {
//                isUp = nums[start] > nums[start - 1] ? true : false;
//                break;
//            }
//        }
//
//        for (int i = start; i < nums.size(); i++) {
//
//            if (isUp == false && nums[i - 1] < nums[i]) {//下降趋势,趋势转变
//                cout<<nums[i - 1]<<" ";
//                count++;
//                isUp = true;
//            }
//
//            if (isUp == true && nums[i - 1] > nums[i]) {//上升趋势，趋势转变
//                cout<<nums[i - 1]<<" ";
//                count++;
//                isUp = false;
//            }
//
//            if (i == nums.size() - 1) {
//                cout<<nums[i]<<" ";
//                count++;
//            }
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<int> arr = {1,1,1,2,2,2,2,2,2};
//        int result = wiggleMaxLength(arr);
//
//        cout<<endl<<result<<endl;
//    }
//};

#pragma mark - 53
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int lastCount = nums[0];
//        int maxCount = nums[0];
//        for (int i = 1; i < nums.size(); i++) {
//            lastCount = max(lastCount + nums[i], nums[i]);//继续累加，还是从头开始
//            maxCount = max(maxCount, lastCount);
//        }
//
//        return maxCount;
//    }
//
//    void test() {
//        vector<int> nums = {-2};
//        int result = maxSubArray(nums);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 122
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        //上升趋势最低买，最高卖
//        int count = 0;
//        int lowIndex = 0;
//        for (int i = 1; i < prices.size(); i++) {
//            if (prices[i] > prices[i - 1]) {
////                cout<<"买入"<<prices[i - 1]<<"->";
//            }
//            else {
//
//                count += prices[i - 1] - prices[lowIndex];
////                if (i - 1 != lowIndex) {
////                    cout<<"卖出"<<prices[i - 1]<<" ";
////                }
//                lowIndex = i;
//            }
//
//            if (i == prices.size() - 1 && prices[i] > prices[lowIndex]) {
////                cout<<"卖出"<<prices[i]<<" ";
//                count += prices[i] - prices[lowIndex];
//            }
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<int> arr = {7};
//        int result = maxProfit(arr);
//
//        cout<<endl<<result<<endl;
//    }
//};

#pragma mark - 55
//class Solution {
//public:
//    bool canJump(vector<int>& nums) {
//        //回溯
//
//        if (nums.size() <= 1) {
//            return true;
//        }
//
//        return backtrack(nums, 0);
//    }
//
//    bool backtrack(vector<int>& nums, int start) {
//        if (start >= nums.size()) {
//            return false;
//        }
//        for (int j = nums[start]; j >= 1; j--) {
//            int jump = nums[start];
//            if (jump + start >= nums.size() - 1) {
//                return true;
//            }
//            else {
//                if( backtrack(nums, start + j)) {
//                    return true;
//                };
//            }
//        }
//
//        return false;
//    }
//
//    bool canJump2(vector<int>& nums) {
//
//        if (nums.size() <= 1) {
//            return true;
//        }
//
//        //记录最远到达的位置，是否可以越过0的位置
//        int maxPos = 0;
//
//        for (int i = 0; i < nums.size(); i++) {
//
//            if (nums[i] == 0) {
//                if (maxPos <= i) {
//                    return false;
//                }
//            }
//
//            if (maxPos < nums[i] + i) {
//                maxPos = nums[i] + i;
//            }
//
//            if (maxPos >= nums.size() - 1) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        vector<int> arr = {2,0,0};
//        bool result = canJump2(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 45
//class Solution {
//public:
//    int count = 0;
//    int jump(vector<int>& nums) {
//
//        if (nums.size() <= 1) {
//            return 0;
//        }
//
//        //找到最早能到达最后位置的，位置pos，在递归寻找到达pos的位置，直到0位置
//        backtrack(nums, (int)nums.size() - 1);
//        return count;
//    }
//    void backtrack(vector<int>nums, int arrivedPos) {
//        if (arrivedPos == 0) {
//            return;
//        }
//        for (int i = 0; i < arrivedPos; i++) {
//            int maxPos = nums[i] + i;
//            if (maxPos >= arrivedPos) {
//                count++;
//                backtrack(nums, i);
//                break;
//            }
//        }
//    }
//
//    void test() {
//        vector<int> arr = {2};
//        int result = jump(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1005
//class Solution {
//public:
//    int largestSumAfterKNegations(vector<int>& A, int K) {
//        //最小数反转
//        for (int i = 0; i < K; i++) {
//            vector<int>::iterator pos = min_element(A.begin(), A.end());
//
//            *pos *= -1;
//        }
//
//        return accumulate(A.begin(), A.end(), 0);
//    }
//
//    int largestSumAfterKNegations2(vector<int>& A, int K) {
//        if (A.size() == 0) {
//            return 0;
//        }
//
//        sort(A.begin(), A.end(), [](int a, int b) {
//            return abs(a) > abs(b);
//        });
//
//        int count = 0;
//        for (int i = 0; i < A.size() - 1; i++) {
//            if (A[i] < 0 && K > 0) {
//                count -= A[i];
//                K--;
//            }
//            else {
//                count += A[i];
//            }
//        }
//
//        if (K % 2 == 0) {
//            count += A[A.size() - 1];
//        }
//        else {
//            count -= A[A.size() - 1];
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<int> arr = {4,2,3};
//        int result = largestSumAfterKNegations2(arr, 1);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 134
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        /**
//
//         */
//        //记录从每站离开时剩余的油量
//        int oweGas = 0;//在记录开始点之前欠的汽油
//        int startPosBalance = 0;//开始点之后汽油余量
//        int pos = -1;//开始点位置
//        for (int i = 0; i < gas.size(); i++) {
//            int curBalance = gas[i] - cost[i];//当前点余量
//            int nextBalance = i == (int)gas.size() - 1 ? 0 : gas[i + 1] - cost[i];//下一个点余量
//            if (pos == -1) {//没有记录当前点
//                if (curBalance + nextBalance >= 0 && curBalance >= 0) {//当前点能到达下一点，当前点有余量，
//                    //记录起始点，其实点余量
//                    pos = i;
//                    startPosBalance += curBalance;
//                }
//                else {
//                    //记录开始点之前的欠量
//                    oweGas += curBalance;
//                }
//            }
//            else {
//                startPosBalance += curBalance;
//                if (startPosBalance < 0) {//当点开始点到达不了下一个点
//                    //重制起始点
//                    pos = -1;
//                    oweGas += startPosBalance;
//                    startPosBalance = 0;
//                }
//            }
//        }
//        if (oweGas + startPosBalance >= 0) {//起始点欠量 小于 起始点之后的余量
//            return pos;
//        }
//        return -1;
//    }
//
//    void test() {
//        /**
//         [2,3,4]
//         [3,4,3]
//
//         [1,2,3,4,5]
//         [3,4,5,1,2]
//
//         [5,1,2,3,4]
//         [4,4,1,5,1]
//
//         [1,2,3,4,5]
//         [3,4,5,1,2]
//
//         [6,1,4,3,5]
//         [3,8,2,4,2]
//         */
//        vector<int> gas = {2,3,4};
//        vector<int> cost = {3,4,3};
//        int result = canCompleteCircuit(gas, cost);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 135
//class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        //找到第一个最小值的位置
//        //从最小值位置先向左遍历，然后向右遍历，如果碰到其他最小值，再次向左遍历，
//        vector<int> result(ratings.size(), 0);
//        int minVal = INT_MAX, minFirstPos = 0;
//        for (int i = 0; i < ratings.size(); i++) {
//            if (ratings[i] < minVal) {
//                minVal = ratings[i];
//                minFirstPos = i;
//            }
//        }
//
//        result[minFirstPos] = 1;
//
//        int lastRightIndex = minFirstPos + 1;
//        int currentIndex = minFirstPos - 1;
//        while (currentIndex < (int)ratings.size()) {
//
//            if (currentIndex < lastRightIndex) {//向左
//                if (currentIndex >= 0 && ratings[currentIndex] != minVal) {//碰到边界之前
//                    int tempVal = 0;
//                    if (ratings[currentIndex] > ratings[currentIndex + 1]) {
//                        tempVal = result[currentIndex + 1] + 1;
//                    }
//                    else if (ratings[currentIndex] <= ratings[currentIndex + 1]) {
//                        tempVal = 1;
//                    }
//                    result[currentIndex] = max(result[currentIndex], tempVal);
//                    currentIndex--;
//                    continue;
//                }
//                else {
//                    currentIndex = lastRightIndex;
//                }
//            }
//            else {//向右
//                if (currentIndex <= ratings.size() - 1 && ratings[currentIndex] != minVal) { //碰到边界之前
//                    int tempVal = 0;
//                    if (ratings[currentIndex] > ratings[currentIndex - 1]) {
//                        tempVal = result[currentIndex - 1] + 1;
//                    }
//                    else if (ratings[currentIndex] <= ratings[currentIndex - 1]) {
//                        tempVal = 1;
//                    }
//                    result[currentIndex] = tempVal;
//                    currentIndex++;
//                }
//                else if (ratings[currentIndex] == minVal) { //碰到最小值，向左遍历
//                    result[currentIndex] = 1;
//                    lastRightIndex = currentIndex + 1;
//                    currentIndex--;
//                }
//            }
//        }
//
//        int count = accumulate(result.begin(), result.end(), 0);
//
//        return count;
//    }
//
//    int candy2(vector<int>& ratings) {
//        vector<int> result(ratings.size(), 0);
//        result[0] = 1;
//        for (int i = 1; i < ratings.size(); i++) {
//            int tempVal = 1;
//            if (ratings[i] > ratings[i - 1]) {
//                tempVal = result[i - 1] + 1;
//            }
//            result[i] = tempVal;
//        }
//
//        int count = result[result.size() - 1];
//        for (int i = (int)ratings.size() - 2; i >= 0; i--) {
//            int tempVal = 0;
//            if (ratings[i] > ratings[i + 1]) {
//                tempVal = result[i + 1] + 1;
//            }
//            result[i] = max(result[i], tempVal);
//            count += result[i];
//
//        }
//        return count;
//    }
//
//    void test() {
//        /*3,2,1,5,2,1,2,
//         [29,51,87,87,72,12]
//         */
//        vector<int> arr = {1,2,2};
//
//        int result = candy2(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 860
//class Solution {
//public:
//    bool lemonadeChange(vector<int>& bills) {
//        //记录5元数量，10元数量
//        //支付20时优先找10元
//        int fiveCount = 0;
//        int tenCount = 0;
//
//        for (int i = 0; i < bills.size(); i++) {
//            if (bills[i] == 5) {
//                fiveCount++;
//            }
//            else if (bills[i] == 10) {
//                fiveCount--;
//                tenCount++;
//            }
//            else {
//                if (tenCount > 0) {
//                    tenCount--;
//                    fiveCount--;
//                }
//                else {
//                    fiveCount -= 3;
//                }
//            }
//
//            if (fiveCount < 0 || tenCount < 0) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> bills = {5,5,5,5,10,5,10,10,10,20};
//        bool result = lemonadeChange(bills);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 406
//class Solution {
//public:
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        sort(people.begin(), people.end(), [](vector<int>a, vector<int>b){
//            if (a[0] == b[0]) {
//                return a[1] < b[1];
//            }
//
//            return a[0] > b[0];
//        });
//
////        vector<vector<int>> result;
//        list<vector<int>> result;
//        for (int i = 0; i < people.size(); i++) {
//            list<vector<int>>::iterator it = result.begin();
//            int count = 0;
//            while (count < people[i][1]) {
//                count++;
//                it++;
//            }
//            result.insert(it, people[i]);
//        }
//
//        return vector<vector<int>>(result.begin(), result.end());
//    }
//
//    void test() {
//        /*
//         {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}
//
//         {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}}
//
//         {{2,4},{3,4},{9,0},{0,6},{7,1},{6,0},{7,3},{2,5},{1,1},{8,0}}
//
//         {{8,2},{4,2},{4,5},{2,0},{7,2},{1,4},{9,1},{3,1},{9,0},{1,0}}
//         */
//        vector<vector<int>> arr = {{8,2},{4,2},{4,5},{2,0},{7,2},{1,4},{9,1},{3,1},{9,0},{1,0}};
//
//        vector<vector<int>> result = reconstructQueue(arr);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 452
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        //按左值排序
//        if (points.size() <= 1) return (int)points.size();
//         //按左值排序
//         sort(points.begin(), points.end(), [](vector<int>a, vector<int>b){
//             if (a[0] == b[0]) {
//                 return a[1] < b[1];
//             }
//             return a[0] < b[0];
//         });
//
//         int count = 1;
//         int maxRightPos = points[0][1];
//         for (int i = 0; i < points.size(); i++) {
//             if (maxRightPos < points[i][0]) {
//                 count++;
//                 maxRightPos = points[i][1];
//             }
//             else {
//                 maxRightPos = min(maxRightPos, points[i][1]);
//             }
//         }
//
//         return count;
//    }
//
//    void test() {
//        vector<vector<int>> arr =  {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
//
//        int result = findMinArrowShots(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 435
//class Solution {
//public:
//    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//        if (intervals.size() <= 1) {
//            return 0;
//        }
//
//        //左值排序，保留右值最小的
//        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){
//            return a[0] < b[0];
//        });
//
//        int count = 0;
//        int lastRightInterVal = intervals[0][1];
//        for (int i = 1; i < intervals.size(); i++) {
//            if (lastRightInterVal > intervals[i][0]) {//右值大于当前左值，重叠，保留右值小的
//                if (lastRightInterVal > intervals[i][1]) {
//
//                    lastRightInterVal = intervals[i][1];
//                }
//                count++;
//                continue;
//            }
//            lastRightInterVal = intervals[i][1];
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<vector<int>> arr = {{23,37},{24,125},{25,99},{26,45},{27,63},{28,40},{29,97},{30,78},{31,102},{32,120},{33,91},{34,107},{35,62},{36,137},{37,55}};
//
//        int result = eraseOverlapIntervals(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 763
//class Solution {
//public:
//    vector<int> partitionLabels(string S) {
//        //记录经过的字母，
//        string luguo;
//        string partition;
//
//        vector<int> result;
//        int lastPos = 0;
//        while (lastPos < S.size()) {
//            int start = lastPos;
//            for (int i = lastPos; i < S.size(); i++) {
//                if (partition.size() == 0) {
//                    partition.push_back(S[i]);
//                    continue;
//                }
//                if (partition.find(S[i]) == -1) {
//                    luguo.push_back(S[i]);
//                }
//                else{
//                    partition.append(luguo);
//                    luguo.clear();
//                    lastPos = i;
//                }
//            }
//
//            result.push_back(lastPos - start + 1);
//            lastPos++;
//            partition.clear();
//            luguo.clear();
//        }
//
//        return result;
//    }
//
//    vector<int> partitionLabels2(string S) {
//        //每个字母最后的位置
//        vector<int> lastPosVec(26);
//        for (int i = 0; i < S.size(); i++) {
//            lastPosVec[S[i] - 'a'] = i;
//        }
//
//        int curPos = 0;
//        vector<int> result;
//        while (curPos < S.size()) {
//            int start = curPos;
//            int maxLastPos = lastPosVec[S[curPos] - 'a'];
//            while (curPos <= maxLastPos) {
//                maxLastPos = max(maxLastPos, lastPosVec[S[curPos] - 'a']);
//                curPos++;
//            }
//
//            result.push_back(curPos - start);
//
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> result = partitionLabels2("ababcbacadefegdehijhklij");
//
//        tool.printVector(result);
//    }
//};

#pragma mark - 56
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        if (intervals.size() <= 1) {
//            return intervals;
//        }
//
//        //左值排序，保留重叠最大右值
//        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
//            return a[0] < b[0];
//        });
//
//        vector<vector<int>> result;
//        vector<int> current = intervals[0];
//        for (int i = 1; i < intervals.size(); i++) {
//            if (current[1] >= intervals[i][0]) {//重叠,记录大的右值
//                current[1] = max(current[1], intervals[i][1]);
//            }
//            else {
//                result.push_back(current);
//                current = intervals[i];
//            }
//        }
//        //
//        result.push_back(current);
//
//        return result;
//    }
//
//    void test() {
//        /*[1,3],[2,6],[8,10],[15,18]
//         */
//        vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};
//
//        vector<vector<int>> result = merge(arr);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 738
//class Solution {
//public:
//    int monotoneIncreasingDigits(int N) {
//        //记录每位数，如果高位>低位，则高位-1，后面低位都是9
//        vector<int> posNum;
//        while (N > 0) {
//            posNum.push_back(N % 10);
//            N /= 10;
//        }
//
//        int isAllNinePos = -1;//后面全是9的位置
//        for (int i = 0; i < (int)posNum.size() - 1; i++) {
//            if (posNum[i] < posNum[i + 1]) {
//                posNum[i + 1]--;
//                isAllNinePos = i;
//            }
//        }
//
//        int result = 0;
//        for (int i = (int)posNum.size() - 1; i >= 0; i--) {
//            if (isAllNinePos + 1 <= i) {
//                result = result * 10 + posNum[i];
//            }
//            else {
//                result = result * 10 + 9;
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        int result = monotoneIncreasingDigits(1);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 714
//class Solution {
//public:
//    int maxProfit(vector<int>& prices, int fee) {
//        //能赚钱才买，卖出后今后还能赚钱就卖
//
//        //记录每个位置后面时间的最高价
//        vector<int> maxPricesVec(prices);
//        //记录每个位置后面时间的最低价
//        vector<int> minPricesVec(prices);
//        for (int i = (int)prices.size() - 2; i >= 0; i--) {
//            maxPricesVec[i] = max(prices[i], maxPricesVec[i + 1]);
//            minPricesVec[i] = min(prices[i], minPricesVec[i + 1]);
//        }
//
//        int inPos = -1;
//        int outPos = -1;
//        int count = 0;
//        for (int i = 0; i < prices.size(); i++) {
//            if (inPos == -1) {//未买入
//                if (prices[i] + fee < maxPricesVec[i]) {//今日买，今后能赚钱，买入
//                    inPos = i;
//                }
//            }
//            else {
//                if (outPos == -1) {//已买入，未卖出
//                    if (prices[i] < maxPricesVec[i] && prices[i] > minPricesVec[i] + fee) {//当前价格小于今后最高价，今后最低价加手续费低于今日值，卖出
//                        outPos = i;
//                        count += prices[outPos] - prices[inPos] - fee;
//                        inPos = -1;
//                        outPos = -1;
//                        continue;
//                    }
//
//                    if (prices[i] == maxPricesVec[i]) {//当前价格已经是今后的最高价,卖出
//                        outPos = i;
//                        count += prices[outPos] - prices[inPos] - fee;
//                        inPos = -1;
//                        outPos = -1;
//                        continue;
//                    }
//
//                }
//            }
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<int> arr = {1,3,2,8,4,9};
//
//        int result = maxProfit(arr, 2);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 968
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
//    int cameraCount = 0;
//    int minCameraCover(TreeNode* root) {
//
//        int rootState = LRDtraversal(root);
//
//        if (rootState == 0) {
//            cameraCount++;
//        }
//
//        return cameraCount;
//    }
//
//    int LRDtraversal(TreeNode *root) {
//        if (root == nullptr) {
//            return -1;
//        }
//
//        int left = LRDtraversal(root->left);
//        int right = LRDtraversal(root->right);
//
//        if (left == 0 || right == 0) {//有一个子节点没有被监控，需要安装
//            cameraCount++;
////            root->val = 2;
//            return 2;
//        }
//
//        //子节点都被监控
//        if (left == 2 || right == 2) {//有一个子节点有camera，不需要安装
////            root->val = 1;
//            return 1;
//        }
//
//        return root->val;
//    }
//
//    void test() {
//        vector<int> arr = {0,-1,0,-1,0,-1,0};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = minCameraCover(root);
//        tool.printBT(root);
//
//        cout<<result<<endl;
//
//    }
//};
#pragma mark - 509
//class Solution {
//public:
//    int fib(int n) {
//        if (n <= 1) {
//            return n;
//        }
//
//        vector<int> result(n + 1);
//        result[0] = 0;
//        result[1] = 1;
//
//        for (int i = 2; i <= n; i++) {
//            result[i] = result[i - 1] + result[i - 2];
//        }
//
//        return result[n];
//    }
//    int fib2(int n) {
//        //f(n) = f(n - 1) + f(n - 2);
//
//        if (n <= 1) {
//            return n;
//        }
//
//        int last1 = 1;
//        int last2 = 0;
//        for (int i = 2; i <= n; i++) {
//            int temp = last1;
//            last1 = last1 + last2;
//            last2 = temp;
//        }
//
//        return last1;
//    }
//
//    void test() {
//        int result = fib2(10);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 70
//class Solution {
//public:
//    int climbStairs(int n) {
//        //f(n) = f(n - 1) + f(n - 2)
//        if (n <= 2) {
//            return n;
//        }
//
//        vector<int> result(2);
//        result[0] = 1;
//        result[1] = 2;
//        for (int i = 3; i <= n; i++) {
//            int sum = result[0] + result[1];
//            result[0] = result[1];
//            result[1] = sum;
//        }
//
//        return result[1];
//    }
//    void test() {
//        int result = climbStairs(10);
//
//        cout<<endl<<result<<endl;
//    }
//};

#pragma mark - 746
//class Solution {
//public:
//    int minCostClimbingStairs(vector<int>& cost) {
//        //f(n) = min(f(n - 1) + cost[n - 1], f(n - 2) + cost[n - 2]);//到达一个台阶的消耗,离开时消费
//        vector<int> result(cost.size() + 1, 0);
//
//        for (int i = 2; i <= cost.size(); i++) {
//            result[i] = min(result[i - 1] + cost[i - 1], result[i - 2] + cost[i - 2]);
//        }
//
//        return result[(int)result.size() - 1];
//    }
//
//    int minCostClimbingStairs2(vector<int>& cost) {
//        int last1 = 0;
//        int last2 = 0;
//        for (int i = 2; i <= cost.size(); i++) {
//            int sum = min(last1 + cost[i - 1], last2 + cost[i - 2]);
//            last2 = last1;
//            last1 = sum;
//        }
//
//        return last1;
//    }
//
//    int minCostClimbingStairs3(vector<int>& cost) {
//        //f(n) = min(f(n - 1), f(n - 2)) + cost[i];//到达时收费
//        vector<int> result(cost.size(), 0);
//        result[0] = cost[0];
//        result[1] = cost[1];
//
//        for (int i = 2; i < cost.size(); i++) {
//            result[i] = min(result[i - 1], result[i - 2]) + cost[i];
//        }
//
//        return min(result[(int)result.size() - 1], result[(int)result.size() - 2]);
//    }
//
//    void test() {
//        vector<int> arr = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
//
//        int result = minCostClimbingStairs3(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 62
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        //f(i, j) = f(i,j - 1) + f(i - 1, j);
//        vector<vector<int>> result(m, vector<int>(n, 1));
//
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                result[i][j] = result[i][j - 1] + result[i - 1][j];
//            }
//        }
//
//        return result[m - 1][n - 1];
//    }
//
//    int uniquePaths2(int m, int n) {
//        vector<int> result(n, 1);
//
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                result[j] = result[j] + result[j - 1];
//            }
//        }
//
//        return result[n - 1];
//    }
//
//    void test() {
//        int result = uniquePaths(3, 7);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 63
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        //f(i,j) = f(i,j - 1) + f(i - 1, j);o[i][j] != 1
//        //f(i,j) = 0;o[i][j] = 0;
//        int m = (int)obstacleGrid.size();
//        int n = (int)obstacleGrid[0].size();
//        vector<vector<int>> result(m, vector<int>(n, 0));
//
//        for (int i = 0; i < m; i++) {
//            if (obstacleGrid[i][0] == 0) {
//                result[i][0] = 1;
//            }
//            else {
//                break;
//            }
//        }
//
//        for (int j = 0; j < n; j++) {
//            if (obstacleGrid[0][j] == 0) {
//                result[0][j] = 1;
//            }
//            else {//碰到障碍后面都是0
//                break;
//            }
//        }
//
//        for (int i = 1; i < m; i++) {
//            for (int j = 1; j < n; j++) {
//                if (obstacleGrid[i][j] == 0) {
//                    result[i][j] = result[i - 1][j] + result[i][j - 1];
//                }
//                else {
//                    result[i][j] = 0;
//                }
//            }
//        }
//
//        return result[m - 1][n - 1];
//    }
//
//    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
//        int m = (int)obstacleGrid.size();
//        int n = (int)obstacleGrid[0].size();
//
//        vector<int> result(n, 0);
//        for (int i = 0; i < n; i++) {
//            if (obstacleGrid[0][i] == 0) {
//                result[i] = 1;
//            }
//            else {
//                break;
//            }
//        }
//
//        for (int i = 1; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (obstacleGrid[i][j] != 1) {
//                    if (j == 0) {
//                        result[j] = min(result[j], 1);
//                    }
//                    else {
//                        result[j] = result[j] + result[j - 1];
//                    }
//                }
//                else{
//                    result[j] = 0;
//                }
//            }
//        }
//
//        return result[n - 1];
//    }
//
//    void test() {
//        vector<vector<int>> arr = {{1},{0}};
//
//        int result = uniquePathsWithObstacles(arr);
//
//        int result2 = uniquePathsWithObstacles2(arr);
//
//        cout<<result<<endl;
//        cout<<result2<<endl;
//    }
//};

#pragma mark - 343
//class Solution {
//public:
//    int integerBreak(int n) {
////        result[i] = max(result[i], max(result[j], j) * max(result[i - j], i - j));//max(result[i - j], i - j)为拆分i-j和i-j取大的
//
//
//        vector<int> result(n + 1);
//        result[0] = 0;
//        result[1] = 1;
//        for (int i = 2; i <= n; i++) {
//            for (int j = 1; j <= i - 1; j++) {
//                result[i] = max(result[i], max(result[j], j) * max(result[i - j], i - j));
//            }
//        }
//
//        return result[n];
//    }
//
//    void test() {
//        int result = integerBreak(58);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 96
//class Solution {
//public:
//    int numTrees(int n) {
////https://leetcode-cn.com/problems/unique-binary-search-trees/solution/shou-hua-tu-jie-san-chong-xie-fa-dp-di-gui-ji-yi-h/
//        //f(n) = f(n - 1)*f(1) + f(n - 2)*f(2).....
//
//        if (n < 2) {
//            return n;
//        }
//
//        vector<int> result(n + 1, 0);
//        result[0] = 1;
//        result[1] = 1;
//        result[2] = 2;
//        for (int i = 3; i <= n; i++) {
//            for (int j = 0; j <= i - 1; j++) {
//                result[i] += result[i - 1 - j]*result[j];
//            }
//        }
//
//        return result[n];
//    }
//
//    void test() {
//        int result = numTrees(2);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 01bag
//class Solution{
//public:
//    int maxValue = 0;
//    int bag(vector<int>& wight, vector<int>& value, int W) {
//        backtrack(wight, value, W, 0, 0);
//
//        return maxValue;
//    }
//
//    void backtrack(vector<int>& wight, vector<int>& value, int W, int start, int allValue) {
//        if (W < 0) {
//            return ;
//        }
//
//        maxValue = max(allValue, maxValue);
//
//        for (int i = start; i < value.size(); i++) {
//            backtrack(wight, value, W - wight[i], start + 1, allValue + value[i]);
//        }
//    }
//
//    int bag2(vector<int>& wight, vector<int>& value, int W) {
//        //f(i,j) = max(f(i-1,j)//不选i , f(i-1,j-1) + value[i]//选i)
//        vector<vector<int>> result(value.size(), vector<int>(W, 0));
//
//        for (int j = wight[0]; j < wight.size(); j++) {
//            result[0][j] = value[0];
//        }
//
//        for (int i = 0; i < value.size(); i++) {
//            result[i][0] = 0;
//        }
//
//        for (int i = 1; i < value.size(); i++) {
//            for (int j = 0; j < W; j++) {
//                if (j < wight[i]) {
//                    result[i][j] = result[i - 1][j];
//                }
//                else {
//                    result[i][j] = max(result[i - 1][j], result[i - 1][j - wight[i]] + value[i]);
//                }
//            }
//        }
//
//        return result[value.size() - 1][W];
//    }
//
//    int bag3(vector<int>& wight, vector<int>& value, int W) {
//        //f(i,j) = max(f(i-1,j)//不选i , f(i-1,j-1) + value[i]//选i)
//        vector<int> result(W + 1,0);
//
//        for (int i = 0; i < wight.size(); i++) {
//            for (int j = W; j >= wight[i]; j++) {
//                result[j] = max(result[j], result[j - wight[i]] + value[i]);
//            }
//        }
//
//        return result[W];
//    }
//
//    void test() {
//        vector<int> wight = {1,3,4};
//        vector<int> value = {15,20,30};
//
//        int result = bag(wight, value, 4);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 416
//class Solution {
//public:
//    bool canPartition(vector<int>& nums) {
//        //从0-i中选n个数，和最近接j,f(i,j) = min(f(i - 1,j) - j//不选i, f(i - 1, j - 1) + nums[i] - j //选i)
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//        if (sum % 2 != 0) {
//            return false;
//        }
//
//        int N = sum / 2;
//
//        vector<vector<int>> result(nums.size(), vector<int>(N + 1, INT_MAX));
//
//        result[0][0] = nums[0];
//        for (int i = 1; i < nums.size(); i++) {
//            result[i][0] = min(nums[i], result[i - 1][0]);
//        }
//
//        for (int j = 0; j <= N; j++) {
//            result[0][j] = nums[0];
//        }
//
//        for (int i = 1; i < nums.size(); i++) {
//            for (int j = 0; j <= N; j++) {
//                if (j > nums[i]) {
//                    int temp1 = result[i - 1][j] - j;
//                    int temp2 = result[i - 1][j - nums[i]] + nums[i] - j;
//
//                    result[i][j] = abs(temp1) < abs(temp2) ? temp1 + j : temp2 + j;
//                }
//                else {
//                    result[i][j] = result[i - 1][j];
//                }
//            }
//        }
//
//        tool.printMatrix(result);
//
//        if (result[nums.size() - 1][N] == N) {
//            return true;
//        }
//
//        return false;
//    }
//
//    bool canPartition2(vector<int>& nums) {
//        //f(n) = min(abs(f(n) - j), abs(f(n - nums[n]) + nums[j] - j));
//        int sum = 0, maxNum = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            maxNum = max(maxNum, nums[i]);
//            sum += nums[i];
//        }
//        if (sum % 2 != 0) {
//            return false;
//        }
//
//        if (maxNum > sum / 2) {
//            return false;
//        }
//
//        int N = sum / 2;
//        vector<int> result(N + 1, 0);
//
//        for (int i = 1; i < nums.size(); i++) {
//            for (int j = N; j >= nums[i]; j--) {
//                result[j] = max(result[j], result[j - nums[i]] + nums[i]);
//            }
//        }
//        return result[N] == N;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,5,2};
//        bool result = canPartition2(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark 1049
//class Solution {
//public:
//    int lastStoneWeightII(vector<int>& stones) {
//        //找几个数的组合最接近总和的一半
//        //f(n)//0-n个数中总和最接近n的 = max(f(n), f(n - stones[i]) + stones[i]);
//        int sum = 0;
//        for (int i = 0; i < stones.size(); i++) {
//            sum += stones[i];
//        }
//
//        int N = sum / 2;
//
//        vector<int> result(N + 1, 0);
//
//        for (int i = 0; i < stones.size(); i++) {
//            for (int j = N; j >= stones[i]; j--) {
//                result[j] = max(result[j], result[j - stones[i]] + stones[i]);
//            }
//        }
//
//        return sum - result[N] * 2;
//    }
//
//    void test() {
//        vector<int> arr = {2};
//        int result = lastStoneWeightII(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 494
//class Solution {
//public:
//    int count = 0;
//    int findTargetSumWays(vector<int>& nums, int target) {
//
//        string str;
//
//        backtrack(nums, target, 0, 0, 0);
//
//        return count;
//    }
//
//    void backtrack(vector<int>& nums, int target, int sum, int start, int used) {
//        if (start >= nums.size()) {
//            if (sum == target && used == nums.size()) {
//                count++;
//            }
//            return;
//        }
//
//        for (int i = start; i < nums.size(); i++) {
//            backtrack(nums, target, sum - nums[i], i + 1, used + 1);
//            backtrack(nums, target, sum + nums[i], i + 1, used + 1);
//        }
//    }
//
//    int findTargetSumWays2(vector<int>& nums, int target) {
//        // l - r = t, l + r = s, l = (t + s) / 2
//
//        //f(n)为0-n中和为n的个数，f(n) = f(n - nums[i]) + f(n)//上一次不包含i的和为n的次数;
//
//        int sum = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            sum += nums[i];
//        }
//
//        int value = (target + sum) >> 1;
//        if ((target + sum) % 2 != 0) {
//            return 0;
//        }
//
//        vector<int> result(value + 1, 0);
//        result[0] = 1;
//
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = value; j >= nums[i]; j--) {
//                result[j] += result[j - nums[i]];
//            }
//        }
//        return result[value];
//    }
//
//    void test() {
//        vector<int> arr = {1,1,1,1,1};
//        int result = findTargetSumWays2(arr, 3);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 474
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        //f(i,j)//i个0，j个1，最大的组合个数，
//        //f(i,j) = max(f(i,j), f(i - nums[i][0], j - nums[i][1]) + 1);
//
////        vector<vector<int>> nums(strs.size(), vector<int>(2, 0));
////        for (int i = 0; i < strs.size(); i++) {
////            nums[i][0] = (int)count(strs[i].begin(), strs[i].end(), '0');
////            nums[i][1] = (int)strs[i].size() - nums[i][0];
////        }
//
//        vector<vector<int>> result(m + 1, vector<int>(n + 1, 0));
//
//        for (int k = 0; k < strs.size(); k++) {
//            int nums0 = (int)count(strs[k].begin(), strs[k].end(), '0');
//            int nums1 = (int)strs[k].size() - nums0;
//
//            for (int i = m; i >= nums0 ; i--) {
//                for (int j = n; j >= nums1; j--) {
//                    result[i][j] = max(result[i][j], result[i - nums0][j - nums1] + 1);
//                }
//            }
//        }
//
//        return result[m][n];
//    }
//
//    void test() {
//        vector<string> strs = {"10","0001","111001","1","0"};
//        int result = findMaxForm(strs, 5, 3);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 518
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        //完全背包
//        //f(n)//0-n个硬币和为n的个数，f(n) = f(n) + f(n - coins[n]);
//
//        vector<int> result(amount + 1, 0);
//        result[0] = 1;
//
//        for (int i = 0; i < coins.size(); i++) {
//            for (int j = coins[i]; j <= amount ; j++) {
//                result[j] += result[j - coins[i]];
//            }
//        }
//
//        return result[amount];
//    }
//
//    void test() {
//        vector<int> conins = {1,2,5};
//        int result = change(5, conins);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 377
//class Solution {
//public:
//    int combinationSum4(vector<int>& nums, int target) {
//        //完全背包
//        //f(n)//0-n个数中和为n的个数,f(n) = f(n) + f(n - nums[n]);
//
//        vector<int> result(target + 1, 0);
//        result[0] = 1;
//
//        for (int j = 0; j <= target; j++) {
//            for (int i = 0; i < nums.size(); i++) {
//                if (j >= nums[i]) {
//                    if (INT_MAX - result[j - nums[i]] >= result[j]) {
//                        result[j] += result[j - nums[i]];
//                    }
//                }
//            }
//        }
//
//        return result[target];
//    }
//
//    void test() {
//        /**
//         []
//         999
//         */
////        vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
////
////        int result = combinationSum4(arr, 999);
//
//        vector<int> arr = {2};
//
//        int result = combinationSum4(arr, 5);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 322
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        //完全背包
//        //f(n)//0-n中和为n的最小数量，f(n) = min(f(n), f(n - coins[n]) + 1)
//
//        vector<int> result(amount + 1, INT_MAX);
//        result[0] = 0;
//
//        for (int i = 0; i < coins.size(); i++) {
//            for (int j = coins[i]; j <= amount ; j++) {
//                if (result[j - coins[i]] == INT_MAX) {
//                    result[j] = result[j];
//                }
//                else {
//                    result[j] = min(result[j], result[j - coins[i]] + 1);
//                }
//            }
//        }
//
//        return result[amount] == INT_MAX ? -1 : result[amount];
//    }
//
//    void test() {
//        vector<int> coins = {1,2,5};
//
//        int result = coinChange(coins,1);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 279
//class Solution {
//public:
//    int numSquares(int n) {
//        //转移方程：f(n) = min(f(n - i^2), f(n - (i + 1)^2).....f(1^2)) + 1
//
//        vector<int> result(n + 1, 9999);
//        result[0] = 0;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j * j <= i; j++) {
//                result[i] = min(result[i], result[i - j * j] + 1);
//            }
//        }
//
//        return result[n];
//    }
//
//    void test() {
//
//    }
//};

#pragma mark - 139
//class Solution {
//public:
//
//    bool wordBreak2(string s, vector<string>& wordDict) {
///*转换方程 f(n) = f(n - k) | f(n);
// f(n - k)在wordDict中
// */
//        if (s.size() == 0) {
//            return false;
//        }
//        vector<bool> result(s.size(), false);
//        for (int i = 0; i <= s.size(); i++) {
//            for (int j = 0; j < wordDict.size(); j++) {
//                string word = wordDict[j];
//                if (i + 1 >= word.size()) {
//                    if (s.substr(i + 1 - word.size(), word.size()) == word) {
//                        if (i < word.size()) {
//                            result[i] = true;
//                        }
//                        else {
//                            result[i] = result[i] || result[i - word.size()];
//                        }
//                    }
//                }
//            }
//        }
//        return result[s.size() - 1];
//    }
//    bool wordBreak(string s, vector<string>& wordDict) {
//        //f(n) 从0-n的字母能否用wordDict组成，f(n) = f(n) || (f(n - wordDict[n].Size()) && wordDict[i] == s[j-n, n]);
//
//        vector<bool> result(s.size() + 1, false);
//        result[0] = true;
//
//
//        for (int j = 0; j <= s.size(); j++) {
//            for (int i = 0; i < wordDict.size(); i++) {
//                if (j >= wordDict[i].size()) {
//                    string currentS = s.substr(j - wordDict[i].size(), wordDict[i].size());
//
//                    result[j] = result[j] || (result[j - wordDict[i].size()] && currentS == wordDict[i]);
//                }
//            }
//        }
//
//        return result[s.length()];
//    }
//
//    void test() {
//        vector<string> arr = {"apple", "pen"};
//        bool result = wordBreak("appleapenapple", arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 198
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        //f(n)//最大钱数 f(n) = max(f(n - 1), f(n - 2) + nums[n]);
//
//        //两个变量
//
//        if (nums.size() == 0) {
//            return 0;
//        }
//
//        if (nums.size() == 1) {
//            return nums[0];
//        }
//
//        if (nums.size() == 2) {
//            return max(nums[0], nums[1]);
//        }
//
//        vector<int> result(2);
//        result[0] = nums[0];
//        result[1] = max(nums[1], nums[0]);
//
//        for (int i = 2; i < nums.size(); i++) {
//            int temp = result[1];
//            result[1] = max(result[1], result[0] + nums[i]);
//            result[0] = temp;
//        }
//
//        return result[1];
//    }
//
//    void test() {
//        vector<int> arr = {2,1,1,2};
//
//        int result = rob(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 213
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        //如果偷第一个，最后一个就不能偷，如果偷最后一个，第一个就不能偷
//        //f(n) = max(f(n - 1), f(n - 2) + nums[n]);
//
//        if (nums.size() == 1) {
//            return nums[0];
//        }
//
//        int rob1 = robRange(nums, 0, (int)nums.size() - 2);
//        int rob2 = robRange(nums, 1, (int)nums.size() - 1);
//
//        return max(rob1, rob2);
//    }
//
//    int robRange(vector<int>& nums, int s, int e) {
//        if (s == e) {
//            return nums[s];
//        }
//
//        if (s == e - 1) {
//            return max(nums[s], nums[e]);
//        }
//
//        if (s > e) {
//            return -1;
//        }
//
//        vector<int> result(e + 1, 0);
//        result[s] = nums[s];
//        result[s + 1] = max(nums[s], nums[s + 1]);
//
//        for (int i = s + 2; i <= e; i++) {
//            result[i] = max(result[i - 1], result[i - 2] + nums[i]);
//        }
//
//        return result[e];
//    }
//
//    void test() {
//        vector<int> arr = {1,3,1,3,100};
//
//        int result = rob(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 337
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
//    int rob(TreeNode* root) {
//        vector<int> result = traveral(root);
//
//        return max(result[0], result[1]);
//    }
//
//    vector<int> traveral(TreeNode *root) {
//        if (root == nullptr) {
//            return {0,0};
//        }
//
//        vector<int> resultLeft = traveral(root->left);
//        vector<int> resultRight = traveral(root->right);
//
//        vector<int> result(2);
//        result[0] = root->val + resultLeft[1] + resultRight[1];
//        result[1] = max(resultLeft[0], resultLeft[1]) + max(resultRight[0], resultRight[1]);
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {4,1,-1,2,-1,3};
//        TreeNode *root = tool.createBT(arr);
//
//        int result = rob(root);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 121
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        //
//        int minVal = INT_MAX;
//        int result = 0;
//        for (int i = 0; i < prices.size(); i++) {
//            minVal = min(minVal, prices[i]);
//
//            result = max(result, prices[i] - minVal);
//        }
//
//        return result;
//    }
//
//    int maxProfit2(vector<int>& prices) {
//        //f(i,0)//i天买入现金，f(i,1)//i天卖出的现金
//        //f(i,0) = max(f(i - 1, 0)//上一天买入，-prices[i]//今天买入)
//        //f(i,1) = max(f(i - 1, 1)//上一天卖出，prices[i] + f(i - 1,0)//今天卖出)
//
//        vector<vector<int>> result(prices.size(), vector<int>(2,0));
//        result[0][0] = -prices[0];
//        result[0][1] = 0;
//
//        for (int i = 1; i < prices.size(); i++) {
//            result[i][0] = max(result[i - 1][0], -prices[i]);
//            result[i][1] = max(result[i - 1][1], prices[i] + result[i - 1][0]);
//        }
//
//        return result[prices.size() - 1][1];
//    }
//
//    int maxProfit3(vector<int>& prices) {
//        //f(i,0)//i天买入现金，f(i,1)//i天卖出的现金
//        //f(i,0) = max(f(i - 1, 0)//上一天买入，-prices[i]//今天买入)
//        //f(i,1) = max(f(i - 1, 1)//上一天卖出，prices[i] + f(i - 1,0)//今天卖出)
//
//
//        vector<vector<int>> result(2, vector<int>(2,0));
//        result[0][0] = -prices[0];
//        result[0][1] = 0;
//
//        for (int i = 1; i < prices.size(); i++) {
//
//            result[1][0] = max(result[0][0], -prices[i]);
//            result[1][1] = max(result[0][1], prices[i] + result[0][0]);
//
//            result[0] = result[1];
//        }
//
//        return result[1][1];
//    }
//
//    void test() {
//        vector<int> arr = {7,1,5,3,6,4};
//
//        int result = maxProfit3(arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 122
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //下跌到最低买，上涨到最高卖
        int result = 0;
        int minVal = -1;
        prices.push_back(0);
        for (int i = 0; i < prices.size() - 1; i++) {
            if (minVal == -1) {
                if (prices[i + 1] > prices[i]) {//开始上涨
                    minVal = prices[i];
                }
            }
            else {
                if (prices[i] > prices[i + 1]) {//开始下跌
                    result += prices[i] - minVal;
                    minVal = -1;
                }
            }
        }

        return result;
    }

    int maxProfit2(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }

//    int maxProfit3(vector<int>& prices) {
//        //f(i,j)
//    }

    void test() {
        vector<int> arr = {7,1,5,3,6,4};

        int result = maxProfit2(arr);

        cout<<result<<endl;
    }
};

#pragma mark - 698
//未完成
//class Solution {
//public:
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int sum = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            sum += nums[i];
//        }
//        if (sum % k != 0) {
//            return false;
//        }
//
//        int target = sum / k;
//        vector<int> used;
//        for (int j = 0; j < nums.size() && used.size() < nums.size(); j++) {
//            used.clear();
//            if (used.size() == 0) {
//                used.push_back(nums[i]);
//            }
//            for (int i = j; i < nums.size() && used.size() < nums.size(); i++) {
//
//                (backtrack(nums, target, nums[0], used) == false);
//            }
//
//            int f = 0;
//        }
//
//        return used.size() == nums.size();
//    }
//
//    bool backtrack(vector<int>& nums, int target, int sum, vector<int>& used) {
//        if (sum == target) {
//            return true;
//        }
//
//        if (target > 0 && sum > target) {
//            return false;
//        }
//
//        for (int i = 0; i < nums.size(); i++) {
//            bool isUsed = false;
//            for (int j = 0; j < used.size(); j++) {
//                if (i == used[j]) {
//                    isUsed = true;
//                    break;
//                }
//            }
//            if (isUsed) {
//                continue;
//            }
//            used.push_back(i);
//            bool isSuccess = backtrack(nums, target,sum + nums[i], used);
//            if (isSuccess == false) {
//                used.pop_back();
//            }
//            else{
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//
//
//    void test() {
//        vector<int> nums = {10,10,10,7,7,7,7,7,7,6,6,6};
//        bool result = canPartitionKSubsets(nums, 3);
//
//        cout<<result<<endl;
//    }
//};
#pragma mark - 473

int main(int argc, const char * argv[]) {
    // insert code here...

//    int i = -8;
//    i = i >> 5;
//    cout<<i<<endl;

    Solution solution;
    solution.test();
    cout<<"end"<<endl;

//    Sort sort;
//    sort.test();

//    LeaZcy zcy;
//    zcy.test();

//    LeaStt stt;
//    stt.test();

    return -1;
}
