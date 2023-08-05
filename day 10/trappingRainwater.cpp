/*
Compute how much water can be stored inside the given elevations.

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long long ans = 0;
    long l = 0, r = n - 1;
    long leftMax = 0, rightMax = 0;

    while(l <= r) {
        if(arr[l] <= arr[r]) {
            if(arr[l] >= leftMax)
                leftMax = arr[l];
            else 
                ans += (leftMax - arr[l]);
            l++;
        }
        else {
            if(arr[r] >= rightMax)
                rightMax = arr[r];
            else 
                ans += (rightMax - arr[r]);
            r--;
        }
    }

    return ans;
}