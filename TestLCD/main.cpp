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

#include "Tools.hpp"
#include "Sort.hpp"
#include "LeaZCY.hpp"
#include "LeaSTT.hpp"

using namespace std;

Tool tool;

#define string(x) #x

#pragma mark - 1
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> result;
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (nums[i] + nums[j] == target) {
//                    result = {i, j};
//                    return result;
//                }
//            }
//        }
//        return result;
//    }
//
//    vector<int> twoSum2(vector<int>& nums, int target) {
//        if (nums.size() < 2) {
//            return {};
//        }
//        //双指针
//        vector<int> temp(nums);
//        vector<int> result;
//        sort(nums.begin(), nums.end());
//        int l = 0, r = (int)nums.size() - 1;
//        while (l < r) {
//            if (nums[l] + nums[r] == target) {
//                for (int i = 0; i < temp.size(); i++) {
//                    if (temp[i] == nums[l] || temp[i] == nums[r]) {
//                        result.push_back(i);
//                        if (result.size() == 2) {
//                            return result;
//                        }
//                    }
//                }
//            }
//            else if (nums[l] + nums[r] < target) {
//                l++;
//            }
//            else {
//                r--;
//            }
//        }
//
//        return {};
//    }
//
//    vector<int> twoSum3(vector<int>& nums, int target) {
//        //map
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); i++) {
//            map[nums[i]] = i;
//        }
//
//        for (int i = 0; i < nums.size(); i++) {
//            int temp = target - nums[i];
//            if (map.count(temp) != 0) {
//                if (map[temp] != i) {
//                    return {map[temp] , i};
//                }
//            }
//        }
//
//        return {};
//    }
//    void test(){
//        vector<int> nums = {3,2,4};
//        vector<int> vec = twoSum3(nums, 5);
//
//        tool.printVector(vec);
//    }
//};
#pragma mark - 2
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//class Solution {
//public:
////    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2){
////        ListNode *rl1 = reverseList(l1);
////        ListNode *rl2 = reverseList(l2);
////        ListNode *result = NULL;
////        int a = 0;
////        while (rl1 != NULL || rl2 != NULL) {
////            int num1 = 0;
////            if (rl1 != NULL) {
////                num1 = rl1->val;
////                rl1 = rl1->next;
////            }
////            int num2 = 0;
////            if (rl2 != NULL) {
////                num2 = rl2->val;
////                rl2 = rl2->next;
////            }
////
////            int sum = num1 + num2 + a;
////            if (sum >= 10) {
////                sum -= 10;
////                a = 1;
////            }
////            else{
////                a = 0;
////            }
////            cout<<sum<<endl;
////            result = new ListNode(sum, result);
////            if (rl1 == NULL && rl2 == NULL && a == 1) {
////                result = new ListNode(1, result);
////            }
////        }
////        return reverseList(result);
////    }
////    ListNode* reverseList(ListNode *list){
////        ListNode *reverseList = NULL;
////        ListNode *p = list;
////        while (p != NULL) {
////            ListNode *temp = p -> next;
////            p->next = reverseList;
////            reverseList = p;
////            p = temp;
////        }
////        return reverseList;
////    }
////    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
////        vector<int> v1, v2;
////        while (l1 != nullptr) {
////            v1.push_back(l1->val);
////            l1 = l1->next;
////        }
////
////        while (l2 != nullptr) {
////            v2.push_back(l2->val);
////            l2 = l2->next;
////        }
////
////        int a = 0;
////        ListNode *result = NULL;
////
////        while (v1.size() > 0 || v2.size() > 0) {
////            int num1 = 0;
////            if (v1.size() > 0) {
////                num1 = v1.at(v1.size() - 1);
////                v1.pop_back();
////            }
////            int num2 = 0;
////            if (v2.size() > 0) {
////                num2 = v2.at(v2.size() - 1);
////                v2.pop_back();
////            }
////            int sum = num1 + num2 + a;
////            if (sum >= 10) {
////                sum -= 10;
////                a = 1;
////            }
////            else{
////                a = 0;
////            }
////            cout<<sum<<endl;
////            result = new ListNode(sum, result);
////            if (v1.size() == 0 && v2.size() == 0 && a == 1) {
////                result = new ListNode(1, result);
////            }
////        }
////
////        return result;
////    }
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
//        ListNode *result = NULL;
//        ListNode *p = NULL;
//        int a = 0;
//        while (l1 != NULL || l2 != NULL) {
//            int num1 = 0;
//            if (l1 != NULL) {
//                num1 = l1->val;
//                l1 = l1->next;
//            }
//            int num2 = 0;
//            if (l2 != NULL) {
//                num2 = l2->val;
//                l2 = l2->next;
//            }
//
//            int sum = num1 + num2 + a;
//            if (sum >= 10) {
//                sum -= 10;
//                a = 1;
//            }
//            else{
//                a = 0;
//            }
//
//            ListNode *node = new ListNode(sum);
//            if (result == NULL) {
//                result = node;
//                p = result;
//            }
//            else {
//                p->next = node;
//                p = node;
//            }
//
//            if (l1 == NULL && l2 == NULL && a == 1) {
//                ListNode *node = new ListNode(a);
//                p->next = node;
//            }
//        }
//        return result;
//    }
//    void test(){
//        vector<int> arr1 = {1,2,4};
//        vector<int> arr2 = {9,8,8,9};
//        ListNode *l1 = createList(arr1);
//        ListNode *l2 = createList(arr2);
//        ListNode *result = addTwoNumbers(l1, l2);
//
//        while (result != NULL) {
//            cout<<result->val;
//            result = result->next;
//        };
//    }
//    ListNode *createList(vector<int>& arr)
//    {
//        ListNode *l = NULL;
//        ListNode *p = NULL;
//        vector<int>::iterator it = arr.begin();
//        while (it != arr.end()) {
//            if (l == NULL) {
//                l = new ListNode(*it, nullptr);
//                p = l;
//            }
//            else{
//                p->next = new ListNode(*it, nullptr);
//                p = p->next;
//            }
//            it++;
//        }
//        return l;
//    }
//};

#pragma mark - 3
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//
//        int max = 0;
//        int strLength = (int)s.size();
//        vector<int> vec;
//        vec.resize(strLength);
//        for (int i = 0; i < strLength; i++) {
//            for (int j = i + 1; j < strLength ; j++) {
//                if (s[i] == s[j]) {
//                    vec[i] = j;
//                    break;
//                }
//            }
//            if (vec[i] == 0) {
//                vec[i] = strLength;
//            }
//
//        }
//        for (int i = 0; i < strLength; i++) {
//            for (int j = i + 1; j < vec[i]; j++) {
//                if (vec[i] > vec[j]) {
//                    vec[i] = vec[j];
//                }
//            }
//            vec[i] -= i;
//            max = max > vec[i] ? max : vec[i];
//        }
//        return max;
//    }
//
//    int lengthOfLongestSubstring2(char * s){
//        char* begin,* end;
//        int length,count;
//        if(!(*s))
//            return 0;
//        length=1;
//        begin=end=s;
//        while(*(++end)){
//            s=end-1;
//            while(s>=begin){
//                if((*end)==(*s)){
//                    begin=s+1;
//                    break;
//                }
//                s--;
//            }
//            count=end-s;
//            if(count>length)
//                length=count;
//        }
//        return length;
//    }
//
//
//
//
//    void test(){
//        int length = lengthOfLongestSubstring("aaaaaa");
//        cout<< length;
//    }
//};
#pragma mark - 4
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//
//        int numsCount1 = (int)nums1.size();
//        int numsCount2 = (int)nums2.size();
//        int allCount = numsCount1 + numsCount2;
//        int midIndex1, midIndex2;
//        midIndex1 = midIndex2 = allCount / 2;
//        if (allCount % 2 == 0) {
//            midIndex1 = midIndex2 - 1;
//        }
//
//        int index = -1;
//        double midNum = 0;
//        int currentNum = 0;
//        int i = 0, j = 0;
//        while (i < numsCount1 && j < numsCount2) {
//            index = i + j;
//            if (nums1[i] < nums2[j]) {
//                currentNum = nums1[i];
//                i++;
//            }
//            else{
//                currentNum = nums2[j];
//                j++;
//            }
//
//            if (index == midIndex1) {
//                midNum = currentNum;
//            }
//
//            if (index == midIndex2) {
//                midNum += currentNum;
//                midNum /= 2.0;
//                return midNum;
//            }
//        }
//
//        if (i < numsCount1) {
//            if (index == midIndex1) {
//                midNum += nums1[i];
//            }
//            else {
//                midNum = (nums1[midIndex1 - j] + nums1[midIndex2 - j]);
//            }
//            return midNum / 2.0;
//        }
//
//        if (j < numsCount2) {
//            if (index == midIndex1) {
//                midNum += nums2[j];
//            }
//            else {
//                midNum = (nums2[midIndex1 - i] + nums2[midIndex2 - i]);
//            }
//            return midNum / 2.0;
//        }
//
//        return 0;
//    }
//
//    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
//        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
//        sort(nums1.begin(), nums1.end());
//        int count = (int)nums1.size();
//        if (count % 2 == 0) {
//            return (nums1[count / 2] + nums1[count / 2 - 1]) / 2.0;
//        }
//        else {
//            return nums1[count / 2];
//        }
//    }
//
//    double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
//        int start1 = 0, start2 = 0;
//        int end1 = (int)nums1.size(), end2 = (int)nums2.size();
//        int mid1 = 0, mid2 = 0;
//
//        int allCount = (int)(nums1.size() + nums2.size());
//        int targetIndex1, targetIndex2;
//
//        /*
//         nums1总数为m,nums2总数为n,
//         如果nums1[a/2] < nums2[n/2],则（m + n）/ 2 + 1个数一定比[s1,mid1]的数大，所以m/2位置的数最大为（m + n）/ 2 - 1
//         要寻找的是(m + n) / 2 和 （m + n）/ 2 - 1
//         除非n=0,否则 m/2 - 1 != (m + n) / 2 - 1
//         所以m/2之前的数一定不是要找的数，但不排除m/2
//
//         同理n/2之后的数据也一定不是要找的数，但不排除n/2
//         */
//        while (true) {
//            mid1 = (start1 + end1) / 2;
//            mid2 = (start2 + end2) / 2;
//
//            if (nums1[mid1] < nums2[mid2]) {
//                start1 = mid1;
//                end2 = mid2;
//            }
//
//            if (nums1[mid1] > nums2[mid2]) {
//                start2 = mid2;
//                end1 = mid1;
//            }
//
//            if (start1 == end1 && start2 == end2) {
//                tark
//            }
//        }
//    }
//
//    void test(){
//        vector<int> nums1 = {};
//        vector<int> nums2 = {1};
//        double testNum = findMedianSortedArrays3(nums1, nums2);
//        cout<<testNum<<endl;
//    }
//};
#pragma mark - 5
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int strLength = (int)s.size();
//        vector<int> arrIndex;
//        int max = 0;
//        string result = s.substr(0, 1);
//        arrIndex.resize(strLength);
//        for (int i = 0; i < strLength; i++) {
//            for (int j = i + 1; j < strLength; j++) {
//                if (s[i] == s[j]) {
//                    arrIndex[i] = j;
//                    break;
//                }
//            }
//        }
//
//        for (int i = strLength - 1; i - 1 > 0; i--) {
//            if (arrIndex[i - 1]  == arrIndex[i] - 1){
//                arrIndex[i - 1] = arrIndex[i];
//            }
//        }
//
//        for (int i = 0; i < strLength; i++) {
//            int palindromeIndex = arrIndex[i];
//            bool isSuccess = true;
//            for (int j = i + 1; j < palindromeIndex; j++) {
//                if (arrIndex[j] == j + 1 || arrIndex[j] == 0) {
//                    break;
//                }
//                if (arrIndex[j] != palindromeIndex - j && arrIndex[j] < palindromeIndex) {
//                    isSuccess = false;
//                    break;
//                }
//            }
//            if (isSuccess) {
//                if (palindromeIndex - i > max) {
//                    max = palindromeIndex - i;
//                    result = s.substr(i, (palindromeIndex - i + 1));
//                }
//            }
//        }
//
//        return result;
//    }
//
//    string longestPalindrome2(string s) {
//        int max = 0;
//        string result = s.substr(0, 1);
//        for (int i = 0; i < s.size(); i++) {
//            int palindromeIndex = i;
//            for (int j = (int)s.size() - 1; j > i; j--) {
//                if (s[i] == s[j]) {
//                    palindromeIndex = j;
//
//                    string str1, str2;
//                    int length = (palindromeIndex - i + 1) / 2;
//                    str1 = s.substr(i, length);
//                    str2 = s.substr(palindromeIndex - length + 1, length);
//
//
//                    bool isSuccess = true;
//                    for (int k = 0; k < length; k++) {
//                        if (str1[k] != str2[length - k - 1]) {
//                            isSuccess = false;
//                            break;
//                        }
//                    }
//                    if (isSuccess) {
//                        if (palindromeIndex - i > max) {
//                            max = palindromeIndex - i;
//                            result = s.substr(i, (palindromeIndex - i + 1));
//                        }
//                        if (max == s.size() - 1) {
//                            return  result;
//                        }
//                    }
//                }
//            }
//        }
//
//        return result;
//    }
//
//    string longestPalindrome3(string s) {
//        vector<int> temp = vector<int>(s.size(), 0);
//        for (int i = 0; i < s.size(); i++) {
//            for (int j = i + 1; j < s.size(); j++) {
//                if (s[i] == s[j]) {
//                    temp.push_back(j);
//                    break;
//                }
//            }
//        }
//
//        for (int i = 0; i < temp.size(); i++) {
//            int length = (temp[i] - i + 1);
//            if (length % 2 == 0) {//偶数个
//                <#statements#>
//            }
//
//        }
//
//        return "";
//    }
//
//    void test() {
//        string result = longestPalindrome2("abacab");
//    }
//};

#pragma mark - 605
//class Solution {
//public:
//    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//        int i = 0;
//        int count = 0;
//        if (flowerbed.size() == 1) {
//            if(flowerbed[0] == 0) {
//                count = 1;
//            }
//        }
//        else {
//            while (i + 1 < flowerbed.size()) {
//                if (count >= n) {
//                    return true;
//                }
//                if (i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
//                    count++;
//                    i += 1;
//                    continue;
//                }
//
//                if (i == flowerbed.size() - 2 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
//                    count++;
//                    break;
//                }
//
//                if (i + 2 < flowerbed.size()) {
//                    if (flowerbed[i] == 0 && flowerbed[i + 2] == 0 && flowerbed[i + 1] != 1) {
//                        count++;
//                        i += 2;
//                        continue;
//                    }
//                }
//                i++;
//            }
//        }
//        if (count >= n) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//
//    void test() {
//        vector<int> flowerbed = {0,0,0,0,1};
//        bool canPlace = canPlaceFlowers(flowerbed, 2);
//    }
//};
#pragma mark - 452
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        if(points.empty()) {
//            return 0;
//        }
//        sort(points.begin(),points.end(),[](const vector<int>&a,const vector<int>&b){
//            return a[1]<b[1];
//
//        });
//
//        int i = 0;
//        int count = 0;
//        int maxShot = points[i][1];
//        for (int i = 0; i < points.size(); i++) {
//            if (maxShot >= points[i][0]) {
//                maxShot = maxShot > points[i][1] ? points[i][1] : maxShot;
//            }
//            else{
//                count++;
//                maxShot = points[i][1];
//            }
//        }
//        count += 1;
//
//        return count;
//    }
//
//    int findMinArrowShots2(vector<vector<int>>& points) {
//
//        sort(points.begin(), points.end(), [](vector<int> a , vector<int> b){
//            return (a[1] > b[1]);
//        });
//        for (int i = 0; i < points.size(); i++) {
//            cout<<points[i][0]<<","<<points[i][1]<<endl;
//        }
//
//        vector<vector<int>> result;
//        for (int i = 0; i < points.size(); i++) {
//            if (points[i][1] == points[i + 1][1]) {
//            }
//        }
//        return 0;
//    }
//
//    void test() {
//
////        {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}}
//        vector<vector<int>> points = {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}};
//        findMinArrowShots(points);
//    }
//};

#pragma mark - 736
//class Solution {
//public:
//    int evaluate(string expression) {
//
//        vector<string> vecAll;
//        int i = 0;
//        char *key = std::strtok(&expression[0], " ");
//        while (key != NULL) {
//
//            vecAll.push_back(key);
//            cout<<key<<endl;
//            key = strtok(NULL, " ");
//            i++;
//        }
//
//        poss(vecAll);
//
//        return 0;
//    }
//
//    void poss(vector<string>& vec){
//        vector<int> vecLetKeyword;
//        vector<int> vecLeftBrackets;
//        vector<int> vecRightBrackets;
//        vector<int> vecAddKeyword;
//        vector<int> vecMultKeyword;
//
//        for (int i = 0; i < vec.size(); i++) {
//            char *key = &(vec[i])[0];
//            if (strstr(key, "let")) {
//                vecLetKeyword.push_back(i);
//            }
//            if (strstr(key, "(")) {
//                vecLeftBrackets.push_back(i);
//            }
//            if (strstr(key, ")")) {
//                vecRightBrackets.push_back(i);
//            }
//            if (strstr(key, "add")) {
//                vecAddKeyword.push_back(i);
//            }
//            if (strstr(key, "mult")) {
//                vecMultKeyword.push_back(i);
//            }
//        }
//
//        if (vecLetKeyword.size() > 0) {
//            map<string, string> mapEV;
//
//            int lastLetStart = *(vecLetKeyword.end() - 1) + 1;
//            int lastLetEnd = lastLetStart;
//            int lastAddIndex = *(vecAddKeyword.end() - 1);
//            if (lastAddIndex > lastLetStart) {
//                lastLetEnd = lastAddIndex - 1;
//            }
//            int lastMultIndex = *(vecMultKeyword.end() - 1);
//            if (lastMultIndex > lastLetStart) {
//                lastLetEnd = lastMultIndex - 1;
//            }
//            if (lastLetEnd == lastLetStart) {
//                lastLetEnd = (int)vec.size() - 1;
//            }
//
//            for (int i = lastLetStart; i + 1< lastLetEnd; i++) {
//                mapEV.insert(map<string, string>::value_type (vec[i + 1], vec[i]));
//            }
//
//            cout<<mapEV["dd"]<<endl;
////            string lLetE = vecAll[*(vecLetKeyword.end() - 1) + 1];
////
////            string lLetV = vecAll[*(vecLetKeyword.end() - 1) + 2];
//        }
//
//
//    }
//
//    void printVector(vector<int>& vec)
//    {
//        vector<int>::iterator it = vec.begin();
//        while (it != vec.end()) {
//            cout<<*it<<endl;
//        }
//    }
//
//    void test() {
//        int result = evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))");
//    }
//};

#pragma mark - 76
//class Solution {
//public:
//    string minWindow(string S, string T) {
//
//        long SLength = S.size();
//        long TLength = T.size();
//        map<char, int> searchMap;
//        map<char, int> targetMap;
//        for (int i = 0; i < TLength; i++) {
//            searchMap[T[i]] = 0;
//            targetMap[T[i]]++;
//        }
//
//
//        int alreadyNum = 0;
//        int start =0, end = 0;
//        int subStrS = 0;
//        unsigned long length = UINTMAX_MAX;
//        while (end < SLength) {
//
//            if (searchMap.count(S[end]) != 0) {
//                searchMap[S[end]]++;
//                if (searchMap[S[end]] <= targetMap[S[end]]) {
//                    alreadyNum++;
//                }
//            }
//
//            if (alreadyNum == 0) {
//                start++;
//            }
//
//            end++;
//
//            while (alreadyNum == TLength) {
//
//                if (length > end - start) {
//                    subStrS = start;
//                    length = end - start;
//                }
//
//                if (length == TLength) {
//                    return S.substr(subStrS, length);
//                }
//
//                if (searchMap.count(S[start]) != 0) {
//                    searchMap[S[start]]--;
//                    if (searchMap[S[start]] < targetMap[S[start]]) {
//                        alreadyNum--;
//                    }
//                }
//                start++;
//            }
//        }
//        if (length > SLength) {
//            return "";
//        }
//        else {
//            return S.substr(subStrS, length);
//        }
//    }
//
//    void test() {
//        string result = minWindow("ADOBECODEBANC", "ABC");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 633
//class Solution {
//public:
//    bool judgeSquareSum(int c) {
//        long long s = 0, e = ceil(sqrt(c));
//        while (s <= e) {
//           long long count = s * s + e * e;
//            if (count > c) {
//                e--;
//            }
//            else if (count < c) {
//                s++;
//            }
//            else {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    void test() {
//        bool result = judgeSquareSum(2147482647);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 680
//class Solution {
//public:
//    bool validPalindrome(string s) {
//        static int deleteNum = 0;
//        int start = 0, end = (int)s.size() - 1;
//        while (start < end) {
//            if (s[start] == s[end]) {
//                start++;
//                end--;
//                continue;
//            }
//            else {
//                return validPalindrome(s.substr(start, end - start)) || validPalindrome(s.substr(start + 1, end - start + 1));
//            }
//        }
//        return true;
//    }
//    bool validPalindrome2(string s) {
//        if (s.size() <= 2) {
//            return true;
//        }
//        int start = 0, end = (int)s.size() - 1;
//        int deleteCount = 0;
//        while (start < end) {
//            if (s[start] == s[end]) {
//                start++;
//                end--;
//                continue;
//            }else if (s[start + 1] == s[end] && s[start + 2] == s[end - 1]) {
//                if (deleteCount != 0) {
//                    return false;
//                }
//                deleteCount++;
//
//                start += 3;
//                end -= 2;
//                continue;
//            }else if (s[start] == s[end - 1] && s[start + 1] == s[end - 2]) {
//                if (deleteCount != 0) {
//                    return false;
//                }
//                deleteCount++;
//
//                start += 2;
//                end -= 3;
//
//                continue;
//            }
//            else {
//                if (start >= end - 1) {
//                    return true;
//                }
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        bool result = validPalindrome("abc");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 524
//class Solution {
//public:
//    string findLongestWord(string s, vector<string>& dictionary) {
//        int resultIndex = -1;
//        int maxLength = 0;
//        for (int i = 0; i < dictionary.size(); i++) {
//            string str = dictionary[i];
//            int length = 0;
//            if (s.find(str) != string::npos) {
//                length = (int)str.size();
//            }
//            else {
//                int lastIndex = -1;
//                for (int j = 0; j < str.size(); j++, length++) {
//                    int k = lastIndex >= 0 ? lastIndex + 1 : 0;
//                    bool isFound = false;
//                    for (; k < s.size(); k++) {
//                        if (s[k] == str[j]) {
//                            isFound = true;
//                            break;
//                        }
//                    }
//
//                    if (isFound && k > lastIndex) {
//                        lastIndex = k;
//                        continue;
//                    }
//                    else {
//                        length = 0;
//                        break;
//                    }
//                }
//            }
//            if (length > maxLength) {
//                maxLength = length;
//                resultIndex = i;
//            }
//            else if (length == maxLength && length > 0) {
//                if (strcmp(&(dictionary[resultIndex])[0], &(dictionary[i])[0]) > 0) {
//                    resultIndex = i;
//                }
//            }
//        }
//        if (resultIndex >= 0) {
//            return dictionary[resultIndex];
//        }
//        return "";
//    }
//    void test() {
//        vector<string> dictionary = {"a","b", "c"};
//        string result = findLongestWord("abce", dictionary);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 69
//class Solution {
//public:
//    int mySqrt(int x) {
//        if (x == 0 || x == 1) {
//            return x;
//        }
//        long start = 0;
//        long end = x;
//        long mid = 0;
//        while (true) {
//            mid = (end - start) / 2 + start;
//            if (start >= mid || end <= mid) {
//                return (int)mid;
//            }
//            long t = mid * mid;
//            if (t == x) {
//                return (int)mid;
//            }
//            else if (t > x) {
//                end = mid;
//            }
//            else {
//                start = mid;
//            }
//        }
//
//        return 0;
//    }
//
//
//
//    void test() {
//        int result = mySqrt(2147395599);
//        cout<<floor(sqrt(0))<<endl;
//        cout<<result<<endl;
//    }
//};

#pragma mark - 34
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//
//        if (nums.size() == 1) {
//            if (nums[0] == target) {
//                return {0,0};
//            }
//            else {
//                return {-1, -1};
//            }
//        }
//        int start = 0;
//        int end = (int)nums.size() - 1;
//        int mid = -1;
//        int targetIndex = -1;
//        int minIndex = -1;
//        int maxIndex = -1;
//
//        //找到target的位置
//        while (end >= start) {
//            mid = (end - start) / 2 + start;
//            if (nums[mid] == target) {
//                targetIndex = mid;
//                break;
//            }
//            if (nums[mid] > target) {
//                end = mid - 1;
//            }
//            else {
//                start = mid + 1;
//            }
//        }
//
//
//        if (targetIndex >= 0) {
//
//            minIndex = targetIndex;
//            maxIndex = targetIndex;
//
//            //向前找
//            int temp = targetIndex;
//            while (--temp >= 0) {
//                if (nums[temp] == target) {
//                    minIndex = temp;
//                }
//            }
//
//            //向后找
//            temp = targetIndex;
//            while (++temp < nums.size()) {
//                if (nums[temp] == target) {
//                    maxIndex = temp;
//                }
//            }
//        }
//
//        return {minIndex, maxIndex};
//    }
//
//    void test() {
//        vector<int> nums = {2, 2, 2};
//        vector<int> result = searchRange(nums, 2);
//        for (int i = 0; i < result.size(); i++) {
//            cout<<result[i]<<endl;
//        }
//    }
//};
#pragma mark - 81
//class Solution {
//public:
//    bool search2(vector<int>& nums, int target) {
//
//        int start = 0;
//        int end = (int)nums.size() - 1;
//        int mid = 0;
//        while (end >= start) {
//            mid = (start + end) / 2;
//            if (nums[start] == target || nums[end] == target || nums[mid] == target) {
//                return true;
//            }
//            if (nums[mid] > nums[start]) {//start-mid递增
//                if (nums[mid] > target && target > nums[start]) {//在此范围内
//                    end = mid - 1;
//                }
//                else {
//                    start = mid + 1;
//                }
//            }
//            else if (nums[mid] < nums[end]) {//mid-end递增
//                if (nums[end] > target && target > nums[mid]) { //在此范围内
//                    start = mid + 1;
//                }
//                else {
//                    end = mid - 1;
//                }
//            }
//            else {
//                start++;
//            }
//        }
//
//        return false;
//    }
//    bool search(vector<int>& nums, int target) {
//        int start = 0;
//        int end = (int)nums.size() - 1;
//        int mid = 0;
//
//        while (end >= start) {
//            if (nums[start] == target || nums[end] == target) {
//                return true;
//            }
//
//            if (nums[start] < target) {//在左边大数部分
//                mid = getLeftMid(nums, start, end);
//                if (mid < 0) {
//                    break;
//                }
//                if (nums[mid] > target) {
//                    end = mid - 1;
//                }
//                else if (nums[mid] < target) {
//                    start = mid + 1;
//                }
//                else {
//                    return true;
//                }
//            }
//            else if (nums[end] > target) {//在右边小数部分
//                mid = getRightMid(nums, start, end);
//                if (mid < 0) {
//                    break;
//                }
//                if (nums[mid] < target) {
//                    start = mid + 1;
//                }
//                else if (nums[mid] > target) {
//                    end = mid - 1;
//                }
//                else {
//                    return true;
//                }
//            }
//            else {
//                break;
//            }
//        }
//
//        return false;
//    }
//
//    //获取右边小数的中值
//    int getRightMid(vector<int>& nums, int s, int e) {
//        int mid = 0;
//        int leftMin = nums[0];
//        while (s < e) {
//            mid = (s + e) / 2;
//            if (nums[mid] > leftMin) {
//                s = mid + 1;
//            }
//            else if (nums[mid] < leftMin) {
//                return mid;
//            }
//            else if (isSameNumberInLeftBigNums(nums, mid) == false) {//mid在右边
//                return mid;
//            }
//            else {
//                s = mid + 1;
//            }
//        }
//        return -1;
//    }
//
//    //获取左边大数的中值
//    int getLeftMid(vector<int>& nums, int s, int e) {
//        int mid = 0;
//        int rightMax = nums[nums.size() - 1];
//        if (nums[0] < rightMax) {//递增数组
//            return (s + e) / 2;
//        }
//        while (s < e) {
//            mid = (s + e) / 2;
//            if (nums[mid] > rightMax) {//mid在左边
//                return mid;
//            }
//            else if (nums[mid] < rightMax) {
//                e = mid - 1;
//            }
//            else if (isSameNumberInLeftBigNums(nums, mid) == true) {//mid在左边
//                return mid;
//            }
//            else {
//                e = mid - 1;
//            }
//        }
//
//        return -1;
//    }
////222221222222;
//
//    //在mid等于边界值时，判断mid是不是在左边
//    bool isSameNumberInLeftBigNums(vector<int>& nums, int index) {
//        if (nums.size() - index > index) {//index离左边近
//            while (index - 1 >= 0) {
//                if (nums[index] != nums[index - 1]) {
//                    return false;
//                }
//                index--;
//            }
//
//            return true;
//        }
//        else{
//            while (index + 1 <nums.size()) {
//                if (nums[index] != nums[index + 1]) {
//                    return true;
//                }
//                index++;
//            }
//            return false;
//        }
//    }
//
//    void test() {
//        vector<int> nums = {3,3,0,1,3};
//        bool result = search2(nums, 1);
//        cout<<result<<endl;
//    }
//};
#pragma mark - 154
//class Solution {
//public:
//    int findMin(vector<int>& nums) {
//        int start = 0;
//        int end = (int)nums.size() - 1;
//        int mid = 0;
//        int minIndex = start;
//        if (start == end || nums[start] < nums[end]) {//递增序列没有翻转
//            return nums[start];
//        }
//        while (end >= start) {
//            mid = (start + end) / 2;
//            if (nums[mid] > nums[start]) {//[start-mid]递增,最小为start或在[mid-end]中
//                if (nums[start] < nums[minIndex]) {
//                    minIndex = start;
//                }
//                start = mid + 1;
//            }//mid<start 则 mid一定<=end
//            else if (nums[mid] < nums[end]) {//[mid-end]递增，最小为mid或在[start-mid]中
//                if (nums[mid] < nums[minIndex]) {
//                    minIndex = mid;
//                }
//                end = mid - 1;
//            }//mid > end 则 mid一定>=start
//            else {//mid == end 或者 mid == start
//                if (nums[start] < nums[minIndex]) {
//                    minIndex = start;
//                }
//                start++;
//            }
//        }
//
//        return nums[minIndex];
//    }
//
//    void test() {
//        vector<int> nums = {5,0,2,3,4};
//        int result = findMin(nums);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 540
//class Solution {
//public:
//    int singleNonDuplicate(vector<int>& nums) {
//        int start = 0;
//        int end = (int)nums.size() - 1;
//        int mid =0;
//
//        while (end >= start) {
//            mid = (start + end) / 2;
//            if (mid <= end - 1 && nums[mid] == nums[mid + 1]) {//mid 和 mid + 1是一对
//                if ((mid + 2) % 2 == 0) {//偶数个，start-mid都是一对的，单数在mid-end中
//                    start = mid + 2;
//                }
//                else {//奇数个,单数在start-mid
//                    end = mid - 1;
//                }
//            }
//            else if (mid >= start + 1 && nums[mid - 1] == nums[mid]) {//mid 和 mid - 1是一对
//                if ((mid + 1) % 2 == 0) {//
//                    start = mid + 1;
//                }
//                else {
//                    end = mid - 2;
//                }
//            }
//            else {//mid不是一对
//                return nums[mid];
//            }
//        }
//        return -1;
//    }
//
//    void test() {
//        vector<int> nums = {0};
//        int result = singleNonDuplicate(nums);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 215
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end());
//        return nums[(int)nums.size() - k];
//    }
//
//    int findKthLargest2(vector<int>& nums, int k) {
//        return quickSortSearch(nums, 0, (int)nums.size() - 1, (int)nums.size() - k);
//    }
//
//    void swap(vector<int>& arr, int i , int j) {
//        int temp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = temp;
//    }
//
//    int quickSortSearch(vector<int>& nums, int l, int r, int numIndex) {
//        if (l >= r) {
//            return nums[numIndex];
//        }
//
//        int s = l, e = r;
//        int key = r;
//
//        while (s < e) {
//            while (nums[e] > nums[key] && s < e) {
//                e--;
//            }
//
//            while (nums[s] <= nums[key] && s < e) {
//                s++;
//            }
//            swap(nums, s, e);
//        }
//
//        swap(nums, s, key);
//
//        if (e == numIndex) {
//            return nums[numIndex];
//        }
//
//        if (e < numIndex) {
//            return quickSortSearch(nums, e, r, numIndex);
//        }
//        else {
//            return quickSortSearch(nums, l, e - 1, numIndex);
//        }
//
//    }
//
//
//    void test() {
//        vector<int> arr = {-1,2,0};
//        int kValue = findKthLargest2(arr, 2);
//        cout<<kValue<<endl;
//    }
//};

#pragma mark - 75
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        //使用计数排序
//        vector<int> arrCount(2);
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] < 2) {
//                arrCount[nums[i]]++;
//            }
//        }
//
//        int k = 0;
//
//        for (int i = 0; i < arrCount.size(); i++) {
//            for (int j = 0; j < arrCount[i]; j++) {
//                nums[k++] = i;
//            }
//        }
//
//        while (k < nums.size()) {
//            nums[k++] = 2;
//        }
//
//    }
//
//    void test() {
//        vector<int> nums = {2,0,2,1,1,0};
//        sortColors(nums);
//        vector<int>::iterator it = nums.begin();
//        while (it != nums.end()) {
//            cout<<*it<<"";
//            it++;
//        }
//    }
//};
#pragma mark - 347
//class Solution {
//public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//
//        //计数排序一层
//        int maxNum = nums[0], minNum = nums[0];
//        for (int i = 0; i < nums.size(); i++) {
//            maxNum = max(maxNum, nums[i]);
//            minNum = min(minNum, nums[i]);
//        }
//
//        for (int i = 0; i < nums.size(); i++) {
//            nums[i] = nums[i] - minNum;
//        }
//
//
//        int maxCount = 0;
//        vector<int> tempCount(maxNum - minNum + 1);
//        for (int i = 0; i < nums.size(); i++) {
//            tempCount[nums[i]]++;
//
//            maxCount = max(maxCount, tempCount[nums[i]]);
//        }
//
//        //计数排序 排 第一次的结果
//        vector<vector<int>> arrResultCount;
//        arrResultCount.resize(maxCount + 1);
//
//        for (int i = 0; i < tempCount.size(); i++) {
//            arrResultCount[tempCount[i]].push_back(i);
//        }
//
//        vector<int> result;
//        for (int i = (int)arrResultCount.size() - 1; i >= 0 && result.size() < k; i--) {
//            for (int j = 0; j < arrResultCount[i].size(); j++) {
//                result.push_back(arrResultCount[i][j] + minNum);
//            }
//        }
//
//
//        return result;
//    }
//
//    void test() {
//        vector<int> nums = {1,1,1,2,2,3};
//        vector<int> result = topKFrequent(nums, 2);
//        vector<int>::iterator it = result.begin();
//        while (it != result.end()) {
//            cout<<*it<<endl;
//            it++;
//        }
//    }
//};

#pragma mark - 451
//class Solution {
//public:
//    string frequencySort(string s) {
//        vector<int> arrStringCount(256);
//
//        int maxCount = 0;
//        for (int i = 0; i < s.size(); i++) {
//            arrStringCount[s[i]]++;
//            maxCount = max(maxCount, arrStringCount[s[i]]);
//        }
//
//        vector<vector<int>> arrCountCount(maxCount + 1, vector<int>());
//        for (int i = 0; i < arrStringCount.size(); i++) {
//            if (arrStringCount[i] > 0) {
//                arrCountCount[arrStringCount[i]].push_back(i);
//            }
//        }
//
//        string result = "";
//        for (int i = (int)arrCountCount.size() - 1; i >= 0; i--) {
//            for (int j = 0; j < arrCountCount[i].size(); j++) {
//                for (int k = i - 1; k >= 0; k--) {
//                    result += arrCountCount[i][j];
//                }
//            }
//        }
//
//        return result;
//    }
//    void test() {
//        string result = frequencySort("Aatree");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 64
//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        //状态转移方程f(i, j) = f(i - 1, j) + f(i, j - 1)
//
//        vector<vector<int>> allPath(grid);
//        for (int j = 1; j < grid[0].size(); j++) {
//            allPath[0][j] = allPath[0][j - 1] + grid[0][j];
//        }
//
//        for (int i = 1; i < grid.size(); i++) {
//            allPath[i][0] = allPath[i - 1][0] + grid[i][0];
//        }
//
//
//        for (int i = 1; i < grid.size(); i++) {
//            for (int j = 1; j < grid[i].size(); j++) {
//
//                int path1 = allPath[i - 1][j] + grid[i][j];
//                int path2 = allPath[i][j - 1] + grid[i][j];
//
//                allPath[i][j] = min(path1, path2);
//            }
//        }
//
//        return allPath[grid.size() - 1][grid[grid.size() - 1].size() - 1];
//    }
//
//    void test() {
////        vector<vector<int>> arr = {{1,3,1},{1,5,1},{4,2,1}};
//        vector<vector<int>> arr = {{1,2,3},{4,5,6}};
//        int result = minPathSum(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 152
//class Solution {
//public:
//    int maxProduct(vector<int>& nums) {
//        /*转移方程
//         f(n) = max(正数f(n - 1) * nums[i], nums[n]) nums[n] > 0
//         f(n) = max(负数f(n - 1) * nums[i], nums[n]) nums[n] <= 0
//
//         改进版只用两个变量记录（正数f(n - 1)） 和 （负数f(n - 1)）
//         */
//        if (nums.size() == 0) {
//            return 0;
//        }
//
//        int maxNum = nums[0] > 0 ? nums[0] : 0;
//        int minNum = nums[0] < 0 ? nums[0] : 0;
//
//
//        int resultMaxNum = nums[0];
//        for (int i = 1; i < nums.size(); i++) {
//
//            if (nums[i] > 0) {
//                maxNum = max(maxNum * nums[i], nums[i]);
//                minNum = min(minNum * nums[i], nums[i]);
//            }
//            else {
//                int temp = maxNum;
//                maxNum = max(minNum * nums[i], nums[i]);
//                minNum = min(temp * nums[i], nums[i]);
//            }
//
//            resultMaxNum = max(maxNum, resultMaxNum);
//        }
//
//        return resultMaxNum;
//    }
//
//    void test() {
//        vector<int> nums = {-2, -3, -4,0,0};
//        int result = maxProduct(nums);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 70
//class Solution {
//public:
//    int climbStairs(int n) {
//        //转移方程 f(n) = f(n - 1) + f(n - 2)
//        if (n <= 2) {
//            return n;
//        }
//
//        int last1 = 2, last2 = 1;
//        int result = 0;
//        for (int i = 3; i <= n; i++) {
//            result = last1 + last2;
//            last2 = last1;
//            last1 = result;
//        }
//
//        return result;
//    }
//
//    void test() {
//        int result = climbStairs(2);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 198
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        //转换方程f(n) = max(f(n - 2) + nums[2], f(n - 1));
//
//        //优化 只用两个变量记录f(n - 2) 和 f(n - 1)
//
//        if (nums.size() < 1) {
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
//        int last2 = nums[0];
//        int last1 = max(nums[0], nums[1]);
//        int result = nums[0];
//        for (int i = 2; i < nums.size(); i++) {
//            result = max(last2 + nums[i], last1);
//            last2 = last1;
//            last1 = result;
//        }
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {2,1,1,2};
//        int result = rob(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 413
//class Solution {
//public:
//    int numberOfArithmeticSlices(vector<int>& nums) {
//        /*等差数列nums[n] - nums[n - 1] = nums[n - 1] - nums[n - 2]
//         nums[n] + nums[n - 2] = 2*nums[n - 1]
//
//         转换方程f(n) = f(n - 1) + length - 2
//         */
//        if (nums.size() < 3) {
//            return 0;
//        }
//
//        int result = 0;
//        int length = 2;
//        int last = 0;
//        for (int i = 2; i < nums.size(); i++) {
//            if (nums[i] + nums[i - 2] == 2 * nums[i - 1]) {
//                length++;
//
//                result += (last + length - 2);
//            }
//            else {
//                length = 2;
//                last = 0;
//            }
//        }
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,8,9,10};
//        int result = numberOfArithmeticSlices(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 542 01
//class Solution {
//public:
//    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
//        /*转移方程
//         f(i, j) = min(f(i - 1, j), f(i, j - 1), f(i + j + 1), f(i + 1, j)) matrix[i][j] != 0
//         f(i, j) = 0 matrix[i][j] = 0;
//         */
//        int lengthI = (int)matrix.size() - 1;
//        int lengthJ = (int)matrix[0].size() - 1;
//
//        vector<vector<int>> result(lengthI + 1, vector<int>(lengthJ + 1, INT_MAX - 1));
//
//        //向左下
//        for (int i = 0; i <= lengthI; i++) {
//            for (int j = 0; j <= lengthJ; j++) {
//                if (matrix[i][j] == 0) {
//                    result[i][j] = 0;
//                }
//                else {
//                    int lastI = i - 1 > 0 ? i - 1 : 0;
//                    int lastJ = j - 1 > 0 ? j - 1 : 0;
//
//                    int temp = INT_MAX - 1;
//                    if (i == 0 && j == 0) {
//
//                    }
//                    else if (i == 0) {
//                        temp = result[i][lastJ] + matrix[i][j];
//                    }
//                    else if (j == 0) {
//                        temp = result[lastI][j] + matrix[i][j];
//                    }
//                    else {
//                        temp = min(result[lastI][j], result[i][lastJ]) + matrix[i][j];
//                    }
//
//                    result[i][j] = min(temp, result[i][j]);
//                }
//            }
//        }
//
////        tool.printMatrix(result);
//
//        //向右上
//        for (int i = (int)matrix.size() - 1; i >= 0 ; i--) {
//            for (int j = (int)matrix[i].size() - 1; j >= 0 ; j--) {
//                if (matrix[i][j] == 0) {
//                    result[i][j] = 0;
//                }
//                else {
//                    int lastI = i + 1 > lengthI ? lengthI : i + 1;
//                    int lastJ = j + 1 > lengthJ ? lengthJ : j + 1;
//
//                    int temp = INT_MAX - 1;
//                    if (i == lengthI && j == lengthJ) {
//
//                    }
//                    else if (i == lengthI) {
//                        temp = result[i][lastJ] + matrix[i][j];
//                    }
//                    else if (j == lengthJ) {
//                        temp = result[lastI][j] + matrix[i][j];
//                    }
//                    else {
//                        temp = min(result[lastI][j], result[i][lastJ]) + matrix[i][j];
//                    }
//
//                    result[i][j] = min(temp, result[i][j]);
//                }
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<vector<int>> matrix = {{1,1,0,0,1,0,0,1,1,0},{1,0,0,1,0,1,1,1,1,1},{1,1,1,0,0,1,1,1,1,0},{0,1,1,1,0,1,1,1,1,1},{0,0,1,1,1,1,1,1,1,0},{1,1,1,1,1,1,0,1,1,1},{0,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,0,0,1,1,1},{0,1,0,1,1,0,1,1,1,1},{1,1,1,0,1,0,1,1,1,1}};
//
//        tool.printMatrix(matrix);
//
//        vector<vector<int>> ans = {{2,1,0,0,1,0,0,1,1,0},{1,0,0,1,0,1,1,2,2,1},{1,1,1,0,0,1,2,2,1,0},{0,1,2,1,0,1,2,3,2,1},{0,0,1,2,1,2,1,2,1,0},{1,1,2,3,2,1,0,1,1,1},{0,1,2,3,2,1,1,0,0,1},{1,2,1,2,1,0,0,1,1,2},{0,1,0,1,1,0,1,2,2,3},{1,2,1,0,1,0,1,2,3,4}};
//
//        tool.printMatrix(ans);
//
//        vector<vector<int>> result = updateMatrix(matrix);
//
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 221
//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        /*f(i,j)为i,j方向内最大正方形边长
//
//         如果f(i,j)为1, f(i,j)的最大正方形为边长为：(min(f(i-1,j),f(i - 1,j)) + 1, f(i-1, j-1)) + 1
//         如果f(i,j)为0, f(i,j) = 0
//
//         */
//        int maxLength = 0;
//        int lengthI = (int)matrix.size() - 1;
//        int lengthJ = (int)matrix[0].size() - 1;
//        vector<vector<int>> result(lengthI + 1, vector<int>(lengthJ + 1, 0));
//
//        for (int i = 0; i <= lengthI; i++) {
//            for (int j = 0; j <= lengthJ; j++) {
//                if (matrix[i][j] == '0') {
//                    result[i][j] = 0;
//                }
//                else {
//                    if (i > 0 && j > 0) {
//                        result[i][j] = min(result[i - 1][j], result[i][j - 1]);
//                        result[i][j] = min(result[i][j], result[i - 1][j - 1]) + 1;
//                    }
//                    else {
//                        result[i][j] = 1;
//                    }
//
//                    maxLength = max(result[i][j], maxLength);
//                }
//            }
//        }
//
//        return maxLength * maxLength;
//    }
//
//    void test() {
//        vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
//        int result = maximalSquare(matrix);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 279
//class Solution {
//public:
//    int numSquares(int n) {
//        //转移方程：f(n) = min(f(n - i^2), f(n - (i + 1)^2).....f(1^2)) + 1
//        vector<int> result(n + 1, 9999);
//        result[0] = 0;
//        for (int i = 1; i <= n; i++) {
//
//            for (int j = 1; j * j <= i; j++) {
//                result[i] = min(result[i], result[i - j * j] + 1);
//            }
//        }
//
//        return result[n];
//    }
//
//    void test() {
//        int result = numSquares(13);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 91
//class Solution {
//public:
//    int numDecodings(string s) {
//        /*转换方程：f(n) = f(n - 1) + {if 0 <= lastc+c <= 26 + 1 //当前字和上一个字可以形成编码，可以多(last - 1）Count组合
//         */
//        if (s.size() == 0) {
//            return 0;
//        }
//
//        if ('0' >= s[0]) {
//            return 0;
//        }
//
//        int result = 1;
//        int lastCount1 = 1;
//        int lastCount2 = 1;
//
//        for (int i = 1; i < s.size(); i++) {
//            if (s[i] == '0') {
//                if (s[i - 1] >= '3' || s[i - 1] <= '0'){//当前是0时，不能和后面组合，如果前面大于3，或者0则不能组合
//                    return 0;
//                }
//                else if (s[i - 1] == 1 || s[i - 1] == 2) {
//                    result = lastCount1;
//                }
//                else {
//                    result = lastCount2;
//                }
//            }
//            else {
//                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {//10-19 或 20- 26
//                    result = lastCount1 + lastCount2;
//                }
//            }
//
//            lastCount2 = lastCount1;
//            lastCount1 = result;
//        }
//
//        return result;
//    }
//
//    void test() {
//        int result = numDecodings("10011");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 139
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
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
//
//    void test() {
//        vector<string> wordDict = {"app", "pl", "ple", "a", "le"};
//        bool result = wordBreak("applee", wordDict);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 300
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
///*转换方程  如果 nums[n - 1] < nums[n] f(n) = max{f(n - 1), f(n - 2)...f(0)} + 1
// f(n) = f(n - 1) + 1如果 nums[n - 1] < nums[n]
// */
//        if (nums.size() <= 0) {
//            return (int)nums.size();
//        }
//
//        vector<int> result(nums.size(), 1);
//        int maxLength = 0;
//        result[0] = 1;
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = 0; j < i; j++) {
//                if (nums[j] < nums[i]) {
//                    result[i] = max(result[i], result[j] + 1);
//                }
//            }
//            maxLength = max(result[i], maxLength);
//        }
//
//        return  maxLength;
//    }
//
////    int lengthOfLIS2(vector<int>& nums) {
////        int max_length = 0, n = nums.size();
////        if (n <= 1) return n;
////        vector<int> dp(n, 1);
////        for (int i = 0; i < n; ++i) {
////           for (int j = 0; j < i; ++j) {
////               if (nums[i] > nums[j]) {
////                  dp[i] = max(dp[i], dp[j] + 1);
////               }
////    }
////           max_length = max(max_length, dp[i]);
////        }
////        return max_length;
////    }
//
//    void test() {
//        vector<int> nums = {10,9,2,5,3,7,101,18};
//        int maxLength = lengthOfLIS(nums);
//        cout<<maxLength<<endl;
//    }
//};

#pragma mark - 35
//class Solution {
//public:
//
//    int searchInsert(vector<int>& nums, int target) {
//        //遍历,O(n)
//        int lessThanTargetIndex = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] == target) {
//                return i;
//            }
//            if (nums[i] < target) {
//                lessThanTargetIndex = i + 1;
//            }
//        }
//
//        return lessThanTargetIndex;
//    }
//
//    int searchInsert2(vector<int>& nums, int target) {
//        //二分 O(logn)
//
//        int l = 0, r = (int)nums.size() - 1;
//        int lessThanTargetIndex = 0;
//        while ( l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (nums[mid] == target) {
//                return mid;
//            }
//
//            if (nums[mid] > target) {
//                r = mid - 1;
//            }
//
//            if (nums[mid] < target) {
//                lessThanTargetIndex = mid + 1;
//                l = mid + 1;
//            }
//        }
//
//        return lessThanTargetIndex;
//    }
//
//    void test() {
//        vector<int> nums = {1};
//        int result = searchInsert2(nums, 0);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 27
//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val) {
//        //遍历 O(n)
//        int removeCount = 0;
//        int arrLength = (int)nums.size();
//        for (int i = 0; i < arrLength - removeCount; i++) {
//            if (nums[i] == val) {
//                removeCount++;
//                nums[i] = nums[arrLength - removeCount];
//                i--;
//            }
//
//        }
//
//        return arrLength - removeCount;
//    }
//
//    int removeElement2(vector<int>& nums, int val) {
//        //双指针 O(n)
//        int i = 0;
//        for (int j = 0; j < nums.size(); j++) {
//            if (nums[j] != val) {
//                nums[i] = nums[j];
//                i++;
//            }
//            else {
//
//            }
//        }
//
//        return i;
//    }
//
//    void test() {
//        vector<int> nums = {1,2,2,2,2};
//        int result = removeElement2(nums, 3);
//        cout<<result<<endl;
//        tool.printVector(nums);
//    }
//};

#pragma mark - 15
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        //map O(n2)
//        sort(nums.begin(), nums.end());
//        map<int, int> listMap;
//        vector<vector<int>> result;
//        for (int i = 0; i < nums.size(); i++) {
//            if (i > 0 && nums[i] == nums[i - 1]) {//重复数字跳过
//                continue;
//            }
//            listMap.clear();
//            for (int k = i; k < nums.size(); k++) {
//                listMap[nums[k]]++;
//            }
//            for (int j = i + 1; j < nums.size(); j++) {
//                if (j > i + 1 && nums[j] == nums[j - 1]) {//重复数字跳过
//                    listMap[nums[j]]--;//更新余量
//                    continue;
//                }
//                int target = - (nums[i] + nums[j]);
//                if (listMap[nums[i]] > 0) {//是否还有余量
//                    listMap[nums[i]]--;//使用一次减一个数量
//                }
//                else {
//                    break;//i没有余量直接跳出
//                }
//
//                if (listMap[nums[j]] > 0) {
//                    listMap[nums[j]]--;
//                }
//                else {
//                    listMap[nums[i]]++;
//                    continue;
//                }
//                if (listMap.count(target) > 0 && listMap[target] > 0) {
//                    vector<int> temp = {nums[i], nums[j], target};
//                    result.push_back(temp);
//                    listMap[target]--;
//                    listMap[nums[i]]++;
//                }
//                else {
//                    //没有匹配成功 恢复使用的量
//                    listMap[nums[i]]++;
//                    listMap[nums[j]]++;
//                }
//            }
//        }
//
//        return result;
//    }
//
//    vector<vector<int>> threeSum2(vector<int>& nums) {
//        //双指针 O(n2)
//        if (nums.size() < 3) {
//            return {};
//        }
//
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> result;
//        for (int i = 0; i < nums.size(); i++) {
//            if (i > 0 && nums[i] == nums[i - 1]) {//和上次匹配过的值重复跳过
//                continue;
//            }
//            int l = i + 1;
//            int r = (int)nums.size() - 1;
//            while (l < r) {
//                if (nums[l] == nums[l - 1] && l > i + 1) {//和上次匹配过的值重复跳过
//                    l++;
//                    continue;
//                }
//                if (r < nums.size() - 1 && nums[r] == nums[r + 1]) {//和上次匹配过的值重复跳过
//                    r--;
//                    continue;
//                }
//                int sum = nums[i] + nums[l] + nums[r];
//                if (sum < 0) {
//                    l++;
//                }
//                else if (sum > 0) {
//                    r--;
//                }
//                else {
//                    vector<int> temp = {nums[i], nums[l], nums[r]};
//                    result.push_back(temp);
//                    l++;
//                    r--;
//                }
//            }
//        }
//        return result;
//    }
//
//    void test() {
//        vector<int> nums = {0, 0, 0};
//        vector<vector<int>> result = threeSum(nums);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 18
//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        //双指针 O(n2)
//        //三数之和外套一层循环
//        if (nums.size() < 4) {
//            return {};
//        }
//
//        //优化 前4个最小数和>target 则跳出循环,后最大4个数和<target,跳出循环
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> result;
//        for (int k = 0; k < nums.size(); k++) {
//
//            if (k < nums.size() - 4 && (nums[k] + nums[k + 1] + nums[k + 2] + nums[k + 3]) > target) return result;//前4个最小数和>target, k之后不会有结果，直接返回
//
//            if (k > 0 && nums[k] == nums[k - 1]) {//和上次匹配过的值重复跳过
//                continue;
//            }
//            for (int i = k + 1; i < nums.size(); i++) {
//                if (i > k + 1 && nums[i] == nums[i - 1]) {//和上次匹配过的值重复跳过
//                    continue;
//                }
//                int l = i + 1;
//                int r = (int)nums.size() - 1;
//
//                if (r > 3 && (nums[r] + nums[r - 1] + nums[r - 2] + nums[r - 3]) < target) break;//后最大4个数和<target 此次循环不会有结果
//
//                while (l < r) {
//                    if (nums[l] == nums[l - 1] && l > i + 1) {//和上次匹配过的值重复跳过
//                        l++;
//                        continue;
//                    }
//                    if (r < nums.size() - 1 && nums[r] == nums[r + 1]) {//和上次匹配过的值重复跳过
//                        r--;
//                        continue;
//                    }
//                    int sum = nums[i] + nums[l] + nums[r];
//                    if (sum < target - nums[k]) {
//                        l++;
//                    }
//                    else if (sum > target - nums[k]) {
//                        r--;
//                    }
//                    else {
//                        vector<int> temp = {nums[i], nums[l], nums[r], nums[k]};
//                        result.push_back(temp);
//                        l++;
//                        r--;
//                    }
//                }
//            }
//        }
//        return result;
//    }
//
//    void test() {
//        vector<int> nums = {0,0,0,0};
//        vector<vector<int>> result = fourSum(nums, 0);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 206
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//
//        if (head == nullptr) {
//            return nullptr;
//        }
//        //原地循环
//        ListNode *ptr = head;
//        head = head->next;
//        ListNode *newHead = nullptr;
//        while (ptr != nullptr) {
//            ptr->next = newHead;
//            newHead = ptr;
//            ptr = head;
//            if (head != nullptr) {
//                head = head->next;
//            }
//        }
//        return newHead;
//    }
//
//    ListNode* reverseList2(ListNode* head) {
//
//        if (head == nullptr) {
//            return nullptr;
//        }
//
//        return reverse(head, nullptr);
//    }
//
//    ListNode *reverse(ListNode *head, ListNode* ptr) {
//
//        if (head == nullptr) {
//            return ptr;
//        }
//        ListNode *temp = head->next;
//        head->next = ptr;
//        ptr = head;
//
//
//        return reverse(temp, ptr);
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,4,5};
//        vector<int>::iterator it = arr.begin();
//        ListNode *head = nullptr;
//        ListNode *temp = nullptr;
//        while (it != arr.end()) {
//            if (head == nullptr) {
//                head = new ListNode(*it);
//                temp = head;
//            }
//            else {
//                ListNode *node = new ListNode(*it);
//                temp->next = node;
//                temp = node;
//            }
//            it++;
//        }
//        tool.printList(head);
//        ListNode *result = reverseList2(head);
//        tool.printList(result);
//
//    }
//};

