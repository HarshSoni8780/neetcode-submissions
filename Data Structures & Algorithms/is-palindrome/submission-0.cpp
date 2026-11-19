class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                res.push_back(tolower(s[i]));
            }
        }

        int left=0;
        int m = res.size();
        int right=m-1;

        while(left < right){
            if(res[left] != res[right]){
                return false;
                break;
            }
            left++;
            right--;
        }
        return true;
    }
};
