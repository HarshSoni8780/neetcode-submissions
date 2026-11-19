class Solution {
public:
    int mySqrt(int x) {
        long long low=0, high= x;
        while(low<=high){
            long long mid=(low+high)>>1;
            long long ans = mid * mid;
            if(ans <= x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};