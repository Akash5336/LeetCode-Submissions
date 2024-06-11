class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans(arr1.size());
        int ind=0;
        map<int,int> mp;
        for(auto i:arr1){
            mp[i]++;
        }
        for(auto var:arr2){
            if(mp[var]!=0){
                for(int j=0;j<mp[var];j++){
                    ans[ind++]=var;
                }
            }
            mp.erase(var);
        }
        for(auto pair:mp){
            for(int j=1;j<=pair.second;j++){
                ans[ind++]=pair.first;
            }
        }
        return ans;
    }
};