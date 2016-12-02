bool Solution::isPower(int A) {
    if (A == 1) {
        return true;
    }
    for (int i = 2; i <= sqrt(A) && i < INT_MAX / i; i++) {
        int result = i;

        while (result < A && result < INT_MAX / i) {
            result *= i;
            if (result == A) {
                return true;
            }
        }
    }
    
    return false;
}