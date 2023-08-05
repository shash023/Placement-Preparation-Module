/*
Merge 2 sorted arrays. arr1 size = m, arr2 size = n
arr1 has the capacity to store m+n elements.
Hint - Start from the end 

T.C - O(m + n)
S.C - O(1)
*/

#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;

	while(i >= 0 && j >= 0) {
		if(arr2[j] >= arr1[i]) {
			arr1[k--] = arr2[j--];
		}
		else {
			arr1[k--] = arr1[i--];
		}
	}

	while(j >= 0) {
		arr1[k--] = arr2[j--];
	}

	return arr1;
}