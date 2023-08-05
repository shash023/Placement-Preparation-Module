/*
Find the number of unique paths from start (0, 0) to finish (m, n) in a matrix if we are allowed to move only right or bottom.

[Recursion - Brute approach]
T.C - O(2^N)
S.C - O(2^N)

[Dynamic Programming - Better approach - use dp in recursion solution]
T.C - O(M * N)
S.C - O(M * N)

[Combinatorics solution - Optimal]
T.C - O(R)
S.C - O(1)
*/

#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	int N = m + n - 2;
	int R = m - 1;
	double res = 1;

	for(int i = 1; i <= R; i++) {
		res = res * (N - R + i) / i;
	}

	return (int)res;
}