/*
Find the length of the longest subarray with sum zero.

T.C - O(N) [unordered_map -- O(N^2) - worst case    map -- O(N * logN)]
S.C - O(N)
*/

#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr) {
  int n = arr.size();
  int sum = 0, maxi = 0;
  unordered_map<int, int> mp;
  for(int i = 0; i < n; i++) {
    sum += arr[i];
    if(sum == 0) {
      maxi = i + 1;
    }

    if(mp.find(sum) != mp.end()) {
      maxi = max(maxi, i - mp[sum]);
    }
    else {
      mp[sum] = i;
    }
  }

  return maxi;
}