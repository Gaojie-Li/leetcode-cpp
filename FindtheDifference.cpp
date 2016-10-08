class Solution {
public:
    char findTheDifference(string s, string t) {
        // using ASCII sum
        int sums = 0;
        int sumt = 0;
        
        for (int i = 0; i < s.size(); i++) {
            sums += s[i];
        }
        
        for (int i = 0; i < t.size(); i++) {
            sumt += t[i];
        }
        
        char result;
        if (sumt > sums) {
            result = sumt - sums;
        }
        else
            result = sums - sumt;
            
        return result;
    }
};