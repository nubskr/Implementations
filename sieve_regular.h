const int N = 1e6 + 10;
bool is_prime[N+1];
vector<int> primes;

void sieve(){
    // memset(is_prime,1,is_prime + N);
    for (int i = 2; i < N+1; ++i)
    {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}