#pragma mark - 142
//class Solution {
//public:
//    ListNode *detectCycle(ListNode *head) {
//
//        //floyd判环
//        if (head == nullptr) {
//            return nullptr;
//        }
//
//        ListNode *slow = head, *fast = head;
//        int time = 0;
//        while (true) {
//            if (fast == slow) {
//                time++;
//
//                if (time == 3) return fast;
//
//                if (time == 2) {
//                    fast = head;
//                    continue;
//                }
//            }
//
//            if (fast->next == nullptr || fast->next->next == nullptr) {
//                return nullptr;
//            }
//
//            if (time == 1) {
//                fast = fast->next->next;
//                slow = slow->next;
//            }
//
//            if (time == 2) {
//                fast = fast->next;
//                slow = slow->next;
//            }
//        }
//    }
//
//    void test() {
//        vector<int> arr = {1};
//        int pos = 0;
//
//        //create list
//        ListNode *cyclePtr = nullptr;
//        ListNode *head = nullptr;
//        ListNode *current = nullptr;
//        for (int i = 0; i < arr.size(); i++) {
//            if (head == nullptr) {
//                head = new ListNode(arr[i]);
//                current = head;
//            }
//            else {
//                ListNode *node = new ListNode(arr[i]);
//                current->next = node;
//                current = node;
//            }
//
//            if (i == pos) {
//                cyclePtr = current;
//            }
//        }
//
//        current->next = cyclePtr;
//
////        tool.printList(head);
//        ListNode *result = detectCycle(head);
//        int i = 0;
//    }
//};

