class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        using Pair = pair<int, int>;

        // 1. Custom comparator with tie-breaking:
        // Primary: smaller distance (.second)
        // Tie-breaker: smaller array value (.first)
        auto cmp = [](const Pair& a, const Pair& b) {
            if (a.second == b.second) {
                return a.first > b.first; 
            }
            return a.second > b.second;
        };

        // 2. Build vector first for O(n) heap initialization
        vector<Pair> initial_items;
        initial_items.reserve(arr.size());
        for (int val : arr) {
            initial_items.emplace_back(val, abs(val - x));
        }

        // 3. Construct the actual priority_queue
        priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(
            cmp, std::move(initial_items)
        );

        vector<int> ans;
        ans.reserve(k);

        // 4. Read top AND pop
        while (k > 0 && !pq.empty()) {
            auto [val, d] = pq.top();
            pq.pop(); // <-- Essential!
            ans.push_back(val);
            k--;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
