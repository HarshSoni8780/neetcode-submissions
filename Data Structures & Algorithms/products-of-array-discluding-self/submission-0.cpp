class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        vector<int> res;
        for(int x=0;x<nums.size();x++){
            for(int i=0;i<nums.size();i++){
                if(i==x){
                    continue;
                }
                else{
                    product *= nums[i];
                }
            }
            res.push_back(product);
            product = 1;
        }
        return res;
    }
};
