class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) {
                continue;
            }
            for (int j = i+1; j < nums.size() - 2; j++) {
                if (j > i+1 && nums[j-1] == nums[j]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else if (nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    }
                    else {
                        result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        do {
                            left++;
                        } while (left < right && nums[left-1] == nums[left]);
                        
                        do {
                            right--;
                        } while (left < right && nums[right+1] == nums[right]);
                    }
                }
            }
        }
        
        return result;
    }
};