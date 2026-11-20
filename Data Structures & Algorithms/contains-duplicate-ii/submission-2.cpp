class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for(int l=0;l<n-1;l++){
            for(int r=l+1;r<n;r++){
                if(nums[l] == nums[r]){
                    if(abs(l-r) <= k){
                        return true;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return false;
    
    }
};