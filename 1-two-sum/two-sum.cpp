class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> n_count;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(n_count.count(comp))
                return {n_count[comp],i};
            n_count[nums[i]] = i;
        }

        return {};
    }
};