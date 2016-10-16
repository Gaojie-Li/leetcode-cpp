class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 1 || nums.size() == 0) {
            return nums;
        }
        
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(nums[i]) != numMap.end()) {
                unordered_map<int, int>::iterator it = numMap.find(nums[i]);
                (it -> second)++;
            }
            else {
                numMap.insert({nums[i], 1});
            }
        }
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            unordered_map<int, int>::iterator it = numMap.begin();
            int max = 0;
            int maxNum = 0;
            for (; it != numMap.end(); it++) {
                if ((it -> second) > max) {
                    max = it -> second;
                    maxNum = it -> first;
                }
            }
            result.push_back(maxNum);
            unordered_map<int, int>::iterator reset = numMap.find(maxNum);
            reset -> second = 0;
        }
        
        return result;
    }
};