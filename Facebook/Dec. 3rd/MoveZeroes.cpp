class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPos = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[zeroPos++] = nums[i];
            }
        }
        
        for (; zeroPos < nums.size(); zeroPos++) {
            nums[zeroPos] = 0;
        }
    }
};