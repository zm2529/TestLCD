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


#pragma mark - 844
//class Solution {
//public:
//    bool backspaceCompare(string s, string t) {
//
//        int sCount = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != '#') {
//                s[sCount++] = s[i];
//            }
//            else{
//                sCount = max(sCount - 1, 0);
//            }
//        }
//
//        int tCount = 0;
//        for (int i = 0; i < t.size(); i++) {
//            if (t[i] != '#') {
//                t[tCount++] = t[i];
//            }
//            else {
//                tCount = max(tCount - 1, 0);
//            }
//        }
//
//        if (sCount != tCount) {
//            return false;
//        }
//
//        while (sCount > 0) {
//            if (s[--sCount] != t[--tCount]) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    bool backspaceCompare2(string s, string t) {
//
//        int sR = (int)s.size() - 1, tR = (int)t.size() - 1;
//        while (sR >= 0 || tR >= 0) {
//            int sBackspaceCount = 0;
//            while (sR >= 0) {
//                if (s[sR] == '#') {
//                    sR--;
//                    sBackspaceCount++;
//                }
//                else {
//                    if (sBackspaceCount == 0) {
//                        break;
//                    }
//                    sR--;
//                    sBackspaceCount--;
//                }
//            }
//
//            int tBackspaceCount = 0;
//            while (tR >= 0) {
//                if (t[tR] == '#') {
//                    tR--;
//                    tBackspaceCount++;
//                }
//                else {
//                    if (tBackspaceCount == 0) {
//                        break;
//                    }
//                    tR--;
//                    tBackspaceCount--;
//                }
//            }
//
//            if (sR < 0 || tR < 0) {
//                if (sR != tR) {
//                    return false;
//                }
//                else{
//                    return true;
//                }
//            }
//
//            if (s[sR--] != t[tR--]) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        bool result2 = backspaceCompare("####aab##", "ac#d#");
//
//        cout<<result2<<endl;
//
//        bool result = backspaceCompare2("####aab##", "ac#d#");
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 977
//class Solution {
//public:
//    vector<int> sortedSquares(vector<int>& nums) {
//        stack<int> st;
//        int curr = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            int square = nums[i] * nums[i];
//            if (nums[i] < 0) {
//                st.push(square);
//            }
//            else {
//                while (st.size() > 0) {
//                    int top = st.top();
//                    if (top > square) {
//                        nums[curr++] = square;
//                        break;
//                    }
//                    else{
//                        nums[curr++] = top;
//                        st.pop();
//                    }
//                }
//
//                if (st.size() == 0) {
//                    nums[curr++] = square;
//                }
//            }
//        }
//
//        while (st.size() > 0) {
//            nums[curr++] = st.top();
//            st.pop();
//        }
//
//        return nums;
//    }
//
//    vector<int> sortedSquares2(vector<int>& nums) {
//        vector<int> result(nums.size());
//        int l = 0, r = (int)nums.size() - 1;
//        int curr = r;
//        while (l <= r) {
//            if (abs(nums[l]) > abs(nums[r])) {
//                result[curr--] = nums[l] * nums[l];
//                l++;
//            }
//            else {
//                result[curr--] = nums[r] * nums[r];
//                r--;
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {-7, - 3, 2, 3, 11};
//
//        vector<int> result = sortedSquares2(arr);
//
//        tool.printVector(result);
//    }
//};

