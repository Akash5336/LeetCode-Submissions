class Solution {
private:
    int getBC(const vector<int> bD,int k,int wD){
        int bC=0;
        int rF = k;
        for(const int day:bD){
            if(day>wD)
                rF = k;
            else if(--rF==0)
                ++bC,rF=k;
        }
        return bC;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < static_cast<long>(m) * k)
            return -1;
        
        int l = ranges::min(bloomDay);
        int r = ranges::max(bloomDay);

        while(l<r){
            const int mid = (l+r)/2;
            if(getBC(bloomDay,k,mid)>=m)
                r = mid;
            else
                l = mid+1;
        }
        return l;
    }
};