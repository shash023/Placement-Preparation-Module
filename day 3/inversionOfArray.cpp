/*
Find the number of inversions in the array i.e, count the number of arr[i] > arr[i + 1] for i < j;
[Hint: Use merge sort technique]

T.C - O(N * logN)
S.C - O(N)
[Mention that we are distorting the array and if required we can make a copy of the array]
*/

#include <bits/stdc++.h> 

int merge(long long *arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int count = 0;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            count += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return count;
}

int mergeSort(long long *arr, int low, int high) {
    int count = 0;
    if(low >= high)
        return count;
    int mid = (low + high) >> 1;
    
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}