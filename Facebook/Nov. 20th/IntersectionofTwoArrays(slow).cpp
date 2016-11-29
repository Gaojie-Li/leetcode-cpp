class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        for (int num: nums1) {
            map1[num]++;
        }
        
        for (int num: nums2) {
            map2[num]++;
        }
        
        unordered_map<int, int>::iterator it1;
        it1 = map1.begin();
        unordered_map<int, int>::iterator it2;
        it2 = map2.begin();
        
        while (it1 != map1.end()) {
            it2 = map2.begin();
            while (it2 != map2.end()) {
                if ((*it1).first == (*it2).first) {
                    result.push_back((*it1).first);
                    break;
                }
                it2++;
            }
            it1++;
        }
        
        return result;
    }
};