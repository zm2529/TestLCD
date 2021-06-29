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

#pragma mark - 9
//class Solution {
//public:
//    bool isPalindrome(int x) {
//
//        if (x < 0) {
//            return false;
//        }
//
//        if (x < 10) {
//            return true;
//        }
//        vector<int> arr;
//
//        int temp = x;
//        while (temp != 0) {
//            arr.push_back(temp % 10);
//            temp /= 10;
//        }
//
//        int l = 0, r = (int)arr.size() - 1;
//        while (l < r) {
//            if (arr[l++] != arr[r--]) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    bool isPalindrome2(int x) {
//
//        if (x < 0 || (x % 10 == 0 && x != 0)) {
//            return false;
//        }
//
//        if (x < 10) {
//            return true;
//        }
//
//        int rightX = 0;
//
//        while (x > rightX) {
//            rightX = rightX * 10 + x % 10;
//            x /= 10;
//
//            if (x == rightX || x / 10 == rightX) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//    void test() {
//        bool result = isPalindrome2(10);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 521
//class Solution {
//public:
//    int findLUSlength(string a, string b) {
//        if (a == b) {
//            return -1;
//        }
//        else {
//            return (int)max(a.size(), b.size());
//        }
//    }
//
//    void test() {
//        int result = findLUSlength("abc", "abcc");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 522
//class Solution {
//public:
//    int findLUSlength(vector<string>& strs) {
//        sort(strs.begin(), strs.end(), [](string a, string b){
//            if (a.size() == b.size()) {
//                return a < b;
//            }
//            return a.size() > b.size();
//        });
//
//        if (strs[0] != strs[1]) {
//            return (int)strs[0].size();
//        }
//
//        int maxLength = -1;
//        for (int i = 0; i < strs.size(); i++) {
//            bool isFind = true;
//            for (int j = 0; j < strs.size(); j++) {
//                if (i != j && isSubStr(strs[j], strs[i])) {
//                    isFind = false;
//                    break;
//                }
//            }
//
//            if (isFind) {
//                maxLength = max(maxLength, (int)strs[i].size());
//            }
//        }
//
//        return maxLength;
//    }
//
//    bool isSubStr(string bigStr, string smallStr) {
//        if (bigStr == smallStr) {
//            return true;
//        }
//
//        if (bigStr.size() < smallStr.size()) {
//            return false;
//        }
//
//        int b = 0, s = 0;
//
//        while (b < bigStr.size() && s < smallStr.size()) {
//            if (bigStr[b] == smallStr[s]) {
//                b++;
//                s++;
//            }
//            else {
//                b++;
//            }
//        }
//
//        return s == smallStr.size();
//    }
//
//    void test() {
//        vector<string> arr = {"a","b","c","d","e","f","a","b","c","d","e","f"};
//        int result = findLUSlength(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi_17.06.2
//class Solution {
//public:
//    int numberOf2sInRange(int n) {
//        int result = 0;
//        for (int i = 0; i <= n; i++) {
//            int m = i;
//            while (m > 0) {
//                if (m % 10 == 2) {
//                    result++;
//                }
//                m /= 10;
//            }
//        }
//
//        return result;
//    }
//
//    int numberOf2sInRange2(int n) {
//        //f[i] 数字i中2的个数， f[i] ==  f[i % div(位数)] if( i / div(位数) == 2 ) + 1;
//
//        int div = 10;
//        int result = 0;
//        unordered_map<int, int> map;
//        if (n >= 2) {
//            map[2] = 1;
//            result = 1;
//        }
//        int current = 0;
//        for (int i = 12; i <= n; i++) {
//            current = 0;
//            if (i % div == 0 && i / div == 10) {
//                div *= 10;
//            }
//
//            if (map.count(i % div) > 0) {
//                current = map[i % div];
//            }
//
//            if (i / div == 2) {
//                current++;
//            }
//
//            if (current > 0) {
//                map[i] = current;
//            }
//
//            result += current;
//        }
//
//        return result;
//    }
//
//
//    void test() {
//        int result = numberOf2sInRange2(222);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1456
//class Solution {
//public:
//    int maxVowels(string s, int k) {
//
//        if (s.size() < k) {
//            return 0;
//        }
//
//        int result = 0;
//
//        int l = 0, r = 0;
//        int currentCount = 0;
//        if (isVowels(s[0])) {
//            currentCount++;
//        }
//        while (r < s.size()) {
//            if (r - l + 1 < k) {
//                if (r + 1 < s.size() && isVowels(s[r + 1])) {
//                    currentCount++;
//                }
//                r++;
//            }
//            else {
//                result = max(result, currentCount);
//                if (isVowels(s[l])) {
//                    currentCount--;
//                }
//                l++;
//            }
//        }
//
//        return result;
//    }
//
//    bool isVowels(char c) {
//        if (c == 'a' ||
//            c == 'e' ||
//            c == 'i' ||
//            c == 'o' ||
//            c == 'u') {
//            return true;
//        }
//
//        return false;
//    }
//
//    void test() {
//        int result = maxVowels("tryhard", 4);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 808
//class Solution {
//public:
//    unordered_map<string, double> map;
//    double soupServings(int n) {
//        if (n >= 4000)
//        {
//            return 1.0;
//        }
//        return soup(n, n);
//    }
//
//    double soup(int a, int b) {
//        if (a <= 0) {
//            if (b <= 0) {
//                return 0.5;
//            }
//            return 1;
//        }
//
//        if (b <= 0) {
//            return 0;
//        }
//
//        string key = to_string(a) + "," + to_string(b);
//        if (map.find(key) != map.end()) {
//            return map[key];
//        }
//
//        double s1 = soup(a - 100, b);
//        double s2 = soup(a - 75, b - 25);
//        double s3 = soup(a - 50, b - 50);
//        double s4 = soup(a - 25, b - 75);
//
//        double result = (s1 + s2 + s3 + s4) / 4;
//        map[key] = result;
//        return result;
//    }
//
//    double soupServings2(int n) {
//        //f[i][j] = (f[i - 4][j] + f[i - 3][j - 1] + f[i - 2][j - 2] + f[i - 1][j - 3]) / 4;
//
//        int size = n / 25 + 1;
//        if (n % 25 > 0) {
//            size++;
//        }
//
//        vector<vector<double>> result(size, vector<double>(size, 0.0));
//        for (int j = 0; j < size; j++) {
//            result[0][j] = 1;
//        }
//        result[0][0] = 0.5;
//
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                if (i == 0 && j == 0) {
//                    result[i][j] = 0.5;
//                }
//                else if (i == 0) {
//                    result[i][j] = 1;
//                }
//                else if (j == 0) {
//                    result[i][j] = 0;
//                }
//                else {
//                    result[i][j] = (result[max(i - 4, 0)][j] +
//                                    result[max(i - 3, 0)][max(j - 1, 0)] +
//                                    result[max(i - 2, 0)][max(j - 2, 0)] +
//                                    result[max(i - 1, 0)][max(j - 3, 0)]) / 4;
//                }
//            }
//        }
//
//        return result[size - 1][size - 1];
//    }
//
//    void test() {
//        double result = soupServings2(850);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1446
//class Solution {
//public:
//    int maxPower(string s) {
//        int result = 0;
//        int currPower = 1;
//        for (int i = 1; i < s.size(); i++) {
//            if (s[i] == s[i - 1]) {
//                currPower++;
//            }
//            else {
//                result = max(currPower, result);
//                currPower = 1;
//            }
//        }
//        result = max(currPower, result);
//
//        return result;
//    }
//
//    void test() {
//        int result = maxPower("tourist");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1572
//class Solution {
//public:
//    int diagonalSum(vector<vector<int>>& mat) {
//        int result = 0;
//        int size = (int)mat.size();
//        for (int i = 0; i < mat.size(); i++) {
//            result += mat[i][i];
//            result += mat[i][size - i - 1];
//        }
//
//        if (size % 2 == 1) {
//            result -= mat[size / 2][size / 2];
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<vector<int>> arr = {
//            {5}
//        };
//        int result = diagonalSum(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1791
//class Solution {
//public:
//    int findCenter(vector<vector<int>>& edges) {
//        unordered_map<int, int> map;
//        for (int i = 0; i < edges.size(); i++) {
//            map[edges[i][0]]++;
//            if (map[edges[i][0]] > 1) {
//                return edges[i][0];
//            }
//            map[edges[i][1]]++;
//            if (map[edges[i][1]] > 1) {
//                return edges[i][1];
//            }
//        }
//
//        return 0;
//    }
//
//    int findCenter2(vector<vector<int>>& edges) {
//        int a = 0, b = 0;
//        for (int i = 0; i < 2; i++) {
//            if (a == edges[i][0] || a == edges[i][1]) {
//                return a;
//            }
//
//            if (b == edges[i][0] || b == edges[i][1]) {
//                return b;
//            }
//
//            a = edges[i][0];
//            b = edges[i][1];
//        }
//
//        return 0;
//    }
//
//};

#pragma mark - 168
//class Solution {
//public:
//    string convertToTitle(int columnNumber) {
//
//        string result = "";
//        int num = columnNumber;
//        while (num > 0) {
//            char c = getCharWithIndex(num % 26);
//            result.push_back(c);
//            num = num / 26 - (num % 26 == 0 ? 1 : 0);
//        }
//
//        reverse(result.begin(), result.end());
//
//        return result;
//    }
//
//    char getCharWithIndex(int index) {
//        if (index == 0) {
//            return 'Z';
//        }
//        return 'A' + index - 1;
//    }
//
//    void test() {
//        string result = convertToTitle(701);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 856
//class Solution {
//public:
//    int scoreOfParentheses(string s) {
//        typedef pair<int, char> IndexPair;
//        typedef pair<int, int> ScorePair;
//
//        stack<IndexPair> stackPair;
//        stack<ScorePair> stackScore;
//
//        vector<int> arrScore(s.size(), 0);
//
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == ')' && stackPair.size() > 0 && stackPair.top().second == '(') {
//                int sum = 0;
//                while (stackScore.size() > 0 && stackScore.top().first >= stackPair.top().first) {
//                    sum += stackScore.top().second;
//                    stackScore.pop();
//                }
//
//                stackScore.push(ScorePair(i, max(1, sum * 2)));
//                stackPair.pop();
//            }
//            else {
//                stackPair.push(IndexPair(i, s[i]));
//            }
//        }
//
//        int result = 0;
//        while (stackScore.size() > 0) {
//            result += stackScore.top().second;
//            stackScore.pop();
//        }
//        return result;
//    }
//
//    void test() {
//        int result = scoreOfParentheses("()()");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 999
//class Solution {
//public:
//    int numRookCaptures(vector<vector<char>>& board) {
//        pair<int, int> rook;
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[i].size(); j++) {
//                if (board[i][j] == 'R') {
//                    rook = pair<int, int>(i, j);
//                }
//            }
//        }
//
//        int result = 0;
//        for (int i = rook.first; i < board.size(); i++) {
//            if (board[i][rook.second] == 'p') {
//                result++;
//                break;
//            }
//            if (board[i][rook.second] == 'B') {
//                break;
//            }
//        }
//
//        for (int i = rook.first; i >= 0; i--) {
//            if (board[i][rook.second] == 'p') {
//                result++;
//                break;
//            }
//            if (board[i][rook.second] == 'B') {
//                break;
//            }
//        }
//
//        for (int j = rook.second; j >= 0; j--) {
//            if (board[rook.first][j] == 'p') {
//                result++;
//                break;
//            }
//            if (board[rook.first][j] == 'B') {
//                break;
//            }
//        }
//
//        for (int j = rook.second; j < board[0].size(); j++) {
//            if (board[rook.first][j] == 'p') {
//                result++;
//                break;
//            }
//            if (board[rook.first][j] == 'B') {
//                break;
//            }
//        }
//
//        return result;
//    }
//};

#pragma mark - 1399
//class Solution {
//public:
//    int countLargestGroup(int n) {
////        vector<vector<int>> arrVal(37,vector<int>(0, 0));
//        vector<int> arr(37, 0);
//
//        int index = 1;
//        for (int i = 1; i <= n; i++) {
//
//            if (i % 10 == 0) {
//                index = getSum(i);
//            }
//
//            arr[index]++;
////            arrVal[index].push_back(i);
//            index++;
//        }
//
//        int result = 0;
//        int maxCount = 0;
//        for (int i = 0; i < arr.size(); i++) {
//            if (maxCount  < arr[i]) {
//                maxCount = arr[i];
//                result = 1;
//            }
//            else if (maxCount == arr[i]) {
//                result++;
//            }
//        }
//
////        tool.printMatrix(arrVal);
////
////        cout<<maxCount<<endl;
//
//        return result;
//    }
//
//    int getSum(int val){
//        int sum = 0;
//        while (val > 0) {
//            sum += val % 10;
//            val = val / 10;
//        }
//
//        return sum;
//    }
//
//    void test() {
//        int result = countLargestGroup(10000);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1342
//class Solution {
//public:
//    int numberOfSteps(int num) {
//        if (num == 0) {
//            return 0;
//        }
//
//        if (num == 1) {
//            return 1;
//        }
//
//        if (num % 2 == 1) {
//            return 2 + numberOfSteps(num / 2);
//        }
//        return 1 + numberOfSteps(num / 2);
//    }
//
//    void test() {
//        int result = numberOfSteps(123);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1295
//class Solution {
//public:
//    int findNumbers(vector<int>& nums) {
//        int result = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            int temp = nums[i];
//            while (temp / 10 > 0) {
//                temp = temp / 100;
//                if (temp == 0) {
//                    result++;
//                    break;
//                }
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> nums = {12,345111,2,6,7896};
//        int result = findNumbers(nums);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1646
//class Solution {
//public:
//    int getMaximumGenerated(int n) {
//        if (n <= 1) {
//            return n;
//        }
//
//        vector<int> arr(n + 1, 0);
//        arr[0] = 0;
//        arr[1] = 1;
//
//        int result = 1;
//
//        for (int i = 2; i <= n; i++) {
//            if (i % 2 == 0) {
//                arr[i] = arr[i / 2];
//            }
//            else {
//                arr[i] = arr[i / 2] + arr[i / 2 + 1];
//            }
//
//            result = max(result, arr[i]);
//        }
//
//        return result;
//    }
//
//    void test() {
//        int result = getMaximumGenerated(7);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 934
//class Solution {
//public:
//    typedef pair<int, int> point;
//    deque<point> deque;
//    vector<int> dx = {-1, 0, 1, 0};
//    vector<int> dy = {0, -1, 0, 1};
//    int shortestBridge(vector<vector<int>>& grid) {
//        int result = 0;
//        //
//        bool findAIsland = false;
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[i].size(); j++) {
//                if (grid[i][j] == 1) {
//                    backtracking(grid, i, j);
//                    findAIsland = true;
//                }
//
//                if (findAIsland) {
//                    break;
//                }
//            }
//
//            if (findAIsland) {
//                break;
//            }
//        }
//
//        while (deque.size() != 0) {
//            int size = (int)deque.size();
//            for (int i = 0; i < size; i++) {
//                point p = deque.front();
//                deque.pop_front();
//
//                int a = p.first;
//                int b = p.second;
//
//                for (int k = 0 ; k < 4; k++) {
//
//                    switch (checkIsSea(grid, a + dx[k], b + dy[k])) {
//                        case 1:
//                            return result;
//                        case 0:
//                            deque.push_back(point(a + dx[k], b + dy[k]));
//                    } ;
//
//                }
//            }
//
//            result++;
//        }
//
//        return result;
//    }
//
//    int checkIsSea(vector<vector<int>>& grid, int i, int j) {
//        if (i < 0 || i >= grid.size() ||
//            j < 0 || j >= grid[0].size()) {
//            return 2;
//        }
//
//        if (grid[i][j] == 2) {
//            return 2;
//        }
//
//        if (grid[i][j] == 0 ) {
//            grid[i][j] = 2;
//            return 0;
//        }
//
//        if (grid[i][j] == 1) {
//            return 1;
//        }
//
//        return 2;
//    }
//
//    bool backtracking(vector<vector<int>>& grid, int i, int j) {
//        if (i < 0 || i >= grid.size() ||
//            j < 0 || j >= grid[0].size()) {
//            return false;
//        }
//
//        if (grid[i][j] == 0 ) {
//            return true;
//        }
//
//        if (grid[i][j] == 2) {
//            return false;
//        }
//
//        grid[i][j] = 2;
//        bool top = backtracking(grid, i - 1, j);//top
//        bool left = backtracking(grid, i, j - 1);//left
//        bool bottom = backtracking(grid, i + 1, j);//bottom
//        bool right = backtracking(grid, i, j + 1);//right;
//
//        if (top || left || bottom || right) {
//            deque.push_back(point(i,j));
//        }
//
//        return false;
//    }
//
//    void test() {
////        vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
//
//        vector<vector<int>> grid = {{0,1}, {1,0}};
//
//        tool.printMatrix(grid);
//
//        int result = shortestBridge(grid);
//
//        tool.printMatrix(grid);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 368
//class Solution {
//public:
//    vector<int> largestDivisibleSubset(vector<int>& nums) {
//
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> dp(nums.size(), vector<int>(0));
//
//        vector<int> result;
//        for (int i = 0; i < nums.size(); i++) {
//            dp[i].push_back(nums[i]);
//            vector<int> temp;
//            for (int j = i - 1; j >= 0; j--) {
//                if (nums[i] % nums[j] == 0) {
//                    if (temp.size() < dp[j].size()) {
//                        temp = dp[j];
//                    }
//                }
//            }
//
//            if (temp.size() > 0) {
//                dp[i].insert(dp[i].end(), temp.begin(), temp.end());
//            }
//
//            if (result.size() < dp[i].size()) {
//                result = dp[i];
//            }
//        }
//
//        return result;
//    }
//
//    vector<int> largestDivisibleSubset2(vector<int>& nums) {
//
//        sort(nums.begin(), nums.end());
//
//        vector<int> dp(nums.size());
//
//        int maxCount = 0;
//        int lastVal = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            int temp = 0;
//            for (int j = i - 1; j >= 0; j--) {
//                if (nums[i] % nums[j] == 0) {
//                    if (temp < dp[j]) {
//                        temp = dp[j];
//                    }
//                }
//            }
//            dp[i] = temp + 1;
//            if (maxCount < dp[i]) {
//                maxCount = dp[i];
//                lastVal = nums[i];
//            }
//        }
//
//        vector<int> result;
//        for (int i = (int)dp.size() - 1; i >= 0 && maxCount >= 0; i--) {
//            if (maxCount == dp[i] && lastVal % nums[i] == 0) {
//                result.push_back(nums[i]);
//                lastVal = nums[i];
//                maxCount--;
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        //[4,8,10,240]
//        vector<int> nums = {4,8,10,240};
//
//        vector<int> result = largestDivisibleSubset2(nums);
//
//        tool.printVector(result);
//    }
//};

#pragma mark - 740
//class Solution {
//public:
//    int deleteAndEarn(vector<int>& nums) {
//        //dp[i] 0-i删除i赚的最多的分数，nums[i] * count + max(dp[0]..dp[i - 2])
//
//        sort(nums.begin(), nums.end());
//        vector<int> dp(nums.size(), 0);
//
//        int lastMaxEarn = 0;
//        int maxEarn = 0;
//        int maxIndex = 0;
//
//        for (int i = 0; i < nums.size(); i++) {
//            dp[i] = nums[i];
//
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                dp[i] += dp[i - 1];
//            }
//            else {
//
//                if (nums[maxIndex] != nums[i] - 1) {//如果最大值不是数值差一的直接使用
//                    dp[i] += maxEarn;
//                }
//                else {//否则只用上一次的最大值
//                    dp[i] += lastMaxEarn;
//                }
//
//                //更新上一次最大值
//                lastMaxEarn = maxEarn;
//            }
//
//            if (maxEarn < dp[i]) {
//                maxEarn = dp[i];
//                maxIndex = i;
//            }
//        }
//
//        return maxEarn;
//    }
//
//    void test() {
//        //[1,1,1,2,4,5,5,5,6]
//        vector<int> nums = {3,4,2};
//
//        int result = deleteAndEarn(nums);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1838
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int maxCount = 1;
        int tempK = k;
        int currentCount = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                currentCount++;
            }
            else {
                maxCount = max(maxCount, currentCount);
                currentCount = 1;
                tempK = k;

                for (int j = i - 1; j >= 0 && tempK > 0; j--) {
                    tempK -= (nums[i] - nums[j]);
                    if (tempK >= 0) {
                        currentCount++;
                    }
                }
            }
        }

        maxCount = max(maxCount, currentCount);

        return maxCount;
    }

    int maxFrequency2(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int result = 1;

        int l = 0, r = 0;
        long long sum = 0;
        while (r < nums.size() - 1) {
            r++;
            sum += (long long)(r - l) * (nums[r] - nums[r - 1]);

            while (sum > k) {
                sum -= (nums[r] - nums[l]);
                l++;
            }

            result = max(result, r - l + 1);
        }

        return result;
    }

    void test() {
        /**
         [100000]
         100000
         */
        vector<int> nums = {100000};

        int k = 100000;

        int result = maxFrequency2(nums, k);

        cout<<result<<endl;
    }
};

#pragma mark - 464


#pragma mark - 1206

#pragma mark - 698
//未完成
//
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
