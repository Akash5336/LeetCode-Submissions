class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted(heights.size());
        partial_sort_copy(begin(heights), end(heights), begin(sorted), end(sorted));
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=sorted[i])
                ans++;
        }
        return ans;
    }
};