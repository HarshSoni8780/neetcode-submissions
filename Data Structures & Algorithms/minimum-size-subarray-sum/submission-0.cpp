class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = n;

        int acc = accumulate(nums.begin(), nums.end(),0);
        if(acc < target){
            return 0;
        }

        while(right < n){
            sum += nums[right];

            while(sum >= target){
                minLen = min(minLen, right-left+1);
                if(sum < target){
                    break;
                }
                sum -= nums[left];
                left++;
            }

            right++;
        }
        return minLen;
    }
};