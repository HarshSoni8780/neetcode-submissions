
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        while(stones.size() > 1) {

            sort(stones.begin(), stones.end());

            int largest = stones.back();
            stones.pop_back();

            int secondLargest = stones.back();
            stones.pop_back();

            if(largest != secondLargest) {
                stones.push_back(largest - secondLargest);
            }
        }

        if(stones.empty()) {
            return 0;
        }

        return stones[0];
    }
};
