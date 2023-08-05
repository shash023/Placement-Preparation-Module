/*
Find the count of the subarray with the given XOR.

T.C - O(N) or O(N * logN) -- depending on the map
S.C - O(N)
*/

#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    int count = 0, xr = 0;
    unordered_map<int, int> mp;
    mp[xr]++; // (0, 1) - initially

    for(int i = 0; i < n; i++) {
        xr = xr ^ arr[i];
        int k = xr ^ x;
        if(mp.find(k) != mp.end()) {
            count += mp[k];
        }
        mp[xr]++;
    }

    return count;
}