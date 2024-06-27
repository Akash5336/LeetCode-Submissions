class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>  count;
        int start=0;
        int result=0;
        for(int end=0;end<s.length();end++){
            count[s[end]]++;
            while(count['a']>=1 && count['b']>=1 && count['c']>=1){
                result+=(s.length()-end);
                count[s[start++]]--;
            }
        }
        return result;
    }
};