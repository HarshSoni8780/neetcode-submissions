class Solution {

public:
    vector<int> getLeftMax(vector<int>& height, int n){
        vector<int> ans(n);

        ans[0] = height[0];

        for(int i=1;i<n;i++){
            ans[i] = max(ans[i-1], height[i]);
        }

        return ans;
    }

    vector<int> getRightMax(vector<int>& height, int n){
        vector<int> ans(n);

        ans[n-1] = height[n-1];

        for(int i=n-2;i>=0;i--){
            ans[i] = max(ans[i+1], height[i]);
        }

        return ans;
    }

public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;

        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);

        for(int i=0;i<n;i++){
            int h = min(leftMax[i], rightMax[i]) - height[i];
            water += h;
        }

        return water;
    }
};
