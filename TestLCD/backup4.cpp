//
//  backup4.cpp
//  TestLCD
//
//  Created by zm on 2021/5/5.
//

#pragma mark - 116

// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* left;
//    Node* right;
//    Node* next;
//
//    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val, Node* _left, Node* _right, Node* _next)
//        : val(_val), left(_left), right(_right), next(_next) {}
//};
//
//
//class Solution {
//public:
//    Node* connect(Node* root) {
//        if (root == nullptr) {
//            return root;
//        }
//
//        if (root->left != nullptr) {
//            root->left->next = root->right;
//            if (root->next != nullptr) {
//                root->right->next = root->next->left;
//            }
//            else {
//                root->right->next = root->next;
//            }
//        }
//
//        connect(root->left);
//        connect(root->right);
//
//        return root;
//    }
//
//    void test() {
//
//    }
//};

#pragma mark - 450
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
//    TreeNode* deleteNode(TreeNode* root, int key) {
//
//        TreeNode *deleteNode = root;
//        TreeNode *parent = nullptr;
//
//
//        while (deleteNode != nullptr && deleteNode->val != key) {
//            parent = deleteNode;
//            if (deleteNode->val > key) {
//                deleteNode = deleteNode->left;
//            }
//            else {
//                deleteNode = deleteNode->right;
//            }
//        }
//
//
//        if (deleteNode != nullptr) {
//            if (deleteNode->right == nullptr) {
//                if (parent == nullptr) {
//                    return deleteNode->left;
//                }
//                else {
//                    if (parent->left == deleteNode) {
//                        parent->left = deleteNode->left;
//                    }
//                    else {
//                        parent->right = deleteNode->left;
//                    }
//                }
//            }
//            else {
//                TreeNode *node = deleteNode ->right;
//                TreeNode *lastLeftNode = nullptr;
//                while (node->left != nullptr) {
//                    if (node->left->left == nullptr) {
//                        lastLeftNode = node->left;
//                        node->left = node->left->right;
//                        break;
//                    }
//                    node = node->left;
//                }
//
//                if (lastLeftNode != nullptr) {
//                    deleteNode->val = lastLeftNode->val;
//                }
//                else {
//                    node->left = deleteNode->left;
//                    if (parent == nullptr) {
//                        return node;
//                    }
//                    else {
//                        if (parent->left == deleteNode) {
//                            parent->left = node;
//                        }
//                        else {
//                            parent->right = node;
//                        }
//                    }
//
//                }
//            }
//        }
//
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {10,5,15,3,7,12,20,2,4,6,8,-1,13,18,25};
//
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = deleteNode(root, 10);
//        tool.printBT(result);
//    }
//};

