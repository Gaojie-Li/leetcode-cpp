class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charMap;
        for (int i = 0; i < s.size(); i++) {
            charMap[s[i]]++;
        }
        int count = 0;
        int check = 0;
        
        unordered_map<char, int>::iterator it = charMap.begin();
        if (charMap.size() == 1) {
            return it -> second;
        }
        for (; it != charMap.end(); it++) {
            if ((it -> second) % 2 == 1) {
                count += (it -> second) / 2;
                check = 1;
            }
            if ((it -> second) % 2 == 0) {
                count += (it -> second) / 2;
            }
        }
        count = count*2 + check;
        return count;
    }
};