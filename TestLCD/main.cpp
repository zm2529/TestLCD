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
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //能赚钱才买，卖出后今后还能赚钱就卖
        
        //记录每个位置后面时间的最高价
        vector<int> maxPricesVec(prices);
        //记录每个位置后面时间的最低价
        vector<int> minPricesVec(prices);
        for (int i = (int)prices.size() - 2; i >= 0; i--) {
            maxPricesVec[i] = max(prices[i], maxPricesVec[i + 1]);
            minPricesVec[i] = min(prices[i], minPricesVec[i + 1]);
        }
                
        int inPos = -1;
        int outPos = -1;
        int count = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (inPos == -1) {//未买入
                if (prices[i] + fee < maxPricesVec[i]) {//今日买，今后能赚钱，买入
                    inPos = i;
                }
            }
            else {
                if (outPos == -1) {//已买入，未卖出
                    if (prices[i] < maxPricesVec[i] && prices[i] > minPricesVec[i] + fee) {//当前价格小于今后最高价，今后最低价加手续费低于今日值，卖出
                        outPos = i;
                        count += prices[outPos] - prices[inPos] - fee;
                        inPos = -1;
                        outPos = -1;
                        continue;
                    }
                    
                    if (prices[i] == maxPricesVec[i]) {//当前价格已经是今后的最高价,卖出
                        outPos = i;
                        count += prices[outPos] - prices[inPos] - fee;
                        inPos = -1;
                        outPos = -1;
                        continue;
                    }
                    
                }
            }
        }
        
        return count;
    }
    
    void test() {
        vector<int> arr = {1,3,2,8,4,9};
        
        int result = maxProfit(arr, 2);
        
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
