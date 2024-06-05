class Solution {
private:
    int gcd(int a,int b){
        while(b>0){
            int tmp=a;
            a=b;
            b=tmp%b;
        }
        return a;
    }
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = numsDivide[0];
        for(auto i:numsDivide){
            g = gcd(g,i);
        }
        int smallest = INT_MAX;
        for(auto num:nums){
            if(g%num==0)
                smallest = min(smallest,num);
        }
        if(smallest==INT_MAX)
            return -1;
        int minOp=0;
        for(auto num:nums){
            if(num<smallest)
                ++minOp;
        }
        return minOp;
    }
};