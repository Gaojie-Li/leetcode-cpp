class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> numMap;
        
        if (nums.size() == 1)
            return nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            if (numMap.find(nums[i]) != numMap.end()) {
                numMap[nums[i]]++;
            }
            else {
                numMap[nums[i]] = 1;
            }
        }
        
        unordered_map<int, int>::iterator it;
        it = numMap.begin();
        for (; it != numMap.end(); it++) {
            if ((*it).second == 1)
                break;
        }
        return (*it).first;
    }
};