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
//        cout<<result2<<endl;
//    }
//};

#pragma mark - 283
//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//
//        int curr = 0;
//        for (int i = 0; i < nums.size(); i++) {
//
//            if (nums[i] != 0) {
//                nums[curr] = nums[i];
//                curr++;
//            }
//        }
//
//        for (int i = curr; i < nums.size(); i++) {
//            nums[i] = 0;
//        }
//
//    }
//
//    void test() {
//        vector<int> arr = {1,0};
//
//        moveZeroes(arr);
//
//        tool.printVector(arr);
//    }
//};

#pragma mark - 992
//class Solution {
//public:
//    int subarraysWithKDistinct(vector<int>& A, int K) {
//        //未完成，超时
//        //双指针
//
//        unordered_map<int, int> map;
//
//        int l = 0, r = 0;
//        int count = 0;
//
//        while (r < A.size()) {
//            if (map.size() <= K) {//小于等于K个数，往后加一个数
//                map[A[r++]]++;
//            }
//
//            while (map.size() > K) {//大于K个数，从前往后删除
//                map[A[l]]--;
//                if (map[A[l]] <= 0) {
//                    map.erase(A[l]);
//                }
//                l++;
//            }
//
//            if (map.size() == K) {//等于K个数，尝试从前往后删除数，是否还符合条件，
//                count++;
//                int tempL = l;
//                unordered_map<int, int> tempMap = map;
//                while (r - tempL > 1) {
//                    tempMap[A[tempL]]--;
//                    if (tempMap[A[tempL]] > 0) {
//                        count++;
//                        tempL++;
//                    }
//                    else{
//                        break;
//                    }
//                }
//            }
//
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<int> A = {1,2,1,2,3};
//
//        int K = 2;
//
//        int result = subarraysWithKDistinct(A, K);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 76
//class Solution {
//public:
//    string minWindow(string S, string T) {
///**
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
//
// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
//
//
//
// 示例 1：
//
// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 示例 2：
//
// 输入：s = "a", t = "a"
// 输出："a"
//
//
// 提示：
//
// 1 <= s.length, t.length <= 105
// s 和 t 由英文字母组成
// */
//        //map记录t中每个字母的次数，从前向s后数组遍历每个字母在map中把次数减1，当map中所有次数都<=0时记录长度，然后从s头部逐渐删除字母增加map中字母的次数，记录长度直到map中有字母的次数大于0 一个位置最多被遍历两遍 时间O(n), 一个最多长度52的map 空间O(1)
//        if (S.size() < T.size()) {
//            return "";
//        }
//
//        int minLength = INT_MAX;
//        int minStart = 0;
//
//        unordered_map<char, int> map;
//
//        for (int i = 0; i < T.size(); i++) {
//            map[T[i]]++;
//        }
//        int sCount = (int)map.size();
//        int currCount = 0;
//        int j = 0;
//        for (int i = 0; i < S.size(); i++) {
//            if (map.count(S[i]) > 0) {//向后统计次数
//                map[S[i]]--;
//                if (map[S[i]] == 0) {
//                    currCount++;//记录匹配完成的字母个数
//                }
//            }
//
//            while  (currCount == sCount) {//字母个数相等，从前向后删减
//                if (minLength > (i - j + 1)) {
//                    minLength = i - j + 1;
//                    minStart = j;
//                }
//
//                if (minLength == T.size()) {
//                    return S.substr(minStart, minLength);;
//                }
//
//                if (map.count(S[j]) > 0) {
//                    map[S[j]]++;
//                    if (map[S[j]] > 0) {
//                        currCount--;
//                    }
//                }
//                j++;
//            }
//        }
//        if (minLength == INT_MAX) {
//            return "";
//        }
//        return S.substr(minStart, minLength);
//    }
//
//    void test() {
//        string result = minWindow("D", "D");
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 21
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//
//        ListNode *head = new ListNode(0), *temp = head;
//
//        while (l1 != nullptr && l2 != nullptr) {
//            if (l1->val > l2->val) {
//                temp->next = l2;
//                temp = temp->next;
//                l2 = l2->next;
//            }
//            else {
//                temp->next = l1;
//                temp = temp->next;
//                l1 = l1->next;
//            }
//        }
//
//        if (l1 != nullptr) {
//            temp->next = l1;
//        }
//        else {
//            temp->next = l2;
//        }
//
//        return head->next;
//    }
//
//    void test() {
//        vector<int> arr1 = {1,2,3,4,5,6,8};
//        ListNode *l1 = tool.createList(arr1, -1);
//        tool.printList(l1);
//
//        vector<int> arr2 = {1,2,7,9,19};
//        ListNode *l2 = tool.createList(arr2, -1);
//        tool.printList(l2);
//
//        ListNode *result = mergeTwoLists(l1, l2);
//
//        tool.printList(result);
//    }
//};

#pragma mark - 82
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        ListNode newHead(0, head);
//        ListNode *pre = &newHead;
//        int deleteVal = -999;
//        while (head != nullptr) {
//            if (head->next != nullptr && head->val == head->next->val) {
//                deleteVal = head->val;
//                pre->next = head->next->next;
//            }
//            else if (head->val == deleteVal) {//
//                pre->next = head->next;
//            }
//            else {
//                pre = head;
//            }
//            head = pre->next;
//        }
//
//        return newHead.next;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,3,4,4,5};
//
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = deleteDuplicates(head);
//        tool.printList(result);
//    }
//};

