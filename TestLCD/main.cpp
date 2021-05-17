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

#pragma mark - 1642
//class Solution {
//public:
//    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//        //优先使用砖头，到不能走的时候，用梯子替换最费砖头的地方，继续向前走
//
//        typedef pair<int, int> BrickPosInfo;//位置，数量
//
//        auto cmp = [&](BrickPosInfo a, BrickPosInfo b) {
//            return a.second < b.second;
//        };
//
//        priority_queue<BrickPosInfo, vector<BrickPosInfo>, decltype(cmp)> queue(cmp);//记录用砖头过的位置和砖头数量
//
//        int result = 0;
//
//        for (int i = 1; i < heights.size(); i++) {
//            int height = heights[i] - heights[i - 1];
//
//            if (height > 0) {
//                if (height <= bricks) {
//                    queue.push(BrickPosInfo(i, height));
//                    bricks -= height;
//                    result = i;
//                }
//                else {
//                    if (ladders > 0) {//还有梯子
//                        //选一个最费砖头的楼层用梯子
//                        if (queue.size() > 0) {//之前有用过砖头
//                            BrickPosInfo info = queue.top();
//                            if (info.second <= height) {//如果之前最费砖头的都没有现在的位置费砖头，现在位置用梯子
//                                ladders--;
////                                cout<<"使用梯子"<<i<<endl;
//                                result = i;
//                            }
//                            else {
//                                queue.pop();
//                                ladders--;//使用梯子
////                                cout<<"使用梯子"<<info.first<<endl;
//                                bricks += info.second;//回收砖头
//                                i--;
//                            }
//                        }
//                        else {//之前没有用过砖头，直接使用梯子
//                            ladders--;
//                            result = i;
//                        }
//                    }
//                    else{
//                        break;
//                    }
//                }
//            }
//            else {
//                result = i;
//            }
//        }
//
//        return result;
//    }
//
//    int furthestBuilding2(vector<int>& heights, int bricks, int ladders) {
//
//        //优化 队列只存用砖头的位置
//        //优先使用砖头，到不能走的时候，用梯子替换最费砖头的地方，继续向前走
//
//        auto cmp = [&](int a, int b) {
//            return (heights[a] - heights[a - 1]) < (heights[b] - heights[b - 1]);
//        };
//
//        priority_queue<int, vector<int>, decltype(cmp)> queue(cmp);//记录用砖头过的位置和砖头数量
//
//        int result = 0;
//
//        for (int i = 1; i < heights.size(); i++) {
//            int height = heights[i] - heights[i - 1];
//
//            if (height > 0) {
//                if (height <= bricks) {
//                    queue.push(i);
//                    bricks -= height;
//                }
//                else {
//                    if (ladders > 0) {//还有梯子
//                        ladders--;
//                        //选一个最费砖头的楼层用梯子
//                        if (queue.size() > 0) {//之前有用过砖头
//                            int pos = queue.top();
//
//                            int costBrick = heights[pos] - heights[pos - 1];
//
//                            if (costBrick > height) {
//                                queue.pop();
//                                bricks = costBrick - height;//回收砖头
//                                queue.push(i);
//                            }
//                        }
//                    }
//                    else{
//                        break;
//                    }
//                }
//            }
//
//            result = i;
//        }
//
//        return result;
//    }
//
//
//    void test() {
//        vector<int> heights = {1,4,6,7};
//        int bricks = 2;
//        int ladders = 1;
//
//        int result = furthestBuilding(heights, bricks, ladders);
//        cout<<result<<endl;
//    }
//};

#pragma mark - mianshi17.14
//class Solution {
//public:
//    vector<int> smallestK(vector<int>& arr, int k) {
//        //直接排序输出
//        if (k == 0) {
//            return {};
//        }
//        vector<int> result;
//        sort(arr.begin(), arr.end());
//
//        result.assign(arr.begin(), arr.begin() + k);
//        return result;
//    }
//
//    vector<int> smallestK2(vector<int>& arr, int k) {
//        //大顶堆
//
//        if (k == 0) {
//            return {};
//        }
//        priority_queue<int, vector<int>, less<int>> queue;
//
//        for (int i = 0; i < arr.size(); i++) {
//            if (queue.size() < k) {
//                queue.push(arr[i]);
//            }
//            else {
//                if (queue.top() > arr[i]) {
//                    queue.pop();
//                    queue.push(arr[i]);
//                }
//            }
//        }
//
//        vector<int> result(k);
//        for (int i = k - 1; i >= 0; i--) {
//            result[i] = queue.top();
//            queue.pop();
//        }
//
//        return result;
//    }
//
//    vector<int> smallestK3(vector<int>& arr, int k) {
//        //快排
//        if (k == 0) {
//            return {};
//        }
//
//        vector<int> result;
//
//        int l = 0, r = (int)arr.size() - 1;
//
//        while (1) {
//            int count = quickSort(arr, l, r);
//
//            if (count == k) {
//                result.assign(arr.begin(), arr.begin() + k);
//                return result;
//            }
//
//            if (count > k) {
//                r = count - 1;
//            }
//            else {
//                l = count;
//            }
//        }
//    }
//
//    int quickSort(vector<int>& arr, int s, int e) {
//        int l = s, r = e;
//        while (l < r) {
//            if (arr[l] <= arr[e]) {
//                l++;
//            }
//            else {
//                r--;
//                swap(arr[l], arr[r]);
//            }
//        }
//        swap(arr[l], arr[e]);
//
//        return l;
//    }
//
//    void test() {
//        vector<int> arr = {5,2,3,4};
//
//        vector<int> result = smallestK3(arr, 1);
//        tool.printVector(result);
//    }
//
//};

#pragma mark - 973
//class Solution {
//public:
//    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//        //最大堆
//
//        auto cmp = [&](vector<int>& a, vector<int>& b){
//            return getDistance(a) < getDistance(b);
//        };
//
//        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> queue(cmp);
//
//        for (int i = 0; i < points.size(); i++) {
//            if (queue.size() < k) {
//                queue.push(points[i]);
//            }
//            else {
//                vector<int> temp = queue.top();
//                if (getDistance(points[i]) < getDistance(temp)) {
//                    queue.pop();
//                    queue.push(points[i]);
//                }
//            }
//        }
//
//        vector<vector<int>> result;
//        while (queue.size() > 0) {
//            result.push_back(queue.top());
//            queue.pop();
//        }
//
//        return result;
//    }
//
//    vector<vector<int>> kClosest2(vector<vector<int>>& points, int k) {
//        //排序
//
//        auto cmp = [&](vector<int>& a, vector<int>& b) {
//            return getDistance(a) < getDistance(b);
//        };
//
//        sort(points.begin(), points.end(), cmp);
//
//        vector<vector<int>> result(points.begin(), points.begin() + k);
//
//        return result;
//    }
//
//    int getDistance(vector<int>& vec) {
//        return vec[0] * vec[0] + vec[1] * vec[1];
//    }
//
//    void test() {
//        vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
//
//        vector<vector<int>> result = kClosest2(points, 2);
//        tool.printMatrix(result);
//    }
//};

