class Solution {
private:
    int numBalls(const vector<int>& position,int force){
        int b=0;
        int prev=-force;
        for(const int pos:position){
            if(pos-prev >= force)
                ++b,prev = pos;
        }
        return b;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        ranges::sort(position);
        int l=1,r=position.back() - position.front();
        while(l<r){
            const int mid = r-(r-l)/2;
            if(numBalls(position,mid)>=m)
                l=mid;
            else
                r = mid-1;
        }
        return l;
    }
};