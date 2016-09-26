class Solution {
public:
    string reverseString(string s) {
        string result = "";
        int size = s.size();
        for (int i = size - 1; i >= 0; i--) {
            result += s[i];
        }
        
        return result;
    }
};