#pragma mark - 209
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        //双指针
//        if (nums.size() == 0) {
//            return 0;
//        }
//        int l = 0, r = 1;
//        int minLength = INT_MAX;
//        int count = nums[l];
//        while (r <= nums.size()) {
//            if (count >= target) {
//                minLength = min(minLength, r - l);
//
//                if (minLength == 1) {
//                    return minLength;
//                }
//
//                count -= nums[l];
//                l++;
//                continue;
//            }
//            if (r < nums.size()) {
//                count += nums[r];
//            }
//            r++;
//
//
//        }
//
//        return minLength > nums.size() ? 0 : minLength;
//    }
//
//    int minSubArrayLen2(int target, vector<int>& nums) {
//        //前缀和 二分
//        vector<int> sums(nums);
//        int minLength = INT_MAX;
//        for (int i = 1; i < sums.size(); i++) {
//            sums[i] = sums[i] + sums[i - 1];
//        }
//
//        for (int i = 0; i < sums.size(); i++) {
//            if (sums[i] >= target) {
//                int lessIndex = getLessNumIndex(sums, sums[i] - target, 0, i);
//                if (lessIndex == i) {
//                    return 1;
//                }
//                minLength = min(minLength, i - lessIndex);
//
//            }
//        }
//
//        return minLength > nums.size() ? 0 : minLength;
//    }
//
//    int getLessNumIndex(vector<int>& arr, int target, int l, int r) {
//        int temp = -1;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (arr[mid] > target) {
//                r = mid - 1;
//            }
//            else {
//                temp = mid;
//                l = mid + 1;
//            }
//        }
//
//        return temp;
//    }
//
//    void check() {
//        for (int i = 0; i < 100; i++) {
//            int n = rand() % 10;
//            vector<int> arr(n);
//            for (int j = 0; j < n; j++) {
//                arr[j] = rand() % 10;
//            }
//            int target = rand() % 10;
//            int result = minSubArrayLen(target, arr);
//            int result2 = minSubArrayLen2(target, arr);
//
//            if (result != result2) {
//                cout<<"false:"<<result<<" "<<result2<<endl;
//                tool.printVector(arr);
//                cout<<"target:"<<target<<endl;
//                return;
//            }
//        }
//
//        cout<<"success"<<endl;
//    }
//
//    void test() {
//        check();
//        return;
//
//        vector<int> nums = {0,9,2,4};
//        int result = minSubArrayLen2(9, nums);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 59
//class Solution {
//public:
//    vector<vector<int>> generateMatrix(int n) {
//        //循环
//        vector<vector<int>> result(n, vector<int>(n));
//        int limitI = 0, limitJ = 0;
//        int i = 0, j = 0;
//        int count = 1;
//        while (limitI <= (n >> 1)) {
//            i = limitI;
//            j = limitJ;
//            while (j < n - limitJ) {
//                result[i][j++] = count++;
//            }
//
//
//            j = n - limitJ - 1;
//            i++;
//            while (i < n - limitI) {
//                result[i++][j] = count++;
//            }
//
//            i = n - limitI - 1;
//            j--;
//            limitI++;
//            while (j >= limitJ) {
//                result[i][j--] = count++;
//            }
//
//            j = limitJ;
//            i--;
//            while (i >= limitI) {
//                result[i--][j] = count++;
//            }
//            limitJ++;
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<vector<int>> result = generateMatrix(2);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 203
//class Solution {
//public:
//    ListNode* removeElements(ListNode* head, int val) {
//        //新链表
//        ListNode *newHead = nullptr;
//        ListNode *ptr = nullptr;
//        while (head != nullptr) {
//            if (head->val != val) {
//                if (newHead == nullptr) {
//                    newHead = new ListNode(head->val);
//                    ptr = newHead;
//                }
//                else {
//                    ListNode *node = new ListNode(head->val);
//                    ptr->next = node;
//                    ptr = ptr->next;
//                }
//            }
//            head = head->next;
//        }
//
//        return newHead;
//    }
//
//    ListNode* removeElements2(ListNode* head, int val) {
//        //原链表删除
//        ListNode *ptr = head;
//        ListNode *temp = nullptr;
//        ListNode *lastPtr = nullptr;
//        while (ptr != nullptr) {
//            if (ptr->val == val) {
//                if (ptr == head) {
//                    head = head->next;
//                    delete ptr;
//                    ptr = head;
//                    continue;
//                }
//                else {
//                    temp = ptr->next;
//                    delete ptr;
//                    lastPtr->next = temp;
//                    ptr = temp;
//                    continue;
//                }
//            }
//            lastPtr = ptr;
//            ptr = ptr->next;
//        }
//        return head;
//    }
//
//    ListNode* removeElements3(ListNode* head, int val) {
//        //原链表 虚拟头节点
//        ListNode *virtualHead = new ListNode(0, head);
//        ListNode *ptr = virtualHead;
//        while (ptr != nullptr && ptr->next != nullptr) {
//            if (ptr->next->val == val) {
//                ListNode *node = ptr->next->next;
//                delete ptr->next;
//                ptr->next = node;
//                continue;
//            }
//            ptr = ptr->next;
//        }
//
//        return virtualHead->next;
//    }
//
//    void test() {
//        vector<int> arr = {2,2,2,23,4,5,6,7};
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//        ListNode *newHead = removeElements3(head, 2);
//        tool.printList(newHead);
//    }
//};

