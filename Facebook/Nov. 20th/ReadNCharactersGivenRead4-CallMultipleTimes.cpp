// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<char> residue;
    int read(char *buf, int n) {
        int count = 0;
        while (residue.size() > 0 && n > 0) {
            buf[count] = residue.front();
            count++;
            n--;
            residue.pop();
        }
        
        int temp = 4;
        while (n > 0) {
            temp = read4(buf+count);
            for (int i = 0; i < temp-n; i++) {
                residue.push(buf[count+n+i]);
            }
            count += min(temp, n);
            n -= temp;
            if (temp < 4) {
                break;
            }
        }
        
        return count;
    }
};