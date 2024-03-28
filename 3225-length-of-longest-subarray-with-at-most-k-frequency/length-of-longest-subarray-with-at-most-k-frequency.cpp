class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int> count;
        int l=0;
        for(int r=0;r<nums.size();r++){
            count[nums[r]]++;
            while(count[nums[r]]>k){
                count[nums[l]]--;
                l++;
            }
            res = max(res,(r-l + 1));

        }

        return res;
    }
};