#pragma mark - 707
//class MyLinkedList {
//
//public:
//
//    ListNode *head;
//    int size;
//
//    /** Initialize your data structure here. */
//    MyLinkedList() {
//        head = new ListNode(0);
//        size = 0;
//    }
//
//    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
//    int get(int index) {
//        if (index >= size || index < 0) {
//            return -1;
//        }
//        ListNode *ptr = head->next;
//        for (int i = 0; i < index; i++) {
//            ptr = ptr->next;
//        }
//
//        return ptr->val;
//    }
//
//    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
//    void addAtHead(int val) {
//        ListNode *ptr = head->next;
//        ListNode *temp = new ListNode(val, ptr);
//        head->next = temp;
//        size++;
//    }
//
//    /** Append a node of value val to the last element of the linked list. */
//    void addAtTail(int val) {
//        ListNode *ptr = head;
//        while (ptr->next != nullptr) {
//            ptr = ptr->next;
//        }
//        ptr->next = new ListNode(val);
//        size++;
//    }
//
//    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
//    void addAtIndex(int index, int val) {
//        if (index > size || index < 0) {
//            return;
//        }
//        ListNode *ptr = head;
//        for (int i = 0; i < index; i++) {
//            ptr = ptr->next;
//        }
//        ListNode *temp = ptr->next;
//        ptr->next = new ListNode(val, temp);
//        size++;
//    }
//
//    /** Delete the index-th node in the linked list, if the index is valid. */
//    void deleteAtIndex(int index) {
//        if (index >= size || index < 0) {
//            return;
//        }
//        ListNode *ptr = head;
//        for (int i = 0; i < index; i++) {
//            ptr = ptr->next;
//        }
//
//        ListNode *temp = ptr->next->next;
//        delete ptr->next;
//        ptr->next = temp;
//        size--;
//    }
//
//};
//
//class Solution {
//public:
//    void test() {
//        MyLinkedList list;
//        vector<int> arr = {2,3,4,5,6,7,78,3,3,1,4};
//        //test addAtHead
//        for (int i = 0; i < arr.size(); i++) {
////            list.addAtHead(arr[i]);
//        }
//
//        //test addAtTail
//        for (int i = 0; i < arr.size(); i++) {
//            list.addAtTail(arr[i]);
//        }
//
//        //test addAtIndex
//        list.addAtIndex(11, 99);
//
//        //test deleteAtIndex
//        list.deleteAtIndex(-1);
//
//        tool.printList(list.head);
//
//        //test get
//        int getVal = list.get(12);
//        cout<<getVal<<endl;
//    }
//};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#pragma mark - 242
//class Solution {
//public:
//    bool isAnagram(string s, string t) {
//        unordered_map<char, int> map;
//        if (s.size() != t.size()) {
//            return false;
//        }
//        for (int i = 0; i < s.size(); i++) {
//            map[s[i]]++;
//        }
//
//        for (int i = 0; i < t.size(); i++) {
//            if (map[t[i]] <= 0) {
//                return false;
//            }
//            map[t[i]]--;
//        }
//
//        return true;
//    }
//
//    void test() {
//        bool result = isAnagram(" ", "1");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 349
//class Solution {
//public:
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        unordered_map<int, int> recodeMap;
//        unordered_map<int, int> resultMap;
//        for (int i = 0; i < nums1.size(); i++) {
//            recodeMap[nums1[i]] = 1;
//        }
//
//        for (int i = 0; i < nums2.size(); i++) {
//            if (recodeMap.count(nums2[i]) != 0) {
//                resultMap[nums2[i]] = 1;
//            }
//        }
//
//        vector<int> result;
//        unordered_map<int, int>::iterator it = resultMap.begin();
//        while (it != resultMap.end()) {
//            result.push_back(it->first);
//            it++;
//        }
//
//        return result;
//    }
//
//    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
//
//        vector<int> result;
//        //排序 双指针
//        sort(nums1.begin(), nums1.end());
//        sort(nums2.begin(), nums2.end());
//
//        for (int i = 0,j = 0; j < nums2.size() && i < nums1.size();) {
//
//            if (nums1[i] == nums2[j]) {
//                if (result.size() == 0 || nums1[i] != result[result.size() - 1]) {
//                    result.push_back(nums1[i]);
//                }
//                i++;
//                j++;
//            }
//            else if (nums1[i] > nums2[j]) {
//                j++;
//            }
//            else {
//                i++;
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> nums1 = {4,9,5};
//        vector<int> nums2 = {5,9,4,9,8,4};
//        vector<int> result = intersection2(nums1, nums2);
//        tool.printVector(result);
//    }
//};

