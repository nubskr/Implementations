const int N = 1e6 + 10;
bool is_prime[N+1];
int spf[N];
vector<int> primes;

void sieve(){
    // memset(is_prime,1,is_prime + N);
    for (int i = 2; i < N+1; ++i)
    {
        is_prime[i] = true;
        spf[i] = i;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if(spf[i]==i){
            for (int j = i * i; j <= N; j += i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
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

vector<int> factorise(int x){
    // all factors in sqrt(N)
    vector<int> v;
    for (int i = 1; i*i <= x; ++i)
    {
        if(x%i==0){
            v.push_back(x);
            int other = x/i;
            if(other != i){
                v.push_back(other);
            }
        }
    }
    return v;
}

vector<pair<int,int>> prime_factor_small(int x){
    // prime facs
    // factorise in log(N) for N<=1e6
    vector<pair<int, int>> v;
    while (x > 1) {
        int p = spf[x], c = 0;
        while (x % p == 0) {
            x /= p;
            c++;
        }
        v.emplace_back(p, c);
    }
    return v;
}

vector<pair<int,int>> prime_factor(int x){
    // prime facs
    // almost sqrt(N)
    vector<pair<int,int>> v;
    for (int p : primes) {
        if ((long long)p*p > x) {
            break;
        }
        if (x % p == 0) {
            int c = 0;
            while (x % p == 0) {
                x /= p;
                c++;
            }
            v.emplace_back(p, c);
        }
    }
    if (x > 1) {
        v.emplace_back(x, 1);
    }
    return v;
}
