    #include<bits/stdc++.h>
    using namespace std;
    
    const int facN = 1e6 + 5;
    int ff[facN], iff[facN];
    bool facinit = false;
    
    int power(int x, int y){
        if (y == 0) return 1;
    
        int v = power(x, y / 2);
        v = 1LL * v * v % mod;
    
        if (y & 1) return 1LL * v * x % mod;
        else return v;
    }
    
    void factorialinit(){
        facinit = true;
        ff[0] = iff[0] = 1;
    
        for (int i = 1; i < facN; i++){
            ff[i] = 1LL * ff[i - 1] * i % mod;
        }
    
        iff[facN - 1] = power(ff[facN - 1], mod - 2);
        for (int i = facN - 2; i >= 1; i--){
            iff[i] = 1LL * iff[i + 1] * (i + 1) % mod;
        }
    }
    
    int C(int n, int r){
        if (!facinit) factorialinit();
    
        if (n == r) return 1;
    
        if (r < 0 || r > n) return 0;
        return 1LL * ff[n] * iff[r] % mod * iff[n - r] % mod;
    }
    
    int P(int n, int r){
        if (!facinit) factorialinit();
    
        assert(0 <= r && r <= n);
        return 1LL * ff[n] * iff[n - r] % mod;
    }
    
    int Solutions(int n, int r){
        //solutions to x1 + ... + xn = r 
        //xi >= 0
    
        return C(n + r - 1, n - 1);
    }