#pragma mark - 202
//class Solution {
//public:
//    bool isHappy(int n) {
//        unordered_set<int> recodeSet;
//        int sum = n;
//        while (sum != 1) {
//            sum = getHappySum(sum);
//
//            if (recodeSet.find(sum) != recodeSet.end()) {
//                return false;
//            }
//
//            recodeSet.insert(sum);
//        }
//
//        return true;
//    }
//
//    int getHappySum(int n) {
//        int sum = 0;
//        do {
//            int temp = n % 10;
//            sum += temp * temp;
//            n = n / 10;
//        } while (n != 0);
//
//        return sum;
//    }
//
//    void test() {
//        bool result = isHappy(2);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 454
//class Solution {
//public:
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//        //循环 map
//        unordered_map<int, int> map;
//        for (int i = 0; i < A.size(); i++) {
//            for (int j = 0; j < B.size(); j++) {
//                map[A[i] + B[j]]++;
//            }
//        }
//
//        int count = 0;
//        for (int i = 0; i < C.size(); i++) {
//            for (int j = 0; j < D.size(); j++) {
//                int temp = - (C[i] + D[j]);
//                if (map.count(temp) != 0) {
//                    count += map[temp];
//                }
//            }
//        }
//
//        return count;
//    }
//    void test() {
//        vector<int> A = {1, 2};
//        vector<int> B = {-2, -1};
//        vector<int> C = {-1, 2};
//        vector<int> D = {0, 2};
//
//        int count = fourSumCount(A, B, C, D);
//        cout<<count<<endl;
//    }
//};

