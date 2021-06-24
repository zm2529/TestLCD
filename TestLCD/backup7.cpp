//
//  backup7.cpp
//  TestLCD
//
//  Created by zm on 2021/6/24.
//

#pragma mark - 42
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        vector<int> mLeft(height.size(), 0), mRight(height.size(), 0);
//
//        int size = (int)height.size();
//
//        int result = 0;
//
//        for (int i = 1; i < size - 1; i++) {
//            mLeft[i] = max(mLeft[i - 1], height[i - 1]);
//            mRight[size - 1 - i] = max(mRight[size - i], height[size - i]);
//        }
//
//        for (int i = 1; i < size - 1; i++) {
//            if (height[i] < mLeft[i] && height[i] < mRight[i]) {
//                result += min(mLeft[i], mRight[i]) - height[i];
//            }
//        }
//
//        return result;
//    }
//
//    int trap2(vector<int>& height) {
//
//        if (height.size() <= 2) {
//            return 0;
//        }
//
//        int l = 0, r = (int)height.size() - 1;
//
//        int mLeft = height[l], mRight = height[r];
//
//        int result = 0;
//
//        while (l < r) {
//            mLeft = max(mLeft, height[l]);
//            mRight = max(mRight, height[r]);
//
//            if (mLeft >= mRight) {
//                result += (mRight - height[r]);
//                r--;
//            }
//
//            if (mLeft < mRight) {
//                result += (mLeft - height[l]);
//                l++;
//            }
//        }
//
//        return result;
//    }
//
//    int trap3(vector<int>& height) {
//        if (height.size() <= 2) {
//            return 0;
//        }
//
//        stack<int> stack;
//
//        int result = 0;
//        int i = 0;
//        while (i < height.size()) {
//            if (stack.size() == 0) {
//                stack.push(i);
//                i++;
//            }
//            else {
//                int topVal = height[stack.top()];
//
//                if (topVal >= height[i]) {
//                    stack.push(i);
//                    i++;
//                }
//                else {
//                    stack.pop();
//
//                    if (stack.size() > 0) {
//                        result += ((min(height[stack.top()], height[i]) - topVal) * (i - stack.top() - 1));
//                    }
//                }
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
//        int result = trap3(height);
//        cout<<result<<endl;
//    }
//};

#pragma mark - jianzhi35

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
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        unordered_map<Node *, int> map;
//
//        Node *curr = head;
//        int i = 0;
//        while (curr != nullptr) {
//            map[curr] = i++;
//            curr = curr->next;
//        }
//
//        vector<int> arrRandomIndex(map.size(), -1);
//
//        curr = head;
//        i = 0;
//        while (curr != nullptr) {
//            if (curr->random != nullptr) {
//                arrRandomIndex[i] = map[curr->random];
//            }
//            i++;
//            curr = curr->next;
//        }
//
//        Node *newHead = new Node(0);
//        Node *newCurr = newHead;
//        curr = head;
//        vector<Node *> arrNewListNode;
//        while (curr != nullptr) {
//            newCurr->next = new Node(curr->val);
//            arrNewListNode.push_back(newCurr->next);
//            curr = curr->next;
//            newCurr = newCurr->next;
//        }
//
//        for (int i = 0; i < arrRandomIndex.size(); i++) {
//            if (arrRandomIndex[i] != -1) {
//                arrNewListNode[i]->random = arrNewListNode[arrRandomIndex[i]];
//            }
//        }
//
//        return newHead->next;
//    }
//
//    Node* copyRandomList2(Node* head) {
//
//        unordered_map<Node*, Node*> map;//老节点和新节点的对应
//
//        Node *curr = head;
//        Node *newHead = new Node(0);
//        Node *newCurr = newHead;
//        while (curr != nullptr) {
//            newCurr->next = new Node(curr->val);
//            map[curr] = newCurr->next;
//            newCurr = newCurr->next;
//            curr = curr->next;
//        }
//
//        curr = head;
//        newCurr = newHead->next;
//        while (curr != nullptr) {
//            if (curr->random != nullptr) {
//                newCurr->random = map[curr->random];
//            }
//            curr = curr->next;
//            newCurr = newCurr->next;
//        }
//
//        return newHead->next;
//    }
//
//    Node* copyRandomList3(Node* head) {
//
//        if (head == nullptr) {
//            return nullptr;
//        }
//
//        Node *curr = head;
//        Node *temp = nullptr;
//        while (curr != nullptr) {
//            temp = curr->next;
//            curr->next = new Node(curr->val);
//            curr->next->next = temp;
//            curr = temp;
//        }
//
//        curr = head;
//        temp = curr->next;
//        while (curr != nullptr && temp != nullptr) {
//            if (curr->random != nullptr) {
//                temp->random = curr->random->next;
//            }
//            curr = temp->next;
//            if (curr != nullptr) {
//                temp = curr->next;
//            }
//        }
//
//        Node *newHead = head->next;
//        curr = head;
//        temp = curr->next;
//        while (curr != nullptr && temp != nullptr) {
//
//            curr->next = temp->next;
//            curr = curr->next;
//
//            if (curr != nullptr) {
//                temp->next = curr->next;
//            }
//            temp = temp->next;
//        }
//
//        return newHead;
//    }
//};