#pragma mark - 743
//class Solution {
//public:
//    /**
//     有 n 个网络节点，标记为 1 到 n。
//
//     给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。
//
//     现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
//
//
//
//     示例 1：
//
//
//
//     输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//     输出：2
//     示例 2：
//
//     输入：times = [[1,2,1]], n = 2, k = 1
//     输出：1
//     示例 3：
//
//     输入：times = [[1,2,1]], n = 2, k = 2
//     输出：-1
//
//
//     提示：
//
//     1 <= k <= n <= 100
//     1 <= times.length <= 6000
//     times[i].length == 3
//     1 <= ui, vi <= n
//     ui != vi
//     0 <= wi <= 100
//     所有 (ui, vi) 对都 互不相同（即，不含重复边）
//
//     关于邻接矩阵与邻接表的复杂度分析,二则在建图部分均花费 n 的时间复杂度，关注循环部分，邻接矩阵遍历了两次顶点，因此循环的时间花费为 n^2 + n^2，即总时间为 n + n^2 + n^2，渐进意义下为O(n^2)；邻接表在循环部分只遍历了一次顶点，在while循环中最终遍历了所有的边，循环部分的总时间为 n^2 + E，总时间为 n + n^2 + E，在图极为稠密时，E = n^2，此时二者差距不大，其他情况下邻接表性能略优，其渐进意义下的时间复杂度仍为O(n^2)。空间上，邻接矩阵利用二维数组保存数据，而邻接表只需 n 个节点数据加上 E 条边节点数据即可，当E较小时，邻接表会极大的节省空间。
//
//     */
//    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//        //dijkstra
//        int MAX_INF = 999;
//
//        vector<int> result(n + 1, MAX_INF);
//        result[k] = 0;
//
//        unordered_set<int> notArrivedPointSet;//未到达的点
//        for (int i = 1; i <= n; i++) {
//            notArrivedPointSet.insert(i);
//        }
//        notArrivedPointSet.erase(k);
//
//        vector<vector<int>> map(n + 1, vector<int>(n + 1, MAX_INF));
//        for (int i = 0; i < times.size(); i++) {
//            map[times[i][0]][times[i][1]] = times[i][2];
//        }
//        map[k][k] = 0;
//
//        int start = k;
//        while (notArrivedPointSet.size() > 0) {//还有未到达的点
//            for (int i = 1; i < map[start].size(); i++) {//从开始点更新到达各个点的距离
//                result[i] = min(result[i], result[start] + map[start][i]);
//            }
//
//            //查找延迟最小的点
//            int minPoint = 0;
//            int minTime = MAX_INF;
//            for (auto i : notArrivedPointSet) {
//                if (minTime >= result[i]) {
//                    minTime = result[i];
//                    minPoint = i;
//                }
//            }
//            notArrivedPointSet.erase(minPoint);//到达延迟最小的点
//            start = minPoint;//从延迟最小的点继续查找
//        }
//
//        int maxDelayTime = 0;
//        for (int i = 1; i < result.size(); i++) {
//            maxDelayTime = max(maxDelayTime, result[i]);
//        }
//
//        return maxDelayTime == MAX_INF ? -1 : maxDelayTime;
//    }
//
//    int networkDelayTime2(vector<vector<int>>& times, int n, int k) {
//        //dijkstra 不用set用堆优化
//        int MAX_INF = 999;
//
//        vector<int> result(n + 1, MAX_INF);
//        result[k] = 0;
//
//        auto cmp = [&](int a, int b) {
//            return result[a] > result[b];
//        };
//        priority_queue<int, vector<int>, decltype(cmp)> queue(cmp);
//
//        unordered_set<int> arrivedPointSet;
//
//        for (int i = 1; i <= n; i++) {
//            if (i != k) {
//                queue.push(i);
//            }
//        }
//
//        vector<vector<int>> map(n + 1, vector<int>(n + 1, MAX_INF));
//        for (int i = 0; i < times.size(); i++) {
//            map[times[i][0]][times[i][1]] = times[i][2];
//        }
//        map[k][k] = 0;
//
//        int start = k;
//        while (queue.size() > 0) {//还有未到达的点
//            arrivedPointSet.insert(start);
//            for (int i = 1; i < map[start].size(); i++) {//从开始点更新到达各个点的距离
//                if (result[i] > result[start] + map[start][i]) {
//                    result[i] = result[start] + map[start][i];
//                    queue.push(i);
//                }
//            }
//            start = -1;
//            while (start == -1 && queue.size() > 0) {
//                start = queue.top();//从延迟最小的点继续查找
//                queue.pop();
//                if (arrivedPointSet.find(start) != arrivedPointSet.end()) {
//                    start = -1;
//                }
//            }
//        }
//
//
//        int maxDelayTime = 0;
//        for (int i = 1; i < result.size(); i++) {
//            maxDelayTime = max(maxDelayTime, result[i]);
//        }
//
//        return maxDelayTime == MAX_INF ? -1 : maxDelayTime;
//    }
//
//    void test() {
//        /**
//         {{4,2,76},{1,3,79},{3,1,81},{4,3,30},{2,1,47},{1,5,61},{1,4,99},{3,4,68},{3,5,46},{4,1,6},{5,4,7},{5,3,44},{4,5,19},{2,3,13},{3,2,18},{1,2,0},{5,1,25},{2,5,58},{2,4,77},{5,2,74}}
//         5
//         3
//
//         {{15,8,1},{7,10,41},{7,9,34},{9,4,31},{12,13,50},{14,3,52},{4,11,99},{4,7,86},{10,13,57},{9,6,10},{1,7,51},{7,15,38},{1,9,11},{12,7,94},{9,13,34},{11,7,79},{7,6,28},{5,3,34},{2,6,97},{14,1,97},{6,10,90},{12,10,37},{13,3,73},{11,14,7},{15,1,39},{6,5,90},{13,6,43},{6,9,32},{4,6,45},{11,10,2},{2,13,4},{14,15,29},{1,14,88},{14,6,19},{6,2,29},{3,14,72},{1,15,4},{11,5,2},{6,7,56},{8,7,88},{13,14,70},{14,12,58},{14,2,86},{11,3,57},{5,2,56},{3,10,26},{2,11,21},{14,5,54},{5,12,40},{14,4,81},{15,2,99},{5,7,57},{13,12,5},{4,9,60},{12,15,48},{6,14,1},{9,7,44},{13,7,69},{5,13,42},{4,1,7},{11,9,76},{8,1,76},{5,14,29},{2,3,69},{7,3,23},{12,14,28},{11,4,85},{10,1,10},{15,12,36},{1,11,69},{15,10,96},{11,13,69},{7,12,49},{1,2,95},{6,4,46},{8,12,94},{12,4,93},{13,5,31},{12,2,60},{6,1,87},{4,14,20},{5,11,89},{4,15,88},{4,10,21},{1,6,5},{10,8,26},{8,2,51},{3,15,23},{7,2,12},{11,1,47},{2,1,75},{3,8,63},{8,10,19},{6,8,18},{4,2,55},{14,11,80},{10,3,73},{3,5,22},{12,3,61},{1,13,33},{9,3,98},{9,12,69},{15,9,6},{7,13,76},{11,12,22},{11,15,51},{13,15,46},{5,10,58},{1,10,26},{13,4,85},{7,14,58},{5,8,46},{11,6,32},{10,9,41},{9,14,35},{14,13,60},{3,9,97},{2,5,39},{7,11,19},{1,12,27},{7,5,13},{8,4,34},{9,15,25},{5,1,93},{15,13,97},{14,9,35},{8,6,67},{9,5,39},{13,11,35},{7,4,21},{12,9,64},{14,8,8},{10,12,94},{8,9,76},{8,5,71},{2,9,64},{10,14,59},{1,4,74},{7,1,69},{15,5,55},{6,15,80},{13,8,84},{8,13,63},{8,3,91},{10,4,87},{1,5,39},{8,11,0},{1,3,79},{4,5,82},{4,12,87},{3,11,29},{7,8,92},{10,7,77},{6,12,42},{13,2,40},{9,10,13},{4,13,65},{2,4,34},{3,13,44},{2,14,69},{3,4,42},{5,15,98},{14,7,6},{15,3,94},{10,2,37},{15,11,7},{9,2,15},{13,9,66},{4,8,83},{8,15,23},{13,1,50},{6,13,57},{2,10,37},{10,6,38},{2,7,45},{9,8,8},{3,12,28},{3,2,83},{2,12,75},{1,8,91},{4,3,70},{12,6,48},{3,1,13},{5,6,42},{6,11,96},{3,6,22},{15,6,34},{11,8,43},{15,7,40},{9,11,57},{11,2,11},{2,8,22},{9,1,73},{2,15,40},{12,11,10},{15,4,78},{12,8,75},{10,15,37},{13,10,44},{8,14,33},{3,7,82},{5,4,46},{12,5,79},{15,14,43},{10,5,65},{5,9,34},{12,1,54},{6,3,16},{14,10,83},{10,11,67}}
//         15
//         8
//
//         */
//        vector<vector<int>> times = {{15,8,1},{7,10,41},{7,9,34},{9,4,31},{12,13,50},{14,3,52},{4,11,99},{4,7,86},{10,13,57},{9,6,10},{1,7,51},{7,15,38},{1,9,11},{12,7,94},{9,13,34},{11,7,79},{7,6,28},{5,3,34},{2,6,97},{14,1,97},{6,10,90},{12,10,37},{13,3,73},{11,14,7},{15,1,39},{6,5,90},{13,6,43},{6,9,32},{4,6,45},{11,10,2},{2,13,4},{14,15,29},{1,14,88},{14,6,19},{6,2,29},{3,14,72},{1,15,4},{11,5,2},{6,7,56},{8,7,88},{13,14,70},{14,12,58},{14,2,86},{11,3,57},{5,2,56},{3,10,26},{2,11,21},{14,5,54},{5,12,40},{14,4,81},{15,2,99},{5,7,57},{13,12,5},{4,9,60},{12,15,48},{6,14,1},{9,7,44},{13,7,69},{5,13,42},{4,1,7},{11,9,76},{8,1,76},{5,14,29},{2,3,69},{7,3,23},{12,14,28},{11,4,85},{10,1,10},{15,12,36},{1,11,69},{15,10,96},{11,13,69},{7,12,49},{1,2,95},{6,4,46},{8,12,94},{12,4,93},{13,5,31},{12,2,60},{6,1,87},{4,14,20},{5,11,89},{4,15,88},{4,10,21},{1,6,5},{10,8,26},{8,2,51},{3,15,23},{7,2,12},{11,1,47},{2,1,75},{3,8,63},{8,10,19},{6,8,18},{4,2,55},{14,11,80},{10,3,73},{3,5,22},{12,3,61},{1,13,33},{9,3,98},{9,12,69},{15,9,6},{7,13,76},{11,12,22},{11,15,51},{13,15,46},{5,10,58},{1,10,26},{13,4,85},{7,14,58},{5,8,46},{11,6,32},{10,9,41},{9,14,35},{14,13,60},{3,9,97},{2,5,39},{7,11,19},{1,12,27},{7,5,13},{8,4,34},{9,15,25},{5,1,93},{15,13,97},{14,9,35},{8,6,67},{9,5,39},{13,11,35},{7,4,21},{12,9,64},{14,8,8},{10,12,94},{8,9,76},{8,5,71},{2,9,64},{10,14,59},{1,4,74},{7,1,69},{15,5,55},{6,15,80},{13,8,84},{8,13,63},{8,3,91},{10,4,87},{1,5,39},{8,11,0},{1,3,79},{4,5,82},{4,12,87},{3,11,29},{7,8,92},{10,7,77},{6,12,42},{13,2,40},{9,10,13},{4,13,65},{2,4,34},{3,13,44},{2,14,69},{3,4,42},{5,15,98},{14,7,6},{15,3,94},{10,2,37},{15,11,7},{9,2,15},{13,9,66},{4,8,83},{8,15,23},{13,1,50},{6,13,57},{2,10,37},{10,6,38},{2,7,45},{9,8,8},{3,12,28},{3,2,83},{2,12,75},{1,8,91},{4,3,70},{12,6,48},{3,1,13},{5,6,42},{6,11,96},{3,6,22},{15,6,34},{11,8,43},{15,7,40},{9,11,57},{11,2,11},{2,8,22},{9,1,73},{2,15,40},{12,11,10},{15,4,78},{12,8,75},{10,15,37},{13,10,44},{8,14,33},{3,7,82},{5,4,46},{12,5,79},{15,14,43},{10,5,65},{5,9,34},{12,1,54},{6,3,16},{14,10,83},{10,11,67}};
//        int n = 15;
//        int k = 8;
//
//        int result = networkDelayTime2(times, n, k);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 882
//class Solution {
//public:
//    /**
//     给你一个无向图（原始图），图中有 n 个节点，编号从 0 到 n - 1 。你决定将图中的每条边细分为一条节点链，每条边之间的新节点数各不相同。
//
//     图用由边组成的二维数组 edges 表示，其中 edges[i] = [ui, vi, cnti] 表示原始图中节点 ui 和 vi 之间存在一条边，cnti 是将边细分后的新节点总数。注意，cnti == 0 表示边不可细分。
//
//     要细分边 [ui, vi] ，需要将其替换为 (cnti + 1) 条新边，和 cnti 个新节点。新节点为 x1, x2, ..., xcnti ，新边为 [ui, x1], [x1, x2], [x2, x3], ..., [xcnti+1, xcnti], [xcnti, vi] 。
//
//     现在得到一个新的 细分图 ，请你计算从节点 0 出发，可以到达多少个节点？节点 是否可以到达的判断条件 为：如果节点间距离是 maxMoves 或更少，则视为可以到达；否则，不可到达。
//
//     给你原始图和 maxMoves ，返回新的细分图中从节点 0 出发 可到达的节点数 。
//
//
//
//     示例 1：
//
//
//     输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
//     输出：13
//     解释：边的细分情况如上图所示。
//     可以到达的节点已经用黄色标注出来。
//     示例 2：
//
//     输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
//     输出：23
//     示例 3：
//
//     输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
//     输出：1
//     解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
//
//
//     提示：
//
//     0 <= edges.length <= min(n * (n - 1) / 2, 104)
//     edges[i].length == 3
//     0 <= ui < vi < n
//     图中 不存在平行边
//     0 <= cnti <= 104
//     0 <= maxMoves <= 109
//     1 <= n <= 3000
//
//     #define pii pair<int, int>
//
//     class Solution {
//     public:
//         int reachableNodes(vector<vector<int>>& edges, int M, int N) {
//             vector<vector<pii>> graph(N);
//             for (vector<int> edge: edges) {
//                 int u = edge[0], v = edge[1], w = edge[2];
//                 graph[u].push_back({v, w});
//                 graph[v].push_back({u, w});
//             }
//
//             map<int, int> dist;
//             dist[0] = 0;
//             for (int i = 1; i < N; ++i)
//                 dist[i] = M+1;
//
//             map<pii, int> used;
//             int ans = 0;
//
//             priority_queue<pii, vector<pii>, greater<pii>> pq;
//             pq.push({0, 0});
//
//             while (!pq.empty()) {
//                 pii top = pq.top();
//                 pq.pop();
//                 int d = top.first, node = top.second;
//                 if (d > dist[node]) continue;
//                 dist[node] = d;
//
//                 // Each node is only visited once.  We've reached
//                 // a node in our original graph.
//                 ans++;
//
//                 for (auto pair: graph[node]) {
//                     // M - d is how much further we can walk from this node;
//                     // weight is how many new nodes there are on this edge.
//                     // v is the maximum utilization of this edge.
//                     int nei = pair.first;
//                     int weight = pair.second;
//                     used[{node, nei}] = min(weight, M - d);
//
//                     // d2 is the total distance to reach 'nei' (nei***or) node
//                     // in the original graph.
//                     int d2 = d + weight + 1;
//                     if (d2 < min(dist[nei], M+1)) {
//                         pq.push({d2, nei});
//                         dist[nei] = d2;
//                     }
//                 }
//             }
//
//             // At the end, each edge (u, v, w) can be used with a maximum
//             // of w new nodes: a max of used[u, v] nodes from one side,
//             // and used[v, u] nodes from the other.
//             for (vector<int> edge: edges) {
//                 int u = edge[0], v = edge[1], w = edge[2];
//                 ans += min(w, used[{u, v}] + used[{v, u}]);
//             }
//             return ans;
//         }
//     };
//
//     */
//    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
//        //dijkstra
//
//        int INF = 999;
//
//        vector<vector<int>> graph(n, vector<int>(n, INF));
//        for (int i = 0; i < n; i++) {
//            graph[edges[i][0]][edges[i][1]] = edges[i][2];
//            graph[edges[i][1]][edges[i][0]] = edges[i][2];
//        }
//        graph[0][0] = 0;
//
//        unordered_set<int> notArrivedPointSet;
//        for (int i = 1; i < n; i++) {
//            notArrivedPointSet.insert(i);
//        }
//
//        vector<int> result(n, INF);
//        result[0] = 0;
//
//        auto cmp = [&](int a, int b) {
//            return result[a] < result[b];
//        };
//
//        int start = 0;
//        while (notArrivedPointSet.size() > 0) {
//            for (int i = 0; i < n; i++) {
//                result[i] = min(result[i], result[start] + graph[start][i]);
//            }
//
//            int minPoint = *min_element(notArrivedPointSet.begin(), notArrivedPointSet.end(), cmp);
//            start = minPoint;
//            notArrivedPointSet.erase(minPoint);
//        }
//
//        int arrivedCount = 0;
//        for (int i = 0; i < result.size(); i++) {
//            if (result[i] != INF) {
//                arrivedCount += min(result[i], maxMoves);
//            }
//        }
//
//        return arrivedCount;
//    }
//
//    int reachableNodes2(vector<vector<int>>& edges, int M, int N) {
//        typedef pair<int, int> pii;
//        vector<vector<pii>> graph(N);
//        for (vector<int> edge: edges) {
//            int u = edge[0], v = edge[1], w = edge[2];
//            graph[u].push_back({v, w});
//            graph[v].push_back({u, w});
//        }
//
//        map<int, int> dist;
//        dist[0] = 0;
//        for (int i = 1; i < N; ++i)
//            dist[i] = M+1;
//
//        map<pii, int> used;
//        int ans = 0;
//
//        priority_queue<pii, vector<pii>, greater<pii>> pq;
//        pq.push({0, 0});
//
//        while (!pq.empty()) {
//            pii top = pq.top();
//            pq.pop();
//            int d = top.first, node = top.second;
//            if (d > dist[node]) continue;
//            dist[node] = d;
//
//            // Each node is only visited once.  We've reached
//            // a node in our original graph.
//            ans++;
//
//            for (auto pair: graph[node]) {
//                // M - d is how much further we can walk from this node;
//                // weight is how many new nodes there are on this edge.
//                // v is the maximum utilization of this edge.
//                int nei = pair.first;
//                int weight = pair.second;
//                used[{node, nei}] = min(weight, M - d);
//
//                // d2 is the total distance to reach 'nei' (nei***or) node
//                // in the original graph.
//                int d2 = d + weight + 1;
//                if (d2 < min(dist[nei], M+1)) {
//                    pq.push({d2, nei});
//                    dist[nei] = d2;
//                }
//            }
//        }
//
//        // At the end, each edge (u, v, w) can be used with a maximum
//        // of w new nodes: a max of used[u, v] nodes from one side,
//        // and used[v, u] nodes from the other.
//        for (vector<int> edge: edges) {
//            int u = edge[0], v = edge[1], w = edge[2];
//            ans += min(w, used[{u, v}] + used[{v, u}]);
//        }
//        return ans;
//    }
//
//    void test() {
//        vector<vector<int>> edges = {{0,1,10},{0,2,1},{1,2,2}};
//        int maxMoves = 6;
//        int n = 3;
//
//        int result = reachableNodes(edges, maxMoves, n);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 264
//class Solution {
//public:
//    int nthUglyNumber(int n) {
//        //最小堆
//        double result = 0;
//
//        vector<int> arr = {2,3,5};
//
//        priority_queue<double, vector<double>, greater<double>> queue;
//        queue.push(1);
//
//        unordered_set<double> set;
//
//        while (n-- > 0) {
//            result = queue.top();
//            queue.pop();
//
//            for (auto val : arr) {
//                if (set.find(val * result) == set.end()) {
//                    queue.push(val * result);
//                    set.insert(val * result);
//                }
//            }
//        }
//
//        return result;
//    }
//
//    int nthUglyNumber2(int n) {
//        //动态规划
//        //f(i) = min(f(ptr[0]) * 2 , f(ptr[1]) * 3, f(ptr[3]) * 5); ptr[min]++;
//
//        vector<int> arr = {2,3,5};
//        vector<int> result;
//        result.push_back(1);
//
//        vector<int> ptr(3, 0);
//
//        while (result.size() < n) {
//            int minVal = INT_MAX;
//            int ptrIndex = -1;
//            for (int i = 0; i < arr.size(); i++) {
//                int currVal = result[ptr[i]] * arr[i];
//                if (minVal > currVal) {
//                    minVal = currVal;
//                    ptrIndex = i;
//                }
//            }
//            if (result[result.size() - 1] != minVal) {
//                result.push_back(minVal);
//            }
//
//            ptr[ptrIndex]++;
//        }
//
//        return result[n - 1];
//    }
//
//    void test() {
//        int result = nthUglyNumber2(1690);
//        cout<<result<<endl;
//
//        int result2 = nthUglyNumber(1690);
//        cout<<result2<<endl;
//    }
//};

