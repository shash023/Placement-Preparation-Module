/*
Count the number of reverse pairs. [i < j ; arr[i] > 2 * arr[j]]
[similar to countInversions -- use mergeSort -- Carefully check for the reverse pairs while merging]

T.C - O(NlogN)
S.C - O(N)
*/

#include <bits/stdc++.h> 

void merge(vector<int> &arr, int low, int mid, int high) {
	vector<int> temp;
	int left = low;
	int right = mid + 1;

	while(left <= mid && right <= high) {
		if(arr[left] <= arr[right]) {
			temp.push_back(arr[left]);
			left++;
		}
		else {
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

}

int countPairs(vector<int> &arr, int low, int mid , int high) {
	int count = 0;
	int right = mid + 1;
	for(int i = low; i <= mid; i++) {
		while(right <= high && arr[i] > 2 * arr[right])
			right++;
		count += (right - (mid + 1));
	}

	return count;
}

int mergeSort(vector<int> &arr, int low, int high) {
	int count = 0;
	if(low >= high)
		return count;
	int mid = (low + high) >> 1;
	count += mergeSort(arr, low, mid);
	count += mergeSort(arr, mid + 1, high);
	count += countPairs(arr, low, mid, high);
	merge(arr, low, mid, high);

	return count;
}

int reversePairs(vector<int> &arr, int n){

	return mergeSort(arr, 0, n - 1);

}