class Solution {
public:
    bool isValid(string s) {
        map<char, char> myMap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> store;
        
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{')
                store.push(c);
            else if (!store.empty() && myMap[store.top()] == c) {
                store.pop();
            }
            else
                return false;
        }
        
        return store.empty();
    }
};