#pragma mark - 83
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        ListNode *newHead = new ListNode(0, head);
//        ListNode *pre = newHead;
//        ListNode *curr = pre->next;
//        while (curr != nullptr) {
//            if (curr->next != nullptr && curr->val == curr->next->val) {
//                pre->next = curr->next;
//            }
//            else {
//                pre = curr;
//            }
//            curr = pre->next;
//        }
//
//        return newHead->next;
//    }
//
//    void test() {
//        vector<int> arr = {1};
//
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = deleteDuplicates(head);
//        tool.printList(result);
//    }
//};

#pragma mark - 86
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode *bigHead = new ListNode();
//        ListNode *smallHead = new ListNode();
//        ListNode *newHead = smallHead;
//        ListNode *bigStart = bigHead;
//
//        while (head != nullptr) {
//            if (head->val < x) {
//                smallHead->next = head;
//                smallHead = smallHead->next;
//                head = head->next;
//                smallHead->next = nullptr;
//            }
//            else{
//                bigHead->next = head;
//                bigHead = bigHead->next;
//                head = head->next;
//                bigHead->next = nullptr;
//            }
//        }
//
//        smallHead->next = bigStart->next;
//
//        return newHead->next;
//    }
//
//    void test() {
//        vector<int> arr = {2};
//        int x = 1;
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = partition(head, x);
//        tool.printList(result);
//    }
//};

#pragma mark - 92
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//
//        int count = 1;
//
//        ListNode *reverseHead = new ListNode();
//        ListNode *reverseLast = nullptr;
//        ListNode *pL = nullptr, *pR = nullptr;
//
//        ListNode *curr = head;
//        while (curr != nullptr && count <= right) {
//
//            if (count >= left ) {
//                pR = curr->next;//记录下一个
//                curr->next = reverseHead->next;//插到第一个
//                reverseHead->next = curr;
//
//                if (reverseLast == nullptr) {
//                    reverseLast = curr;//记录第一个位置，是反转后的最后位置
//                }
//
//                curr = pR;
//            }
//            else {
//                pL = curr;
//                curr = curr->next;
//            }
//
//            count++;
//        }
//
//        if (reverseLast != nullptr) {//把尾巴连上
//            reverseLast->next = pR;
//        }
//
//        if (pL != nullptr) {//把头连上
//            pL->next = reverseHead->next;
//        }
//        else {
//            head = reverseHead->next;
//        }
//
//        return head;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,4,5};
//
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = reverseBetween(head, 1,1);
//        tool.printList(result);
//    }
//};

#pragma mark - 138
/**

 给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

 构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

 例如，如果原链表中有 X 和 Y 两个节点，其中 X.random --> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random --> y 。

 返回复制链表的头节点。

 用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

 val：一个表示 Node.val 的整数。
 random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 你的代码 只 接受原链表的头节点 head 作为传入参数。



 示例 1：



 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 示例 2：



 输入：head = [[1,1],[2,1]]
 输出：[[1,1],[2,1]]
 示例 3：



 输入：head = [[3,null],[3,0],[3,null]]
 输出：[[3,null],[3,0],[3,null]]
 示例 4：

 输入：head = []
 输出：[]
 解释：给定的链表为空（空指针），因此返回 null。


 提示：

 0 <= n <= 1000
 -10000 <= Node.val <= 10000
 Node.random 为空（null）或指向链表中的节点。
 */

// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};
//
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        //时间O(n) 空间O(n)
//        unordered_map<Node*, Node *> map;//记录原始node和对应的新的node
//
//        //next链
//        Node *newHead = new Node(0);
//        Node *curr = head;
//        Node *newCurr = newHead;
//        while (curr != nullptr) {
//            Node *node = new Node(curr->val);
//            newCurr->next = node;
//            newCurr = node;
//
//            map[curr] = node;
//
//            curr = curr->next;
//        }
//
//        //random链
//        curr = head;
//        newCurr = newHead->next;
//        while (curr != nullptr) {
//            if (curr->random != nullptr) {
//                newCurr->random = map[curr->random];
//            }
//
//            curr = curr->next;
//            newCurr = newCurr->next;
//        }
//
//        return newHead->next;
//    }
//
//    Node* copyRandomList2(Node* head) {
//        //空间迭代，新节点放到老节点next,O(n) O(n)(不算输出链表的空间)
//
//        if (head == nullptr) {
//            return nullptr;
//        }
//
//        //新节点放到next
//        Node *curr = head;
//        while (curr != nullptr) {
//            Node *node = new Node(curr->val);
//            Node *temp = curr->next;
//            curr->next = node;
//            node->next = temp;
//
//            curr = temp;
//        }
//
//        //设置新节点random
//        curr = head;
//        while (curr != nullptr) {
//            if (curr->random != nullptr) {
//                curr->next->random = curr->random->next;
//            }
//
//            curr = curr->next->next;
//        }
//
//        //拆出新链表
//        Node *newHead = new Node(0);
//        Node * newCurr = newHead;
//        curr = head;
//
//        while (curr != nullptr) {
//            newCurr ->next = curr->next;
//            curr->next = curr->next->next;
//            curr = curr->next;
//            newCurr = newCurr->next;
//        }
//
//        return newHead->next;
//    }
//
//    void test() {
//
//    }
//};