#pragma mark - 383
//class Solution {
//public:
//    bool canConstruct(string ransomNote, string magazine) {
//        // map
//        unordered_map<char, int> map;
//        for (int i = 0; i < magazine.size(); i++) {
//            map[magazine[i]]++;
//        }
//
//        for (int i = 0; i < ransomNote.size(); i++) {
//            if (map.count(ransomNote[i]) != 0) {
//                if (--map[ransomNote[i]] < 0) {
//                    return false;
//                }
//            }
//            else {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    bool canConstruct2(string ransomNote, string magazine) {
//        //数组
//        vector<int> arrMagazineCount(26);
//        for (int i = 0; i < magazine.size(); i++) {
//            arrMagazineCount[(magazine[i] - 'a')]++;
//        }
//
//        for (int i = 0; i < ransomNote.size(); i++) {
//            if (--(arrMagazineCount[(ransomNote[i] - 'a')]) < 0) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        bool result = canConstruct2("a", "ab");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 344
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int l = 0, r = (int)s.size() - 1;
//        while (l < r) {
//            swap(s, l++, r--);
//        }
//    }
//
//    void swap(vector<char>& arr, int i, int j) {
//        char temp = arr[i];
//        arr[i] = arr[j];
//        arr[j] = temp;
//    }
//
//    void test() {
//        vector<char> s = {'h','e','l','l','o'};
//        reverseString(s);
//        vector<char>::iterator it = s.begin();
//        while (it != s.end()) {
//            cout<<*it<<",";
//            it++;
//        }
//        cout<<endl;
//    }
//};

