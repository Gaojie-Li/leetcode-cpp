vector<bool> generatePrimes(int A) {
    vector<bool> prime(A + 1, true);
    prime[0] = false;
    prime[1] = false;
    
    for (int i = 2; i <= A; i++) {
        for (int temp = 2; temp <= A / i; temp++) {
            prime[i*temp] = false;
        }
    }
    
    return prime;
}
vector<int> Solution::primesum(int A) {
    vector<int> result;
    vector<bool> primes;
    if (A % 2 != 0) {
        return result;
    }
    
    primes = generatePrimes(A);
    
    for (int i = 2; i < primes.size(); i++) {
        if (primes[i] == false) {
            continue;
        }
        
        if (primes[A-i] == true) {
            result.push_back(i);
            result.push_back(A - i);
            break;
        }
    }
    
    return result;
}