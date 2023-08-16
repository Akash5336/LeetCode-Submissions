class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        // for(int i =0;i<nums.size()-k+1;i++){
        //     vector<int> temp;
        //     for(int j=i;j<i+k;j++){
        //         temp.push_back(nums[j]);
        //     }
        //     ans.push_back(*max_element(temp.begin(),temp.end()));
        // }
        deque<int> temp;
        for(int i=0;i<nums.size();i++){
            if(!temp.empty() && temp.front() ==i-k)
                temp.pop_front();
            while(!temp.empty() && nums[temp.back()]<nums[i])
                temp.pop_back();
            temp.push_back(i);
            if(i>=k-1)
                ans.push_back(nums[temp.front()]);
        }
        return ans;
    }
};