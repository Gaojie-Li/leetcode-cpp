class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lastPos = 0;
        int n = nums.size();
        int k = 0;
        
        while (k < 3) {
            for (int i = lastPos; i < n; i++) {
                if (nums[i] == k) {
                    int temp = nums[i];
                    nums[i] = nums[lastPos];
                    nums[lastPos++] = temp;
                }
            }
            k++;
        }
    }
};