class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> count;
        for(auto edge:edges){
            for(auto e:edge){
                count[e]++;
            }
        }
        int ans=0;
        for(auto val:count){
            if(val.second==edges.size()){
                ans=val.first;
                break;
            }
        }
        return ans;
    }
};