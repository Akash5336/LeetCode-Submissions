class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> friends(n);
        int fC = n,fp=0;
        while(fC>1){
            for(int i=0;i<k;i++,++fp)
            while(friends[fp%n])
                ++fp;
            friends[(fp-1)%n] = true;
            --fC;
        }
        const auto it = 
        find_if(friends.begin(),friends.end(),[](int f){return !f;});
        return distance(friends.begin(),it)+1;
    }
};