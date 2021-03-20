//
//  Sort.cpp
//  TestLCD
//
//  Created by zm on 2021/3/19.
//

#include "Sort.hpp"
#include <iostream>

using namespace std;

#pragma mark - test
void printVector(vector<int>& arr) {
    vector<int>::iterator it = arr.begin();
    while (it != arr.end()) {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}

void swap(vector<int>& arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

#pragma mark - selection
void selectionSort(vector<int>& arr) {
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

#pragma mark - bubbling
void bubblingSort(vector<int>& arr) {
    bool isSwap = false;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j + 1 < arr.size() - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
                isSwap = true;
            }
        }
        
        if (isSwap == false) {
            return;
        }
    }
}

void bubblingSort2(vector<int>& arr, int length) {
    
    if (length == 0) {
        return;
    }
    for (int i = 0; i + 1 < length; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr, i, i + 1);
        }
    }
    
    bubblingSort2(arr, length - 1);
}

void bubblingSort3(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0, k = (int)arr.size() - i - 1; j + 1 < arr.size() - i && k - 1 > 0; j++, k--) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
            if (arr[k] > arr[k - 1]) {
                swap(arr, k, k - 1);
            }
        }
    }
}

#pragma mark - insert
void arrayInsert(vector<int>& arr, int fromIndex, int toIndex) {
    if (fromIndex <= toIndex) {
        return;
    }
    for (int i = fromIndex; i - 1 >= toIndex; i--) {
        swap(arr, i, i - 1);
    }
}

void insertSort(vector<int>& arr) {
    int insertIndex = (int)arr.size();
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                insertIndex = j;
            }
            else {
                break;
            }
        }
        arrayInsert(arr, i, insertIndex);
    }
}

void insertSort2(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) {
                swap(arr, i, j);
            }
            else {
                break;
            }
        }
    }
}

#pragma mark - shell
void shellSort(vector<int>& arr) {
    for (int gap = (int)arr.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); i ++) {
            for (int j = i - gap; j >= 0 ; j -= gap) {
                if (arr[j + gap] < arr[j]) {
                    swap(arr, j, j + gap);
                }
                else{
                    break;
                }
            }
        }
    }
}

void shellSort2(vector<int>& arr) {
    //knuth序列
    int h = 1;
    while (h < arr.size() / 3) {
        h = 3 * h + 1;
    }
    for (int gap = h; gap > 0; gap = (gap - 1) / 3) {
        for (int i = gap; i < arr.size(); i ++) {
            for (int j = i - gap; j >= 0 ; j -= gap) {
                if (arr[j + gap] < arr[j]) {
                    swap(arr, j, j + gap);
                }
                else{
                    break;
                }
            }
        }
    }
    
}

#pragma mark - merge
void mergeArray(vector<int>& arr, int l, int r, int endPos){
    vector<int> temp(endPos - l + 1);
    int i = 0, mid = r, start = l;
    while (l < mid && r <= endPos) {
        if (arr[l] <= arr[r]) {
            temp[i++] = arr[l++];
        }
        else {
            temp[i++] = arr[r++];
        }
    }
    
    while (l < mid) {
        temp[i++] = arr[l++];
    }
    
    while (r <= endPos) {
        temp[i++] = arr[r++];
    }
    
    i = start;
    while (i <= endPos) {
        arr[i] = temp[i - start];
        i++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    
    if (left >= right) {
        return;
    }
    
    int mid = (right + left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    
    mergeArray(arr, left, mid + 1, right);
}

void mergeSort2(vector<int>& arr, int l, int r, int bounds) {
    
    if (bounds == l) {
        return;
    }
    
    mergeSort2(arr, l, (l + r) / 2, r - 1);
    mergeSort2(arr, r, (bounds + r + 1) / 2, bounds);
    
    int mid = r, start = l, length = bounds - l + 1;
    vector<int> temp(length);
    int i = 0;
    while (i <= bounds && l < mid && r <= bounds) {
        if (arr[l] <= arr[r]) {
            temp[i] = arr[l];
            l++;
            i++;
        }
        else {
            temp[i] = arr[r];
            r++;
            i++;
        }
    }
    
    while (l < mid) {
        temp[i++] = arr[l++];
    }
    
    while (r <= bounds) {
        temp[i++] = arr[r++];
    }
    
    for (int i = 0; i < temp.size(); i++) {
        cout<<temp[i]<<" ";
    }
    
    cout<<endl<<"all:";
    for (int i = start; i <= bounds; i++) {
        arr[i] = temp[i - start];
    }
    
    for (int i = 0; i < arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
}

#pragma mark - quick
void quickSort(vector<int>& arr, int left, int right) {
    
    if (left >= right) {
        return;
    }
    
    int s = left, e = right;
    cout<<"---"<<arr[right]<<endl;
    while (s < e) {
        while (arr[s] < arr[right] && s < e) s++;
        while (arr[e] >= arr[right] && s < e) e--;
        swap(arr, s, e);
    }
    swap(arr, s, right);
    
    quickSort(arr, left, s - 1);
    quickSort(arr, s + 1, right);
}

//非递归
void quickSort2(vector<int>& arr) {
    vector<int> cacheWillSortIndex = {0, (int)arr.size() - 1};
    while (cacheWillSortIndex.size() >= 2) {
        
        int right = *(cacheWillSortIndex.end() - 1);
        cacheWillSortIndex.pop_back();
        int left = *(cacheWillSortIndex.end() - 1);
        cacheWillSortIndex.pop_back();
        
        int s = left, e = right, key = right;
        cout<<"---"<<arr[right]<<endl;
        
        while (s < e) {
            while (arr[s] < arr[key] && s < e) s++;
            while (arr[e] >= arr[key] && s < e) e--;
            swap(arr, s, e);
        }
        swap(arr, s, key);
        int div = s;
        if (left < div - 1 && div + 1 < right) {
            cacheWillSortIndex.push_back(left);
            cacheWillSortIndex.push_back(div - 1);
            cacheWillSortIndex.push_back(div + 1);
            cacheWillSortIndex.push_back(right);
        }
        
        cout<<"+++";
        printVector(arr);
        cout<<"***";
        printVector(cacheWillSortIndex);
    }
}

#pragma mark - test
void Sort::test() {
    //    vector<int> arr = {1, 9, 3, -1, 8, 8, 2, -100, 3, 8, 100, 200, 8};
    vector<int> arr = {7,3,2,6,8,1,9,5,4,6,10,6};
    //    selectionSort(arr);
    //    bubblingSort(arr);
    //    bubblingSort2(arr, (int)arr.size());
    //    insertSort(arr);
    //    insertSort2(arr);
    //    shellSort(arr);
    //        shellSort2(arr);
    //    mergeSort2(arr, 0, arr.size() / 2, arr.size() - 1);
    //    mergeSort(arr, 0, (int)arr.size() - 1);
//    quickSort(arr, 0, (int)arr.size() - 1);
    quickSort2(arr);
    //    int i = 0;
    //    cout<<i<<" "<<arr[i++]<<" "<<i<<endl;
    vector<int>::iterator it = arr.begin();
    while (it != arr.end()) {
        cout<<*it<<endl;
        it++;
    }
}