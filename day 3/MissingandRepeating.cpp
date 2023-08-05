/*
Find the missing and repeating numbers from the array containing numbers in the range [1, N]
[Hint: Form two equations (X - Y) and (X + Y) then solve them]
[Can be solved using XOR but is tricky]

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long SN = (n * (n + 1)) / 2;
	long long SN2 = (n * (long long)(n + 1) * (long long)(2 * n + 1)) / 6;

	long long S = 0;
	long long S2 = 0;

	for(int i = 0; i < n; i++) {
		S += arr[i];
		S2 += (long long)arr[i] * (long long)arr[i];
	}

	long long val1 = S - SN;
	long long val2 = S2 - SN2;

	val2 = val2 / val1;
	long long x = (val1 + val2) / 2;
	long long y = x - val1;

	return {(int)y, (int)x};
}