#pragma mark - 541
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        if (k <= 1) {
//            return s;
//        }
//        for (int i = 0, n = 0; i < s.size(); i += k, n++) {
//            if (n % 2 == 0) {
//                int r = i + k - 1;
//                if (i + k > s.size()) {
//                    r = (int)s.size() - 1;
//                }
//                reverseString(s, i, r);
//            }
//        }
//
//        return s;
//    }
//
//    void reverseString(string& s, int i ,int j) {
//        int l = i, r = j;
//        while (l < r) {
//            swap(s, l++, r--);
//        }
//    }
//
//    void swap(string& s, int i, int j) {
//        char temp = s[i];
//        s[i] = s[j];
//        s[j] = temp;
//    }
//
//    void test() {
//        string s = "abcdefghijklmn";
//        string result = reverseStr(s, 0);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 剑指05
//class Solution {
//public:
//    string replaceSpace(string s) {
//        //新字符串
//        string result = "";
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ') {
//                result += s[i];
//            }
//            else {
//                result += "%20";
//            }
//        }
//        return result;
//    }
//
//    string replaceSpace2(string s) {
//        //原数组添加
//        int length = (int)s.size();
//        int count = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == ' ') count++;
//        }
//
//        if (count == 0) {
//            return s;
//        }
//
//        s.resize(s.size() + count * 2);
//
//        int j = (int)s.size() - 1;
//        for (int i = length - 1; i >= 0; i--) {
//            if (s[i] == ' ') {
//                s[j--] = '0';
//                s[j--] = '2';
//                s[j--] = '%';
//            }
//            else {
//                s[j--] = s[i];
//            }
//        }
//
//        return s;
//    }
//
//    void test() {
//        string result = replaceSpace2("We are happy.");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 151
//class Solution {
//public:
//    string reverseWords(string s) {
//        //数组
//        vector<string> arrResult;
//        int l = -1;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ' && l == -1) {
//                l = i;
//            }
//
//            if (s[i] == ' ' && l != -1 ) {
//                string str = s.substr(l, i - l);
//                arrResult.push_back(str);
//                l = -1;
//            }
//
//            if (i == s.size() - 1 && l != -1) {
//                string str = s.substr(l, i - l + 1);
//                arrResult.push_back(str);
//                l = -1;
//            }
//        }
//
//        reverse(arrResult.begin(), arrResult.end());
//        string resultStr = "";
//        for (int i = 0; i < arrResult.size(); i++) {
//            resultStr += arrResult[i];
//            if (i != arrResult.size() - 1) {
//                resultStr += " ";
//            }
//        }
//
//        return resultStr;
//    }
//
//    string reverseWords2(string s) {
//        //原地处理
//
//        //过滤空格
//        int k = 0;
//        bool isSpace = false;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ') {
//                if (isSpace == true) {
//                    if (k != 0) {
//                        s[k++] = ' ';
//                    }
//                    isSpace = false;
//                }
//                s[k++] = s[i];
//            }
//            else {
//                isSpace = true;
//            }
//        }
//
//        int length = k;
//        s.resize(length);//重新设置新大小
//        reverseString(s, 0, length - 1);//整体反转字符串
//        int l = -1;
//        //每个小字符串反转
//        for (int i = 0; i < length; i++) {
//            if (s[i] != ' ' && l == -1) {
//                l = i;
//            }
//
//            if (s[i] == ' ' && l != -1) {
//                reverseString(s, l, i - 1);
//                l = -1;
//            }
//
//            if (i == length - 1 && l != -1) {
//                reverseString(s, l, i);
//                l = -1;
//            }
//        }
//
//        return s;
//    }
//
//    void reverseString(string& s, int i, int j) {
//        int l = i , r = j;
//        while (l < r) {
//            swap(s[l++], s[r--]);
//        }
//    }
//
//    void test() {
//        string result = reverseWords2("    the    sky is    blue   ");
//        cout<<"!"<<result<<"!"<<endl;
//    }
//};

#pragma mark - 剑指 58 II
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        //原地处理

        //反转第一部分字串
        reverseString(s, 0, n - 1);
        //反转第二部分字串
        reverseString(s, n, (int)s.size() - 1);
        //整体反转
        reverseString(s, 0, (int)s.size() - 1);

        return s;
    }

    void reverseString(string& s, int i, int j) {
        int l = i, r = j;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

    void test() {
        string result = reverseLeftWords("", 0);
        cout<<"!"<<result<<"!"<<endl;
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