#pragma mark - 263
//class Solution {
//public:
//    bool isUgly(int n) {
//        if (n == 0) {
//            return false;
//        }
//
//        while (n % 2 == 0) {
//            n /= 2;
//        }
//
//        while (n % 3 == 0) {
//            n /= 3;
//        }
//
//        while (n % 5 == 0) {
//            n /= 5;
//        }
//
//        return n == 1;
//    }
//
//    void test() {
//        int result = isUgly(14);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1201
//class Solution {
//public:
//    int nthUglyNumber(int n, int a, int b, int c) {
//        //动态规划 未完成，超时
//        vector<int> arr = {a, b, c};
//
//        int result = 0;
//
//
//        auto cmp = [&](vector<int>& a, vector<int>& b) {
//            return a[2] > b[2];
//        };
//        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> queue(cmp);
//        queue.push({a, 1, a});
//        queue.push({b, 1, b});
//        queue.push({c, 1, c});
//
//        while (n-- > 0) {
//
//            vector<int> info = queue.top();
//            queue.pop();
//
//            if (result == info[2]) {
//                n++;
//            }
//
//            result = info[2];
//
//            info[1]++;
//            info[2] = info[1] * info[0];
//
//            queue.push(info);
//
////            cout<<result<<endl;
//        }
//
//        return result;
//    }
//
//    void test() {
//        /**
//         示例 1：
//
//         输入：n = 3, a = 2, b = 3, c = 5
//         输出：4
//         解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
//         示例 2：
//
//         输入：n = 4, a = 2, b = 3, c = 4
//         输出：6
//         解释：丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
//         示例 3：
//
//         输入：n = 5, a = 2, b = 11, c = 13
//         输出：10
//         解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
//         示例 4：
//
//         输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
//         输出：1999999984
//         */
//        int result = nthUglyNumber(1000000000, 2, 11, 13);
//        cout<<endl<<result<<endl;
//    }
//};

