class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> count;
        int val_count=0;
        for(auto c:s){
            count[c]++;
        }
        for(auto val:count){
            val_count+= val.second%2==0?val.second:val.second-1;
        }
        bool hasOddCount = ranges::any_of(count,[](const auto& pair){return pair.second&1;});
        return val_count+hasOddCount;
    }
};