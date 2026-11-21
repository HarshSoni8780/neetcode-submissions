class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //lambda function
        auto comp = [](const vector<int>& a, const vector<int> &b){
            return a[0]*a[0]+a[1]*a[1] > b[0]*b[0]+b[1]*b[1];
        };

        //pq init
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp) > pq(comp);

        for(auto& point : points){
            pq.push({point[0], point[1]});
        }

        vector<vector<int>> res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
