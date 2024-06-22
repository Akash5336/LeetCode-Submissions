class Solution {
private:
    int nOSAtMost(vector<int> &nums,int k){
        int ans=0;
        for(int l=0,r=0;r<=nums.size();){
            if(k>=0){
                ans += r-l;
                if(r==nums.size())
                    break;
                if(nums[r] & 1)
                    --k;
                ++r;
            }else{
                if(nums[l] & 1)
                    ++k;
                ++l;
            }
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return nOSAtMost(nums,k) - nOSAtMost(nums,k-1);
    }
};