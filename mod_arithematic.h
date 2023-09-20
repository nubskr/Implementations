const int MOD = 1e9 + 7;

int multm(int a, int b) { a%=MOD; b%=MOD; return ((a*b)%MOD); }
int addm(int a, int b) { a%=MOD; b%=MOD; return ((a+b)%MOD); }
int subm(int a, int b) { a%=MOD; b%=MOD; return ((a-b+MOD)%MOD); }
