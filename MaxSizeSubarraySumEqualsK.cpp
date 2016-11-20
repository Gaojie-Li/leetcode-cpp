class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        
        unordered_map<int, int> result;
        int maxSub = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                maxSub = i + 1;
            }
            else if (result.find(sum - k) != result.end()){
                maxSub = max(maxSub, i - result[sum - k]);
            }
            
            if (result.find(sum) == result.end()) {
                result[sum] = i;
            }
        }
        
        return maxSub;
    }
};