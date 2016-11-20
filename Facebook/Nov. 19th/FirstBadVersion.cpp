// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lower = 1;
        int upper = n;
        int mid;
        
        while (lower < upper) {
            // cannot use (upper+lower)/2, will exceed limit of int type
            mid = lower + (upper - lower) / 2;
            if (!isBadVersion(mid)) {
                lower = mid + 1;
            }
            else {
                upper = mid;
            }
        }
        
        return lower;
    }
};