#pragma mark - 669
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
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        while (root != nullptr && (root->val < low || root->val > high)) {
//
//            if (root->val < low) {
//                root = root->right;
//            }
//
//            if (root->val > high) {
//                root = root->left;
//            }
//        }
//
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        TreeNode *node = root;
//        while (node->left != nullptr) {
//            if (node->left->val < low) {
//                node->left = node->left->right;
//                continue;
//            }
//            node = node->left;
//        }
//
//        node = root;
//        while (node->right != nullptr) {
//            if (node->right->val > high) {
//                node->right = node->right->left;
//                continue;
//            }
//            node = node->right;
//        }
//
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {10,5,15,3,7,12,20,2,4,6,8,11,13,18,25};
//
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = trimBST(root, 15, 20);
//        tool.printBT(result);
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
//    vector<int> result;
//
//    unordered_map<TreeNode*, TreeNode*> superNodeMap;
//
//    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//        //时间O(n),空间O(h),h为target的深度;
//        //三种情况，一种是target的子节点，一种是target的祖先节点，或者祖先的兄弟节点
//
//        //祖先节点，记录到target路过的节点的父节点
//        getTargetNodeSuperNode(root, target);
//
//
//        TreeNode *node = target;
//        //找子节点
//        subNodeBacktracking(node, K);
//
//        //找祖先节点
//        while (node != nullptr) {
//            TreeNode *superNode = superNodeMap[node];
//            if (superNode != nullptr) {
//                if (K == 1) {//superNode距离为1记录superNode
//                    result.push_back(superNode->val);
//                }
//                else {
//                    //查找另一边的兄弟节点
//                    if (node == superNode->left) {
//                        subNodeBacktracking(superNode->right, K - 2);
//                    }
//                    else {
//                        subNodeBacktracking(superNode->left, K - 2);
//                    }
//                }
//            }
//            node = superNode;
//            K--;
//        }
//
//        return result;
//    }
//
//    bool getTargetNodeSuperNode(TreeNode *node, TreeNode* target)
//    {
//        if (node == nullptr) {
//            return false;
//        }
//
//        if (node == target) {
//            return true;
//        }
//
//        bool isLeft = getTargetNodeSuperNode(node->left, target);
//        if (isLeft) {
//            superNodeMap[node->left] = node;
//        }
//        bool isRight = getTargetNodeSuperNode(node->right, target);
//        if (isRight) {
//            superNodeMap[node->right] = node;
//        }
//
//
//        return isLeft || isRight;
//    }
//
//    void subNodeBacktracking(TreeNode *node, int K){
//        if (node == nullptr || K < 0) {
//            return;
//        }
//
//        if (K == 0) {
//            result.push_back(node->val);
//            return;
//        }
//
//        subNodeBacktracking(node->left, K - 1);
//        subNodeBacktracking(node->right, K - 1);
//    }
//
//    void test() {
//        vector<int> arr = {10,5,15,3,7,12,20,2,4,6,8,11,13,18,25};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<int> result = distanceK(root, root->left->left, 4);
//        tool.printVector(result);
//    }
//};

#pragma mark - 98
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
//    TreeNode *lastNode = nullptr;
//    bool isValidBST(TreeNode* root) {
//        //中序遍历
//        if (root == nullptr) {
//            return true;
//        }
//
//        bool isLeft = isValidBST(root->left);
//        if (lastNode != nullptr) {
//            if (lastNode->val >= root->val) {
//                return false;
//            }
//        }
//        lastNode = root;
//        bool isRight = isValidBST(root->right);
//
//        return isLeft && isRight;
//    }
//
//    bool isValidBST2(TreeNode* root) {
//        //中序迭代
//        stack<TreeNode *> stack;
//        TreeNode *node = root;
//        while (node != nullptr) {
//            stack.push(node);
//            node = node->left;
//        }
//
//
//        while (stack.size() != 0) {
//            TreeNode *leftNode = stack.top();
//            stack.pop();
//
//            if (lastNode != nullptr && lastNode->val >= leftNode->val) {
//                return false;
//            }
//            lastNode = leftNode;
//
//            if (lastNode->right != nullptr) {
//                stack.push(lastNode->right);
//                TreeNode *temp = lastNode->right->left;
//                while (temp != nullptr) {
//                    stack.push(temp);
//                    temp = temp->left;
//                }
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<int> arr = {2,1,3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        bool result = isValidBST2(root);
//        cout<<result<<endl;
//    }
//
//};

#pragma mark - 99
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
////    TreeNode *errorNode1, *errorNode2;
////    TreeNode *lastNode;
////    bool isFinish = false;
////    void recoverTree(TreeNode* root) {
////        LDRTraversal(root);
////
////        int temp = errorNode2->val;
////        errorNode2->val = errorNode1->val;
////        errorNode1->val = temp;
////    }
////
////    void LDRTraversal(TreeNode *node) {
////        if (node == nullptr || isFinish) {
////            return;
////        }
////
////        LDRTraversal(node->left);
////        if (lastNode != nullptr) {
////            if (lastNode->val >= node->val) {
////                if (errorNode1 == nullptr) {
////                    errorNode1 = lastNode;
////                    errorNode2 = node;
////                }
////                else {
////                    errorNode2 = node;
////                    isFinish = true;
////                    return;
////                }
////            }
////        }
////        lastNode = node;
////        LDRTraversal(node->right);
////    }
//
//    void recoverTree(TreeNode* root) {
//        //morris
//
//        TreeNode *errorNode1 = nullptr, *errorNode2 = nullptr;
//        TreeNode *lastNode = nullptr;
//
//        while (root != nullptr) {
//            if (root->left != nullptr) {
//                TreeNode *node = root->left;
//                while (node->right != nullptr && node->right != root) {
//                    node = node->right;
//                }
//
//                if (node->right == nullptr) {
//                    node->right = root;
//                    root = root->left;
//                }
//                else {
//
//                    node->right = nullptr;
//                    if (lastNode != nullptr && lastNode->val >= root->val) {
//                        if (errorNode1 == nullptr) {
//                            errorNode1 = lastNode;
//                            errorNode2 = root;
//                        }
//                        else {
//                            errorNode2 = root;
//                        }
//                    }
//                    lastNode = root;
//                    root = root->right;
//
//
//                }
//            }
//            else {
//                TreeNode *node = root;
//                if (lastNode != nullptr && lastNode->val >= node->val) {
//                    if (errorNode1 == nullptr) {
//                        errorNode1 = lastNode;
//                        errorNode2 = node;
//                    }
//                    else {
//                        errorNode2 = node;
//                    }
//                }
//                lastNode = root;
//
//                root = root->right;
//            }
//        }
//
//        int temp = errorNode2->val;
//        errorNode2->val = errorNode1->val;
//        errorNode1->val = temp;
//    }
//
//    void test() {
//        vector<int> arr = {10,5,15,0,8,13,20,2,-5,6,9,12,14,18,25};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        recoverTree(root);
//        tool.printBT(root);
//    }
//};

#pragma mark - 222
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
//    int countNodes(TreeNode* root) {
//
//        if (root == nullptr) {
//            return 0;
//        }
//
//        return countNodes(root->left) + countNodes(root->right) + 1;
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
//        //层先
//        if (root == nullptr) {
//            return 0;
//        }
//
//        typedef pair<TreeNode *, int> NodePos;
//        deque<NodePos> deque;
//        deque.push_back(NodePos(root, 0));
//
//        int maxCount = 1;
//
//        while (deque.size() != 0) {
//            int size = (int)deque.size();
//            int left = -1;
//            int right = -1;
//            for (int i = 0; i < size; i++) {
//                NodePos nodePos = deque.front();
//                deque.pop_front();
//
//                TreeNode *node = nullptr;
//                int pos = -1;
//                if (nodePos.first->left != nullptr) {
//                    node = nodePos.first->left;
//                    pos = 2 * nodePos.second;
//                    if (left == -1) {
//                        left = pos;
//                    }
//                    else {
//                        right = pos;
//                    }
//
//                    deque.push_back(NodePos(node, pos - left));
//                }
//
//                if (nodePos.first->right != nullptr) {
//                    node = nodePos.first->right;
//                    pos = 2 * nodePos.second + 1;
//                    if (left == -1) {
//                        left = pos;
//                    }
//                    else {
//                        right = pos;
//                    }
//
//                    deque.push_back(NodePos(node, pos - left));
//                }
//
//
//                maxCount = max(maxCount, right - left + 1);
//            }
//        }
//
//        return maxCount;
//    }
//
//    void test() {
//        vector<int> arr = {1,3,-1,5,3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = widthOfBinaryTree(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 124
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
//    int maxSum = -2000;
//    int maxPathSum(TreeNode* root) {
//
//        int rootSum = tarversal(root);
//
//        return max(maxSum, rootSum);
//    }
//
//    int tarversal(TreeNode *root) {
//        if (root == nullptr) {
//            return -2000;
//        }
//
//        int leftSum = tarversal(root->left);
//        int rightSum = tarversal(root->right);
//
//        int currentRootSum = 0;//root为根节点的最大路径
//        //同时选左右两边就一定要选中间,带root最大的情况
//        {
//            currentRootSum = root->val;
//
//            if (leftSum > 0) {
//                currentRootSum += leftSum;
//            }
//
//            if (rightSum > 0) {
//                currentRootSum += rightSum;
//            }
//        }
//
//        //不包含root最大的情况
//        int currentSubNodeSum = max(leftSum, rightSum);
//
//        int maxRootSum = max(currentRootSum, currentSubNodeSum);
//
//        maxSum = max(maxRootSum, maxSum);
//
//        int maxSubNodeSum = max(max(leftSum, rightSum), 0);
//        return maxSubNodeSum + root->val;//root为子节点的最大路径
//
//    }
//
//    int maxPathSum2(TreeNode* root) {
//        //f(i) 包含当前节点最大的路径 f(i) = max((l + r + root), max(l,r) + root, root)
//
//        treeTarversal(root);
//
//        return maxSum;
//
//    }
//
//    int treeTarversal(TreeNode *node) {
//        if (node == nullptr) {
//            return -2000;
//        }
//
//        int leftSum = treeTarversal(node->left);
//        int rightSum = treeTarversal(node->right);
//
//        int currentSum = max({leftSum + rightSum, max(leftSum, rightSum), 0}) + node->val;
//
//        maxSum = max({currentSum, currentSum - node->val, maxSum});
//
//        return currentSum;
//    }
//
//    void test() {
//        vector<int> arr = {-1,8,3,-1,-9,0,-1,-1,-1,-3};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = maxPathSum2(root);
//        cout<<result<<endl;
//    }
//
//};

#pragma mark - 113
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
//    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//
//        vector<int> path;
//        backTracking(root, targetSum, path);
//
//        return result;
//    }
//
//    void backTracking(TreeNode *node, int target, vector<int> &path) {
//        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
//            if (node != nullptr && target == node->val) {
//                path.push_back(node->val);
//                result.push_back(path);
//                path.pop_back();
//            }
//            return;
//        }
//
//        path.push_back(node->val);
//        backTracking(node->left, target - node->val, path);
//        backTracking(node->right, target - node->val, path);
//        path.pop_back();
//    }
//
//    void test() {
//        vector<int> arr = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<vector<int>> result = pathSum(root, 22);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - mianshi0412
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
//    int result = 0;
//    int pathSum(TreeNode* root, int sum) {
//        if (root == nullptr) {
//            return result;
//        }
//        treeTraversal(root, sum);
//        pathSum(root->left, sum);//不算root
//        pathSum(root->right, sum);
//
//        return result;
//    }
//
//    void treeTraversal(TreeNode *node, int target) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (target == node->val) {
//            result++;
//        }
//
//        treeTraversal(node->left, target - node->val);
//        treeTraversal(node->right, target - node->val);
//    }
//
//    void test() {
//        /**
//         [1,2,null,3,null,4,null,5]
//         6
//
//         [1,null,2,null,3,null,4,null,5]
//         3
//         */
//        vector<int> arr = {1,-1,2,-1,3,-1,4,-1,5};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = pathSum(root, 3);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 563
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
//    int TiltSum = 0;
//    int findTilt(TreeNode* root) {
//        treeSumTraversal(root);
//
//        return TiltSum;
//    }
//
//    int treeSumTraversal(TreeNode *node) {
//        if (node == nullptr) {
//            return 0;
//        }
//
//        int leftSum = treeSumTraversal(node->left);
//        int rightSum = treeSumTraversal(node->right);
//
//        TiltSum += abs(leftSum - rightSum);
//
//        return leftSum + rightSum + node->val;
//    }
//
//    void test() {
//        vector<int> arr = {4,2,-9,3,5,-1,7};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = findTilt(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 129
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
//    int result = 0;
//    int sumNumbers(TreeNode* root) {
//
//        treeTraversal(root, 0);
//
//        return result;
//    }
//
//    void treeTraversal(TreeNode *node, int count) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (node->left == nullptr && node->right == nullptr) {
//            result += (count * 10) + node->val;
//            return;
//        }
//
//        if (node->left != nullptr) {
//            treeTraversal(node->left, (count * 10 + node->val));
//        }
//
//        if (node->right != nullptr) {
//            treeTraversal(node->right, (count * 10 + node->val));
//        }
//    }
//
//    void test() {
//        vector<int> arr = {4,9,0,5,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = sumNumbers(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1448
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
//    int result = 0;
//    int goodNodes(TreeNode* root) {
//
//        treeTraversal(root, INT_MIN);
//
//        return result;
//    }
//
//    void treeTraversal(TreeNode *node, int maxVal) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (maxVal <= node->val) {
//            result++;
//        }
//
//        treeTraversal(node->left, max(maxVal, node->val));
//        treeTraversal(node->right, max(maxVal, node->val));
//    }
//
//    void test() {
//        vector<int> arr = {1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = goodNodes(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1022
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
//    int result = 0;
//    int sumRootToLeaf(TreeNode* root) {
//        treeTraversal(root, 0);
//
//        return result;
//    }
//
//    void treeTraversal(TreeNode *node, int num) {
//        if (node == nullptr) {
//            return;
//        }
//
//        if (node->left == nullptr && node->right == nullptr) {
//            result += (num * 2 + node->val);
//            return;
//        }
//
//        treeTraversal(node->left, num * 2 + node->val);
//        treeTraversal(node->right, num * 2 + node->val);
//    }
//
//    void test() {
//        vector<int> arr = {1,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = sumRootToLeaf(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 814
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
//    TreeNode* pruneTree(TreeNode* root) {
//        bool result = treeTraversal(root);
//
//        return result ? root : nullptr;
//    }
//
//    bool treeTraversal(TreeNode *node) {
//        if (node == nullptr) {
//            return false;
//        }
//
//        bool left = treeTraversal(node->left);
//        if (left == false) {
//            node->left = nullptr;
//        }
//        bool right = treeTraversal(node->right);
//        if (right == false) {
//            node->right = nullptr;
//        }
//
//        return (node->val == 1) || left || right;
//    }
//
//    void test() {
//        vector<int> arr = {1,1,0,1,1,0,1,0};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = pruneTree(root);
//        tool.printBT(result);
//    }
//};

#pragma mark - 1325
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
//    TreeNode* removeLeafNodes(TreeNode* root, int target) {
//        bool result = treeTraversal(root, target);
//
//        return result ? nullptr : root;
//    }
//
//    bool treeTraversal(TreeNode *node, int target) {
//        if (node == nullptr) {
//            return false;
//        }
//
//        bool left = treeTraversal(node->left, target);
//        if (left == true) {
//            node->left = nullptr;
//        }
//        bool right = treeTraversal(node->right, target);
//        if (right == true) {
//            node->right = nullptr;
//        }
//
//        if (node->left == nullptr && node->right == nullptr && node->val == target) {
//            return true;
//        }
//
//        return false;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,2,-1,2,4};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = removeLeafNodes(root, 2);
//        tool.printBT(result);
//
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
//    TreeNode* bstFromPreorder(vector<int>& preorder) {
//        TreeNode *root = new TreeNode(preorder[0]);
//
//        for (int i = 1; i < preorder.size(); i++) {
//            buildTree(root, preorder[i]);
//        }
//
//        return root;
//    }
//
//    void buildTree(TreeNode *root, int val) {
//
//        if (root->val < val) {
//            if (root->right == nullptr) {
//                root->right = new TreeNode(val);
//                return;
//            }
//            buildTree(root->right, val);
//        }
//        else {
//            if (root->left == nullptr) {
//                root->left = new TreeNode(val);
//                return;
//            }
//            buildTree(root->left, val);
//        }
//    }
//
//    TreeNode* bstFromPreorder2(vector<int>& preorder) {
//        TreeNode *root = buildBST(preorder, 0, (int)preorder.size() - 1);
//        return root;
//    }
//
//    TreeNode* buildBST(vector<int>& preorder, int s, int e) {
//        if (s > e) {
//            return nullptr;
//        }
//        TreeNode *root = new TreeNode(preorder[s]);
//
//        int sep = s;
//
//        int l = s, r = e;
//        while (l <= r) {
//            sep = ((r - l) >> 1) + l;
//            if (preorder[sep] > preorder[s]) {
//                r = sep - 1;
//            }
//            else {
//                l = sep + 1;
//            }
//        }
//        if (preorder[sep] > preorder[s]) {
//            sep--;
//        }
//
//        root->left = buildBST(preorder, s + 1, sep);
//        root->right = buildBST(preorder, sep + 1, e);
//
//        return root;
//    }
//
//    TreeNode* bstFromPreorder3(vector<int>& preorder) {
//        TreeNode *root = buildBST(preorder, 0, (int)preorder.size() - 1);
//        return root;
//    }
//
//    void test() {
//        vector<int> arr = {8,5,1,7,10,12};
//        TreeNode *result = bstFromPreorder2(arr);
//        tool.printBT(result);
//    }
//};

#pragma mark - 783
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
//    int result = INT_MAX;
//    int minDiffInBST(TreeNode* root) {
//
//        int lastVal = -1;
//        treeTraversal(root, lastVal);
//
//        return result;
//    }
//
//    void treeTraversal(TreeNode *node, int &lastVal) {
//        if (node == nullptr || result == 1) {
//            return;
//        }
//
//        treeTraversal(node->left, lastVal);
//        if (lastVal != -1) {
//            result = min(result, node->val - lastVal);
//        }
//        lastVal = node->val;
//        treeTraversal(node->right, lastVal);
//    }
//
//    void test() {
//        vector<int> arr = {1,0,48,-1,-1,12,49};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = minDiffInBST(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 865
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
//    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//        //层先找最深节点
//
//        if (root == nullptr) {
//            return nullptr;
//        }
//
//        int deepestLevel = 0;
//
//        deque<TreeNode *> deque;
//        deque.push_back(root);
//        while (deque.size() != 0) {
//            int size = (int)deque.size();
//            deepestLevel++;
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = deque.front();
//                deque.pop_front();
//
//                if (node->left != nullptr) {
//                    deque.push_back(node->left);
//                }
//
//                if (node->right != nullptr) {
//                    deque.push_back(node->right);
//                }
//            }
//        }
//
//        return treeTraversal(root, deepestLevel);
//    }
//
//    TreeNode* subtreeWithAllDeepest2(TreeNode* root) {
//        int maxDeep = 0;
//        getMaxDeep(root, maxDeep, 0);
//
//        return treeTraversal(root, maxDeep);
//    }
//
//    void getMaxDeep(TreeNode *node, int &maxDeep, int currDeep) {
//        if (node == nullptr) {
//            maxDeep = max(maxDeep, currDeep);
//            return;
//        }
//
//        getMaxDeep(node->left, maxDeep, currDeep + 1);
//        getMaxDeep(node->right, maxDeep, currDeep + 1);
//    }
//
//    TreeNode *treeTraversal(TreeNode *node, int level) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//
//        if (level == 1) {
//            return node;
//        }
//
//        TreeNode *left = treeTraversal(node->left, level - 1);
//        TreeNode *right = treeTraversal(node->right, level - 1);
//
//        if (left != nullptr && right != nullptr) {
//            return node;
//        }
//
//        if (left != nullptr) {
//            return left;
//        }
//
//        if (right != nullptr) {
//            return right;
//        }
//
//        return nullptr;
//    }
//    typedef pair<TreeNode*, int> NodeDeep;
//    int maxDeep = 0;
//    TreeNode* subtreeWithAllDeepest3(TreeNode* root) {
//
//        return getDeepestNode(root, 0).first;
//    }
//
//    NodeDeep getDeepestNode(TreeNode *node, int deep) {
//        if (node == nullptr) {
//            maxDeep = max(maxDeep, deep);
//            return NodeDeep(nullptr, deep);
//        }
//
//
//        NodeDeep leftNodeDeep = getDeepestNode(node->left, deep + 1);
//        NodeDeep rightNodeDeep = getDeepestNode(node->right, deep + 1);
//
//        if (leftNodeDeep.second == maxDeep && rightNodeDeep.second == maxDeep) {
//            return NodeDeep(node, maxDeep);
//        }
//
//        if (leftNodeDeep.second == maxDeep) {
//            return leftNodeDeep;
//        }
//
//        if (rightNodeDeep.second == maxDeep) {
//            return rightNodeDeep;
//        }
//
//        return NodeDeep(node, deep + 1);
//    }
//
//
//    void test() {
//        vector<int> arr = {3,5,1,6,2,0,8,-1,-1,7,4};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        TreeNode *result = subtreeWithAllDeepest3(root);
//        tool.printBT(result);
//    }
//
//};

#pragma mark - 1530
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
//    int findDistance = 0;
//    int result = 0;
//    int countPairs(TreeNode* root, int distance) {
//        findDistance = distance;
//        treeTraversal(root);
//
//        return result;
//    }
//
//    vector<int> treeTraversal(TreeNode *node) {
//        if (node == nullptr) {
//            return {};
//        }
//        if (node->left == nullptr && node->right == nullptr) {
//            return {1};
//        }
//
//        vector<int> left = treeTraversal(node->left);
//        vector<int> right = treeTraversal(node->right);
//
//        if (left.size() != 0 && right.size() != 0) {
//            for (int i = 0; i < left.size(); i++) {
//                for (int j = 0; j < right.size(); j++) {
//                    if (left[i] + right[j] <= findDistance) {
//                        result++;
//                    }
//                }
//            }
//        }
//
//        left.insert(left.end(), right.begin(), right.end());
//
//        for (int i = 0; i < left.size(); i++) {
//            left[i]++;
//        }
//
//        return left;
//    }
//
//    void test() {
//        vector<int> arr = {7,1,4,6,-1,5,3,-1,-1,-1,-1,-1,2};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = countPairs(root, 3);
//        cout<<result<<endl;
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
//    vector<TreeNode*> allPossibleFBT(int n) {
//        if (n % 2 == 0) {
//            return {};
//        }
//
//        if (n == 1) {
//            return {new TreeNode(0)};
//        }
//
//        vector<TreeNode *>result;
//        for (int i = 1; i < n; i++) {
//            vector<TreeNode *> left = allPossibleFBT(i);
//            vector<TreeNode *> right = allPossibleFBT(n - i - 1);
//
//            for (int j = 0; j < left.size(); j++) {
//                for (int k = 0; k < right.size(); k++) {
//                    TreeNode *root = new TreeNode(0);
//                    root->left = left[j];
//                    root->right = right[k];
//                    result.push_back(root);
//                }
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<TreeNode *> result = allPossibleFBT(7);
//
//        for (int i = 0; i < result.size(); i++) {
//            tool.printBT(result[i]);
//        }
//    }
//};

#pragma mark - jianzhi55-1
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
//    int maxDepth(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
//    }
//
//    void test() {
//        vector<int> arr = {3,9,20,-1,-1,15,7};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        int result = maxDepth(root);
//        cout<<result<<endl;
//    }
//};

#pragma mark - jiangzhi34
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
//        vector<int> path;
//
//        treeTraversal(root, target, path);
//
//        return result;
//    }
//
//    void treeTraversal(TreeNode *node, int target, vector<int> &path) {
//        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
//            if (node != nullptr && target == node->val) {
//                path.push_back(node->val);
//                result.push_back(path);
//                path.pop_back();
//            }
//            return;
//        }
//
//        path.push_back(node->val);
//        treeTraversal(node->left, target - node->val, path);
//        treeTraversal(node->right, target - node->val, path);
//        path.pop_back();
//    }
//
//    void test() {
//        vector<int> arr = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
//        TreeNode *root = tool.createBT(arr);
//        tool.printBT(root);
//
//        vector<vector<int>> result = pathSum(root, 22);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 101
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
//    bool isSymmetric(TreeNode* root) {
//        //递归
//        if (root == nullptr) {
//            return true;
//        }
//        
//        return isSymmetricNode(root->left, root->right);
//    }
//    
//    bool isSymmetricNode(TreeNode *left, TreeNode *right) {
//        if (left == nullptr || right == nullptr) {
//            if (left != right) {
//                return false;
//            }
//            return true;
//        }
//        if (left->val != right->val) {
//            return false;
//        }
//        
//        bool leftSymmetric = isSymmetricNode(left->left, right->right);
//        bool rightSymmeric = isSymmetricNode(left->right, right->left);
//        
//        return leftSymmetric && rightSymmeric;
//    }
//    
//    bool isSymmetric2(TreeNode* root) {
//        //迭代
//        if (root == nullptr) {
//            return true;
//        }
//
//        deque<TreeNode *> dequeLeft, dequeRight;
//        dequeLeft.push_back(root->left);
//        dequeRight.push_back(root->right);
//
//        while (dequeLeft.empty() == false || dequeRight.empty() == false) {
//            int leftCount = (int)dequeLeft.size();
//            int rightCount = (int)dequeRight.size();
//
//            if (leftCount != rightCount) {
//                return false;
//            }
//            
//            for (int i = 0; i < leftCount; i++) {
//                TreeNode *left = dequeLeft.front();
//                dequeLeft.pop_front();
//                TreeNode *right = dequeRight.front();
//                dequeRight.pop_front();
//                
//                if (left == nullptr || right == nullptr) {
//                    if (left != right) {
//                        return false;
//                    }
//                }
//                else {
//                    if (left->val != right->val) {
//                        return false;
//                    }
//                    
//                    dequeLeft.push_back(left->left);
//                    dequeRight.push_back(right->right);
//                    dequeLeft.push_back(left->right);
//                    dequeRight.push_back(right->left);
//                }
//            }
//        }
//        
//        return true;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,2,3,4,4};
//        TreeNode *root = tool.createBT(arr);
//        
//        bool result = isSymmetric2(root);
//        cout<<result<<endl;
//        
//    }
//    
//};
