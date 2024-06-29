class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> graph[n];

        for(const auto& edge:edges){
            graph[edge[0]].push_back(edge[1]);
        }

        vector<vector<int>> ans(n);

        auto bfs = [&](int start){
            queue<int> q;
            q.push(start);
            vector<bool> visited(n,false);
            visited[start]=true;

            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(int adj:graph[curr]){
                    if(!visited[adj]){
                        visited[adj]=true;
                        ans[adj].push_back(start);
                        q.push(adj);
                    }
                }
            }
        };

        for(int i=0;i<n;i++)
            bfs(i);
        return ans;
    }
};