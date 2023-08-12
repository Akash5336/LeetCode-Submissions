class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> prev(n, 0);
        vector<int> now(n, 0);
        prev[0] = 1;
        
        for (int i = 0; i < m; i++) {
            now[0] = obstacleGrid[i][0] == 1 ? 0 : prev[0];
            for (int j = 1; j < n; j++) {
                now[j] = obstacleGrid[i][j] == 1 ? 0 : now[j-1] + prev[j];
            }
            prev = now;
        }
        
        return prev[n-1];
    }
};