#pragma mark - 649
//class Solution {
//public:
//    string predictPartyVictory(string senate) {
//        //两个队列
//
//        typedef pair<int, int> PredicInfo;//座位号，轮次
//        deque<PredicInfo> queueR, queueD;
//
//        for (int i = 0; i < senate.size(); i++) {
//            if (senate[i] == 'R') {
//                queueR.push_back(PredicInfo(i, 0));
//            }
//            else {
//                queueD.push_back(PredicInfo(i, 0));
//            }
//        }
//
//        while (queueR.size() > 0 && queueD.size() > 0) {
//            PredicInfo RIndex = queueR.front();
//            queueR.pop_front();
//
//            PredicInfo DIndex = queueD.front();
//            queueD.pop_front();
//
//
//            if (RIndex.second == DIndex.second) {//轮次相同，座位号在前的🈲️掉后面的
//                if (RIndex.first < DIndex.first) {
//                    RIndex.second++;
//                    queueR.push_back(RIndex);
//                }
//                else {
//                    DIndex.second++;
//                    queueD.push_back(DIndex);
//                }
//            }
//
//            else if (RIndex.second < DIndex.second) {//轮次低的🈲️高的
//                RIndex.second++;
//                queueR.push_back(RIndex);
//            }
//            else {
//                DIndex.second++;
//                queueD.push_back(DIndex);
//            }
//
//
//        }
//
//        if (queueR.size() > 0) {
//            return "Radiant";
//        }
//        else {
//            return "Dire";
//        }
//    }
//
//    string predictPartyVictory2(string senate) {
//        int banRCount = 0;
//        int banDCount = 0;
//
//        int RCount = 1;
//        int DCount = 1;
//
//        while (RCount != 0 && DCount != 0) {
//            RCount = 0;
//            DCount = 0;
//            for (int i = 0; i < senate.size(); i++) {
//
//                if (senate[i] == 'R') {
//                    if (banRCount == 0) {
//                        banDCount++;
//                        RCount++;
//                    }
//                    else{
//                        senate[i] = 'B';
//                        banRCount--;
//                    }
//                }
//
//                if (senate[i] == 'D'){
//                    if (banDCount == 0) {
//                        banRCount++;
//                        DCount++;
//                    }
//                    else {
//                        senate[i] = 'B';
//                        banDCount--;
//
//                    }
//                }
//            }
//        }
//
//        if (RCount != 0) {
//            return "Radiant";
//        }
//        else {
//            return "Dire";
//        }
//
//    }
//
//    void test() {
//        string result = predictPartyVictory2("RDDR");
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1654
//class Solution {
//public:
//    //未完成
//    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
//        //ma - nb = x;
//        if (x == 0) {
//            return 0;
//        }
//
//        unordered_set<int> set(forbidden.begin(), forbidden.end());
//
//        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> queue;
//
//        int m = -1;
//        int n = -1;
//
////        for (int i = 0; i * a < ; <#increment#>) {
////            <#statements#>
////        }
//
//        int ptrA = 0;
//        while (1) {
//            ptrA++;
//            for (int i = 0; i <= ptrA; i++) {
//                int temp = a * ptrA - b * i;
//                if (temp > 0) {
//                    queue.push({temp, ptrA, i});
//                }
//            }
//
//            vector<int> distance = queue.top();
//            queue.pop();
//            if (distance[0] == x) {
//                m = distance[1];
//                n = distance[2];
//                break;
//            }
//
//            if (distance[0] > x) {
//                break;
//            }
//
//        }
//
//        int result = m + n;
//
//        int pos = 0;
//        for (int i = 1; i <= m; i++) {
//            int jumpPos = a + pos;
//            if (set.find(jumpPos) == set.end()) {
//                pos = jumpPos;
//                if (n > 0) {
//                    int backPos = jumpPos - b;
//                    if (set.find(backPos) == set.end()) {
//                        n--;
//                        pos = backPos;
//                    }
//                }
//            }
//            else {
//                break;
//            }
//        }
//
//        if (pos == x) {
//            return result;
//        }
//        else {
//            return -1;
//        }
//    }
//
//    void test() {
//        /**
//         [1,6,2,14,5,17,4]
//         16
//         9
//         7
//
//         [162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98]
//         29
//         98
//         80
//         */
//        vector<int> arr = {162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
//
//        int result = minimumJumps(arr, 29, 98, 80);
//        cout<<result<<endl;
//
//    }
//};

