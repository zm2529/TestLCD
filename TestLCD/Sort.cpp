//
//  Sort.cpp
//  TestLCD
//
//  Created by zm on 2021/3/19.
//

#include "Sort.hpp"
#include <iostream>

using namespace std;

void swap(vector<int>& arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

#pragma mark - selection
void Sort::selectionSort(vector<int>& arr) {
    int minIndex = 0, maxIndex = 0;
    for (int i = 0, j = (int)arr.size() - 1; j > i; i++, j--) {
        for (int k = i; k <= j;  k++) {
            if (arr[minIndex] > arr[k]) {
                minIndex = k;
            }

            if (arr[maxIndex] < arr[k]) {
                maxIndex = k;
            }
        }

        swap(arr, minIndex, i);
        if (i == maxIndex) {
            maxIndex = minIndex;
        }
        swap(arr, maxIndex, j);
    }
}


#pragma mark - test
void Sort::test() {
    vector<int> arr = {1, 9, 3, -1, 8, 8, 2, -100, 3};
    selectionSort(arr);
    vector<int>::iterator it = arr.begin();
    while (it != arr.end()) {
        cout<<*it<<endl;
        it++;
    }
}
