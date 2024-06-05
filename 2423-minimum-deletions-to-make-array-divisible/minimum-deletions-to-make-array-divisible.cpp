class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(auto i:numsDivide){
            g = __gcd(g,i);
        }
        // int smallest = INT_MAX;
        // for(auto num:nums){
        //     if(g%num==0)
        //         smallest = min(smallest,num);
        // }
        // if(smallest==INT_MAX)
        //     return -1;
        // int minOp=0;
        // for(auto num:nums){
        //     if(num<smallest)
        //         ++minOp;
        // }
        // return minOp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            if(g%nums[i]==0) return i;
        return -1;
    }
};