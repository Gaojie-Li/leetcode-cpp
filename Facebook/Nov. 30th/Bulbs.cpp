int Solution::bulbs(vector<int> &A) {
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (count % 2 != 0) {
            A[i] = 1 - A[i];
        }
        
        if (A[i] == 0) {
            A[i] = 1;
            count++;
        }
    }
    
    return count;
}