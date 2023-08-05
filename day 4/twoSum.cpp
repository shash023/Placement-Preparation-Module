/*
Find all the pairs with the given sum.
[Hint: In the HashMap store the occurences of the element]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   unordered_map<int, int> mp;
   
   for(auto i : arr) {
      int more = s - i;
      if(mp.find(more) != mp.end()) {
         for(int j = 0; j < mp[more]; j++) {
            ans.push_back({min(i, more), max(i, more)});
         }
      }
      mp[i]++;
   }

   sort(ans.begin(), ans.end());
   return ans;
}