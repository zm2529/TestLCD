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
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //记录从每站离开时剩余的油量
        int oweGas = 0;
        int pos = -1;
        for (int i = 0; i < gas.size(); i++) {
            int balance = gas[i] - cost[i];
            oweGas += balance;
            if (gas[i] - cost[i] >= 0) {
                if (pos == -1) {
                    pos = i;
                }
            }
            else {
                if (oweGas < 0) {
                    pos = -1;
                }
            }
        }

        if (oweGas >= 0) {
            return pos;
        }
        else {
            return - 1;
        }
    }

    void test() {
        vector<int> gas = {3,1,1};
        vector<int> cost = {1,2,2};
        int result = canCompleteCircuit(gas, cost);

        cout<<result<<endl;
    }
};

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