#pragma mark - 875
//class Solution {
//public:
//    int minEatingSpeed(vector<int>& piles, int h) {
//        //最大的速度为piles中的最大数，最小速度为所有香蕉数量/h,找需要时间h的最小K
//
//        int maxSpeed = *max_element(piles.begin(), piles.end());
//        int minSpeed = ceil(*min_element(piles.begin(), piles.end()) / h);
//
//        int l = minSpeed, r = maxSpeed;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//
//            if (getEatingTime(piles, mid) <= h) {//速度太快，需要放慢
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//
//        return l;
//    }
//
//    int getEatingTime(vector<int>& piles, int speed) {
//        int time = 0;
//        for (int i = 0; i < piles.size(); i++) {
//            time += ((piles[i] + speed - 1) / speed);//向上取整
//        }
//
//        return time;
//    }
//
//    void test() {
//        vector<int> piles = {30,11,23,4,20};
//
//        int result = minEatingSpeed(piles, 6);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 475
//class Solution {
//public:
//    int findRadius(vector<int>& houses, vector<int>& heaters) {
//        //最大半径为houses与heaters最远距离,二分查找能覆盖的最小半径
//        sort(houses.begin(), houses.end());
//        sort(heaters.begin(), heaters.end());
//
//        int maxRadius = max(abs(houses[houses.size() - 1] - heaters[0]), abs(houses[0] - heaters[heaters.size() - 1]));
//
//        int l = 0, r = maxRadius;
//
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            if (isCanCoverHouses(houses, heaters, mid)) {//如果能覆盖到，缩小半径
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//
//        return l;
//    }
//
//    bool isCanCoverHouses(vector<int>& houses, vector<int>& heaters ,int radius) {
//        vector<int>::iterator heaterPtr = heaters.begin();
//        for (int i = 0; i < houses.size(); i++) {
//            if (abs(houses[i] - *heaterPtr) > radius) {//当前暖气覆盖不到
//                if (heaterPtr == heaters.end() - 1) {//已经是最后一个
//                    return false;
//                }
//                else{
//                    heaterPtr++;
//                    i--;
//                }
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        /**
//         [1,1,1,1,1,1,999,999,999,999,999]
//         [499,500,501]
//
//         [282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923]
//         [823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612]
//         */
//        vector<int> houses = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
//        vector<int> heaters = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
//        int result = findRadius(houses, heaters);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 778
//class Solution {
//public:
//    int swimInWater(vector<vector<int>>& grid) {
//        //0-最高点，二分找能到达终点的最小值
//        int maxHeight = 0;
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid.size(); j++) {
//                maxHeight = max(maxHeight, grid[i][j]);
//            }
//        }
//
//        int l = 0, r = maxHeight;
//        while (l <= r) {
//            int mid = l + ((r - l) >> 1);
//            vector<vector<int>> temp(grid);
//            if (isCanArrived(grid, mid, 0, 0, temp)) {
//                r = mid - 1;
//            }
//            else {
//                l = mid + 1;
//            }
//        }
//
//        return l;
//    }
//
//    bool isCanArrived(vector<vector<int>>& grid, int t, int x, int y, vector<vector<int>>& pos)
//    {
//        if (x >= pos.size() || y >= pos.size() || x < 0 || y < 0) {
//            return false;
//        }
//
//        if (pos[x][y] == -1) {
//            return false;
//        }
//
//        if (grid[x][y] <= t) {
//            if (x == grid.size() - 1 && y == grid.size() - 1) {
//                return true;
//            }
//            pos[x][y] = -1;
//            return isCanArrived(grid, t, x + 1, y, pos) ||
//            isCanArrived(grid, t, x - 1, y, pos) ||
//            isCanArrived(grid, t, x, y + 1, pos) ||
//            isCanArrived(grid, t, x, y - 1, pos);
//        }
//        else{
//            return false;
//        }
//    }
//
//    void test() {
//        vector<vector<int>> arr = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
//
//        int result = swimInWater(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 327
//class Solution {
//public:
//
//    int countRangeSum(vector<int>& nums, int lower, int upper) {
//        int result = 0;
//
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = i; j < nums.size(); j++) {
//                long sum = 0;
//                for (int k = i; k <= j; k++) {
//                    sum += nums[k];
//                }
//
//                if (sum >= lower && sum <= upper) {
//                    result++;
//                }
//            }
//        }
//
//        return result;
//    }
//
//    void test() {
//        /**
//         [2147483647,-2147483648,-1,0]
//         -1
//         0
//         */
//        vector<int> nums = {2147483647,-2147483648,-1,0};
//        int result = countRangeSum(nums, -1, 0);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 439
//class Solution {
//public:
//    int reversePairs(vector<int>& nums) {
//        int result = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            float target = (nums[i] / 2.0);
//            for (int j = i; j < nums.size(); j++) {
//                if (target > nums[j]) {
//                    result++;
//                }
//            }
//        }
//
//        return result;
//    }
//
////    int reversePairs2(vector<int>& nums) {
////890
////    }
//
//    void test() {
//        vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
//
//        int result = reversePairs(nums);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 200
//class Solution {
//public:
//
//    int numIslands(vector<vector<char>>& grid) {
//
//        int result = 0;
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[i].size(); j++) {
//                if (grid[i][j] == '1') {
//                    result++;
//                    isLands(grid, i, j);
//                }
//            }
//        }
//
//        return result;
//    }
//
//    void isLands(vector<vector<char>>& grid, int x, int y) {
//
//        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
//            return;
//        }
//
//        if (grid[x][y] == '0') {
//            return;
//        }
//
//
//        grid[x][y] = '0';
//
//        isLands(grid, x, y - 1);//上
//        isLands(grid, x - 1, y);//左
//        isLands(grid, x, y + 1);//下
//        isLands(grid, x + 1, y);//右
//    }
//
//    void test() {
//        vector<vector<char>> grid = {
//            {'1','1','0','0','0'},
//            {'1','1','0','0','0'},
//            {'0','0','1','0','0'},
//            {'0','0','0','1','1'}
//          };
//
//        int result = numIslands(grid);
//        cout<<result<<endl;
//    }
//
//    void print(vector<vector<char>>& arr) {
//        for (int i = 0; i < arr.size(); i++) {
//            for (int j = 0; j < arr[i].size(); j++) {
//                cout<<arr[i][j]<<",";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//    }
//};

#pragma mark - 695
//class Solution {
//public:
//    int maxAreaOfIsland(vector<vector<int>>& grid) {
//        int result = 0;
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[i].size(); j++) {
//                if (grid[i][j] == 1) {
//                    result = max(result, islandArea(grid, i, j));
//                }
//            }
//        }
//
//        return result;
//    }
//
//    int islandArea(vector<vector<int>>& grid, int x, int y) {
//        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
//            return 0;
//        }
//
//        if (grid[x][y] == 0) {
//            return 0;
//        }
//
//        grid[x][y] = 0;
//
//        int top = islandArea(grid, x, y - 1);
//        int left = islandArea(grid, x - 1, y);
//        int bottom = islandArea(grid, x, y + 1);
//        int right = islandArea(grid, x + 1, y);
//
//        return top + left + bottom + right + 1;
//    }
//
//    void test() {
//        vector<vector<int>> arr = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
//            {0,0,0,0,0,0,0,1,1,1,0,0,0},
//            {0,1,1,0,1,0,0,0,0,0,0,0,0},
//            {0,1,0,0,1,1,0,0,1,0,1,0,0},
//            {0,1,0,0,1,1,0,0,1,1,1,0,0},
//            {0,0,0,0,0,0,0,0,0,0,1,0,0},
//            {0,0,0,0,0,0,0,1,1,1,0,0,0},
//            {0,0,0,0,0,0,0,1,1,0,0,0,0}};
//
//        int result = maxAreaOfIsland(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 1162
//class Solution {
//public:
//    int maxDistance(vector<vector<int>>& grid) {
//
//        int count = 1;
//        int mark = 0;
//        while (count != 0) {
//            mark++;
//            count = 0;
//            for (int i = 0; i < grid.size(); i++) {
//                for (int j = 0; j < grid[0].size(); j++) {
//                    if (grid[i][j] == mark) {
//                        count += markSea(grid, i, j, mark + 1);
//                    }
//                }
//            }
//        }
//
//        if (mark == 1) {
//            return -1;
//        }
//
//        return mark - 1;
//    }
//
//    int markSea(vector<vector<int>>& grid, int x, int y, int mark){
//        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
//            return 0;
//        }
//
//        if (grid[x][y] == 0) {
//            grid[x][y] = mark;
//            return 1;
//        }
//
//        if (grid[x][y] == -1) {
//            return 0;
//        }
//
//        if (grid[x][y] >= mark) {
//            return 0;
//        }
//
//
//        grid[x][y] = -1;
//        int top = markSea(grid, x, y - 1, mark);
//        int left = markSea(grid, x - 1, y, mark);
//        int bottom = markSea(grid, x, y + 1, mark);
//        int right = markSea(grid, x + 1, y, mark);
//
//        return top + left + bottom + right;
//    }
//
//    void test() {
//        vector<vector<int>> arr = {{1,0},{0,0}};
//
//        int result = maxDistance(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 463
//class Solution {
//public:
//
//    //上左下右
//    vector<int> dx = {0,-1,0,1}, dy = {-1,0,1,0};
//    int islandPerimeter(vector<vector<int>>& grid) {
//        int result = 0;
//
//        for (int i = 0; i < grid.size(); i++) {
//            for (int j = 0; j < grid[i].size(); j++) {
//                if (grid[i][j] == 1) {
//                    island(grid, i, j, result);
//                    break;
//                }
//            }
//        }
//
//        return result;
//    }
//
//    bool island(vector<vector<int>>& grid, int x, int y, int& perimeter) {
//        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
//            return false;
//        }
//
//        if (grid[x][y] == 0) {
//            return false;
//        }
//
//        if (grid[x][y] == -1) {
//            return true;
//        }
//
//        grid[x][y] = -1;
//
//        for (int i = 0; i < dx.size(); i++) {
//            if (island(grid, x + dx[i], y + dy[i], perimeter) == false) {
//                perimeter++;
//            }
//        }
//
//        return true;
//    }
//
//    void test() {
//        vector<vector<int>> arr = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
//
//        int result = islandPerimeter(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 5
//class Solution {
//public:
//    /**
//     给你一个字符串 s，找到 s 中最长的回文子串。
//
//
//
//     示例 1：
//
//     输入：s = "babad"
//     输出："bab"
//     解释："aba" 同样是符合题意的答案。
//     示例 2：
//
//     输入：s = "cbbd"
//     输出："bb"
//     示例 3：
//
//     输入：s = "a"
//     输出："a"
//     示例 4：
//
//     输入：s = "ac"
//     输出："a"
//
//
//     提示：
//
//     1 <= s.length <= 1000
//     s 仅由数字和英文字母（大写和/或小写）组成
//     */
//    string longestPalindrome(string s) {
///**
//s[i - 1] == s[j + 1] f[i][j] = f[i + 1][j - 1];
//    b a b a d
// b  1 0 1 0 0
// a    1 0 1 0
// b      1 0 1
// a        1 0
// d          1
// */
//
//        if (s.size() < 2) {
//            return s;
//        }
//
//        int start = 0, end = 0;
//        int length = 0;
//        vector<vector<int>> result(s.size(), vector<int>(s.size(), 0));
//
//        for (int i = 0; i < s.size(); i++) {
//            result[i][i] = 1;
//        }
//
//        for (int k = 1; k < s.size(); k++) {
//            for (int i = 0; i + k < s.size(); i++) {
//                int j = i + k;
//                if (s[i] == s[j]) {
//                    if (j - i == 1) {
//                        result[i][j] = 1;
//                    }
//                    else {
//                        result[i][j] = result[i + 1][j - 1];
//                    }
//                    if (result[i][j] == 1 && (j - i + 1 > length)) {
//                        length = j - i + 1;
//                        start = i;
//                        end = j;
//                    }
//                }
//                else {
//                    result[i][j] = 0;
//                }
//            }
//        }
////        tool.printMatrix(result);
//        return s.substr(start, end - start + 1);
//    }
//
//    string longestPalindrome2(string s) {
//
//        /**
//            a b a
//         a
//         b
//         a      1
//
//         a b a
//      a
//      b    1 0
//      a      1
//
//         a b a
//      a  1
//      b    1 0
//      a      1
//
//         a b a
//      a  1   1
//      b    1 0
//      a      1
//
//         a b a
//      a  1 0 1
//      b    1 0
//      a      1
//
//         */
//        if (s.size() < 2) {
//            return s;
//        }
//
//        int start = 0, end = 0;
//        int length = 0;
//
//        vector<int> result(s.size(), 1);
//
//
//        for (int i = (int)s.size() - 1; i >= 0 ; i--) {
//            for (int k = (int)s.size() - 1 - i; k > 0 ; k--) {//从i 到 s.size() - 1开始对比，到i到i + 1
//                int j = i + k;
//                if (s[i] == s[j]) {
//                    if (j - i == 1) {
//                        result[j] = 1;
//                    }
//                    else {
//                        result[j] = result[j - 1];//二维数组的result[i + 1][j - 1];
//                    }
//
//                    if (result[j] == 1 && (j - i + 1 > length)) {
//                        length = j - i + 1;
//                        start = i;
//                        end = j;
//                    }
//                }
//                else{
//                    result[j] = 0;
//                }
//            }
//        }
//
//        return s.substr(start, end - start + 1);
//    }
//
//    string longestPalindrome3(string s) {
//
//        if (s.size() < 2) {
//            return s;
//        }
//
//        int start = 0, end = 0;
//        int length = 1;
//        for (int i = 1; i < s.size(); i++) {
//            pair<int, int> palindromeIndex1 = isPalindrome(s, i, i - 1);
//            pair<int, int> palindromeIndex2 = isPalindrome(s, i, i);
//
//            pair<int, int> currMaxPalindrome = getMaxPair(palindromeIndex1, palindromeIndex2);
//
//            if (currMaxPalindrome.second - currMaxPalindrome.first + 1 > length) {
//                length = currMaxPalindrome.second - currMaxPalindrome.first + 1;
//                start = currMaxPalindrome.first;
//                end = currMaxPalindrome.second;
//            }
//        }
//
//        return s.substr(start, end - start + 1);
//    }
//
//    pair<int, int> getMaxPair(pair<int, int>& pair1, pair<int, int>& pair2){
//
//        int length1 = pair1.second - pair1.first;
//        int length2 = pair2.second - pair2.first;
//
//        if (length1 > length2) {
//            return pair1;
//        }
//        else {
//            return pair2;
//        }
//    }
//
//    pair<int, int> isPalindrome(string& s, int center, int otherCenter) {
//        int l = center, r = otherCenter;
//
//        while (l >= 0 && r < s.size() && s[l] == s[r]) {
//            l--;
//            r++;
//        }
//
//        return pair<int, int>(l + 1, r - 1);
//    }
//
//
//    void test() {
//        /**
//         civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth
//         */
//        string result = longestPalindrome3("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth");
//        cout<<result<<endl;
//    }
//};

#pragma mark - 724
//class Solution {
//public:
//    int pivotIndex(vector<int>& nums) {
////        计算整体和，指针指向零，想右移动，直到两边和相同
//
//        int leftSum = 0, rightSum = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            rightSum += nums[i];
//        }
//
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (i > 0) {
//                leftSum += nums[i - 1];
//            }
//            rightSum -= nums[i];
//
//            if (leftSum == rightSum) {
//                return i;
//            }
//        }
//
//        return -1;
//    }
//
//    int pivotIndex2(vector<int>& nums) {
////        计算整体和，指针指向零，想右移动，直到两边和相同
//
//        int leftSum = 0, allSum = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            allSum += nums[i];
//        }
//
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (i > 0) {
//                leftSum += nums[i - 1];
//            }
//
//            if (leftSum == allSum - leftSum - nums[i]) {
//                return i;
//            }
//        }
//
//        return -1;
//    }
//
//
//    void test() {
//        vector<int> nums = {};
//
//        int result = pivotIndex(nums);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 19
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
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        //一遍遍历，数组存储
//        vector<ListNode *> arr;
//
//        ListNode *p = head;
//        while (p != nullptr) {
//            arr.push_back(p);
//            p = p->next;
//        }
//
//        if (arr.size() == n) {
//            return head->next;
//        }
//
//        p = arr[arr.size() - n - 1];
//        p->next = p->next->next;
//
//        return head;
//    }
//
//    ListNode* removeNthFromEnd2(ListNode* head, int n) {
//        //一遍遍历 快慢指针
//
//
//        ListNode *f = head;
//        for (int i = 0; i < n && f != nullptr; i++) {
//            f = f->next;
//        }
//
//        ListNode *prePtr = nullptr;
//        ListNode *s = head;
//        while (f != nullptr) {
//            prePtr = s;
//            f = f->next;
//            s = s->next;
//        }
//
//        if (prePtr == nullptr) {
//            return head->next;
//        }
//
//        prePtr->next = s->next;
//
//        return head;
//    }
//
//    void test() {
//        vector<int> arr = {1,2,3,4,5};
//        int n = 3;
//        ListNode *head = tool.createList(arr, -1);
//        tool.printList(head);
//
//        ListNode *result = removeNthFromEnd2(head, n);
//        tool.printList(result);
//    }
//};

#pragma mark - 877
//class Solution {
//public:
//    bool stoneGame(vector<int>& piles) {
////https://leetcode-cn.com/problems/stone-game/solution/dong-tai-gui-hua-fang-shi-xiang-jie-java-by-yan-ta/
//        //f[i][j] = max(p[i] - f[i + 1][j], p[j] - f[i][j - 1]);
//
//        vector<vector<int>> result(piles.size(), vector<int>(piles.size(), 0));
//        for (int i = 0; i < piles.size(); i++) {
//            result[i][i] = piles[i];
//        }
//
//        for (int i = (int)piles.size() - 1; i >= 0; i--) {
//            for (int j = i + 1; j < piles.size(); j++) {
//                result[i][j] = max(piles[i] - result[i + 1][j], piles[j] - result[i][j - 1]);
//            }
//        }
//
//        return result[0][piles.size() - 1] > 0;
//    }
//
//    bool stoneGame2(vector<int>& piles) {
//        //优化一维数组
//
//        vector<int> result(piles);
//
//        for (int i = (int)piles.size(); i >= 0; i-- ) {
//            for (int j = i + 1; j < piles.size(); j++) {
//                result[j] = max(piles[i] - result[j], piles[j] - result[j - 1]);
//            }
//        }
//
//        return result[piles.size() - 1] > 0;
//    }
//
//    void test() {
//        vector<int> piles = {1,3,4,5};
//
//        bool result = stoneGame2(piles);
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 91
//class Solution {
//public:
//    int numDecodings(string s) {
//        //f[i] = s[i] == true f[i] = f[i - 1]  s[i- 1]s[i] == true f[i] += f[i - 2]
//
//        if (s[0] == '0') {
//            return 0;
//        }
//
//        vector<int> result(s.size(), 0);
//        result[0] = 1;
//
//        for (int i = 1; i < s.size(); i++) {
//            if (s[i] != '0') {
//                result[i] = result[i - 1];
//            }
//
//            if (s[i - 1] != 0 && ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] <= '6'))) {
//                if (i >= 2) {
//                    result[i] += result[i - 2];
//                }
//                else {
//                    result[i] += 1;
//                }
//            }
//
//
//        }
//
//        return result[s.size() - 1];
//    }
//
//    void test() {
//        int result = numDecodings("11006");
//
//        cout<<result<<endl;
//    }
//};

#pragma mark - 322
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        //f[i] 第i个数最少需要多少个硬币 f[i] = min(f[i - coin[0]], f[i - coin[1]]... f[i - coin[n]]);
//
//        sort(coins.begin(), coins.end());
//
//        vector<int> result(amount + 1, INT_MAX);
//        result[0] = 0;
//        for (int i = 1; i < result.size(); i++) {
//            for (int j = 0; j < coins.size(); j++) {
//                if (coins[j] <= i ) {
//                    result[i] = min(result[i], result[i - coins[j]]);
//                }
//                else {
//                    break;
//                }
//            }
//            if (result[i] != INT_MAX) {
//                result[i]++;
//            }
//        }
//
//        return result[amount] == INT_MAX ? -1 : result[amount];
//    }
//
//    int coinChange2(vector<int>& coins, int amount) {
//        //优化
//
//        vector<int> result(amount + 1, amount + 1);
//        result[0] = 0;
//        for (int i = 1; i < result.size(); i++) {
//            for (int j = 0; j < coins.size(); j++) {
//                if (coins[j] <= i ) {
//                    result[i] = min(result[i], result[i - coins[j]] + 1);
//                }
//            }
//        }
//
//        return result[amount] > amount ? -1 : result[amount];
//
//    }
//
//    void test() {
//        vector<int> coins = {2};
//        int result = coinChange(coins, 0);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 139
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        //f[i] 从0 - i的字符串能否用wordDict组成 f[i] = f[i = wordDict[j].size] == ture 有 s[i到 i + wordDict[j].size] == wordDirct[j] 则为true
//
//        vector<bool> result(s.size() + 1, false);
//        result[0] = true;
//
//        for (int i = 0; i < result.size(); i++) {
//            for (int j = 0; j < wordDict.size(); j++) {
//                string temp = wordDict[j];
//                if (i >= temp.size() && result[i - temp.size()]) {
//                    if (temp== s.substr(i - temp.size(), temp.size())) {
//                        result[i] = true;
//                        break;
//                    }
//                }
//            }
//        }
//
//        return result[s.size()];
//    }
//
//    void test() {
//        vector<string> arr = {"cats", "dog", "sand", "and", "cat"};
//
//        bool result = wordBreak("catsandog", arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 198
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//// f[i] 从0 - i家最大的金额，f[i] = max(max(f[i - 2]...f[0]) + nums[i], f[i - 1]);
//
//        if (nums.size() == 0) {
//            return 0;
//        }
//        if (nums.size() == 1) {
//            return nums[0];
//        }
//
//        int last1 = nums[1];
//        int last2 = nums[0];
//
//        int result = max(last1, last2);
//
//        for (int i = 2; i < nums.size(); i++) {
//            result = max(last2 + nums[i], last1);
//            last2 = max(last2, last1);
//            last1 = result;
//        }
//
//        return result;
//    }
//
//    void test() {
//        vector<int> nums = {2,1,1,2};
//
//        int result = rob(nums);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 309
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        //f[i][0] i天买入的现金 f[i][0] = f[i - 2][1] - p[i]和 昨天买入f[i - 1][0] 最大值
//        //f[i][1] i天卖出的现金 f[i][1] = f[i - 1][0] + p[i] 和 昨天卖出f[i - 1][1] 最大值
//
//        if (prices.size() < 2) {
//            return 0;
//        }
//
//        vector<vector<int>> result(prices.size(), vector<int>(2, 0));
//
//        result[0][0] = -prices[0];
//        result[1][0] = max(-prices[1], result[0][0]);
//        result[1][1] = max(prices[1] + result[0][0], 0);
//
//        for (int i = 2; i < prices.size(); i++) {
//            result[i][0] = max(result[i - 2][1] - prices[i], result[i - 1][0]);
//            result[i][1] = max(result[i - 1][0] + prices[i], result[i - 1][1]);
//        }
//
//        return result[prices.size() - 1][1];
//    }
//
//    void test() {
//        vector<int> arr = {2,1,4};
//
//        int result = maxProfit(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 121
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        //只能买卖一次，最小值买入，最大值卖出
//
//        int result = 0;
//        int inPrices = INT_MAX;
//        int outPrices = 0;
//        for (int i = 0; i < prices.size(); i++) {
//            if (inPrices > prices[i]) {
//                inPrices = prices[i];
//                outPrices = INT_MIN;
//            }
//            else {
//                outPrices = max(outPrices, prices[i]);
//
//                result = max(result, outPrices - inPrices);
//            }
//        }
//
//        return result;
//    }
//
//    int maxProfit2(vector<int>& prices) {
//
//        //f[i][0] 买入价格 f[i][0] = min(f[i - 1][0], prices[i])
//        //f[i][1] 卖出价格 f[i][1] = max(f[i - 1][1], prices[i] - f[i - 1][0])
//
//        if (prices.size() < 2) {
//            return 0;
//        }
//
//        vector<vector<int>> result(prices.size(), vector<int>(2, 0));
//
//        result[0][0] = prices[0];
//        result[0][1] = 0;
//
//        for (int i = 1; i < prices.size(); i++) {
//            result[i][0] = min(result[i - 1][0], prices[i]);
//            result[i][1] = max(result[i - 1][1], prices[i] - result[i - 1][0]);
//        }
//
//        return result[prices.size() - 1][1];
//    }
//
//    int maxProfit3(vector<int>& prices) {
//
//        //f[i][0] 买入价格 f[i][0] = min(f[i - 1][0], prices[i])
//        //f[i][1] 卖出价格 f[i][1] = max(f[i - 1][1], prices[i] - f[i - 1][0])
//
//        //优化 不用数组
//
//        if (prices.size() < 2) {
//            return 0;
//        }
//
//        int lastInPrices = prices[0];
//        int lastOutPrices = 0;
//
//        for (int i = 1; i < prices.size(); i++) {
//            lastOutPrices = max(lastOutPrices, prices[i] - lastInPrices);
//            lastInPrices = min(lastInPrices, prices[i]);
//        }
//
//        return lastOutPrices;
//    }
//
//
//    void test() {
//        vector<int> arr = {7,1,5,3,6,4};
//
//        int result = maxProfit2(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 122
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        //每天都交易，正收益就记录
//        int result = 0;
//        for (int i = 1; i < prices.size(); i++) {
//            if (prices[i] > prices[i - 1]) {
//                result += (prices[i] - prices[i - 1]);
//            }
//        }
//
//        return result;
//    }
//
//    int maxProfit2(vector<int>& prices) {
//        //f[i][0] 第i天持有的现金 f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i])
//        //f[i][1] 第i天不持有的现金 f[i][1] = max(f[i - 1][1], prices[i] + f[i - 1][0])
//
//        vector<vector<int>> result(prices.size(), vector<int>(2, 0));
//        result[0][0] = -prices[0];
//
//        for (int i = 1; i < prices.size(); i++) {
//            result[i][0] = max(result[i - 1][0], result[i - 1][1] - prices[i]);
//            result[i][1] = max(result[i - 1][1], prices[i] + result[i - 1][0]);
//        }
//
//        return result[prices.size() - 1][1];
//    }
//
//    int maxProfit3(vector<int>& prices) {
//        //f[i][0] 第i天持有的现金 f[i][0] = max(f[i - 1][0], f[i - 1][1] - prices[i])
//        //f[i][1] 第i天不持有的现金 f[i][1] = max(f[i - 1][1], prices[i] + f[i - 1][0])
//
//        //优化 不使用数组
//
//        int lastInCash = -prices[0];
//        int lastOutCash = 0;
//
//        for (int i = 1; i < prices.size(); i++) {
//            int tempInCash = max(lastInCash, lastOutCash - prices[i]);
//            int tempOutCash = max(lastOutCash, prices[i] + lastInCash);
//
//            lastInCash = tempInCash;
//            lastOutCash = tempOutCash;
//        }
//
//        return lastOutCash;
//    }
//
//
//    void test() {
//        vector<int> arr = {7,1,5,3,6,4};
//
//        int result = maxProfit3(arr);
//        cout<<result<<endl;
//    }
//};

#pragma mark - 123
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //贪心 统计盈利区间最大值
        priority_queue<int, vector<int>, less<int>> resultQueue;
        
        int count = 0;
        int currMaxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int temp = prices[i] - prices[i - 1];
            
            count += temp;

            
            if (count > 0) {
                currMaxProfit = max(currMaxProfit, count);
            }
            else {
                if (currMaxProfit != 0) {
                    resultQueue.push(currMaxProfit);
                }
                count = 0;
                currMaxProfit = 0;
            }
        }
        
        if (currMaxProfit > 0) {
            resultQueue.push(currMaxProfit);
        }
            
            
        int result = 0;
        int size = (int)resultQueue.size();
        for (int i = 0 ; i < 2 && i < size; i++) {
            result += resultQueue.top();
            resultQueue.pop();
        }
        return result;
    }
    
    int maxProfit2(vector<int>& prices) {
        //0 第一次持有 f[i][0] = max(f[i - 1][0], -prices[i])
        //1 第一次未持有 f[i][1] = max(f[i - 1][1], prices[i] + f[i - 1][0])
        //2 第二次持有 f[i][2] = max(f[i - 1][2], f[i][1] - prices[i])
        //3 第二次未持有 f[i][3] = max(f[i - 1][3], prices[i] + f[i - 1][2])

        vector<vector<int>> result(prices.size(), vector<int>(4, 0));
        result[0][0] = -prices[0];
        result[0][2] = -prices[0];
        
        for (int i = 1; i < prices.size(); i++ ){
            int p = prices[i];
            result[i][0] = max(result[i - 1][0], -p);
            result[i][1] = max(result[i - 1][1], p + result[i - 1][0]);
            result[i][2] = max(result[i - 1][2], result[i][1] - p);
            result[i][3] = max(result[i - 1][3], p + result[i - 1][2]);
        }
        
        return result[prices.size() - 1][3];
    }
    
    int maxProfit3(vector<int>& prices) {
        //0 第一次持有 f[i][0] = max(f[i - 1][0], -prices[i])
        //1 第一次未持有 f[i][1] = max(f[i - 1][1], prices[i] + f[i - 1][0])
        //2 第二次持有 f[i][2] = max(f[i - 1][2], f[i][1] - prices[i])
        //3 第二次未持有 f[i][3] = max(f[i - 1][3], prices[i] + f[i - 1][2])

        vector<int> result(4,0);

        result[0] = -prices[0];
        result[2] = -prices[0];
        
        for (int i = 1; i < prices.size(); i++ ){
            int p = prices[i];
            result[3] = max(result[3], p + result[2]);
            result[2] = max(result[2], result[1] - p);
            result[1] = max(result[1], p + result[0]);
            result[0] = max(result[0], -p);
        }
        
        return result[3];
    }

    
    void test() {
        vector<int> arr = {1,2,3,4,5};
        
        int result = maxProfit3(arr);
        
        cout<<result<<endl;
    }
    
};

#pragma mark - 464


#pragma mark - 1206

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
