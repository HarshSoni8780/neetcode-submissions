class Solution {
public:     
    bool found(vector<int>& matrix, int n, int target){
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = (low+high)>>1;
            if(matrix[mid] == target){
                return true;
            }
            else if(matrix[mid] < target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            if(found(matrix[i],n,target))
            return true;
        }
        return false;
    }
};
