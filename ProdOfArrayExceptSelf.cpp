class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        vector<int> left(size, 1);
        vector<int> right(size, 1);
        int prod;
        
        for (int i = 1; i < size; i++) {
            left[i] = left[i-1] * nums[i - 1];
        }
        
        for (int i = size - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < size; i++) {
            result[i] = left[i] * right[i];
        }
        
        return result;
    }
};