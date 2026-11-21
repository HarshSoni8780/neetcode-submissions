class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(int i=0;i<tokens.size();i++){
            string s = tokens[i];

            if(s != "+" && s != "-" && s != "*" && s != "/"){
                st.push(s);
            }
            else{
                string f = st.top();
                st.pop();
                int second = stoi(f);

                string se = st.top();
                st.pop();
                int first = stoi(se);

                string op = s;

                if(op == "+"){
                    st.push(to_string(first + second));
                }
                else if(op == "*"){
                    st.push(to_string(first*second));
                }
                else if(op == "-"){
                    st.push(to_string(first-second));
                }
                else{
                    st.push(to_string(first/second));
                }
            }
        }

        string res = st.top();
        return stoi(res);
    }
};
