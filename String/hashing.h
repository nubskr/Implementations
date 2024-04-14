long long compute_hash(string const& s) {
    /* 
    ref: https://cp-algorithms.com/string/string-hashing.html 

    and just like this, we can now compare strings in O(1) UwU
    */
    
    const int p = 31; // closest prime to the number of different characters
    const int m = 1e9 + 9; // big enough prime??
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}