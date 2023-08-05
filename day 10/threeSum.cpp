/*
Find triplets with the given sum.

T.C - O(N^2)
S.C - O(1)
*/

#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int s) {
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;

	for(int i = 0; i < n; i++) {
		if(i > 0 && arr[i] == arr[i - 1]) continue;
		int j = i + 1;
		int k = n - 1;
		while(j < k) {
			long long sum = arr[i] + arr[j];
			sum += arr[k];
			if(sum < s) {
				j++;
			}
			else if(sum > s) {
				k--;
			}
			else {
				ans.push_back({arr[i], arr[j], arr[k]});
				j++;
				k--;
				while(j < k && arr[j] == arr[j - 1]) j++;
				while(j < k && arr[k] == arr[k + 1]) k--;
			}
		}
	}

	return ans;
}