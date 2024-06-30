class UnionFind{
    private:
        int count;
        vector<int> parents;
        vector<int> sizes;
        int find(int x){
            if(parents[x]!=x)
                parents[x] = find(parents[x]);
            return parents[x];
        }
    public:
        UnionFind(int n):count(n), parents(n),sizes(n,1){
            iota(parents.begin(),parents.end(),0);
        }
        int getCount() const {
            return count;
        }
        bool unite(int a,int b){
            int pA = find(a-1);
            int pB = find(b-1);
            if(pA==pB)
                return false;
            if(sizes[pA] > sizes[pB])
                parents[pB] = pA,sizes[pA] += sizes[pB];
            else
                parents[pA] = pB,sizes[pB] += sizes[pA];
            --count;
            return true;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufa(n);
        UnionFind ufb(n);
        int remC = 0;
        for(auto& edge:edges){
            if(edge[0]==3){
                bool united = ufa.unite(edge[1],edge[2]);
                ufb.unite(edge[1],edge[2]);
                if(!united)
                    ++remC;
            }
        }
        for(auto& edge:edges){
            int type = edge[0],u=edge[1],c=edge[2];
            if(type==1)
                remC += !ufa.unite(edge[1],edge[2]);
            if(type==2)
                remC += !ufb.unite(edge[1],edge[2]);
        }
        if(ufa.getCount()==1 && ufb.getCount()==1)
            return remC;
        else
            return -1;
    }
};