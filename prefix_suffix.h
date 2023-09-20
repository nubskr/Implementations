struct PSA{
    // source: https://codeforces.com/contest/1622/submission/142753260
    // usage: PSA pref_shit(v)
    vector<int> pre, suf;
    // 0 based indexing
    int n; 
    PSA(vector<int> &inp){
        n = inp.size();
        pre.resize(n);
        suf.resize(n);
        
        for(int i = 0; i < n; ++i){
            if(i == 0) pre[i] = inp[i];
            else pre[i] = combine(pre[i - 1], inp[i]);
        }
        for(int i = n - 1; i >= 0; --i){
            if(i == n - 1) suf[i] = inp[i];
            else suf[i] = combine(suf[i + 1], inp[i]);
        }
    }
 
    int combine(int a, int b){
        return a + b;
    }
   
    int pre_query(int i){
        return pre[i];
    }
 
    int suf_query(int i){
        return suf[i];
    }
};