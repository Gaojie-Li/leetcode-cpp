class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    if (result.size() != 0) {
                        int flag = 0;
                        for (int a = 0; a < result.size(); a++) {
                            if (result[a] == nums2[j]) {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 1)
                            continue;
                    }
                    result.push_back(nums1[i]);
                    continue;
                }
            }
        }
        
        return result;
    }
};