#pragma mark - 1277
//class Solution {
//public:
//    int countSquares(vector<vector<int>>& matrix) {
//        //f[i,j] i,j位置的正方向大小，f[i][j] == 1 if (f[i - 1][j - 1] == f[i - 1][j] == f[i][j - 1]) {f[i][j] = f[i - 1][j - 1] + 1} else {f[i][j] = min{f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]} + 1};
//
//        vector<vector<int>> result(matrix);
//
//        int count = 0;
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix[i].size(); j++) {
//                if (matrix[i][j] == 1) {
//                    if (i > 0 && j > 0) {
//                        result[i][j] = min({result[i - 1][j - 1], result[i - 1][j], result[i][j - 1]}) + 1;
//                    }
//                    count += result[i][j];
//                }
//            }
//        }
//
//        return count;
//    }
//
//    int countSquares2(vector<vector<int>>& matrix) {
//        //优化 一维数组
//
//        vector<int> result(matrix[0]);
//
//
//        int count = 0;
//        for (int i = 0; i < matrix.size(); i++) {
//            vector<int> temp(result);
//            for (int j = 0; j < matrix[i].size(); j++) {
//                if (j == 0) {
//                    result[j] = matrix[i][j];
//                }
//
//                if (matrix[i][j] == 1) {
//                    if (i > 0 && j > 0) {
//                        result[j] = min({temp[j], temp[j - 1], result[j - 1]}) + 1;
//                    }
//                    count += result[j];
//                }
//                else {
//                    result[j] = 0;
//                }
//            }
//        }
//
//        return count;
//    }
//
//    void test() {
//        vector<vector<int>> arr = {
//            {0,1,1,1},
//            {1,1,0,1},
//            {1,1,1,1},
//            {1,0,1,0}
//        };
//
//        int result = countSquares2(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi_02.01
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
//    ListNode* removeDuplicateNodes(ListNode* head) {
//        unordered_set<int> set;
//
//        ListNode *curr = head;
//        ListNode *newHead = new ListNode(-1);
//        ListNode *newCurr = newHead;
//        while (curr != nullptr) {
//            if (set.find(curr->val) == set.end()) {
//                set.insert(curr->val);
//                newCurr->next = curr;
//                newCurr = newCurr->next;
//            }
//
//            curr = curr->next;
//        }
//        newCurr->next = nullptr;
//
//        return newHead->next;
//    }
//
//    ListNode* removeDuplicateNodes2(ListNode* head) {
//        ListNode *curr = head;
//        ListNode *newHead = new ListNode(-1);
//        ListNode *newCurr = newHead;
//        while (curr != nullptr) {
//            if (isDuplicate(newHead->next, curr)) {
//                newCurr->next = curr;
//                newCurr = newCurr->next;
//            }
//            curr = curr->next;
//
//            newCurr->next = nullptr;
//        }
//
//        return newHead->next;
//    }
//
//    bool isDuplicate(ListNode *head, ListNode *node) {
//        ListNode *curr = head;
//        while (curr != nullptr) {
//            if (curr->val == node->val) {
//                return false;
//            }
//            curr = curr->next;
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> arr = {1, 2, 3, 3, 2, 1};
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = removeDuplicateNodes2(head);
//        tool.printList(result);
//    }
//};

#pragma mark - mianshi_17.19
//class Solution {
//public:
//    vector<int> missingTwo(vector<int>& nums) {
//        //等差数列求和公式 na + n(n - 1)d / 2
//
//        //1-n求和 减去 数组和 = m， m分两半（两个数一个大于 m / 2, 一个小于 m / 2） 分别求和  应该和-实际和
//
//        int size = (int)nums.size() + 2;
//        int sum = size + (size - 1) * size / 2;
//
//        int missSum = accumulate(nums.begin(), nums.end(), 0);
//
//        int midSum = (sum - missSum) / 2;
//
//        int smallSum = midSum + (midSum - 1) * midSum / 2;
//        int bigSum = sum - smallSum;
//
//        int missSmallSum = 0, missBigSum = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > midSum) {
//                missBigSum += nums[i];
//            }
//            else {
//                missSmallSum += nums[i];
//            }
//        }
//
//        return {smallSum - missSmallSum, bigSum - missBigSum};
//    }
//
//    vector<int> missingTwo2(vector<int>& nums) {
//        //特殊归位
//
//        nums.push_back(-1);
//        nums.push_back(-1);
//        nums.push_back(-1);
//
//        for (int i = 0; i < nums.size(); i++) {
//            while (i != nums[i] && nums[i] != -1) {
//                swap(nums[i], nums[nums[i]]);
//            }
//        }
//
//        vector<int> result;
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums[i] == -1) {
//                result.push_back(i);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {1, 2, 3, 4, 6, 7, 9, 10};
//        vector<int> result = missingTwo2(arr);
//
//        tool.printVector(result);
//    }
//};

#pragma mark - mianshi_17.09
//class Solution {
//public:
//    int getKthMagicNumber(int k) {
//        priority_queue<int, vector<int>, greater<int>> queue;
//        unordered_set<int> set;
//
//        queue.push(1);
//        set.insert(1);
//
//        vector<int> arrNumber = {3,5,7};
//
//
//        for (int i = 0; i < k - 1; i++) {
//            int top = queue.top();
//            queue.pop();
//            for (int j = 0; j < arrNumber.size(); j++) {
//                long long val = top * (long long)arrNumber[j];
//
//                if (val <= INT_MAX && (set.find(val) == set.end())) {
//                    queue.push(val);
//                    set.insert(val);
//                }
//            }
//        }
//
//        return queue.top();
//    }
//
//    int getKthMagicNumber2(int k) {
//
//        vector<int> result;
//        result.push_back(1);
//
//        vector<int> arrNumber = {3,5,7};
//        vector<int> arrP(3,0);
//
//        for (int i = 0; i < k; i++) {
//
//            int minVal = INT_MAX;
//            int minIndex = 0;
//            for (int j = 0; j < arrP.size(); j++) {
//                int val = result[arrP[j]] * arrNumber[j];
//                if (minVal > val) {
//                    minVal = val;
//                    minIndex = j;
//                }
//            }
//            arrP[minIndex]++;
//
//            if (minVal == result.back()) {
//                i--;
//            }
//            else {
//                result.push_back(minVal);
//            }
//        }
//
//        return result[k - 1];
//    }
//
//    void test() {
//        int result = getKthMagicNumber2(7);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1310
//class Solution {
//public:
////    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
////        vector<int> result;
////        for (int i = 0; i < queries.size(); i++) {
////            int temp = 0;
////            for (int j = queries[i][0]; j <= queries[i][1]; j++) {
////                temp ^= arr[j];
////            }
////            result.push_back(temp);
////        }
////
////        return result;
////    }
//
//
////    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
////        //f[i][j] //从i到j的异或值，f[i][j] = f[i - 1][j] ^ arr[i]
////
////        vector<vector<int>> arrXor(arr.size(), vector<int>(arr.size(), 0));
////
////
////        for (int i = 0; i < arr.size(); i++) {
////            for (int j = i; j < arr.size(); j++) {
////                if (i == j) {
////                    arrXor[i][j] = arr[j];
////                }
////                else {
////                    arrXor[i][j] = arrXor[i][j - 1] ^ arr[j];
////                }
////            }
////        }
////
////        vector<int> result;
////        for (int i = 0; i < queries.size(); i++) {
////            result.push_back(arrXor[queries[i][0]][queries[i][1]]);
////        }
////
////        return result;
////    }
//
//
////    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
////        //f[i][j] //从i到j的异或值，f[i][j] = f[i - 1][j] ^ f[i]
////
////        vector<vector<int>> arrXor(arr.size(), vector<int>(arr.size(), -1));
////
////        vector<int> result;
////        for (int i = 0; i < queries.size(); i++) {
////            int val = xorArr(arr, queries[i][0], queries[i][1], arrXor);
////            result.push_back(val);
////        }
////
////        return result;
////    }
////
////    int xorArr(vector<int>& arr, int s, int e, vector<vector<int>>& arrXor) {
////
////        if (arrXor[s][e] != -1) {
////            return arrXor[s][e];
////        }
////
////        if (s == e) {
////            arrXor[s][e] = arr[s];
////            return arrXor[s][e];
////        }
////
////        int val = xorArr(arr, s, e - 1, arrXor) ^ arr[e];
////        arrXor[s][e] = val;
////
////        return arrXor[s][e];
////    }
//
//    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//
//        vector<int> arrXor(arr.size(), 0);
//        arrXor[0] = arr[0];
//
//        for (int i = 1; i < arr.size(); i++) {
//            arrXor[i] = arrXor[i - 1] ^ arr[i];
//        }
//
//        vector<int> result;
//        for (int i = 0; i < queries.size(); i++) {
//            if (queries[i][0] == 0) {
//                result.push_back(arrXor[queries[i][1]]);
//            }
//            else {
//                result.push_back(arrXor[queries[i][0] - 1] ^ arrXor[queries[i][1]]);
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> arr = {4,8,2,10};
//        vector<vector<int>> queries = {{2,3},{1,3},{0,0},{0,3}};
//
//        vector<int> result = xorQueries(arr, queries);
//        tool.printVector(result);
//    }
//
//};

#pragma mark - 1626
//class Solution {
//public:
//    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//
//        //f[i] 0-i 包含i的最高得分
//        vector<int> order(scores.size(), 0);
//        for (int i = 0; i < order.size(); i++) {
//            order[i] = i;
//        }
//
//        sort(order.begin(), order.end(), [&](int a, int b){
//            if (ages[a] == ages[b]) {
//                return scores[a] < scores[b];
//            }
//
//            return ages[a] < ages[b];
//        });
//
//        vector<int> arrScores(scores.size());
//        int result = 0;
//
//        for (int i = 0; i < order.size(); i++) {
//            arrScores[i] = scores[order[i]];
//
//            for (int j = 0; j < i; j++) {
//                if (scores[order[j]] <= scores[order[i]]) {
//                    arrScores[i] = max(arrScores[i], arrScores[j] + scores[order[i]]);
//                }
//            }
//
//            result = max(result, arrScores[i]);
//        }
//
//        return result;
//    }
//};

#pragma mark - 1080
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
//    TreeNode* sufficientSubset(TreeNode* root, int limit) {
//        treeTraversal(root, 0, limit);
//
//        return root;
//    }
//
//    int treeTraversal(TreeNode*& node, int parentSum, int limit) {
//        if (node == nullptr) {
//            return INT_MIN;
//        }
//
//        int leftSum = treeTraversal(node->left, parentSum + node->val, limit);
//        int rightSum = treeTraversal(node->right, parentSum + node ->val, limit);
//
//        int maxSum = max(leftSum, rightSum);//子树路径最大和
//
//        if (maxSum == INT_MIN) {//
//            maxSum = node->val;
//        }
//        else {
//            maxSum += node->val;
//        }
//
//        if (maxSum + parentSum < limit) {//各个路径和都小于limit 删除
//            node = nullptr;
//        }
//
//        return maxSum;
//    }
//
//    void test() {
//        /**
//         [1,2,-3,-5,null,4,null]
//         -1
//         */
//        vector<int> arr = {1,2,-3,-5,-1,4,-1};
//        int limit = -1;
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = sufficientSubset(root, limit);
//        tool.printBT(result);
//    }
//};

#pragma mark - mianshi_17.23
//class Solution {
//public:
////    vector<int> findSquare(vector<vector<int>>& matrix) {
////        //f[i][j]  i - j 中最大正方形长度，f[i][j] = min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1;
////
////        vector<vector<int>> result(matrix);
////
////        for (int i = 0; i < result.size(); i++) {
////            for (int j = 0; j < result[i].size(); j++) {
////                if (result[i][j] == 1) {
////                    result[i][j] = -1;
////                }
////            }
////        }
////
////        vector<int> ans(3,-1);
////        for (int i = 0; i < result.size(); i++) {
////            for (int j = 0; j < result[i].size(); j++) {
////
////                if (result[i][j] == 0) {
////                    if (i * j == 0) {
////                        result[i][j] = 1;
////                    }
////                    else {
////                        result[i][j] = max(min({result[i - 1][j], result[i][j - 1], result[i - 1][j - 1]}) + 1, 1);
////                    }
////                }
////
////                if (ans[2] < result[i][j]) {
////                    ans[0] = i - result[i][j] + 1;
////                    ans[1] = j - result[i][j] + 1;
////                    ans[2] = result[i][j];
////                }
////            }
////        }
////
////        tool.printMatrix(result);
////
////        if (ans[2] == -1) {
////            return {};
////        }
////
////        return ans;
////    }
//
//    vector<int> findSquare2(vector<vector<int>>& matrix) {
//
//        vector<int> result(3,0);
//        vector<vector<int>> rMatrix(matrix), bMatrix(matrix);
//
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix.size(); j++) {
//                if (matrix[i][j] == 1) {
//                    rMatrix[i][j] = 0;
//                    bMatrix[i][j] = 0;
//                }
//                else {
//                    if (j == 0) {
//                        rMatrix[i][j] = 1;
//                    }
//                    else {
//                        rMatrix[i][j] = rMatrix[i][j - 1] + 1;
//                    }
//
//                    if (i == 0) {
//                        bMatrix[i][j] = 1;
//                    }
//                    else {
//                        bMatrix[i][j] = bMatrix[i - 1][j] + 1;
//                    }
//                }
//            }
//        }
//
////        tool.printMatrix(rMatrix);
////        tool.printMatrix(bMatrix);
//
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix.size(); j++) {
//                int size = min({rMatrix[i][j], bMatrix[i][j]});
//                while (size > result[2]) {
//                    int indexI = i - size + 1;
//                    int indexJ = j - size + 1;
//                    if (rMatrix[indexI][j] >= size && bMatrix[i][indexJ] >= size) {
//                        result[2] = size;
//                        result[0] = indexI;
//                        result[1] = indexJ;
//                    }
//                    else{
//                        size--;
//                    }
//                }
//            }
//        }
//
//
//        if (result[2] == 0) {
//            return {};
//        }
//        return result;
//    }
//
//    void test() {
//        vector<vector<int>> arr =  {{1, 1, 1, 1, 0, 1, 0, 1, 1, 1}, {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 1, 0, 1, 0, 1}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, {1, 1, 0, 0, 1, 0, 1, 0, 0, 1}, {0, 0, 0, 1, 1, 1, 0, 1, 0, 1}, {0, 0, 0, 1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 1, 0, 1, 1, 1}, {1, 1, 1, 0, 1, 0, 0, 1, 1, 1}};
//
//        tool.printMatrix(arr);
//
//        vector<int> result = findSquare2(arr);
//        tool.printVector(result);
//    }
//};

#pragma mark - 97
//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.size() + s2.size() != s3.size()) {
//            return false;
//        }
//        return backtracking(s1, s2, s3, 0, 0, 0);
//    }
//
//    bool backtracking(string& s1, string& s2, string& s3, int index1, int index2, int index3) {
//        if (index3 == s3.size()) {
//            if (index1 == s1.size() && index2 == s2.size()) {
//                return true;
//            }
//            return false;
//        }
//
//        bool interleave1 = false;
//        if (index1 < s1.size() && s3[index3] == s1[index1]) {
//            interleave1 = backtracking(s1, s2, s3, index1 + 1, index2, index3 + 1);
//        }
//
//        if (interleave1) {
//            return interleave1;
//        }
//
//        bool interleave2 = false;
//        if (index2 < s2.size() && s3[index3] == s2[index2]) {
//            interleave2 = backtracking(s1, s2, s3, index1, index2 + 1, index3 + 1);
//        }
//
//        return interleave2;
//    }
//
//    bool isInterleave2(string s1, string s2, string s3) {
//        //f[i][j] 前i个s1和前j个s2 能否组成前i+j个s3 f[i][j] = (s1[i] == s3[i + j] && f[i - 1][j]) || (s2[j] == s3[i + j] && f[i][j - 1])
//
//        if (s1.size() + s2.size() != s3.size()) {
//            return false;
//        }
//
//        vector<vector<bool>> result(s1.size() + 1, vector<bool>(s2.size() + 1, false));
//
//        for (int i = 0; i <= s1.size(); i++) {
//            for (int j = 0; j <= s2.size(); j++) {
//                if (i == 0 && j == 0) {
//                    result[i][j] = true;
//                }
//                else {
//                    int index3 = i + j - 1;
//                    if (j != 0 && (s2[j - 1] == s3[index3] && result[i][j - 1])) {
//                        result[i][j] = true;
//                    }
//
//                    if (i != 0 && (s1[i - 1] == s3[index3] && result[i - 1][j])) {
//                        result[i][j] = true;
//                    }
//                }
//            }
//        }
//
//        return result[s1.size()][s2.size()];
//    }
//
//    bool isInterleave3(string s1, string s2, string s3) {
//
//        //优化 一维数组
//
//        if (s1.size() + s2.size() != s3.size()) {
//            return false;
//        }
//
//        vector<bool> result(s2.size() + 1, false);
//        for (int i = 0; i <= s1.size(); i++) {
//            for (int j = 0; j <= s2.size(); j++) {
//                if (i == 0 && j == 0) {
//                    result[j] = true;
//                }
//                else {
//                    int index3 = i + j - 1;
//                    bool temp = false;
//                    if (j != 0 && (s2[j - 1] == s3[index3] && result[j - 1])) {
//                        temp = true;
//                    }
//
//                    if (i != 0 && (s1[i - 1] == s3[index3] && result[j])) {
//                        temp = true;
//                    }
//
//                    result[j] = temp;
//                }
//            }
//        }
//
//        return result[s2.size()];
//    }
//
//    void test() {
//        /**
//         "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
//         "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
//         "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
//
//         "aabcc",
//         "dbbca",
//         "aadbbcbcac"
//         */
//        bool result = isInterleave3("a", "", "c");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 993
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
//    bool isCousins(TreeNode* root, int x, int y) {
//        //层先
//
//        if (root == nullptr) {
//            return false;
//        }
//
//        if (root->val == x || root->val == y) {
//            return false;
//        }
//
//        queue<TreeNode *> queue;
//        if (root != nullptr) {
//            queue.push(root);
//        }
//        TreeNode* firstNodeParent = nullptr;
//        while (queue.size() != 0) {
//            int size = (int)queue.size();
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = queue.front();
//                queue.pop();
//
//                if (node->left != nullptr) {
//                    if (node->left->val == x || node->left->val == y) {
//                        if (firstNodeParent != nullptr) {
//                            if (firstNodeParent != node) {
//                                return true;
//                            }
//                            else {
//                                return false;
//                            }
//                        }
//                        firstNodeParent = node;
//                    }
//                    queue.push(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    if (node->right->val == x || node->right->val == y) {
//                        if (firstNodeParent != nullptr) {
//                            if (firstNodeParent != node) {
//                                return true;
//                            }
//                            else {
//                                return false;
//                            }
//                        }
//                        firstNodeParent = node;
//                    }
//                    queue.push(node->right);
//                }
//            }
//
//            if (firstNodeParent != nullptr) {
//                return false;
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        /**
//         [1,2,3,null,4]
//         2
//         3
//         */
//        vector<int> arr = {1,2,3,-1,4};
//        int x = 2;
//        int y = 3;
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        bool result = isCousins(root, x, y);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 415
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        string result = "";
//
//        int index1 = (int)num1.size() - 1, index2 = (int)num2.size() - 1;
//
//        int lastNum = 0;
//        while (index1 >= 0 || index2 >= 0) {
//            int n1 = index1 >= 0 ? getIntFromChar(num1[index1]) : 0;
//            int n2 = index2 >= 0 ? getIntFromChar(num2[index2]) : 0;
//
//            int sum = lastNum + n1 + n2;
//            lastNum = sum / 10;
//            sum = sum % 10;
//
//            result.push_back((sum + '0'));
//
//            index1--;
//            index2--;
//        }
//
//        if (lastNum > 0) {
//            result.push_back('1');
//        }
//
//        string ans;
//        for (int i = (int)result.size() - 1; i >= 0 ; i--) {
//            ans.push_back(result[i]);
//        }
//
//        return ans;
//    }
//
//    int getIntFromChar(char c) {
//        return c - '0';
//    }
//
//    void test() {
//        string result = addStrings("198", "8");
//        cout<<result<<endl;
//    }
//};

#pragma mark - jianzhi_26
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
////    bool isSubStructure(TreeNode* A, TreeNode* B) {
////        //先序 遍历 找子串
////
////        if (A == nullptr || B == nullptr) {
////            return false;
////        }
////
////        string strA = "", strB = "";
////        traversal(A, strA);
////        traversal(B, strB);
////
////        if (strA.size() < strB.size()) {
////            return false;
////        }
////
////        if (strA.find(strB) == strA.npos) {
////            return false;
////        }
////
////        return true;
////
////    }
////
////    void traversal(TreeNode *root, string& result) {
////        if (root == nullptr) {
////            return;
////        }
////
////        result += to_string(root->val);
////        traversal(root->left, result);
////        traversal(root->right, result);
////    }
//
//
//    bool isSubStructure(TreeNode* A, TreeNode* B) {
//        if (A == nullptr || B == nullptr) {
//            if (A == B) {
//                return true;
//            }
//            return false;
//        }
//
//        if (checkSameTree(A, B)) {
//            return true;
//        }
//
//
//        bool aLeft = isSubStructure(A->left, B);
//        bool aRight = isSubStructure(A->right, B);
//
//        return aLeft || aRight;
//    }
//
//    bool checkSameTree(TreeNode *A, TreeNode * B) {
//        if (A == nullptr || B == nullptr) {
//            if (A == B) {
//                return true;
//            }
//            return false;
//        }
//
//        if (A->val == B->val) {
//            bool left = true;
//            if (B->left != nullptr) {
//                left = checkSameTree(A->left, B->left);
//            }
//
//            bool right = true;
//            if (B->right != nullptr) {
//                right = checkSameTree(A->right, B->right);
//            }
//
//            if (left && right) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        /*
//         [10,12,6,8,3,11]
//         [10,12,6,8]
//
//         [4,2,3,4,5,6,7,8,9]
//         [4,8,9]
//
//         [10,12,6,8,3,11]
//         [10,12,6,8]
//
//         [1,0,1,-4,-3]
//         [1,-4]
//         */
//        vector<int> arrA = {4,2,3,4,5,6,7,8,9};
//        vector<int> arrB = {4,8,9};
//
//        TreeNode *A = tool.createBT(arrA);
//        tool.printBT(A);
//        TreeNode *B = tool.createBT(arrB);
//        tool.printBT(B);
//
//        bool result = isSubStructure(A, B);
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi_01.07
//class Solution {
//public:
//    /**
//     给定 matrix =
//     [
//       [1,2,3],
//       [4,5,6],
//       [7,8,9]
//     ],
//
//     原地旋转输入矩阵，使其变为:
//     [
//       [7,4,1],
//       [8,5,2],
//       [9,6,3]
//     ]
//     */
//    void rotate(vector<vector<int>>& matrix) {
//        vector<int> arrX = {0, 1, 0, -1};
//        vector<int> arrY = {1, 0, -1, 0};
//
//        int size = (int)matrix.size() - 1;
//        int start = (int)matrix.size() - 1 - size;
//        while (size > 0) {
//            cout<<"===================="<<endl;
//
//            for (int i = start; i <= start + size; i++) {
//                int lastVal = 0;
//                int x = start, y = i;
//                int currVal = matrix[x][y];
//
//                for (int idx = 0; idx < arrX.size(); idx++) {
//                    int targetX = x + size * arrX[idx];
//                    int targetY = y + size * arrY[idx];
//
//                    switch (idx) {
//                        case 0:
//                            if (targetY > size) {
//                                targetX += targetY % size;
//                                targetY = size;
//                            }
//                            break;
//                        case 1:
//                            if (targetX > size) {
//                                targetY -= targetX % size;
//                                targetX = size;
//                            }
//                            break;
//                        case 2:
//                            if (targetY < 0) {
//                                targetX += targetY % size;
//                                targetY = 0;
//                            }
//                            break;
//                        case 3:
//                            if (targetX < 0) {
//                                targetY -= targetX % size;
//                                targetX = 0;
//                            }
//                            break;
//                    }
//
//                    lastVal = matrix[targetX][targetY];
//                    matrix[targetX][targetY] = currVal;
//
//                    x = targetX;
//                    y = targetY;
//                    currVal = lastVal;
//                }
//
//                tool.printMatrix(matrix);
//            }
//            size -= 2;
//            start++;
//        }
//    }
//
//    void rotate2(vector<vector<int>>& matrix) {
//
//        int size = (int)matrix.size() - 1;
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix.size() / 2; j++) {
//                swap(matrix[i][j], matrix[i][size - j]);
//            }
//        }
//        tool.printMatrix(matrix);
//
//        for (int i = 0; i < matrix.size(); i++) {
//            for (int j = 0; j < matrix.size() - i; j++) {
//                swap(matrix[i][j], matrix[size - j][size - i]);
//            }
//        }
//    }
//
//    void test() {
//        vector<vector<int>> matrix = {
//            {1,2,3,4},
//            {5,6,7,8},
//            {9,10,11,12},
//            {13,14,15,16}
//        };
////        vector<vector<int>> matrix = {
////            {1,2,3},
////            {4,5,6},
////            {7,8,9}
////        };
//        tool.printMatrix(matrix);
//
//        rotate2(matrix);
//        tool.printMatrix(matrix);
//    }
//};

#pragma mark - 445
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
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode *rl1 = reverseList(l1);
//        ListNode *rl2 = reverseList(l2);
//
//        ListNode *p1 = rl1, *p2 = rl2;
//
//        ListNode *newHead = new ListNode(0);
//        ListNode *pNew = newHead;
//        int last = 0;
//        while (p1 != nullptr || p2 != nullptr) {
//            int n1 = (p1 != nullptr ? p1->val : 0);
//            int n2 = (p2 != nullptr ? p2->val : 0);
//
//            int sum = n1 + n2 + last;
//            last = sum / 10;
//            pNew->next = new ListNode(sum % 10);
//
//            pNew = pNew->next;
//            if (p1 != nullptr) {
//                p1 = p1->next;
//            }
//
//            if (p2 != nullptr) {
//                p2 = p2->next;
//            }
//        }
//
//        if (last != 0) {
//            pNew->next = new ListNode(1);
//        }
//
//        return reverseList(newHead->next);
//    }
//
//    ListNode *reverseList(ListNode *head) {
//        ListNode *pre = nullptr;
//        ListNode *curr = head;
//        ListNode *temp = nullptr;
//        while (curr != nullptr) {
//            temp = curr->next;
//
//            curr->next = pre;
//            pre = curr;
//            curr = temp;
//        }
//
//        return pre;
//    }
//
//    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
//        ListNode *newHead = new ListNode(0);
//
//        ListNode *pNew = newHead;
//        ListNode *c1 = l1;
//        ListNode *c2 = l2;
//
//        while (c1 != nullptr && c2 != nullptr) {
//            c1 = c1->next;
//            c2 = c2->next;
//        }
//
//        if (c2 != c1) {//长度不同
//            if (c1 != nullptr) {
//                ListNode *h1 = l1;
//                while (c1 != nullptr) {//计算前几个数字不需要计算
//                    h1 = h1->next;
//                    c1 = c1->next;
//                }
//
//                c1 = h1;
//                h1 = l1;
//
//                while (h1 != c1) {//把l1到c1前的数字复制到结果
//                    pNew->next = new ListNode(h1->val);
//                    pNew = pNew->next;
//                    h1 = h1->next;
//                }
//                c1 = h1;
//                c2 = l2;
//            }
//            else {
//                ListNode *h2 = l2;
//
//                while (c2 != nullptr) {//计算前几个数字不需要计算
//                    h2 = h2->next;
//                    c2 = c2->next;
//                }
//
//                c2 = h2;
//                h2 = l2;
//
//
//                while (h2 != c2) {
//                    pNew->next = new ListNode(h2->val);
//                    pNew = pNew->next;
//                    h2 = h2->next;
//                }
//                c1 = l1;
//                c2 = h2;
//            }
//        }
//        else {
//            //重置c1，c2
//            c1 = l1;
//            c2 = l2;
//        }
//
//        while (c1 != nullptr || c2 != nullptr) {
//            int n1 = (c1 != nullptr ? c1->val : 0);
//            int n2 = (c2 != nullptr ? c2->val : 0);
//
//            int val = n1 + n2;
//
//            pNew->val += val / 10;
//            pNew->next = new ListNode(val % 10);
//
//            pNew = pNew->next;
//
//            if (c1 != nullptr) {
//                c1 = c1->next;
//            }
//
//            if (c2 != nullptr) {
//                c2 = c2->next;
//            }
//        }
//
//        if (newHead->val >= 10) {
//            ListNode *temp = new ListNode(newHead->val / 10);
//            temp->next = newHead;
//            newHead->val %= 10;
//            newHead = temp;
//        }
//
//        if (newHead->val == 0) {
//            return newHead->next;
//        }
//
//        return newHead;
//    }
//
//    ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
//        stack<int> stack1, stack2;
//
//        ListNode *p1 = l1, *p2 = l2;
//        while (p1 != nullptr || p2 != nullptr) {
//            if (p1 != nullptr) {
//                stack1.push(p1->val);
//                p1 = p1->next;
//            }
//
//            if (p2 != nullptr) {
//                stack2.push(p2->val);
//                p2 = p2->next;
//            }
//        }
//
//        ListNode *newHead = new ListNode(0);
//
//        int last = 0;
//        while (stack1.size() > 0 || stack2.size() > 0) {
//            int n1 = 0;
//            if (stack1.empty() == false) {
//                n1 = stack1.top();
//                stack1.pop();
//            }
//
//            int n2 = 0;
//            if (stack2.empty() == false) {
//                n2 = stack2.top();
//                stack2.pop();
//            }
//
//            int val = last + n1 + n2;
//            last = val / 10;
//
//            ListNode *temp = newHead->next;
//            newHead->next = new ListNode(val % 10, temp);
//        }
//
//        if (last == 1) {
//            ListNode *temp = newHead->next;
//            newHead->next = new ListNode(1, temp);
//        }
//
//        return newHead->next;
//    }
//
//    void test() {
//        /**
//         [7,2,4,3]
//         [5,6,4]
//
//         [1]
//         [9,9]
//         */
//        vector<int> arr1 = {1};
//        vector<int> arr2 = {9,9};
//
//        ListNode *h1 = tool.createList(arr1, -1);
//        tool.printList(h1);
//
//        ListNode *h2 = tool.createList(arr2, -1);
//        tool.printList(h2);
//
//        ListNode *result = addTwoNumbers3(h1, h2);
//        tool.printList(result);
//    }
//};

#pragma mark - 454
//class Solution {
//public:
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//        unordered_map<int, int> map;
//        for (int i = 0; i < A.size(); i++) {
//            for (int j = 0; j < B.size(); j++) {
//                map[A[i] + B[j]]++;
//            }
//        }
//
//        int result = 0;
//        for (int i = 0; i < C.size(); i++) {
//            for (int j = 0; j < D.size(); j++) {
//                int target = -(C[i] + D[j]);
//                if (map.count(target) > 0) {
//                    result += map[target];
//                }
//            }
//        }
//
//        return result;
//    }
//};

#pragma mark - 48
//class Solution {
//public:
//    void rotate(vector<vector<int>>& matrix) {
//        int size = (int)matrix.size();
//        for (int i = 0; i < matrix.size() / 2; i++) {
//            for (int j = 0; j < (matrix.size() + 1) / 2; j++) {
//
//                //result[j][size - 1 - i] = matrix[i][j];
//
//                int temp = matrix[i][j];
//
//                matrix[i][j] = matrix[size - 1 - j][i];//左上
//
//                matrix[size - 1 - j][i] = matrix[size - 1 - i][size - 1 - j];//左下
//
//                matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];//右下
//
//                matrix[j][size - 1 - i] = temp;//matrix[i][j]; //右上
//
//            }
//
//
////            tool.printMatrix(matrix);
//        }
//    }
//
//    void rotate2(vector<vector<int>>& matrix) {
//        vector<vector<int>> result(matrix.size(), vector<int>(matrix.size(), 0));
//
//        int size = (int)matrix.size();
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                result[j][size - 1 - i] = matrix[i][j];
//            }
//
//            tool.printMatrix(result);
//        }
//
//
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size; j++) {
//                matrix[i][j] = result[i][j];
//            }
//        }
//
//    }
//
//    void test() {
////        vector<vector<int>> matrix = {
////            {1,2,3},
////            {4,5,6},
////            {7,8,9}4
////        };
//
//        vector<vector<int>> matrix = {
//            {1,2,3,4},
//            {5,6,7,8},
//            {9,10,11,12},
//            {13,14,15,16}
//        };
//
//
//        rotate(matrix);
//        tool.printMatrix(matrix);
//    }
//};

#pragma mark - 508
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
//    unordered_map<int, int> map;
//    vector<int> findFrequentTreeSum(TreeNode* root) {
//        traversal(root);
//
//        vector<int> result;
//        int maxCount = INT_MIN;
//        for (auto it : map) {
//            if (it.second == maxCount) {
//                result.push_back(it.first);
//            }
//            else if (it.second > maxCount) {
//                maxCount = it.second;
//                result.clear();
//                result.push_back(it.first);
//            }
//        }
//
//        return result;
//    }
//
//    int traversal(TreeNode *root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        int left = traversal(root->left);
//        int right = traversal(root->right);
//        int val = left + right + root->val;
//
//        map[val]++;
//
//        return val;
//    }
//
//    void test() {
//        vector<int> arr = {5,2,-5};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<int> result = findFrequentTreeSum(root);
//        tool.printVector(result);
//    }
//
//};

#pragma mark - 572
//class Solution {
//public:
//    bool isSubtree(TreeNode* s, TreeNode* t) {
//        if (s == nullptr) {
//            return false;
//        }
//
//        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
//    }
//
//    bool isSameTree(TreeNode *s, TreeNode *t) {
//        if (s == nullptr || t == nullptr) {
//            if (s == t) {
//                return true;
//            }
//            else {
//                return false;
//            }
//        }
//
//        if (s->val == t->val) {
//            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
//        }
//        else {
//            return false;
//        }
//    }
//
//    void test() {
//        /**
//         [3,4,5,1,2]
//         [4,1,2]
//
//         [1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,2]
//         [1,-1,1,-1,1,-1,1,-1,1,-1,1,2]
//         */
//        vector<int> arrS = {1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,2};
//        TreeNode *s = tool.createBT(arrS);
//        tool.printBT(s);
//
//        vector<int> arrT = {1,-1,1,-1,1,-1,1,-1,1,-1,1,2};
//        TreeNode *t = tool.createBT(arrT);
//        tool.printBT(t);
//
//        bool result = isSubtree(s, t);
//        cout<<result<<endl;
//    }
//
//};

#pragma mark - mianshi_08.04
//class Solution {
//public:
//    vector<vector<int>> result;
//    vector<vector<int>> subsets(vector<int>& nums) {
////        sort(nums.begin(), nums.end());
//
//        vector<int> path;
//        result.push_back(path);
//        backtracking(nums, path, 0);
//
//        return result;
//    }
//
//    void backtracking(vector<int>& nums, vector<int>& path, int index) {
//        for (int i = index; i < nums.size(); i++) {
////            if (i - 1 >= index && nums[i] == nums[i - 1]) {
////
////            }
////            else {
//                path.push_back(nums[i]);
//                result.push_back(path);
//                backtracking(nums, path, i + 1);
//                path.pop_back();
////            }
//        }
//    }
//
//    void test() {
//        vector<int> arr = {1,1,2,3};
//        vector<vector<int>> result = subsets(arr);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 1504
//class Solution {
//public:
//    int numSubmat(vector<vector<int>>& mat) {
//        int reuslt = 0;
//        vector<vector<int>> hMat(mat);
//
//        for (int i = 0; i < mat.size(); i++) {
//            for (int j = 0; j < mat[i].size(); j++) {
//                if (hMat[i][j] != 0) {
//                    if (j > 0) {
//                        hMat[i][j] = hMat[i][j - 1] + 1;
//                    }
//
//                    int minWidth = hMat[i][j];
//                    for (int k = i; k >= 0; k--) {
//                        if (hMat[k][j] < minWidth) {
//                            minWidth = hMat[k][j];
//                        }
//
//                        if (minWidth > 0) {
//                            reuslt += minWidth;
//                        }
//                        else {
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//
//        return reuslt;
//    }
//
//    void test() {
//        /**
//         [[0,1,1,0],
//                     [0,1,1,1],
//                     [1,1,1,0]]
//
//
//
//         [[1,1,1,1,0,1,0],[1,1,1,0,0,0,1],[0,1,1,1,1,0,0],[1,1,0,1,1,0,1],[1,0,0,0,0,0,1],[1,1,0,1,1,1,1],[1,1,0,0,1,1,1]]
//         */
////        vector<vector<int>> mat = {
////            {1,1,1,1,0,1,0},
////            {1,1,1,0,0,0,1},
////            {0,1,1,1,1,0,0},
////            {1,1,0,1,1,0,1},
////            {1,0,0,0,0,0,1},
////            {1,1,0,1,1,1,1},
////            {1,1,0,0,1,1,1}
////        };
//
//        vector<vector<int>> mat = {
//            {0,1,1,0},
//            {0,1,1,1},
//            {1,1,1,0}
//        };
//
//        int result = numSubmat(mat);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1525
//class Solution {
//public:
//    int numSplits(string s) {
//        unordered_map<char, int> map1, map2;
//
//        for (int i = 0; i < s.size(); i++) {
//            map2[s[i]]++;
//        }
//
//        int result = 0;
//
//        for (int i = 0; i < s.size() && map1.size() <= map2.size(); i++) {
//            map1[s[i]]++;
//            map2[s[i]]--;
//            if (map2[s[i]] == 0) {
//                map2.erase(s[i]);
//            }
//
//            if (map1.size() == map2.size()) {
//                result++;
//            }
//        }
//
//        return result;
//    }
//
////    int numSplits2(string s) {
////
////    }
//
//    void test() {
//        int result = numSplits("");
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi_04.10
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
//    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
//        if (t1 == nullptr || t2 == nullptr) {
//            if (t1 == t2) {
//                return true;
//            }
//            return false;
//        }
//
//        if (t1->val == t2->val) {
//            return checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right);
//        }
//        else {
//            return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
//        }
//    }
//
//    bool checkSubTree2(TreeNode* t1, TreeNode* t2) {
//        string dlr1, dlr2, lrd1, lrd2;
//        traveral(t1, dlr1, true);
//        traveral(t2, dlr2, true);
//        traveral(t1, lrd1, false);
//        traveral(t2, lrd2, false);
//
//        if (dlr1.find(dlr2) != string::npos && lrd1.find(lrd2) != string::npos) {
//            return true;
//        }
//
//        return false;
//    }
//
//    void traveral(TreeNode *root, string &path, bool isFirst) {
//        if (root == nullptr) {
//            return;
//        }
//
//        if (isFirst) {
//            path += to_string(root->val);
//        }
//        traveral(root->left, path, isFirst);
//        traveral(root->right, path, isFirst);
//
//        if (!isFirst) {
//            path += to_string(root->val);
//        }
//    }
//
//    void test() {
//        vector<int> arr1 = {1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1};
//        TreeNode *t1 = tool.createBT(arr1);
//        tool.printBT(t1);
//
//        vector<int> arr2 = {3,6,7};
//        TreeNode *t2 = tool.createBT(arr2);
//        tool.printBT(t2);
//
//        bool result = checkSubTree2(t1, t2);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1124
//class Solution {
//public:
//    int longestWPI(vector<int>& hours) {
//        int ans = 0;
//        vector<int> result(hours.size(), 0);
//
//        for (int i = 0; i < hours.size(); i++) {
//            int lastBigIndex = i - 1;
//            for (int j = i; j < hours.size(); j++) {
//                if (i == j) {
//                    if (hours[j] > 8) {
//                        result[j] = 1;
//                    }
//                    else {
//                        result[j] = -1;
//                    }
//                }
//                else {
//                    if (hours[j] > 8) {
//                        result[j] = result[j - 1] + 1;
//                    }
//                    else {
//                        result[j] = result[j - 1] - 1;
//                    }
//                }
//
//                if (result[j] > 0) {
//                    lastBigIndex = j;
//                }
//            }
//
//            ans = max(lastBigIndex - i + 1, ans);
//
//            if (lastBigIndex == hours.size() - 1) {
//                return ans;
//            }
//        }
//
//        return ans;
//    }
//
//    int longestWPI2(vector<int>& hours) {
//        vector<int> prefixSum(hours.size() + 1, 0);
//
//        stack<int> stack;
//        stack.push(0);
//        for (int i = 0; i < hours.size(); i++) {
//            if (hours[i] > 8) {
//                prefixSum[i + 1] = prefixSum[i] + 1;
//            }
//            else {
//                prefixSum[i + 1] = prefixSum[i] - 1;
//            }
//
//            if (prefixSum[stack.top()] > prefixSum[i + 1]) {
//                stack.push(i + 1);
//            }
//        }
//
//        int result = 0;
//        for (int i = (int)prefixSum.size() - 1; i >= 0; i--) {
//
//            while (stack.size() > 0 && stack.top() >= i) {
//                stack.pop();
//            }
//
//            while (stack.size() > 0 && prefixSum[i] > prefixSum[stack.top()]) {
//                result = max(i - stack.top(), result);
//                stack.pop();
//            }
//
//            if (stack.size() == 0) {
//                break;
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> hours = {6,0,6,6,9};
//        int result = longestWPI2(hours);
//        cout<<result<<endl;
//    }
//};

#pragma mark - jianzhi_04
//class Solution {
//public:
//    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
//
//        if (matrix.size() == 0) {
//            return false;
//        }
//
//        if (matrix[0].size() == 0) {
//            return false;
//        }
//
//        int m = (int)matrix.size() - 1;
//        int n = (int)matrix[0].size() - 1;
//
//        int minI = 0, minJ = 0, maxI = m, maxJ = n;
//        for (int i = 0; i <= m; i++) {
//            if (matrix[i][0] == target) {
//                return true;
//            }
//            if (matrix[i][0] > target) {
//                maxI = i - 1;
//                break;
//            }
//
//            if (matrix[i][n] == target) {
//                return true;
//            }
//            if (matrix[i][n] < target) {
//                minI = i + 1;
//            }
//        }
//
//        for (int j = 0; j <= n; j++) {
//            if (matrix[0][j] == target) {
//                return true;
//            }
//            if (matrix[0][j] > target) {
//                maxJ = j - 1;
//                break;
//            }
//
//            if (matrix[m][j] == target) {
//                return true;
//            }
//            if (matrix[m][j] < target) {
//                minJ = j + 1;
//            }
//        }
//        for (int i = minI; i <= maxI; i++) {
//            if (findNumberInRange(matrix[i], target, minJ, maxJ)) {
//                return true;
//            }
//        }
//
//        return false;
//    }
//
//    bool findNumberInRange(vector<int>& vec, int target, int minI, int maxI) {
//
//        if (minI > maxI) {
//            return false;
//        }
//
//        if (vec[minI] > target) {
//            return false;
//        }
//
//        if (vec[minI] == target) {
//            return true;
//        }
//
//        if (vec[maxI] < target) {
//            return false;
//        }
//
//        if (vec[maxI] == target) {
//            return true;
//        }
//
//        int mid = ((maxI - minI) >> 2) + minI;
//        if (vec[mid] == target) {
//            return true;
//        }
//
//        if (vec[mid] > target) {
//            return findNumberInRange(vec, target, minI, mid - 1);
//        }
//
//        if (vec[mid] < target) {
//            return findNumberInRange(vec, target, mid + 1, maxI);
//        }
//
//        return false;
//    }
//
//    bool findNumberIn2DArray2(vector<vector<int>>& matrix, int target) {
//
//        if (matrix.size() == 0) {
//            return false;
//        }
//
//        if (matrix[0].size() == 0) {
//            return false;
//        }
//
//        int m = (int)matrix.size() - 1;
//        int n = (int)matrix[0].size() - 1;
//        int i = 0, j = n;
//        while (i <= m && i >= 0 && j <= n && j >= 0) {
//            if (matrix[i][j] == target) {
//                return true;
//            }
//
//            if (matrix[i][j] > target) {
//                j--;
//                continue;
//            }
//
//            if (matrix[i][j] < target) {
//                i++;
//                continue;
//            }
//        }
//
//        return false;
//    }
//
//    void test() {
//        vector<vector<int>> matrix = {
//            {1,   4,  7, 11, 15},
//            {2,   5,  8, 12, 19},
//            {3,   6,  9, 16, 22},
//            {10, 13, 14, 17, 24},
//            {18, 21, 23, 26, 30},
//        };
//
//        int target = 20;
//
//        bool result = findNumberIn2DArray2(matrix, target);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 706
//struct MapNode {
//    MapNode *next;
//    int key;
//    int val;
//};
//class MyHashMap {
//public:
//
//    MapNode *head;
//    MapNode *tail;
//
//    /** Initialize your data structure here. */
//    MyHashMap() {
//        head = new MapNode();
//        tail = head;
//    }
//
//    /** value will always be non-negative. */
//    void put(int key, int value) {
//        MapNode *node = getNode(key);
//        if (node == nullptr) {
//            node = new MapNode();
//            node->key = key;
//            node->val = value;
//            tail->next = node;
//            tail = node;
//        }
//        else {
//            node->val = value;
//        }
//    }
//
//    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//    int get(int key) {
//        MapNode *node = getNode(key);
//        if (node == nullptr) {
//            return -1;
//        }
//        else {
//            return node->val;
//        }
//    }
//
//    MapNode *getNode(int key) {
//        MapNode *temp = head->next;
//        while (temp != nullptr) {
//            if (temp->key == key) {
//                return temp;
//            }
//            temp = temp->next;
//        }
//
//        return nullptr;
//    }
//
//    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//    void remove(int key) {
//        MapNode *p = head->next;
//        MapNode *pre = head;
//        while (p != nullptr) {
//            if (p->key == key) {
//                pre->next = p->next;
//                if (p == tail) {
//                    tail = pre;
//                }
//                return;
//            }
//            pre = p;
//            p = p->next;
//        }
//    }
//};
//
//class MyHashMap {
//public:
//
//    typedef pair<int, int> KVPair;
//    static const int base = 769;
//    vector<list<KVPair>> mapVec;
//    static int hash(int key) {
//        return key % base;
//    }
//    /** Initialize your data structure here. */
//    MyHashMap() {
//        mapVec.resize(base);
//    }
//
//    /** value will always be non-negative. */
//    void put(int key, int value) {
//        for (list<KVPair>::iterator i = mapVec[hash(key)].begin(); i != mapVec[hash(key)].end(); i++) {
//            if (i->first == key) {
//                i->second = value;
//                return;
//            }
//        }
//
//        mapVec[hash(key)].push_back(KVPair(key, value));
//    }
//
//    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//    int get(int key) {
//        for (list<KVPair>::iterator i = mapVec[hash(key)].begin(); i != mapVec[hash(key)].end(); i++) {
//            if (i->first == key) {
//                return i->second;
//            }
//        }
//
//        return -1;
//    }
//
//    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
//    void remove(int key) {
//        for (list<KVPair>::iterator i = mapVec[hash(key)].begin(); i != mapVec[hash(key)].end(); i++) {
//            if (i->first == key) {
//                mapVec[hash(key)].erase(i);
//                return;
//            }
//        }
//    }
//};
//
//class Solution {
//public:
//    void test() {
//        MyHashMap hashMap;
//
//        hashMap.put(2, 3);
//        cout<<hashMap.get(2)<<endl;
//    }
//};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

#pragma mark - 1871
//class Solution {
//public:
//    bool canReach(string s, int minJump, int maxJump) {
//        if (s[s.size() - 1] == '1') {
//            return false;
//        }
//
//        int lenght = (int)s.size();
//        deque<int> deque;
//        deque.push_back(0);
//
//        int lastPos = 0;
//        while (deque.size() > 0) {
//            int start = deque.front();
//            deque.pop_front();
//
//            for (int j = max((start + minJump), lastPos); j <= min(start + maxJump, lenght - 1); j++) {
//                if (s[j] == '0') {
//                    deque.push_back(j);
//
//                    if (j == lenght - 1) {
//                        return true;
//                    }
//                }
//                lastPos = max(lastPos, j);
//            }
//        }
//
//        return false;
//    }
//
//    bool canReach2(string s, int minJump, int maxJump) {
//        //f[i] 能否到达i s[i] == '0' f[i - max] - f[i - min]中有ture
//        //pre[i] = f[0] + f[1]...f[i]; f[i - max] - f[i - min]中有ture 即为 pre[i - min + 1] - pre[i - max - 1] > 0即min到max之间至少有一个true;
//
//        if (s[s.size() - 1] == '1') {
//            return false;
//        }
//
//        vector<int> result(s.size(), false);
//        result[0] = true;
//
//        vector<int> preSum(s.size(), false);
//        preSum[0] = 1;
//
//        for (int i = 1; i < s.size(); i++) {
//            if (s[i] == '0') {
//                int preMax = i - minJump;
//                int preMin = i - maxJump - 1;
//
//                if (preMax >= 0) {
//                    if (preMin < 0) {
//                        if (preSum[preMax] > 0) {
//                            result[i] = true;
//                        }
//                    }
//                    else {
//                        if (preSum[preMax] - preSum[preMin] > 0) {
//                            result[i] = true;
//                        }
//                    }
//                }
//            }
//
//            preSum[i] = preSum[i - 1] + (result[i] ? 1 : 0);
//        }
//
//        return result[s.size() - 1];
//    }
//
//    void test() {
//        /**
//         "011010"
//         2
//         3
//         ""
//         5
//         99998
//         */
//        bool result = canReach2("00", 1, 1);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - LCP 12
//class Solution {
//public:
//    int minTime(vector<int>& time, int m) {
//        int l = 0;
//        int r = accumulate(time.begin(), time.end(), 0);
//
//        while (l < r) {
//            int mid = ((r - l) >> 1) + l;
//            if (checkIsCanFinish(time, mid, m)) {
//                r = mid;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//
//        return r;
//    }
//
//    bool checkIsCanFinish(vector<int>& time, int t, int m) {
//
//        int maxTime = 0;
//        int day = 1;
//        int i = 0;
//        bool isUseHelp = false;
//        int currTime = t;
//        while (i < time.size()) {
//            maxTime = max(maxTime, time[i]);
//            if (currTime >= time[i]) {
//                currTime -= time[i];
//                i++;
//            }
//            else {
//                if (isUseHelp == false) {
//                    currTime += maxTime;
//                    isUseHelp = true;
//                }
//                else {
//                    currTime = t;
//                    isUseHelp = false;
//                    day++;
//                    maxTime = 0;
//                }
//
//                if (day > m) {
//                    return false;
//                }
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> time = {1,2,3,3};
//
//        int result = minTime(time, 2);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1131
//class Solution {
//public:
//    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
//        int result = INT_MIN;
//        for (int i = 0; i < arr1.size(); i++) {
//            for (int j = 0; j < arr1.size(); j++) {
//                int val = abs(arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) + abs(i - j);
//                result = max(result, val);
//            }
//        }
//
//        return result;
//    }
//
//    int maxAbsValExpr2(vector<int>& arr1, vector<int>& arr2) {
//
//        /**
//         |a[i] - a[j]| + |b[i] - b[j]| + |i - j| =
//
//         a[i] - a[j] < 0 && b[i] - b[j] < 0 : a[j] - a[i] + b[j] - b[i] + j - 1;
//         a[i] - a[j] < 0 && b[i] - b[j] > 0 : a[j] - a[i] + b[i] - b[j]
//
//         */
//        vector<int> sortArr1(arr1.size()), sortArr2(arr2.size());
//
//        for (int i = 0; i < arr1.size(); i++) {
//            sortArr1[i] = i;
//            sortArr2[i] = i;
//        }
//
//        sort(sortArr1.begin(), sortArr1.end(), [&](int a, int b){
//            return arr1[a] < arr1[b];
//        });
//
//        sort(sortArr2.begin(), sortArr2.end(), [&](int a, int b){
//            return arr2[a] < arr2[b];
//        });
//
//        int indexI = 0, indexJ = arr1.size();
//
//    }
//
//    void test() {
//        vector<int> arr1 = {1,-2,-5,0,10};
//        vector<int> arr2 = {0,-2,-1,-7,-4};
//        int result = maxAbsValExpr2(arr1, arr2);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1016
//class Solution {
//public:
//    bool queryString(string s, int n) {
//        unordered_set<int> set;
//
//        int l = 0, r = 0;
//        int val = 0;
//        while (l < s.size()) {
//            if (s[l] == '0') {//去除前部的0
//                l++;
//                continue;
//            }
//
//            if (l > r) {
//                r = l;
//            }
//
//            //计算l到r的值
//            if (r < s.size()) {
//                if (s[r] == '1') {
//                    val = val * 2 + 1;
//                }
//                else {
//                    val = val * 2;
//                }
//            }
//
//            //如果值过大，或者r到头，移动l
//            if (val > n || r >= s.size()) {
//                int e = min(r, (int)s.size() - 1);
//                val -= getVal(e - l + 1);
//                l++;
//            }
//
//            //val符合要求加入统计
//            if (val <= n && val > 0) {
//                set.insert(val);
//            }
//
//            r++;
//        }
//
//        return set.size() == n;
//    }
//
//    int getVal(int bitCount) {
//        int val = 1;
//        while (--bitCount > 0) {
//            val *= 2;
//        }
//
//        return val;
//    }
//
//    bool queryString2(string s, int n) {
//        for (int i = 1; i <= n; i++) {
//            string subString;
//            int temp = i;
//            while (temp > 0) {
//                if (temp % 2 == 0) {
//                    subString.push_back('0');
//                }
//                else {
//                    subString.push_back('1');
//                }
//                temp = temp / 2;
//            }
//
//            reverse(subString.begin(), subString.end());
//
//            if (s.find(subString) == s.npos) {
//                return false;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        /**
//         "1111000101"
//         5
//         */
//        string s = "11110001001";
//        int n = 5;
//
//        bool result = queryString2(s, n);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi_04.05
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
//    bool isValidBST(TreeNode* root) {
//        int min, max;
//        return traveral(root, min, max);
//    }
//
//    bool traveral(TreeNode *root, int &min, int &max) {
//        if (root == nullptr) {
//            return true;
//        }
//
//        min = root->val;
//        max = root->val;
//
//        if (root->left != nullptr) {
//            int lMin, lMax;
//            bool left = traveral(root->left, lMin, lMax);
//
//            if (lMax >= root->val || left == false) {
//                return false;
//            }
//
//            min = lMin;
//        }
//
//        if (root->right != nullptr) {
//            int rMin, rMax;
//            bool right = traveral(root->right, rMin, rMax);
//
//            if (rMin <= root->val || right == false) {
//                return false;
//            }
//
//            max = rMax;
//        }
//
//        return true;
//    }
//    long lastVal = LONG_MIN;
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) {
//            return true;
//        }
//
//        bool left = isValidBST(root->left);
//
//        if (left == false) {
//            return false;
//        }
//
//        if (lastVal < root->val) {
//            lastVal = root->val;
//        }
//        else {
//            return false;
//        }
//
//        bool right = isValidBST(root->right);
//
//        return right;
//    }
//
//    long lastVal = LONG_MIN;
//    bool isValidBST(TreeNode* root) {
//        if (root == nullptr) {
//            return true;
//        }
//        stack<TreeNode *> stack;
//        TreeNode *node = root;
//        while (node != nullptr) {
//            stack.push(node);
//            node = node->left;
//        }
//
//
//        while (stack.size() > 0) {
//            TreeNode *node = stack.top();
//            stack.pop();
//            if (lastVal >= node->val) {
//                return false;
//            }
//            lastVal = node->val;
//
//            node = node->right;
//            while (node != nullptr) {
//                stack.push(node);
//                node = node->left;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> arr = {3,2,5,1,-1,2,6};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        bool result = isValidBST(root);
//        cout<<result<<endl;
//
//    }
//};

#pragma mark - 1413
//class Solution {
//public:
//    int minStartValue(vector<int>& nums) {
//        int preSum = 0;
//
//        int result = INT_MAX;
//        for (int i = 0; i < nums.size(); i++) {
//            preSum += nums[i];
//            result = min(result, preSum);
//        }
//
//        return max(1 - result, 1);
//    }
//
//    void test() {
//        vector<int> nums = {-3,2,-3,4,2};
//
//        int result = minStartValue(nums);
//
//        cout<<result<<endl;
//    }
//};
