class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] > target) 
                break;
            if (i >= 1 && numbers[i] == numbers[i - 1])
                continue;
 
            for (int j = i+1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] > target)
                    break;
                if(numbers[i] + numbers[j] == target) {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    break;
                }
                
                if (result.size() != 0) {
                    break;
                }
            }
        }
        
        return result;
    }
};