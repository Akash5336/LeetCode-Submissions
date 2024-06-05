class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minCount(26,INT_MAX);
        for(const auto& word:words){
            vector<int> count(26,0);
            for(char c:word){
                count[c-'a']++;
            }
            for(int i=0;i<26;i++){
                minCount[i] = min(minCount[i],count[i]);
            }
        }
        vector<string> result;
        for(int i=0;i<26;i++)
            for(int j=0;j<minCount[i];j++)
                result.push_back(string(1,i+'a'));
        
        return result;
    }
};