#pragma mark - 209
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int l = 0, r = 0;
//        int count = 0;
//        int minLength = (int)nums.size() + 1;
//        while (l < nums.size() && r <= nums.size()) {
//            if (count >= target) {
//                minLength = min(r - l, minLength);
//                if (minLength == 1) {
//                    return 1;
//                }
//                count -= nums[l];
//                l++;
//            }
//            else {
//                if (r >= nums.size()) {
//                    break;
//                }
//                count += nums[r];
//                r++;
//            }
//        }
//
//        return minLength == nums.size() + 1 ? 0 : minLength;
//    }
//
//    int minSubArrayLen2(int target, vector<int>& nums) {
//        //O(nlongn)
//        //前序和 二分
//        int minLenght = (int)nums.size() + 1;
//
//        if (nums[0] >= target) {
//            return 1;
//        }
//
//        for (int i = 1; i < nums.size(); i++) {
//            nums[i] = nums[i - 1] + nums[i];//前序和
//
//            if (nums[i] >= target) {//前序和大于target，计算最小值
//                minLenght = min(i + 1, minLenght);
//
//                if (nums[i] - nums[0] >= target) {//前序和去除第一个大于target，所有0-i中有k,k>0,k-i>=tagert,二分找k，
//                    int l = 0, r = i;
//                    int m = 0;
//
//                    while (l <= r) {
//                        m = ((r - l) >> 1) + l;
//                        if (nums[i] - nums[m] >= target ) {//m-i>=target,计算最小值
//                            minLenght = min(i - m, minLenght);
//                            l = m + 1;
//                        }
//                        else {
//                            r = m - 1;
//                        }
//                    }
//                }
//
//                if (minLenght == 1) {
//                    return 1;
//                }
//            }
//        }
//
//        return minLenght == nums.size() + 1 ? 0 : minLenght;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,4,5};
//
//        int target = 15;
//
//        int result = minSubArrayLen(target, arr);
//        cout<<result<<endl;
//
//        int result2 = minSubArrayLen2(target, arr);
//        cout<<result2<<endl;
//    }
//};

#pragma mark - 904
//class Solution {
//public:
//    int totalFruit(vector<int>& tree) {
//        if (tree.size() <= 2) {
//            return (int)tree.size();
//        }
//
//        vector<int> arrCount(tree.size());
//
//        vector<vector<int>> basket(2, vector<int>(2, 0));
//        basket[0][0] = tree[0];
//
//        int maxCount = 0;
//        for (int i = 0; i < tree.size(); i++) {
//            if (i > 0 && tree[i - 1] == tree[i]) {
//                arrCount[i] = arrCount[i - 1] + 1;
//            }
//            else {
//                arrCount[i] = 1;
//            }
//
//            if (basket[0][0] == tree[i]) {//和第一个篮子一样，放入第一个篮子
//                basket[0][1]++;
//            }
//            else if (basket[1][0] == tree[i]) {//和第二个篮子一样，放入第二个篮子
//                basket[1][1]++;
//            }
//            else {//两个篮子都不一样，剔除第一个篮子
//                basket[0][0] = tree[i - 1];
//                basket[0][1] = arrCount[i - 1];
//
//                basket[1][0] = tree[i];
//                basket[1][1] = 1;
//            }
//            maxCount = max(basket[0][1] + basket[1][1], maxCount);
//        }
//
//        return maxCount;
//    }
//
//    int totalFruit2(vector<int>& tree) {
//        unordered_map<int, int> map;
//
//        int maxLength = 0;
//
//        int l = 0, r = 0;
//        while (r < tree.size()) {
//            map[tree[r++]]++;
//            while (map.size() > 2) {
//                map[tree[l]]--;
//                if (map[tree[l]] <= 0) {
//                    map.erase(tree[l]);
//                }
//                l++;
//            }
//            maxLength = max(maxLength, r - l);
//        }
//
//        return maxLength;
//    }
//
//    void test() {
//        vector<int> arr = {1,0};
//
//        int result = totalFruit(arr);
//
//        cout<<result<<endl;
//
//        int result2 = totalFruit2(arr);
//
//        cout<<result2<<endl;
//    }
//};

#pragma mark - 992
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        //双指针
        
        unordered_map<int, int> map;
        
        int l = 0, r = 0;
        int count = 0;
        
        while (r < A.size()) {
            if (map.size() <= K) {//小于等于K个数，往后加一个数
                map[A[r++]]++;
            }
                        
            while (map.size() > K) {//大于K个数，从前往后删除
                map[A[l]]--;
                if (map[A[l]] <= 0) {
                    map.erase(A[l]);
                }
                l++;
            }
            
            if (map.size() == K) {//等于K个数，尝试从前往后删除数，是否还符合条件，
                count++;
                int tempL = l;
                unordered_map<int, int> tempMap = map;
                while (r - tempL > 1) {
                    tempMap[A[tempL]]--;
                    if (tempMap[A[tempL]] > 0) {
                        count++;
                        tempL++;
                    }
                    else{
                        break;
                    }
                }
            }

        }
        
        return count;
    }
    
    void test() {
        vector<int> A = {1,2,1,2,3};
        
        int K = 2;
        
        int result = subarraysWithKDistinct(A, K);
        
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
