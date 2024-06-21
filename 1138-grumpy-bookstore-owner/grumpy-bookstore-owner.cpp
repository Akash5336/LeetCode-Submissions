class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int s=0,mS=0,wS=0;

        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0)
                s+=customers[i];
            else
                wS+=customers[i];
            if(i>=minutes && grumpy[i-minutes]==1)
                wS-=customers[i-minutes];
            mS= max(mS,wS);
        }
        return s+mS;
    }
};