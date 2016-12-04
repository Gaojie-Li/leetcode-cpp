class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int finalLength = 0;
        int finalPos = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[finalPos++] = nums[i];
                finalLength++;
            }
        }
        
        return finalLength;
    }
};