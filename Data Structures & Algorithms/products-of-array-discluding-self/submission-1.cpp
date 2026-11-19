class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        vector<int> res;

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                ind = i;
                break;
            }
        }

        if(ind != -1){
            long product = 1;
            for(int i=0;i<n;i++){
                if(i != ind){
                    product *= nums[i];
                }
            }
            vector<int> res(n,0);
            res[ind] = product;
            return res;
        }
        else{
            long product = 1;
            for(int i=0;i<n;i++){
                product *= nums[i];
            }
            for(int i=0;i<n;i++){
                res.push_back(product / nums[i]);
            }
        }
        return res;
    }
};
