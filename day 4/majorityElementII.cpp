/*
Find all the majority elements in the array. Majorit element - occurence greater than n/3
In this problem, at max we can have 2 major elements in the array.
Modify the solution fot the majorityElement problem [ > n/2]

T.C - O(2N)
S.C - O(1)
*/

#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && arr[i] != el2) {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i] != el1) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(arr[i] == el1) {
            cnt1++;
        }
        else if(arr[i] == el2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == el1)
            cnt1++;
        if(arr[i] == el2)
            cnt2++;
    }

    if(cnt1 > (n / 3))
        ans.push_back(el1);
    if(cnt2 > (n / 3))
        ans.push_back(el2);

    return ans;

}