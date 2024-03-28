class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> counts;
        for(auto &str:strs){
            string sorted = str;
            sort(sorted.begin(),sorted.end());
            counts[sorted].push_back(str);
        }
        for(auto &val:counts){
            ans.push_back(val.second);
        }
        return ans;
    }
};