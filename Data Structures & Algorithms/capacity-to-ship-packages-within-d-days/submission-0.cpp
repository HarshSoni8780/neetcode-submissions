class Solution {
public: 
    int isWeightPossible(vector<int>& weights, int capacity){
        //we cant start days with 0 lol
        int days = 1;
        int load = 0;
        int n = weights.size();

        for(int i=0; i<n; i++){
            if(load + weights[i] > capacity){
                // if total capacity exceeds capacity then the load will
                // be shifted to another day and calculate new load
                days++;
                load =  weights[i];
            }
            else{
                //otherwise add to total load
                load += weights[i];
            }
        }
        return days;

    }

public:
    int SumOfAll(vector<int>& weights){
        int sum = 0;
        int n = weights.size();
        for(int i=0; i<n; i++){
            sum += weights[i];
        }
        return sum;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = SumOfAll(weights);

        while(low <= high){
            int mid = (low + high)>>1;

            if(isWeightPossible(weights,mid) <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};