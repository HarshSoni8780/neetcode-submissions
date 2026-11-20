class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int res = 1;
        if(s.empty()){
            return 0;
        }
        unordered_set<char> st;

        while(r < n){
            if(st.find(s[r]) != st.end()){
                char c = s[r];
                while(l < r){
                    if(s[l] != c){
                        st.erase(s[l++]);
                    }
                    else{
                        l++;
                        break;
                    }
                }
                
            }
            
            st.insert(s[r]);
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};
