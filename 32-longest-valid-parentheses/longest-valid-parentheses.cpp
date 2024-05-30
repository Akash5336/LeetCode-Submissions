class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int result = 0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<len;i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    result = max(result,i-st.top());
            }
        }
        return result;
    }
};