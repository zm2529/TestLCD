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

#include "Sort.hpp"

using namespace std;

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
//    void test(){
//        vector<int> nums = {1,2,3,8,9};
//        vector<int> vec = this->twoSum(nums, 10);
//        vector<int>::iterator it = vec.begin();
//        while (it != vec.end()) {
//            cout<<*it<<endl;
//            it++;
//        }
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
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int numsCount1 = (int)nums1.size();
        int numsCount2 = (int)nums2.size();
        int allCount = numsCount1 + numsCount2;
        int midIndex1, midIndex2;
        midIndex1 = midIndex2 = allCount / 2;
        if (allCount % 2 == 0) {
            midIndex1 = midIndex2 - 1;
        }

        int index = -1;
        double midNum = 0;
        int currentNum = 0;
        int i = 0, j = 0;
        while (i < numsCount1 && j < numsCount2) {
            index = i + j;
            if (nums1[i] < nums2[j]) {
                currentNum = nums1[i];
                i++;
            }
            else{
                currentNum = nums2[j];
                j++;
            }

            if (index == midIndex1) {
                midNum = currentNum;
            }

            if (index == midIndex2) {
                midNum += currentNum;
                midNum /= 2.0;
                return midNum;
            }
        }

        if (i < numsCount1) {
            if (index == midIndex1) {
                midNum += nums1[i];
            }
            else {
                midNum = (nums1[midIndex1 - j] + nums1[midIndex2 - j]);
            }
            return midNum / 2.0;
        }

        if (j < numsCount2) {
            if (index == midIndex1) {
                midNum += nums2[j];
            }
            else {
                midNum = (nums2[midIndex1 - i] + nums2[midIndex2 - i]);
            }
            return midNum / 2.0;
        }

        return 0;
    }

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int count = (int)nums1.size();
        if (count % 2 == 0) {
            return (nums1[count / 2] + nums1[count / 2 - 1]) / 2.0;
        }
        else {
            return nums1[count / 2];
        }
    }

    double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
        int start1 = 0, start2 = 0;
        int end1 = (int)nums1.size(), end2 = (int)nums2.size();
        int mid1 = 0, mid2 = 0;

        int allCount = (int)(nums1.size() + nums2.size());
        int targetIndex1, targetIndex2;

        /*
         nums1总数为m,nums2总数为n,
         如果nums1[a/2] < nums2[n/2],则（m + n）/ 2 + 1个数一定比[s1,mid1]的数大，所以m/2位置的数最大为（m + n）/ 2 - 1
         要寻找的是(m + n) / 2 和 （m + n）/ 2 - 1
         除非n=0,否则 m/2 - 1 != (m + n) / 2 - 1
         所以m/2之前的数一定不是要找的数，但不排除m/2

         同理n/2之后的数据也一定不是要找的数，但不排除n/2
         */
        while (true) {
            mid1 = (start1 + end1) / 2;
            mid2 = (start2 + end2) / 2;

            if (nums1[mid1] < nums2[mid2]) {
                start1 = mid1;
                end2 = mid2;
            }

            if (nums1[mid1] > nums2[mid2]) {
                start2 = mid2;
                end1 = mid1;
            }

            if (start1 == end1 && start2 == end2) {
                tark
            }
        }
    }

    void test(){
        vector<int> nums1 = {};
        vector<int> nums2 = {1};
        double testNum = findMedianSortedArrays3(nums1, nums2);
        cout<<testNum<<endl;
    }
};
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

int main(int argc, const char * argv[]) {
    // insert code here...

    Solution solution;
    solution.test();

//    Sort sort;
//    sort.test();

    return 0;
}
