class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        
        if (nums.size() < 3) 
            return result;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    while (nums[k] == nums[k + 1]) {
                        k++;
                    }
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
                
                while (j + 1 < nums.size() - 1 && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i + 1 < nums.size() - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return result;
    }
};