class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int max=0;
        // set<int> test;
    //     for(auto i: nums){
    //         test.insert(i);
    //     }
    //    for(int i=0;i<k;i++){
    //         max = *max_element(test.begin(),test.end());
    //         auto it = find(test.begin(), test.end(), max);
    //         if (it != test.end()) {
    //             test.erase(it);
    //         }
    //    }
    //     for(auto i: test){
    //         cout<<i;
    //     }
    //    return max;
    sort(nums.begin(),nums.end());
    return nums[nums.size()-k];
    }
};