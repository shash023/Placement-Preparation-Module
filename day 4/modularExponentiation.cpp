/*
Find pow(x, n) using modular exponentiation. For example: (2)^10 = (2 x 2)^5 = (4)^5......
[Note: Take care of overflows(Converting to higher types) and negative power(Taking reciprocal)]

T.C - O(logN)
S.C - O(1) 
*/

#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	long long ans = 1LL;
	long long nn = n;
	long long xl = x;

	while(nn) {
		if(nn % 2 == 0) {
			xl = ((xl % m) * (xl % m)) % m;
			nn = nn / 2;
		}
		else {
			ans = ((ans % m) * (xl % m)) % m;
			nn = nn - 1;
		}
	}

	return ans;
}