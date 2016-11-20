class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
    
        if (haystack.size() < needle.size()) {
            return -1;
        }
        
        for (int i = 0, j = 0; i < haystack.size() - needle.size() + 1; i++, j = 0) {
            while (haystack[i] == needle[j] && j < needle.size()) {
                i++;
                j++;
            }
            if (j == needle.size()) {
                return i - j;
            }
            else 
                i = i - j;
        }
        
        return -1;
    }
};