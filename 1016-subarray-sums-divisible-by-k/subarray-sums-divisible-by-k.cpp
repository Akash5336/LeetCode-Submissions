class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,ans=0,rem;
        mp[0]=1;
        for(auto num:nums){
            sum+=num;
            rem= (sum%k + k)%k;
            mp[rem]++;
            if(mp[rem]>1)
                ans += mp[rem]-1;
        }
        return ans;
    }
};