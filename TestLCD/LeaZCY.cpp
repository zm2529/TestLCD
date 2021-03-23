//
//  LeaZCY.cpp
//  TestLCD
//
//  Created by zm on 2021/3/23.
//

#include "LeaZCY.hpp"

#include <iostream>
#include <vector>

using namespace std;

/*数组装水
 一个数组看成柱状图，问最大能装多少水
 */
int water(vector<int>& arr) {

    vector<int> arrLeftMax(arr.size());//存储从左向右的最大值
    vector<int> arrRightMax(arr.size());//存储从右向左的最大值
    arrLeftMax[0] = arr[0];
    arrRightMax[0] = arr[arr.size()];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arrLeftMax[i - 1]) {
            arrLeftMax[i] = arr[i];
        }
        else {
            arrLeftMax[i] = arrLeftMax[i - 1];
        }

        if (arr[arr.size() - 1 - i] > arrRightMax[i - 1]) {
            arrRightMax[i] = arr[arr.size() - 1 - i];
        }
        else {
            arrRightMax[i] = arrRightMax[i - 1];
        }
    }

    int allWater = 0;
    for (int i = 0; i < arr.size(); i++) {
        int limit = min(arrLeftMax[i], arrRightMax[i]);
        int water = max(limit - i, 0);
        allWater += water;
    }

    return allWater;
}

//数组装水最优
int waterForOptimize(vector<int>& arr) {
    //双指针，两边最大的真实值就是当前位置的限制

    int leftMax = arr[0], rightMax = arr[arr.size() - 1];
    int lPtr = 1, rPtr = (int)arr.size() - 2;
    int allWater = 0;
    while (lPtr < rPtr) {

        if (arr[lPtr] > leftMax) {
            leftMax = arr[lPtr];
        }

        if (arr[rPtr] > rightMax) {
            rightMax = arr[rPtr];
        }

        if (leftMax < rightMax) {//左边的小，左边是已经遍历过的最大值，当前位置的最大限制为左边最大值
            allWater = leftMax - arr[lPtr];
            lPtr++;
        }
        else {
            allWater = rightMax - arr[rPtr];
            rPtr--;
        }
    }

    return allWater;
}


/*随机数字
 一个随机数方法只能返回a-b，给出等概率返回c-d的方法
 */

static int a = 0, b = 4, c = 15, d = 28;

int randomAB() {
    return (rand() % (b - a + 1) + a);
}

int randomBinary() {

    int r = randomAB();

    if ((b - a + 1) % 2 == 0) {

        if (r <= (a + b) / 2) {
            return 0;
        }
        else {
            return 1;
        }

    }
    else {
        if (r == (a + b) / 2) {
            return randomBinary();
        }
        else if (r > (a + b) / 2) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

int randomCD() {
    int count = d - c;
    int times = 0;
    while (count > 0) {
        count = count / 2;
        times++;
    }
    int num = 0;
    while (times >= 0) {
        int r = randomBinary();
        num += (r << times);
        times--;
    }

    if (num + c > d) {
        return randomCD();
    }

    return num + c;
}

/*不等概率随机数字
 一个随机数方法，p概率返回0，1-p概率返回1，给出等概率返回0和1的方法
 */
int randomUnfair() {
    return rand() % 100 < 90 ? 0 : 1;
}

int randomFair() {
    int r1 = 0 , r2 = 0;
    while (r1 == r2) {
        r1 = randomUnfair();
        r2 = randomUnfair();
    }

    return r1;
}

/*bst后序遍历恢复
 一个后序遍历的bst数组，恢复bst，并返回头
 */
struct TNode {
    TNode *left;
    TNode *right;
    int value;
    TNode(int value):value(value),left(nullptr),right(nullptr){}
};

TNode *createBST(vector<int>& arrValue) {
    TNode *head = new TNode(arrValue[0]);
    TNode *p = head;
    for (int i = 1; i < arrValue.size(); i++) {
        while (p == nullptr) {
            if (arrValue[i] > p->value) {
                p = p->right;
            }
            else {
                p = p->left;
            }
        }
        p = new TNode(arrValue[i]);
    }

    return head;
}


TNode *createPostorderTraversalSubMethod(TNode *head, vector<int>& arrPos) {
    if (head->left == nullptr && head->right == nullptr) {
        return head;
    }
    TNode *left = createPostorderTraversalSubMethod(head->left, arrPos);
    TNode *right = createPostorderTraversalSubMethod(head->right, arrPos);

    arrPos.push_back(left->value);
    arrPos.push_back(right->value);
    arrPos.push_back(head->value);

    return head;
}

vector<int> createPostorderTraversal(TNode *head) {

    vector<int> arr;

    createPostorderTraversalSubMethod(head, arr);

    return arr;

}

TNode * recoveBSTSubMethod(vector<int>& arrPos, int left, int right) {

    if (left >= right) {
        return nullptr;
    }
    int headValue = arrPos[right];
    TNode *head = new TNode(headValue);

    int leftHead = left - 1, rightHead = right - 1;
    while (leftHead < right) {
        if (arrPos[leftHead] < headValue) {
            leftHead++;
        }
        else{
            break;
        }
    }

    head->left = recoveBSTSubMethod(arrPos, left, leftHead);
    head->right = recoveBSTSubMethod(arrPos, leftHead + 1, rightHead);

    return head;
}

TNode* recoveBSTFromPostorderTraversal(vector<int>& arrPos) {
    return recoveBSTSubMethod(arrPos, 0, (int)arrPos.size() - 1);
}



//bst后序遍历logn二分搜索

//bst对数器

/*包含字串
 给定长度为m的字符串aim，以及一个长度为n的字符串str，问能否在str中国呢找到一个长度为m的连续字串，使得这个字串刚好由m个字符组成，顺序无所谓，返回任意满足条件的一个字串的起始位置，未找到的返回-1
 */

void LeaZcy::test() {

    srand((int)time(NULL));

//    //随机0，1
//    {
//        vector<int> arr(2);
//        for (int i = 0; i < 100000; i++) {
//            arr[randomFair()]++;
//        }
//
//        for (int i = 0; i < arr.size(); i++) {
//            cout<<i<<":"<<arr[i]<<endl;
//        }
//    }

//    //随机abcd
//    {
//        vector<int> arr(14);
//        for (int i = 0; i < 1000000; i++) {
//            int r = randomCD() - c;
//            arr[r]++;
//        }
//
//        for (int i = 0; i < arr.size(); i++) {
//            cout<<i + c<<":"<<arr[i]<<endl;
//        }
//    }

    //生成bst
    {
        vector<int> arr = {4,2,9,2,8,5,4,7,1,0};
    }
}