#pragma mark - 141
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
//    bool hasCycle(ListNode *head) {
//        //floyd判环
//        ListNode *f = head, *s = head;
//        while (f != nullptr && f->next != nullptr) {
//            f = f->next->next;
//            s = s->next;
//
//            if (f == s) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        vector<int> arr = {3,2,0,-4};
//
//        ListNode *head = tool.createList(arr, 0);
//
//        bool result = hasCycle(head);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 142
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
//    ListNode *detectCycle(ListNode *head) {
//        //floyd判环
//        ListNode *f = head, *s = head;
//
//        while (f != NULL && f->next != NULL) {
//            f = f->next->next;
//            s = s->next;
//
//            if (f == s) {
//                f = head;
//                while (f != s) {
//                    f = f->next;
//                    s = s->next;
//                }
//                return s;
//            }
//        }
//
//        return NULL;
//    }
//
//    void test() {
//        vector<int> arr = {3,2,0,-4};
//
//        ListNode *head = tool.createList(arr, -1);
//
//        ListNode *result = detectCycle(head);
//
//        cout<<(result != NULL ? result->val : -1)<<endl;
//    }
//};

#pragma mark - 143
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    void reorderList(ListNode* head) {
//
//        //时间O(n),空间O(n)
//        vector<ListNode *> allNode;
//
//        ListNode *curr = head;
//        while (curr != nullptr) {
//            allNode.push_back(curr);
//
//            curr = curr->next;
//        }
//
//        for (int i = 0; i * 2 < allNode.size() - 1; i++) {
//            allNode[i]->next = allNode[allNode.size() - 1 - i];
//            allNode[i]->next->next = allNode[i + 1];
//        }
//        allNode[allNode.size() / 2]->next = nullptr;
//    }
//
//    void reorderList2(ListNode* head) {
//        //找中点，然后翻转插入
//        //时间O(n),空间O(1)
//
//        //找中点
//        ListNode *f = head, *s = head;
//        ListNode *preS = head;
//        while (f != nullptr && f->next != nullptr) {
//            preS = s;
//            f = f->next->next;
//            s = s->next;
//        }
//
//        //中点到结尾反转
//        ListNode *pre = s->next;
//        s->next = nullptr;
//
//        if (pre != nullptr) {
//            ListNode *curr = pre->next;
//            pre->next = nullptr;
//            while (curr != nullptr) {
//                ListNode *temp = curr->next;
//                curr->next = pre;
//                pre = curr;
//                curr = temp;
//            }
//        }
//
//        //插入
//        ListNode *last = pre;
//        ListNode *curr = head;
//        while (curr != nullptr && last != nullptr) {
//            ListNode *temp0 = curr->next;
//            ListNode *temp1 = last->next;
//
//            curr->next = last;
//            last->next = temp0;
//
//            curr = temp0;
//            last = temp1;
//        }
//    }
//
//    void test() {
//        vector<int> arr = {1};
//
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        reorderList2(head);
//        tool.printList(head);
//    }
//};

#pragma mark - 148
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//class Solution {
//public:
//    ListNode* sortList(ListNode* head) {
//        //归并排序
//
//        ListNode *curr = head;
//        while (curr != nullptr && curr->next != nullptr) {
//            curr = curr->next;
//        }
//
//        return backtracking(head, curr);
//    }
//
//    ListNode* backtracking(ListNode *start, ListNode *end) {
//        if (start == nullptr || end == nullptr) {
//            return nullptr;
//        }
//
//        end->next = nullptr;
//
//        if (start == end) {
//            return start;
//        }
//
//        if (start->next == end) {
//            ListNode *head;
//            if (start->val < end->val) {
//                head = start;
//                head->next = end;
//            }
//            else{
//                head = end;
//                head->next = start;
//            }
//
//            head->next->next = nullptr;
//
//            return head;
//        }
//
//        ListNode *mid = getMidNode(start, end);
//        ListNode *temp = mid->next;
//        ListNode *left = backtracking(start, mid);
//        ListNode *right = backtracking(temp, end);
//
//        return merge(left, right);
//
//    }
//
//    ListNode* merge(ListNode *l, ListNode *r){
//        ListNode *head = new ListNode();
//        ListNode *curr = head;
//
//        while (l != nullptr || r != nullptr) {
//            if (l == nullptr) {
//                curr->next = r;
//                curr = curr->next;
//                r = r->next;
//                continue;
//            }
//
//            if (r == nullptr) {
//                curr->next = l;
//                curr = curr->next;
//                l = l->next;
//                continue;
//            }
//
//            if (l->val < r->val) {
//                curr->next = l;
//                curr = curr->next;
//                l = l->next;
//            }
//            else {
//                curr->next = r;
//                curr = curr->next;
//                r = r->next;
//            }
//        }
//        curr->next = nullptr;
//
//        return head->next;
//    }
//
//    ListNode* getMidNode(ListNode *start, ListNode *end) {
//
//        ListNode *s = start, *f = start;
//        while (f != nullptr && f != end &&
//               f->next != nullptr && f->next != end) {
//            s = s->next;
//            f = f->next->next;
//        }
//
//        return s;
//    }
//
//    void swap(ListNode *preA, ListNode *preB) {
//        ListNode *A = preA->next;
//        ListNode *B = preB->next;
//        ListNode *lastA = A->next;
//        ListNode *lastB = B->next;
//
//        preA->next = B;
//        preB->next = A;
//        A->next = lastA;
//        B->next = lastB;
//    }
//
//    void test() {
//        vector<int> arr = {70};
//
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = sortList(head);
//        tool.printList(result);
//    }
//};

#pragma mark - 234
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 * @全体成员 由于现在8层工位紧张，人事座位安排不开，所以需要咱们和坐在人事对面位置的运维的同事换座位。计划明天下午下班时搬。
 */
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        //找到中间，反转两边对比 O(n), O(1)
//        ListNode *s = head, *f = head;
//        while (f != nullptr) {
//            f = f->next;
//            s = s->next;
//            if (f != nullptr) {
//                f = f->next;
//            }
//        }
//
//        //反转
//        ListNode *pre = s;
//        ListNode *temp = nullptr;
//        ListNode *curr = nullptr;
//        if (pre != nullptr) {
//            curr = pre->next;
//            pre->next = nullptr;
//            while (curr != nullptr) {
//                temp = curr->next;
//                curr->next = pre;
//                pre = curr;
//                curr = temp;
//            }
//        }
//
//        //对比
//        ListNode *reverseHead = pre;
//        while (reverseHead != nullptr) {
//            if (reverseHead->val != head->val) {
//                return false;
//            }
//            reverseHead = reverseHead->next;
//            head = head->next;
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> arr = {1,2};
//
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        bool result = isPalindrome(nullptr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - jianzhi34
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
//    vector<vector<int>> result;
//    vector<vector<int>> pathSum(TreeNode* root, int target) {
//
//        vector<int> traversal;
//        DLRTraversal(root, 0, traversal, target);
//
//        return result;
//    }
//
//    void DLRTraversal(TreeNode *root, int count, vector<int>& traversal, int target) {
//
//        if (root == nullptr) {
//            return;
//        }
//
//        if (root->left == nullptr && root->right == nullptr) {
//            if (count + root->val == target) {
//                traversal.push_back(root->val);
//                result.push_back(traversal);
//                traversal.pop_back();
//            }
//            return;
//        }
//
//        traversal.push_back(root->val);
//        count += root->val;
//        DLRTraversal(root->left, count, traversal, target);
//        DLRTraversal(root->right, count, traversal, target);
//        count -= root->val;
//        traversal.pop_back();
//    }
//
//    void test() {
//        vector<int> arr = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
//
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<vector<int>> result = pathSum(root, 22);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 1372
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
//    int maxLength = 0;
//    int longestZigZag(TreeNode* root) {
//        DLRTraversal(root, 0, true);
//
//        return maxLength - 1;
//    }
//
//    void DLRTraversal(TreeNode* root, int count, bool isLeft) {
//
//        if (root == nullptr) {
//            maxLength = max(maxLength, count);//没有节点，记录最大值
//            return;
//        }
//
//        if (isLeft) {
//            DLRTraversal(root->right, count + 1, false);//有反转节点，向下记录
//            DLRTraversal(root->left, 1, true);//重新开始记录节点
//        }
//        else {
//            DLRTraversal(root->left, count + 1, true);
//            DLRTraversal(root->right, 1, false);
//        }
//    }
//
//    void test() {
//        vector<int> arr = {1};
//
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
////[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,
//        int result = longestZigZag(root);
//
//        cout<<result<<endl;
//    }
//
//
//};

#pragma mark - jianzhi37
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Codec {
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//
//        string result = "";
//
//        deque<TreeNode *> deque;
//        if (root != nullptr) {
//            deque.push_back(root);
//        }
//
//        while (deque.size() > 0) {
//
//            int size = (int)deque.size();
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//
//                if (node != nullptr) {
//                    result += (to_string(node->val) + ",");
//
//                    deque.push_back(node->left);
//                    deque.push_back(node->right);
//                }
//                else {
//                    result += "n,";
//                }
//            }
//        }
//
//        return result;
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        TreeNode *root = nullptr;
//        deque<TreeNode *> deque;
//        char *p = strtok(&data[0], ",");
//
//        while (p != nullptr) {
//            if (root == nullptr) {
//                string str = p;
//                if (str != "n") {
//                    root = new TreeNode(stoi(str));
//                    deque.push_back(root);
//                }
//                else {
//                    return nullptr;
//                }
//            }
//            else {
//                int dequeSize = (int)deque.size();
//                if (dequeSize == 0) {
//                    break;
//                }
//                for (int j = 0; j < dequeSize && p != nullptr; j++) {
//                    TreeNode *node = deque.front();
//                    deque.pop_front();
//
//                    p = strtok(NULL, ",");
//                    {
//                        string str = p;
//                        if (str != "n") {
//                            node->left = new TreeNode(stoi(str));
//                            deque.push_back(node->left);
//                        }
//                    }
//
//                    p = strtok(NULL, ",");
//                    {
//                        string str = p;
//                        if (str != "n") {
//                            node->right = new TreeNode(stoi(str));
//                            deque.push_back(node->right);
//                        }
//                    }
//                }
//            }
//        }
//
//        return root;
//    }
//};
//
//class Solution {
//public:
//    void test() {
//        vector<int> arr = {1,2,3,-1,-1,4,5};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        Codec codec;
//        root->val = -1;
//        TreeNode *result = codec.deserialize(codec.serialize(root));
//        tool.printBT(result);
//    }
//};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

#pragma mark - 886
//class Solution {
//public:
//    //未完成
//    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//        //map记录每个人与谁不和
//        //f(i) 0没有队伍，1在一队，2在2队 f(i) = map[i][0] ... map[i][n] 都不同的队伍
//        //时间O(n) 空间O(n)
//
////        unordered_map<int, vector<int>> map;
////        for (int i = 0; i < dislikes.size(); i++) {
////            int p1 = dislikes[i][0];
////            int p2 = dislikes[i][1];
////            map[p1].push_back(p2);
////            map[p2].push_back(p1);
////        }
//
//        vector<int> arr(N + 1,0);
//        for (int i = 1; i <= dislikes.size(); i++) {
//            int p1 = dislikes[i][0];
//            int p2 = dislikes[i][1];
//            if (arr[p1] == 0) {
//                arr[p1] = 1;
//            }
//
//            if (arr[p2] == arr[p1]) {
//                return false;
//            }
//            arr[p2] = -1 * arr[p1];
//
////            for (int j = 0; j < map[i].size(); j++) {
////                int p = map[i][j];
////                if (arr[p] == arr[i]) {
////                    return false;
////                }
////                arr[map[i][j]] = -1 * arr[i];
////            }
//        }
//
//        for (int i = 1; i <= dislikes.size(); i++) {
//            int p1 = dislikes[i][0];
//            int p2 = dislikes[i][1];
//            if (arr[p1] == 0) {
//                arr[p1] = 1;
//            }
//
//            if (arr[p2] == arr[p1]) {
//                return false;
//            }
//            arr[p2] = -1 * arr[p1];
//
////            for (int j = 0; j < map[i].size(); j++) {
////                int p = map[i][j];
////                if (arr[p] == arr[i]) {
////                    return false;
////                }
////                arr[map[i][j]] = -1 * arr[i];
////            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<vector<int>> arr = {{21,47},{4,41},{2,41},{36,42},{32,45},{26,28},{32,44},{5,41},{29,44},{10,46},{1,6},{7,42},{46,49},{17,46},{32,35},{11,48},{37,48},{37,43},{8,41},{16,22},{41,43},{11,27},{22,44},{22,28},{18,37},{5,11},{18,46},{22,48},{1,17},{2,32},{21,37},{7,22},{23,41},{30,39},{6,41},{10,22},{36,41},{22,25},{1,12},{2,11},{45,46},{2,22},{1,38},{47,50},{11,15},{2,37},{1,43},{30,45},{4,32},{28,37},{1,21},{23,37},{5,37},{29,40},{6,42},{3,11},{40,42},{26,49},{41,50},{13,41},{20,47},{15,26},{47,49},{5,30},{4,42},{10,30},{6,29},{20,42},{4,37},{28,42},{1,16},{8,32},{16,29},{31,47},{15,47},{1,5},{7,37},{14,47},{30,48},{1,10},{26,43},{15,46},{42,45},{18,42},{25,42},{38,41},{32,39},{6,30},{29,33},{34,37},{26,38},{3,22},{18,47},{42,48},{22,49},{26,34},{22,36},{29,36},{11,25},{41,44},{6,46},{13,22},{11,16},{10,37},{42,43},{12,32},{1,48},{26,40},{22,50},{17,26},{4,22},{11,14},{26,39},{7,11},{23,26},{1,20},{32,33},{30,33},{1,25},{2,30},{2,46},{26,45},{47,48},{5,29},{3,37},{22,34},{20,22},{9,47},{1,4},{36,46},{30,49},{1,9},{3,26},{25,41},{14,29},{1,35},{23,42},{21,32},{24,46},{3,32},{9,42},{33,37},{7,30},{29,45},{27,30},{1,7},{33,42},{17,47},{12,47},{19,41},{3,42},{24,26},{20,29},{11,23},{22,40},{9,37},{31,32},{23,46},{11,38},{27,29},{17,37},{23,30},{14,42},{28,30},{29,31},{1,8},{1,36},{42,50},{21,41},{11,18},{39,41},{32,34},{6,37},{30,38},{21,46},{16,37},{22,24},{17,32},{23,29},{3,30},{8,30},{41,48},{1,39},{8,47},{30,44},{9,46},{22,45},{7,26},{35,42},{1,27},{17,30},{20,46},{18,29},{3,29},{4,30},{3,46}};
//
//        bool result = possibleBipartition(50, arr);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 654
//class Solution {
//public:
//    /**
//     给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
//
//     二叉树的根是数组 nums 中的最大元素。
//     左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
//     右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
//     返回有给定数组 nums 构建的 最大二叉树 。
//
//
//
//     示例 1：
//
//
//     输入：nums = [3,2,1,6,0,5]
//     输出：[6,3,5,null,2,0,null,null,1]
//     解释：递归调用如下所示：
//     - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
//         - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
//             - 空数组，无子节点。
//             - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
//                 - 空数组，无子节点。
//                 - 只有一个元素，所以子节点是一个值为 1 的节点。
//         - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
//             - 只有一个元素，所以子节点是一个值为 0 的节点。
//             - 空数组，无子节点。
//     示例 2：
//
//
//     输入：nums = [3,2,1]
//     输出：[3,null,2,null,1]
//
//
//     提示：
//
//     1 <= nums.length <= 1000
//     0 <= nums[i] <= 1000
//     nums 中的所有整数 互不相同
//
//     */
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        //时间O（n2）空间（1）
//        TreeNode *root = buildTree(nums, 0, (int)nums.size() - 1);
//
//        return root;
//    }
//
//    TreeNode *buildTree(vector<int>& nums, int l , int r) {
//        if (l > r) {
//            return nullptr;
//        }
//        int maxIndex = l;
//        for (int i = l; i <= r; i++) {
//            if (nums[maxIndex] < nums[i]) {
//                maxIndex = i;
//            }
//        }
//
//        TreeNode *node = new TreeNode(nums[maxIndex]);
//        node->left = buildTree(nums, l, maxIndex - 1);
//        node->right = buildTree(nums, maxIndex + 1, r);
//
//        return node;
//    }
//
//    void test() {
//        vector<int> arr = {3};
//
//        TreeNode *result = constructMaximumBinaryTree(arr);
//
//        tool.printBT(result);
//    }
//};

#pragma mark - 894
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
//    /**
//     满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。
//
//     返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。
//
//     答案中每个树的每个结点都必须有 node.val=0。
//
//     你可以按任何顺序返回树的最终列表。
//
//
//
//     示例：
//
//     输入：7
//     输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//     解释：
//
//
//
//     提示：
//
//     1 <= N <= 20
//     */
//
//    //得到一个列表，存放着所有满足条件的树的root
////    vector<TreeNode*> allPossibleFBT(int N) {
////        vector<TreeNode*> dp;
////
////        //边界条件1:如果输入的是偶数，return一个空列表
////        if(N & 1 == 0) return dp;
////        //边界条件2:如果输入为1，那么结果就只有一个值为0的结点
////        if(N == 1) {dp.push_back(new TreeNode(0));return dp;}
////
////        //我们知道一共有N个结点，root占了1个结点，左子树可能有1，3，5，..，N-2个结点
////        //对应的，右子树可能有N-2，..，5，3，1个结点
////        //那么，我们可以用一个循环，找到所有可能的左右子树的可能的数量的情况，把root放进列表里
////        for(int i=1;i<=N-2;i+=2){
////            //这里就是递归的精髓了，每次看到递归，就一头雾水
////            //在这里，我们不用去关心左右子树是怎么递归形成的
////            //我们可以仅仅去关心，这个函数，它实现的是什么功能
////            //allPossibleFBT(i)返回了一个列表，它存放着当结点数为i时，所有满足条件的树的root的集合
////            //我们可以认为，allPossibleFBT(i)存放着所有满足条件的左子树的集合
////            //同样，allPossibleFBT(N-1-i)存放着所有满足条件的右子树的集合
////            //这是由vector<TreeNode*> allPossibleFBT(int N)这个函数的定义所确定的
////            vector<TreeNode*> left = allPossibleFBT(i);
////            vector<TreeNode*> right = allPossibleFBT(N-1-i);
////
////            //接下来，就是左右子树的排列组合，当左子树为m时，右子树可能有right.size()个可能
////            //所以一共有right.size() * left.size()种可能
////            //我们把每一种排列，都放到我们所要的结果中
////            for(int j=0;j<left.size();++j){
////                for(int k=0;k<right.size();++k){
////                    TreeNode *root = new TreeNode(0);
////                    root->left = left[j];
////                    root->right = right[k];
////                    //对于左子树有i个结点，右子树有N-1-i个结点时，我们把所有可能的树push进入队列
////                    dp.push_back(root);
////                }
////            }
////        }
////        //所以说，看到递归，我们可以屏蔽掉复杂的递归思考过程，而是单纯的把递归函数本身，看成一个封装完全
////        //功能独立的一个函数。
////        return dp;
////    }
//
//    vector<TreeNode*> allPossibleFBT(int n) {
//        if (n % 2 == 0) {
//            return {};
//        }
//
//        if (n == 1) {
//            return {new TreeNode(0)};
//        }
//
//        vector<TreeNode *> result;
//        for (int i = 1; i < n; i += 2) {
//            vector<TreeNode *> left = allPossibleFBT(i);
//            vector<TreeNode *> right = allPossibleFBT(n - i - 1);
//
//            for (int j = 0; j < left.size(); j++) {
//                for (int k = 0; k < right.size(); k++) {
//                    TreeNode *root = new TreeNode(0);
//                    root->left = left[j];
//                    root->right = right[k];
//
//                    result.push_back(root);
//                }
//            }
//        }
//
//        return result;
//    }
//
//
//    void test() {
//        vector<TreeNode *> result = allPossibleFBT(7);
//
//        for (int i = 0; i < result.size(); i++) {
//            tool.printBT(result[i]);
//        }
//    }
//};

#pragma mark - 1008
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
//    /**
//     返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
//
//     (回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right。）
//
//     题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树。
//
//
//
//     示例：
//
//     输入：[8,5,1,7,10,12]
//     输出：[8,5,10,1,7,null,12]
//
//
//
//     提示：
//
//     1 <= preorder.length <= 100
//     1 <= preorder[i] <= 10^8
//     preorder 中的值互不相同
//     */
//    TreeNode* bstFromPreorder(vector<int>& preorder) {
//
//        //从前往后 preorder[i] > preorder[i + 1] 则 i + 1 为左节点，如果比 父节点 小为右节点，否则向上回溯到跟节点右节点
//        stack<TreeNode *> stack;
//        TreeNode *root = nullptr;
//        for (int i = 0; i < preorder.size(); i++) {
//            if (stack.size() == 0) {//创建跟节点
//                root = new TreeNode(preorder[i]);
//                stack.push(root);
//            }
//            else {
//                TreeNode *node = stack.top();
//                if (node->val > preorder[i]) {//比当前节点小，作为左节点
//                    node->left = new TreeNode(preorder[i]);
//                    stack.push(node->left);
//                }
//                else{//比当前节点大，和父节点对比
//                    stack.pop();
//                    if (stack.size() != 0) {//没有到头节点
//                        TreeNode *parent = stack.top();
//                        if (parent->val > preorder[i]) {//比父节点小，作为当前节点右节点
//                            node->right = new TreeNode(preorder[i]);
//                            stack.push(node->right);
//                        }
//                        else {//比父节点大，pop出当前节点，重新比较当前值
//                            i--;
//                        }
//                    }
//                    else {//当前节点为头节点，作为当前节点的右节点
//                        node->right = new TreeNode(preorder[i]);
//                        stack.push(node->right);
//                    }
//                }
//            }
//        }
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {8,5,1,7,10,12};
//
//        TreeNode *result = bstFromPreorder(arr);
//
//        tool.printBT(result);
//    }
//};

#pragma mark - 226
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
//    TreeNode* invertTree(TreeNode* root) {
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        TreeNode *temp = root->left;
//        root->left = root->right;
//        root->right = temp;
//
//        invertTree(root->left);
//        invertTree(root->right);
//
//
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {4,2,7,1,3,6,9};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = invertTree(root);
//        tool.printBT(result);
//    }
//};

#pragma mark - 543
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
//    int diameter = 0;
//    int diameterOfBinaryTree(TreeNode* root) {
//
//        maxDistanceTree(root);
//
//        return diameter;
//    }
//
//    int maxDistanceTree(TreeNode *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//
//        int left = maxDistanceTree(node->left);
//        int right = maxDistanceTree(node->right);
//
//        diameter = max(diameter, left + right);
//
//        return max(left, right) + 1;
//    }
//
//    void test() {
//        vector<int> arr = {1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = diameterOfBinaryTree(root);
//        cout<<result<<endl;
//    }
//};
#pragma mark - 662
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
//    int widthOfBinaryTree(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        typedef pair<TreeNode*, int> NodePos;
//        deque<NodePos> deque;
//        deque.push_back(NodePos(root, 1));
//
//        int maxWidth = 0;
//
//        while (deque.size() != 0) {
//            int size = (int)deque.size();
//            int startPos = -1, endPos = -1;
//            for (int i = 0; i < size; i++) {
//                NodePos nodePos = deque.front();
//                deque.pop_front();
//
//                TreeNode *node = nodePos.first;
//                int pos = nodePos.second;
//                if (startPos == -1) {
//                    startPos = pos;
//                }
//                pos -= startPos;
//                endPos = pos;
//
//                if (node->left != nullptr) {
//                    deque.push_back(NodePos(node->left, pos * 2));
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(NodePos(node->right, pos * 2 + 1));
//                }
//            }
//
//            maxWidth = max(maxWidth, endPos + 1);
//        }
//
//        return maxWidth;
//    }
//
//    void test() {
//        vector<int> arr = {1,1,1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,1,-1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = widthOfBinaryTree(root);
//        cout<<result<<endl;
//    }
//
//};

#pragma mark - 971
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
//    vector<int> result;
//    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
//        if (root == nullptr) {
//            return {};
//        }
//
//        int index = 0;
//        treeTraversal(root, index, voyage);
//
//        return result;
//    }
//
//    void treeTraversal(TreeNode *node, int &index, vector<int>& voyage) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (index >= voyage.size()) {
//            return;
//        }
//
//        if (result.size() >= 1 && result[0] == -1) {
//            return;
//        }
//
//        if (node->val != voyage[index]) {
//            result.clear();
//            result.push_back(-1);
//            return;
//        }
//
//        if (node->left != nullptr && node->left->val != voyage[index + 1]) {
//            TreeNode *temp = node->left;
//            node->left = node->right;
//            node->right = temp;
//            result.push_back(node->val);
//        }
//
//        index++;
//        treeTraversal(node->left, index, voyage);
//        treeTraversal(node->right, index, voyage);
//
//    }
//
//
//    void test() {
//        /**
//         [1,2,null,3]
//         [1,3,2]
//         [15,26,40,25,38,29,6,48,1,16,8,18,27,21,19,31,39,46,null,49,45,null,22,34,41,42,null,9,null,2,4,null,null,null,17,null,null,null,null,36,24,null,33,null,30,null,null,23,37,null,null,5,12,null,10,7,null,null,null,13,null,null,null,11,43,null,null,null,null,null,null,50,35,3,32,null,null,null,null,null,null,null,null,null,47,null,28,44,14,null,null,null,null,null,20]
//         [15,40,6,21,9,19,2,12,50,47,35,28,20,5,4,10,32,3,14,44,29,18,34,7,11,43,41,27,42,37,23,26,38,16,45,24,13,36,49,8,22,33,25,1,46,48,31,39,17,30]
//
//         [8,9,4,12,46,7,14,48,29,6,37,10,null,null,15,26,3,50,42,45,null,17,40,null,null,18,null,null,25,11,31,41,null,null,null,1,null,null,null,22,19,null,null,null,null,13,null,null,null,null,34,null,null,27,null,23,null,28,38,null,null,33,null,16,20,null,null,43,null,44,35,5,49,21,36,24,null,2,47,null,null,null,null,null,39,null,null,null,null,null,null,null,32,null,30]
//         [8,9,12,29,42,50,41,34,48,26,25,49,31,11,13,38,43,24,28,46,6,45,1,37,40,22,27,33,44,47,30,2,32,35,19,23,16,5,3,39,20,36,21,17,4,14,15,18,7,10]
//         */
//        vector<int> arr = {1,2,3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<int> voyage = {1,3,2};
//        vector<int> result = flipMatchVoyage(root, voyage);
//
//        tool.printBT(root);
//
//        tool.printVector(voyage);
//        DLR(root);
//        cout<<endl;
//
//        tool.printVector(result);
//    }
//
//    void DLR(TreeNode *node) {
//        if (node == nullptr) {
//            return;
//        }
//
//        cout<<node->val<<",";
//        DLR(node->left);
//        DLR(node->right);
//    }
//};

#pragma mark - 987
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
//    vector<vector<int>> verticalTraversal(TreeNode* root) {
//
//        //层先
//        vector<vector<int>> result;
//
//        unordered_map<int, vector<int>> map;
//        int minCol = 0, maxCol = 0;
//
//        typedef pair<int, int> NodePos;
//        typedef pair<TreeNode*, NodePos> NodeInfo;
//
//        deque<NodeInfo> deque;
//        if (root != nullptr) {
//            deque.push_back(NodeInfo(root, NodePos(0,0)));
//        }
//
//        while (deque.size() != 0) {
//            int size = (int)deque.size();
//            unordered_map<int, vector<int>> tempMap;
//            for (int i = 0; i < size; i++) {
//                NodeInfo info = deque.front();
//                deque.pop_front();
//
//                TreeNode *node = info.first;
//                NodePos pos = info.second;
//
//                maxCol = max(maxCol, pos.second);
//                minCol = min(minCol, pos.second);
//
//                tempMap[pos.second].push_back(node->val);
//
//                if (node->left != nullptr) {
//                    deque.push_back(NodeInfo(node->left, NodePos(pos.first + 1, pos.second - 1)));
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(NodeInfo(node->right, NodePos(pos.first + 1, pos.second + 1)));
//                }
//            }
//
//            unordered_map<int, vector<int>>::iterator it = tempMap.begin();
//            while (it != tempMap.end()) {
//                int col = it->first;
//                vector<int> arrVal = it->second;
//                sort(arrVal.begin(), arrVal.end());
//
//                map[col].insert(map[col].end(), arrVal.begin(), arrVal.end());
//                it++;
//            }
//        }
//
//
//        for (int i = minCol; i <= maxCol; i++) {
//            vector<int> colVal = map[i];
//            if (colVal.size() > 0) {
//                result.push_back(colVal);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {0,1,2,4,5,9,3,11,-1,-1,10,15,-1,6,18,14,-1,-1,21,-1,-1,7,12,-1,-1,22,-1,-1,24,13,8,-1,17,-1,-1,-1,-1,-1,-1,16,19,-1,-1,-1,-1,23,20};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<vector<int>> result = verticalTraversal(root);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 863
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
//    unordered_map<TreeNode*, TreeNode*> map;
//    vector<int> result;
//    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//
//        recodeTargetParents(root, target);
//
//        //查找target子节点
//        findK(target, K);
//
//        //查找target兄弟节点和祖先节点
//
//        K -= 1;
//        TreeNode *node = target;
//        while (node != nullptr && K >= 0) {
//            TreeNode *parentNode = map[node];
//            if (parentNode != nullptr) {
//                if (K == 0) {
//                    result.push_back(parentNode->val);
//                }
//
//                K -= 1;
//                if (parentNode->left == node) {
//                    findK(parentNode->right, K);
//                }
//                else {
//                    findK(parentNode->left, K);
//                }
//            }
//
//            node = parentNode;
//        }
//
//        return result;
//    }
//
//    void findK(TreeNode *node, int K) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (K == 0) {
//            result.push_back(node->val);
//            return;
//        }
//
//        findK(node->left, K - 1);
//        findK(node->right, K - 1);
//    }
//
//    bool recodeTargetParents(TreeNode *node, TreeNode *target) {
//        if (node == nullptr) {
//            return false;
//        }
//
//        if (node == target) {
//            return true;
//        }
//
//        bool isLeft = recodeTargetParents(node->left, target);
//        if (isLeft) {
//            map[node->left] = node;
//        }
//
//        bool isRight = recodeTargetParents(node->right, target);
//        if (isRight) {
//            map[node->right] = node;
//        }
//
//        return isLeft || isRight;
//    }
//
//    void test() {
//        vector<int> arr = {};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<int> result = distanceK(root, root->left->left, 2);
//        tool.printVector(result);
//    }
//
//};

#pragma mark - mianshi0406
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

 如果指定节点没有对应的“下一个”节点，则返回null。

 示例 1:

 输入: root = [2,1,3], p = 1

   2
  / \
 1   3

 输出: 2
 示例 2:

 输入: root = [5,3,6,2,4,null,null,1], p = 6

       5
      / \
     3   6
    / \
   2   4
  /
 1

 输出: null

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/successor-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
//class Solution {
//public:
//    TreeNode *targetNode = nullptr;
//    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//        //找大于p的最小值
//        if (root == nullptr) {
//            return targetNode;
//        }
//
//        if (root->val <= p->val) {//找大于p的值
//            inorderSuccessor(root->right, p);
//        }
//        else {
//            inorderSuccessor(root->left, p);
//        }
//        if (root->val > p->val) {//找到大于p值，取最小值
//            if (targetNode == nullptr) {
//                targetNode = root;
//            }
//            else if (root->val < targetNode->val) {
//                targetNode = root;
//            }
//        }
//
//        return targetNode;
//    }
//
//    void test() {
//        vector<int> arr = {5,3,6,2,4,-1,-1,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = inorderSuccessor(root, new TreeNode(3));
//        cout<<result->val<<endl;
//
//    }
//};

#pragma mark - 1046
//class Solution {
//public:
//    int lastStoneWeight(vector<int>& stones) {
////        sort(stones.begin(), stones.end(), [](int a, int b){
////            return a > b;
////        });
//
//        int start = 0;
//        while (start + 1 < (int)stones.size()) {
//            if (stones[start + 1] != stones[start]) {
//                stones.push_back(abs(stones[start] - stones[start + 1]));
////                sort(stones.begin() + start + 2, stones.end(), [](int a, int b){
////                    return a > b;
////                });
//            }
//            start += 2;
//        }
//
//        if (start == stones.size() - 1) {
//            return stones[start];
//        }
//        else {
//            return 0;
//        }
//    }
//
//    int lastStoneWeight2(vector<int>& stones) {
////        priority_queue
//        priority_queue<int> queue;
//        for (int i = 0; i < stones.size(); i++) {
//            queue.push(stones[i]);
//        }
//
//        while (queue.size() > 1) {
//            int y = queue.top();
//            queue.pop();
//
//            int x = queue.top();
//            queue.pop();
//
//            if (y != x) {
//                queue.push(y - x);
//            }
//        }
//
//        if (queue.size() == 1) {
//            return queue.top();
//        }
//        else {
//            return 0;
//        }
//    }
//
//    void test() {
//        vector<int> arr = {2,7,4,1,8,1};
//        int result = lastStoneWeight2(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 313
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

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
