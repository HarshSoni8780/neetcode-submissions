class Solution {
public: 
    int kokocanEat(vector<int>& piles, int k){
        int hour = 0;
        for(int i=0; i<piles.size(); i++){
            hour += ceil(double(piles[i])/double(k));
        }
        return hour;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = *max_element(piles.begin(),piles.end());
        while(low <= high){
            int mid = (low+high)>>1;
            if(kokocanEat(piles,mid) <= h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low; 
    }
};
