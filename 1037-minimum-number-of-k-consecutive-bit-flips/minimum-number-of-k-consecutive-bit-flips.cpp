class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans=0,flipTime=0;
        for(int i=0;i<nums.size();i++){
            if(i>=k && nums[i-k]==2)
                --flipTime;
            if(flipTime %2==nums[i]){
                if(i+k > nums.size())
                    return -1;
                ++ans;
                ++flipTime;
                nums[i] = 2;
            }
        }
        return ans;
    }
};