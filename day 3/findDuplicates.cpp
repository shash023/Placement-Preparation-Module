/*
Find the duplicates in an array. All elements appear exactly once except one element which repeats. Elements are in range [1, N - 1].
Hint: Use slow and fast pointer approach

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	
	int slow = arr[0];
	int fast = arr[0];

	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while(slow != fast);

	fast = arr[0];
	while(slow != fast) {
		slow = arr[slow];
		fast = arr[fast];
	}

	return slow;

}
