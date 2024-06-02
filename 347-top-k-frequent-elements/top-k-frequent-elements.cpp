class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        vector<pair<int,int>> sorted(count.begin(),count.end());
        sort(sorted.begin(),sorted.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.second>b.second;
        });
        for(int i=0;i<k&&i<sorted.size();i++){
            result.push_back(sorted[i].first);
        }
        return result;
    }
};