class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0,l=0,r = height.size()-1;
        while(l<r){
            int hgt = min(height[l],height[r]);
            int wdth= r-l;
            area = max(area,hgt*wdth);
            if(height[l]>height[r])
                r--;
            else
                l++;
        }
        return area;
    }
};