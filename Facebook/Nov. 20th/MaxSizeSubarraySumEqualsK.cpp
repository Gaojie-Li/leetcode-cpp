class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        int maxL = 0;
        unordered_map<int, int> sum;
        int curSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum == k) {
                maxL = i + 1;
            }
            else if (sum.find(curSum - k) != sum.end()) {
                maxL = max(maxL, i - sum[curSum - k]);
            }
            
            if (sum.find(curSum) == sum.end()) {
                sum[curSum] = i;
            }
        }
        
        return maxL;
    }
};