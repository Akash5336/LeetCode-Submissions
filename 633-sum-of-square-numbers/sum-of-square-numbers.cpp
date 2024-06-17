class Solution {
public:
    bool judgeSquareSum(int c) {
        unsigned l=0,r=sqrt(c);
        if(r*r==c)
            return true;
        while(l<=r){
            const unsigned sum=l*l+r*r;
            if(sum==c)
                return true;
            if(sum<c)
                l++;
            else
                r--;
        }
        return false;
    }
};