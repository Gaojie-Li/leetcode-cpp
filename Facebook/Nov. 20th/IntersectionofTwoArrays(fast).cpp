class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, bool> map1;
        for (int num: nums1) {
            map1[num] = true;
        }
        
        for (int num: nums2) {
            if (map1.find(num) != map1.end()) {
                if (map1[num]) {
                    result.push_back(num);
                    map1[num] = false;
                }
            }
        }
        
        return result;
    }
};