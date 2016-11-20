class Solution {
public:
    string DFS(string s, int& index) {
        string res = "";
        int count = 0;
        
        while (index < s.size()) {
            if (isdigit(s[index])) {
                count = 10 * count + (s[index] - '0');
                index++;
            }
            else if (s[index] == '[') {
                index++;
                string temp = DFS(s, index);
                for (int i = 0; i < count; i++) {
                    res += temp;
                }
                count = 0;
            }
            else if (s[index] == ']') {
                index++;
                return res;
            }
            else {
                res += s[index];
                index++;
            }
        }
        
        return res;
    }
    
    string decodeString(string s) {
        string result;
        int index = 0;
        result = DFS(s, index);
        
        return result;
    }
};