/*
Find the maximum count of the characters in a string without repitition.

[Brute -- Generate all substrings]
[Better -- use two pointers left and right -- check set for duplicate elements]
[Optimal -- Same as better but directly jump the left pointer to the correct location]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int len = 0;
    int left = 0, right = 0;
    int n = input.size();
    vector<int> mp (256, -1);

    while(right < n) {
        if(mp[input[right]] != -1)
            left = max(mp[input[right]] + 1, left);

        mp[input[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }

    return len;
}