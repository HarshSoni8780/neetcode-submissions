class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        int cnt = 0;
        int i = 0;
        for(auto num: st){
            nums[i++] = num;
            cnt++; 
        }

        return cnt;
    }
};