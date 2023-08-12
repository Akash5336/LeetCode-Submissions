class Solution {
public:
    bool isValid(string s) {
        stack<char> test;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                test.push(s[i]);
            else{
                if(test.empty() || 
                (s[i] == ')' && test.top() != '(') ||
                (s[i] == ']' && test.top() != '[') ||
                (s[i] == '}' && test.top() != '{'))
                return false;
                test.pop();
            }
        }
        return test.empty();
    }
};