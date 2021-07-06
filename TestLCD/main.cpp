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
//class Solution {
//public:
//    int maxFrequency(vector<int>& nums, int k) {
//
//        sort(nums.begin(), nums.end());
//
//        int maxCount = 1;
//        int tempK = k;
//        int currentCount = 1;
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums[i] == nums[i - 1]) {
//                currentCount++;
//            }
//            else {
//                maxCount = max(maxCount, currentCount);
//                currentCount = 1;
//                tempK = k;
//
//                for (int j = i - 1; j >= 0 && tempK > 0; j--) {
//                    tempK -= (nums[i] - nums[j]);
//                    if (tempK >= 0) {
//                        currentCount++;
//                    }
//                }
//            }
//        }
//
//        maxCount = max(maxCount, currentCount);
//
//        return maxCount;
//    }
//
//    int maxFrequency2(vector<int>& nums, int k) {
//
//        sort(nums.begin(), nums.end());
//
//        int result = 1;
//
//        int l = 0, r = 0;
//        long long sum = 0;
//        while (r < nums.size() - 1) {
//            r++;
//            sum += (long long)(r - l) * (nums[r] - nums[r - 1]);
//
//            while (sum > k) {
//                sum -= (nums[r] - nums[l]);
//                l++;
//            }
//
//            result = max(result, r - l + 1);
//        }
//
//        return result;
//    }
//
//    void test() {
//        /**
//         [100000]
//         100000
//         */
//        vector<int> nums = {100000};
//
//        int k = 100000;
//
//        int result = maxFrequency2(nums, k);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1684
//class Solution {
//public:
//    int countConsistentStrings(string allowed, vector<string>& words) {
//        unordered_set<char> set;
//        for (int i = 0; i < allowed.size(); i++) {
//            set.insert(allowed[i]);
//        }
//
//        int result = 0;
//        for (int i = 0; i < words.size(); i++) {
//            result++;
//            for (int j = 0; j < words[i].size(); j++) {
//                if (set.find(words[i][j]) == set.end()) {
//                    result--;
//                    break;
//                }
//            }
//        }
//
//        return result;
//    }
//
//    int countConsistentStrings2(string allowed, vector<string>& words) {
//        int result = 0;
//
//        for (int i = 0; i < words.size(); i++) {
//            result++;
//            for (int j = 0; j < words[i].size(); j++) {
//                if (allowed.find(words[i][j]) == allowed.npos) {
//                    result--;
//                    break;
//                }
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<string> words = {"cc","acd","b","ba","bac","bad","ac","d"};
//        string allowed = "cad";
//        int result = countConsistentStrings2(allowed, words);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1375
//class Solution {
//public:
//    int numTimesAllBlue(vector<int>& light) {
//        //f[i] i之前是不是都是蓝色
//
//        int result = 0;
//        vector<bool> vec(light.size() + 1, false);
//        vec[0] = true;
//        int lastPos = -1;
//        int lastBluePos = 0;
//
//        for (int i = 0; i < light.size(); i++) {
//            lastPos = max(light[i], lastPos);
//
//            vec[light[i]] = true;
//
//            for (int j = lastBluePos + 1; j <= lastPos; j++) {
//                if (vec[j] == true) {
//                    lastBluePos++;
//                }
//                else {
//                    break;
//                }
//            }
//
//
//            if (lastBluePos == lastPos) {
//                result++;
//            }
//        }
//
//        return result;
//    }
//
//    int numTimesAllBlue2(vector<int>& light) {
//        int result = 0;
//
//        int lastPos = -1;
//
//        for (int i = 0; i < light.size(); i++) {
//            lastPos = max(light[i], lastPos);
//
//            if (lastPos == i + 1) {
//                result++;
//            }
//        }
//
//        return result;
//    }
//
//
//    void test() {
//        vector<int> light = {2,1,4,3,6,5};
//
//        int result = numTimesAllBlue2(light);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 50
//class Solution {
//public:
////    double myPow(double x, int n) {
////        if (n == 0) {
////            return 1;
////        }
////
////        if (n < 0) {
////            return 1 / x * myPow(x, n + 1);
////        }
////        else {
////            return x * myPow(x, n - 1);
////        }
////    }
//
////    double myPow(double x, int n) {
////        if (n == 0) {
////            return 1;
////        }
////
////        double tempVal = x;
////
////        if (n < 0) {
////            tempVal = 1 / x;
////        }
////        else {
////            tempVal = x;
////        }
////
////        if (abs(n) % 2 == 1) {
////            return tempVal * myPow(x, n / 2) * myPow(x, n / 2);
////        }
////        else {
////            return myPow(x, n / 2) * myPow(x, n / 2);
////        }
////    }
//
////    double myPow(double x, int n) {
////        if (n == 0) {
////            return 1;
////        }
////
////        double tempVal = x;
////
////        if (n < 0) {
////            tempVal = 1 / x;
////        }
////        else {
////            tempVal = x;
////        }
////
////        double res = myPow(x, n / 2);
////
////        if (n % 2 == 0) {
////            return res * res;
////        }
////        else {
////            return tempVal * res * res;
////        }
////    }
//
//    double myPow(double x, int n) {
//        if (n == 0) {
//            return 1;
//        }
//
//        double res = 1;
//        int tempN = n;
//        while (tempN != 0) {
//            if (tempN % 2 != 0) {
//                res *= x;
//            }
//            x *= x;
//
//            tempN = tempN / 2;
//        }
//
//        if (n < 0) {
//            return 1 / res;
//        }
//        else {
//            return res;
//        }
//    }
//
//    void test() {
//        /**
//         2.10000
//         3
//         */
//        double result = myPow(2.10000, 3);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1249
//class Solution {
//public:
//    string minRemoveToMakeValid(string s) {
//        stack<int> stack;
//        unordered_set<int> set;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == ')') {
//                if (stack.size() != 0 && s[stack.top()] == '(') {
//                    stack.pop();
//                }
//                else {
//                    set.insert(i);
//                }
//            }
//            else if (s[i] == '(') {
//                stack.push(i);
//
//            }
//        }
//
//        while (stack.size() > 0) {
//            set.insert(stack.top());
//            stack.pop();
//        }
//
//        string result = "";
//        for (int i = 0; i < s.size(); i++) {
//            if (set.find(i) == set.end()) {
//                result.push_back(s[i]);
//            }
//        }
//
//        return result;
//    }
//
//    string minRemoveToMakeValid2(string s) {
//        stack<int> stack;
//        vector<bool> vec(s.size(), false);
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == ')') {
//                if (stack.size() != 0 && s[stack.top()] == '(') {
//                    vec[stack.top()] = false;
//                    stack.pop();
//                }
//                else {
//                    vec[i] = true;
//                }
//            }
//            else if (s[i] == '(') {
//                stack.push(i);
//                vec[i] = true;
//            }
//        }
//
//        string result = "";
//        for (int i = 0; i < s.size(); i++) {
//            if (vec[i] == false) {
//                result.push_back(s[i]);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        string result = minRemoveToMakeValid("(a(b(c)d)");
//
//        cout<<result<<endl;
//    }
//};
//
//class Solution {
//public:
//    bool validTicTacToe(vector<string>& board) {
//        int XCount = 0, OCount = 0;
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board[i].size(); j++) {
//                if (board[i][j] == 'O') {
//                    OCount++;
//                }
//
//                if (board[i][j] == 'X') {
//                    XCount++;
//                }
//            }
//        }
//
//        if (OCount > XCount) {
//            return false;
//        }
//
//        if (XCount > OCount + 1) {
//            return false;
//        }
//
//        for (int i = 0; i < board.size(); i++) {
//
//            string tempS = board[i];
//            if (checkIsVaild(tempS, XCount, OCount) == false) {
//                return false;
//            }
//
//            tempS = "";
//            for (int j = 0; j < board[i].size(); j++) {
//                tempS.push_back(board[j][i]);
//            }
//
//            if (checkIsVaild(tempS, XCount, OCount) == false) {
//                return false;
//            }
//
//            tempS = "";
//            if (i == 0) {
//                tempS.push_back(board[0][0]);
//                tempS.push_back(board[1][1]);
//                tempS.push_back(board[2][2]);
//                if (checkIsVaild(tempS, XCount, OCount) == false) {
//                    return false;
//                }
//            }
//
//            tempS = "";
//            if (i == 2) {
//                tempS.push_back(board[2][0]);
//                tempS.push_back(board[1][1]);
//                tempS.push_back(board[0][2]);
//
//                if (checkIsVaild(tempS, XCount, OCount) == false) {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }
//
//    bool checkIsVaild(string & s, int & XCount, int & OCount) {
//        if (s == "XXX") {
//            if (XCount != OCount + 1) {
//                return false;
//            }
//        }
//
//        if (s == "OOO") {
//            if (XCount != OCount) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        //["XXX","OOX","OOX"]
//        vector<string> board = {"XXX","OOX","OOX"};
//
//        bool result = validTicTacToe(board);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 650
//class Solution {
//public:
//    int minSteps(int n) {
//        if (n == 1) {
//            return 0;
//        }
//        if (n == 2) {
//            return 2;
//        }
//
//        for (int i = 2; i < n; i++) {
//            if (n % i == 0) {
//                return minSteps(n / i) + minSteps(i);
//            }
//        }
//
//        return n;
//    }
//
//    void test() {
//        int result = minSteps(27);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi0204
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode *minHead = new ListNode(0);
//        ListNode *maxHead = new ListNode(0);
//
//        ListNode *p = head, *pMin = minHead, *pMax = maxHead;
//        while (p != nullptr) {
//            if (p->val >= x) {
//                pMax->next = p;
//                p = p->next;
//                pMax = pMax->next;
//                pMax->next = nullptr;
//            }
//            else {
//                pMin->next = p;
//                p = p->next;
//                pMin = pMin->next;
//                pMin->next = nullptr;
//            }
//        }
//
//        pMin->next = maxHead->next;
//
//        return minHead->next;
//    }
//
//    void test() {
//        vector<int> arr = {3,5,8,5,10,2,1};
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = partition(head, 5);
//        tool.printList(result);
//    }
//};

#pragma mark - 457
//class Solution {
//public:
//    bool circularArrayLoop(vector<int>& nums) {
//
//        bool isZhengShu = false;
//        int start = 0;
//        int end = 0;
//        int markVal = 1001;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] <= 1000) {
//                isZhengShu = nums[i] > 0 ? true : false;
//                start = i;
//                markVal += i;
//
//                bool isFaild = false;
//                while (nums[start] <= 1000) {
//                    end = start;
//                    int jump = nums[start];
//                    nums[start] = markVal;
//                    int fromIndex = start;
//
//                    start = getJumpToIndex(fromIndex, jump, (int)nums.size());
//
//                    if (start == end) {//1个点循环
//                        isFaild = true;
//                        break;
//                    }
//
//                    if (nums[start] == markVal) {//循环并且是和本次遍历循环
//                        isFaild = false;
//                        break;
//                    }
//
//                    if (nums[start] > 1000 && nums[start] != markVal) {//进入之前的错误循环
//                        isFaild = true;
//                        break;;
//                    }
//
//                    if (isZhengShu != (nums[start] > 0)) {//存在正反数，前面的部分一定不是
//                        isFaild = true;
//                        break;
//                    }
//                }
//
//                if (isFaild == false) {
//                    return true;
//                }
//            }
//        }
//
//        return false;
//    }
//
//    int getJumpToIndex(int fromIndex, int jump, int size) {
//        int targetIndex = fromIndex + jump;
//
//        while (targetIndex >= size) {
//            targetIndex -= size;
//        }
//
//        while (targetIndex < 0) {
//            targetIndex += size;
//        }
//
//        return targetIndex;
//    }
//
//    void test() {
//        vector<int> arr = {-1,-1,-1};
//
//        bool result = circularArrayLoop(arr);
//
//        cout<<endl;
//        cout<<result<<endl;
//    }
//};

#pragma mark - jianzhi_15
//class Solution {
//public:
////    int hammingWeight(uint32_t n) {
////        int result = 0;
////        while (n > 0) {
////            if (n % 2 == 1) {
////                result++;
////            }
////            n /= 2;
////        }
////
////        return result;
////    }
//
//    int hammingWeight(uint32_t n) {
//        int result = 0;
//        while (n > 0) {
//            n &= (n - 1);
//            result++;
//        }
//
//        return result;
//    }
//
//    void test() {
//        int result = hammingWeight(4294967293);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1262
//class Solution {
//public:
//    int maxSumDivThree(vector<int>& nums) {
//        //f[i][n] 从0到i余数为n的最大值，n为0，1，2，
//        vector<vector<int>> result(nums.size(), vector<int>(3, 0));
//
//        result[0][nums[0] % 3] = nums[0];
//
//        for (int i = 1; i < nums.size(); i++) {
//            switch (nums[i] % 3) {
//                case 0: {
//                    result[i][0] = result[i - 1][0] + nums[i];
//                    if (result[i - 1][1] != 0) {
//                        result[i][1] = result[i - 1][1] + nums[i];
//                    }
//
//                    if (result[i - 1][2] != 0) {
//                        result[i][2] = result[i - 1][2] + nums[i];
//                    }
//                    break;
//                }
//                case 1:{
//                    result[i][0] = max(result[i - 1][0], result[i - 1][2] == 0 ? 0 : result[i - 1][2] + nums[i]);
//
//                    result[i][1] = max(result[i - 1][1], result[i - 1][0] + nums[i]);
//
//                    result[i][2] = max(result[i - 1][2], result[i - 1][1] == 0 ? 0 : result[i - 1][1] + nums[i]);
//
//                    break;
//                }
//                case 2:{
//                    result[i][0] = max(result[i - 1][0], result[i - 1][1] == 0 ? 0 : result[i - 1][1] + nums[i]);
//
//                    result[i][1] = max(result[i - 1][1], result[i - 1][2] == 0 ? 0 : result[i - 1][2] + nums[i]);
//
//                    result[i][2] = max(result[i - 1][2], result[i - 1][0] + nums[i]);
//                    break;
//                }
//            }
//        }
//
//        return result[nums.size() - 1][0];
//    }
//
//    void test() {
//        vector<int> nums = {3,6,5,1,8};
//        int result = maxSumDivThree(nums);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 698
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

//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//
//        if (sum % k != 0) {
//            return false;
//        }
//
//        int target = sum / k;
//
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); i++) {
//            map[nums[i]]++;
//        }
//
//        while (map.size() > 0) {
//
//            int a = map.begin()->first;
//            int b = target - a;
//
//            if (a == target) {
//                if (--map[a] == 0) {
//                    map.erase(a);
//                }
//            }
//            else {
//                if (map.count(b) == 0 || map.count(a) == 0) {
//                    return false;
//                }
//                else {
//                    if (--map[b] == 0) {
//                        map.erase(b);
//                    }
//                    if (--map[a] == 0) {
//                        map.erase(a);
//                    }
//                }
//            }
//        }
//
//        return true;
//    }
//
//    bool canPartitionKSubsets(vector<int>& nums, int k) {
//        int sum = accumulate(nums.begin(), nums.end(), 0);
//
//        if (sum % k != 0) {
//            return false;
//        }
//
//        sort(nums.begin(), nums.end(), [&](int a, int b){
//            return a > b;
//        });
//
//        int target = sum / k;
//
//        if (nums[0] > target) {
//            return false;
//        }
//
//
//        vector<bool> used(nums.size(), false);
//        int result = 0;
//        for (int j = 0; j < nums.size(); j++) {
//            if (j > 0 && nums[j] == nums[j - 1]) {
//                continue;
//            }
//
//            result = 0;
//            for (int i = j; i < nums.size(); i++) {
//                if (used[i] == true) {
//                    continue;
//                }
//                used[i] = true;
//                if (backtracking(nums, used, target - nums[i])) {
//                    result++;
//                }
//                else {
//                    used[i] = false;
//                }
//            }
//
//            bool isAllUsed = true;
//            for (auto u : used) {
//                if (u == false) {
//                    isAllUsed = false;
//                }
//                u = false;
//            }
//
//            if (result == k && isAllUsed) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//    bool backtracking(vector<int>& nums, vector<bool>& used, int target) {
//        if (target == 0) {
//            return true;
//        }
//
//        if (target < 0) {
//            return false;
//        }
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (used[i] == true) {
//                continue;
//            }
//
//            if (target >= nums[i]) {
//                used[i] = true;
//                if (backtracking(nums, used, target - nums[i])) {
//                    return true;
//                }
//                used[i] = false;
//                while (i > 0 && i < nums.size() && nums[i] == nums[i - 1]) {
//                    i++;
//                }
//            }
//        }
//
//        return false;
//    }
//
//
//
//    void test() {
//        /**
//
//         [4,4,6,2,3,8,10,2,10,7]
//         4
//
//         4, 3, 2, 3, 5, 2, 1
//         4
//
//         10,10,10,7,7,7,7,7,7,6,6,6
//         3
//
//         [1,1,1,1,2,2,2,2]
//         3
//
//         [85,35,40,64,86,45,63,16,5364,110,5653,97,95]
//         7
//         */
//        vector<int> nums = {10,10,10,7,7,7,7,7,7,6,6,6};
//        bool result = canPartitionKSubsets(nums, 3);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi_16.20
//class Solution {
//public:
////    vector<string> getValidT9Words(string num, vector<string>& words) {
////
////        vector<int> indexVec = {3,3,3,3,3,4,3,4};
////        unordered_map<char, char> map;
////        int index = 0;
////        for (char c = 'a'; c <= 'z'; c++) {
////            if (indexVec[index] > 0) {
////                map[c] = index + '2';
////                indexVec[index]--;
////            }
////            else {
////                index++;
////                c--;
////            }
////        }
////
////        vector<string> result;
////        for (int i = 0; i < words.size(); i++) {
////            string tempNums = "";
////            for (int j = 0; j < words[i].size(); j++) {
////                tempNums.push_back(map[words[i][j]]);
////            }
////
////            if (tempNums == num) {
////                result.push_back(words[i]);
////            }
////        }
////
////
////        return result;
////    }
//
////    vector<string> getValidT9Words(string num, vector<string>& words) {
////
//////        vector<int> indexVec = {3,3,3,3,3,4,3,4};
////        unordered_map<char, char> map;
//////        int index = 0;
//////        for (char c = 'a'; c <= 'z'; c++) {
//////            if (indexVec[index] > 0) {
//////                map[c] = index + '2';
//////                indexVec[index]--;
//////            }
//////            else {
//////                index++;
//////                c--;
//////            }
//////        }
////        map['a'] = '2';
////        map['b'] = '2';
////        map['c'] = '2';
////
////        map['d'] = '3';
////        map['e'] = '3';
////        map['f'] = '3';
////
////        map['g'] = '4';
////        map['h'] = '4';
////        map['i'] = '4';
////
////        map['j'] = '5';
////        map['k'] = '5';
////        map['l'] = '5';
////
////        map['m'] = '6';
////        map['n'] = '6';
////        map['o'] = '6';
////
////        map['p'] = '7';
////        map['q'] = '7';
////        map['r'] = '7';
////        map['s'] = '7';
////
////        map['t'] = '8';
////        map['u'] = '8';
////        map['v'] = '8';
////
////        map['w'] = '9';
////        map['x'] = '9';
////        map['y'] = '9';
////        map['z'] = '9';
////
////
////
////        vector<string> result;
////        for (int i = 0; i < words.size(); i++) {
////            string tempNums = "";
////            for (int j = 0; j < words[i].size(); j++) {
////                tempNums.push_back(map[words[i][j]]);
////            }
////
////            if (tempNums == num) {
////                result.push_back(words[i]);
////            }
////        }
////
////
////        return result;
////    }
//
//    vector<string> getValidT9Words(string num, vector<string>& words) {
//
//        vector<int> indexVec = {3,3,3,3,3,4,3,4};
//        unordered_map<char, char> map;
////        int index = 0;
////        for (char c = 'a'; c <= 'z'; c++) {
////            if (indexVec[index] > 0) {
////                map[c] = index + '2';
////                indexVec[index]--;
////            }
////            else {
////                index++;
////                c--;
////            }
////        }
//
//
//        vector<string> result;
//        for (int i = 0; i < words.size(); i++) {
//            string tempNums = "";
//            for (int j = 0; j < words[i].size(); j++) {
//                tempNums.push_back(map[words[i][j]]);
//            }
//
//            if (tempNums == num) {
//                result.push_back(words[i]);
//            }
//        }
//
//
//        return result;
//    }
//
//    void test() {
//        vector<string> words = {"a", "b", "c", "d"};
//        vector<string> result = getValidT9Words("2", words);
//
//        vector<string> :: iterator it = result.begin();
//        while (it != result.end()) {
//            cout<<*it<<",";
//            it++;
//        }
//        cout<<endl;
//    }
//};

#pragma mark - 621
//class Solution {
//public:
////    int leastInterval(vector<char>& tasks, int n) {
////        vector<vector<int>> arr(26, vector<int>(3, 0));
////        for (int i = 0; i < arr.size(); i++) {
////            arr[i][0] = i;
////        }
////
////        for (int i = 0; i < tasks.size(); i++) {
////            arr[tasks[i] - 'A'][1]++;
////        }
////
////        int time = 0;
////
////        while (1) {
////            bool isFind = false;
////            int emptyCount = 0;
////
////            sort(arr.begin(), arr.end(), [&](vector<int>& a, vector<int>& b){
////                return a[1] > b[1];
////            });
////
////            for (int i = 0; i < arr.size(); i++) {
////                if (arr[i][1] <= 0) {
////                    emptyCount++;
////                    continue;
////                }
////
////                if (arr[i][2] > 0) {
////                    arr[i][2]--;
////                    continue;
////                }
////
////                if (isFind == false) {
////                    arr[i][1]--;
////                    arr[i][2] = n;
////                    isFind = true;
//////                    cout<<char('A' + arr[i][0])<<"->";
////                }
////            }
////
////            if (emptyCount == arr.size()) {
////                break;
////            }
////
////            time++;
////
//////            if (isFind == false) {
//////                cout<<"WAIT"<<"->";
//////            }
////        }
////
////        return time;
////    }
//
//    int leastInterval(vector<char>& tasks, int n) {
//
//
////        typedef pair<char, int> TaskInfo;
////        auto cmp = [&](TaskInfo a, TaskInfo b) {
////            return a.second < b.second;
////        };
////
////        priority_queue<TaskInfo, vector<TaskInfo>, decltype(cmp)> queue(cmp);
////
//
//        priority_queue<int, vector<int>, less<int>> queue;
//        unordered_map<char, int> map;
//        for (int i = 0; i < tasks.size(); i++) {
//            map[tasks[i]]++;
//        }
////
//        for (auto pair : map) {
//            queue.push(pair.second);
//        }
//
//        vector<vector<int>> wait(26, vector<int>(2,0));
////
////
////        for (int i = 0; i < tasks.size(); i++) {
////            cout<<i<<endl;
////        }
////
////        vector<TaskInfo> arrWait(26, 0);
////
////        int time = 0;
////        while (queue.size() > 0) {
////            <#statements#>
////        }
////
////        return 0;
//    }
//
//    void test() {
//        /**
//         ["A","A","A","B","B","B"]
//         0
//
//         'A','A','A','A','A','A','B','C','D','E','F','G'
//         2
//
//         'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'
//         2
//         */
//        vector<char> tasks = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};
//
//        int result = leastInterval(tasks, 2);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1599
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if (boardingCost * 4 <= runningCost) {
            return -1;
        }
        int waitCount = customers[0];
        int time = 0;
        int resultTime = -1;
        int maxProfit = 0;
        int profit = 0;

        while (waitCount > 0 || time < customers.size()) {
            int playCount = min(4, waitCount);
            time++;
            profit += (playCount * boardingCost - runningCost);
            if (profit > maxProfit) {
                maxProfit = profit;
                resultTime = time;
            }
            waitCount -= playCount;
            if (time < customers.size()) {
                waitCount += customers[time];
            }
        }

        return resultTime;
    }

    void test() {
        /**
         [0,43,37,9,23,35,18,7,45,3,8,24,1,6,37,2,38,15,1,14,39,27,4,25,27,33,43,8,44,30,38,40,20,5,17,27,43,11,6,2,30,49,30,25,32,3,18,23,45,43,30,14,41,17,42,42,44,38,18,26,32,48,37,5,37,21,2,9,48,48,40,45,25,30,49,41,4,48,40,29,23,17,7,5,44,23,43,9,35,26,44,3,26,16,31,11,9,4,28,49,43,39,9,39,37,7,6,7,16,1,30,2,4,43,23,16,39,5,30,23,39,29,31,26,35,15,5,11,45,44,45,43,4,24,40,7,36,10,10,18,6,20,13,11,20,3,32,49,34,41,13,11,3,13,0,13,44,48,43,23,12,23,2]
         43
         54
         */
        vector<int> customers = {0,43,37,9,23,35,18,7,45,3,8,24,1,6,37,2,38,15,1,14,39,27,4,25,27,33,43,8,44,30,38,40,20,5,17,27,43,11,6,2,30,49,30,25,32,3,18,23,45,43,30,14,41,17,42,42,44,38,18,26,32,48,37,5,37,21,2,9,48,48,40,45,25,30,49,41,4,48,40,29,23,17,7,5,44,23,43,9,35,26,44,3,26,16,31,11,9,4,28,49,43,39,9,39,37,7,6,7,16,1,30,2,4,43,23,16,39,5,30,23,39,29,31,26,35,15,5,11,45,44,45,43,4,24,40,7,36,10,10,18,6,20,13,11,20,3,32,49,34,41,13,11,3,13,0,13,44,48,43,23,12,23,2};
        int result = minOperationsMaxProfit(customers, 43, 54);

        cout<<result<<endl;
    }
};

#pragma mark - 464


#pragma mark - 1206

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
