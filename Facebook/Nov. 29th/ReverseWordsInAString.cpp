class Solution {
public:
    void reverseWord(string& s, int l, int r) {
        while(l < r) {
            char temp = s[l];
            s[l++] = s[r];
            s[r--] = temp;
        }    
    }
    
    void reverseWords(string &s) {
        int left = 0;
        int i = 0;
        int j = 0;
        int wordcount = 0;
        
        while (1) {
            while (s[i] == ' ' && i < s.size())
                i++;
            
            if (i == s.size()) {
                break;
            }
            
            if (wordcount)
                s[j++] = ' ';
                
            left = j;
            while (s[i] != ' ' && i < s.size()) {
                s[j] = s[i];
                j++;
                i++;
            }
            reverseWord(s, left, j-1);
            wordcount++;
        }
        
        s.resize(j);
        reverseWord(s, 0, j-1);
    }
};