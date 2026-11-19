class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // first elemnt->mat[i][0];
        // last el->mat[i][n-1];

        int ind = -1;
        for (int i = 0; i < matrix.size(); i++) {
            if (target >= matrix[i][0] && target <= matrix[i][matrix[0].size() - 1]) {
                ind = i;
                break;
            }
        }

        if(ind == -1){
            return false;
        }
        else{
            if (ind != -1) {
            int low = 0;
            int high = matrix[0].size() - 1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (target == matrix[ind][mid]) {
                    return true;
                } else if (matrix[ind][mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
        }
    }
};
