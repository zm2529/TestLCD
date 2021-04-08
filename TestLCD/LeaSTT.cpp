//
//  LeaSTT.cpp
//  TestLCD
//
//  Created by zm on 2021/3/24.
//

#include "LeaSTT.hpp"
#include <iostream>
#include <vector>

using namespace std;

struct TNode {
    TNode *left;
    TNode *right;
    int value;
};

vector<int> gem(vector<int>& arr) {

//    vector<vector<int>> tempGem((int)arr.size(), vector<int>((int)arr.size()));
//    tempGem[0][0] = arr[0];
//    int result = 0;
//    int s = 0, e = 0;
//    for (int i = 0; i < arr.size(); i++) {
//        for (int j = i + 1; j < arr.size(); j++) {
//            tempGem[i][j] = tempGem[i][j - 1] + arr[j];
//            if (tempGem[i][j] > result) {
//                result = tempGem[i][j];
//                s = i;
//                e = j;
//            }
//        }
//    }

    vector<int> tempGem((int)arr.size());
    tempGem[0] = arr[0];
    int result = arr[0];
    int s = 0, e = 0;
    for (int i = 1; i < arr.size(); i++) {
        tempGem[i] = max(arr[i], tempGem[i - 1] + arr[i]);
        if (tempGem[i - 1] < 0 && tempGem[i] > tempGem[i - 1]) {
            s = i;
        }

        if (tempGem[i] > result ) {
            result = tempGem[i];
            e = i;
        }
    }

    return {s, e};
}

int stairs(int n) {
    //转移方程f(n) = f(n - 1) + f(n - 2) + f(n - 3)
    int mod = 1000000007;
    int count = n + 1;
    if (n < 4) {
        count = 4;
    }
    vector<int> result(count);
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 4;

    for (int i = 4; i <= n; i++) {
        result[i] = (((result[i - 1]) + (result[i - 2])) % mod + (result[i - 3]))  % mod;
    }

    return result[n];
}

//class Solution {
//public:
//    vector<int> f;
//    int mod = 1000000007;
//    int waysToStep(int n) {
//        f.resize(n+1);
//        f[0] = 1;
//        for(int i = 1; i <= n; i++) {
//            f[i] = f[i-1];
//            if(i >= 2) f[i] = (f[i] + f[i-2]) % mod;
//            if(i >= 3) f[i] = (f[i] + f[i-3]) % mod;
//        }
//        return f[n];
//    }
//};
//
//
//void LeaStt::test() {
//
////    vector<int> arr = {};
////    vector<int> result = gem(arr);
////
////    int i = 0;
//
////    int result = stairs(76);
//    Solution solution;
//    for (int i = 0; i < 10; i++) {
//        int r = rand() % 100;
//        cout<<r<<"  ";
//        int result = solution.waysToStep(r);
//        int result2 = stairs(r);
//
//        cout<<result<<"  "<<result2<<endl;
//    }
//}
