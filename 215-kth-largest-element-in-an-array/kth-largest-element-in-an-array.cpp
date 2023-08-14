class Solution {
public:
int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;

        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) {
                l++;
            }
            if (nums[r] <= pivot) {
                r--;
            }
        }

        swap(nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
    //     int max=0;
    //    for(int i=0;i<k;i++){
    //         max = *max_element(nums.begin(),nums.end());
    //         auto it = find(nums.begin(), nums.end(), max);
    //         if (it != nums.end()) {
    //             nums.erase(it);
    //         }
    //    }
    //    return max;
    // sort(nums.begin(),nums.end());
    // return nums[nums.size()-k];
    int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == k - 1) {
                return nums[pivotIndex];
            } else if (pivotIndex < k - 1) {
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }

        return -1;
    }
};