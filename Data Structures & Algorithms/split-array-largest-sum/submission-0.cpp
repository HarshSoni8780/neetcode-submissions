class Solution {

    int partition(vector<int>& nums, int summ){
        int n = nums.size();
        int part = 1;
        int tot = 0;
        for(int i=0; i<n; i++){
            if(tot + nums[i] > summ){
                part++;
                tot = nums[i];
            }
            else{
                tot += nums[i];
            }
        }
        return part;
    }

    int maxElement(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }

    int Total(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        return sum;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = maxElement(nums);
        int high = Total(nums);
        while(low <= high){
            int mid = (low+high)>>1;
            int part = partition(nums, mid);

            if(part > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};