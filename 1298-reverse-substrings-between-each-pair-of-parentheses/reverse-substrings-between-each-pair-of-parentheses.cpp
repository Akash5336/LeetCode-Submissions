class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;
        unordered_map<int,int> p;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                const int j = st.top();
                st.pop();
                p[i] = j;
                p[j] = i;
            }
        }
        for(int i=0,d=1;i<s.length();i+=d){
            if(s[i]=='(' || s[i]==')'){
                i = p[i];
                d = -d;
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};