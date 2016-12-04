class Solution {
public:
    string convertToTitle(int n) {
        if (n == 0) {
            return "";
        }
        
        char leftOver;
        leftOver = (n - 1) % 26 + 'A';
    
        return convertToTitle((n-1) / 26) + leftOver;
    }
};