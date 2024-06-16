class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long coverLimit=1;
        int patch=0;
        size_t idx=0;
        while(coverLimit<=n){
            if(idx<nums.size() && nums[idx]<=coverLimit)
                coverLimit += nums[idx++];
            else{
                ++patch;
                coverLimit<<=1;
            }
        }
        return patch;
    }
};