class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n - 1;
        while(r < m && c >= 0){
            if(matrix[r][c] > target){
                c -= 1;
            } else if(matrix[r][c] < target){
                r += 1;
            } else{
                return true;
            }
        }
        return false;
    }
};