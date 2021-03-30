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
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //计数排序
        unordered_map<int, int> map;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            maxCount = max(map[nums[i]], maxCount);
        }

        vector<vector<int>> arrCount;
        arrCount.resize(maxCount + 1);
        unordered_map<int, int>::iterator it = map.begin();
        while (it != map.end()) {
            arrCount[it->second].push_back(it->first);
            it++;
        }

        vector<int> result;
        int num = 0;
        for (int i = (int)arrCount.size() - 1; i >= 0 && num < k; i--) {
            vector<int>::iterator it = arrCount[i].begin();
            while (it != arrCount[i].end() && num < k) {
                result.push_back(*it);
                it++;
                num++;
            }
        }

        return result;
    }

    vector<int> topKFrequent2(vector<int>& nums, int k) {
        //单调队列
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        deque<vector<vector<int>>> deque;
        unordered_map<int, int>::iterator it = map.begin();
        while (it != map.end()) {
//            dequeAddSomeone(deque, {{it->first}, {it->second}}, k);
            stack<vector<vector<int>>> stack;
            while (deque.empty() == false && deque.back()[1][0] < it->second) {//把小于当前值的都弹出，用stack存储
                stack.push(deque.back());
                deque.pop_back();
            }

            deque.push_back({{it->first}, {it->second}});

            while (stack.empty() == false && deque.size() < k) {//把stack存储的数据移动到deque中
                deque.push_back(stack.top());
                stack.pop();
            }


            it++;
        }
        vector<int> result;
        int num = 0;
        while (num < k && deque.empty() == false) {
            result.push_back(deque.front()[0][0]);
            num++;
            deque.pop_front();
        }

        return result;
    }

    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent3(vector<int>& nums, int k) {
        //优先队列
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }

    void test() {
        vector<int> nums = {1,1,1,2,2,3,4,4,4};
        vector<int> result = topKFrequent3(nums, 2);
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
