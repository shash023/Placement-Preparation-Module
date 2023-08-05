/*
Find an element in a matrix.

T.C - O(log(n * m))
S.C - O(1)
*/

bool searchMatrix(vector<vector<int>>& mat, int target) {

    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = n * m - 1;
    while(low <= high) {
        int mid = (low + high) >> 1;

        if(mat[mid / m][mid % m] == target) {
            return true;
        }
        else if(mat[mid / m][mid % m] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;

}