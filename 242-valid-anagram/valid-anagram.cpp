class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s1,s2;
        for(auto a:s){
            s1[a]++;
        }
        for(auto a:t){
            s2[a]++;
        }
        if(s1==s2)
            return true;
        else
            return false;
    }

};