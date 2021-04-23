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

#pragma mark - 704
//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        for (int i = 0; i < nums.size(); i++) {
//            if (target == nums[i]) {
//                return i;
//            }
//        }
//
//        return -1;
//    }
//
//    int search2(vector<int>& nums, int target) {
//        //2分
//        int l = 0, r = (int)nums.size() - 1;
//        while (l <= r) {
//            int m = ((r - l) >> 1) + l;
//            if (nums[m] == target) {
//                return m;
//            }
//
//            if (nums[m] > target) {
//                r = m - 1;
//            }
//            else {
//                l = m + 1;
//            }
//        }
//
//        return -1;
//    }
//
//    void test() {
//        vector<int> arr = {-1,0,3,5,9,12};
//
//        int result = search2(arr, 12);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 367
//class Solution {
//public:
//    bool isPerfectSquare(int num) {
//
//        int l = 0, r = num;
//        long m = 0;
//        while (l <= r) {
//            m = ((r - l) >> 1) + l;
//            if (m * m == num) {
//                return true;
//            }
//
//            if (m * m > num) {
//                r = (int)m - 1;
//            }
//            else {
//                l = (int)m + 1;
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        bool result = isPerfectSquare(2147483647);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 283
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                nums[curr] = nums[i];
                curr++;
            }
        }

        for (int i = curr; i < nums.size(); i++) {
            nums[i] = 0;
        }

    }

    void test() {
        vector<int> arr = {1,0};

        moveZeroes(arr);

        tool.printVector(arr);
    }
};


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
