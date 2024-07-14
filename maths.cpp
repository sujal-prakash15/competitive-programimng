    #include<bits/stdc++.h>
    using namespace std;
    
    const int facN = 1e6 + 5;
    int ff[facN], iff[facN];
    bool facinit = false;
    //bpow
    int power(int x, int y){
        if (y == 0) return 1;
    
        int v = power(x, y / 2);
        v = 1LL * v * v % mod;
    
        if (y & 1) return 1LL * v * x % mod;
        else return v;
    }
    //calculating factorial
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
    //ncr
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
    //extended euclidean for finding solutions to ax+by+cz+..=gcd(a,b,c,..)
    int ex_gcd(int a, int b, int& x, int& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int d = ex_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    } 
    bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
            g = gcd(abs(a), abs(b), x0, y0);
            if (c % g) {
                return false;
            }
        
            x0 *= c / g;
            y0 *= c / g;
            if (a < 0) x0 = -x0;
            if (b < 0) y0 = -y0;
            return true;
        }
        void shift_solution(int & x, int & y, int a, int b, int cnt) {
        x += cnt * b;
        y -= cnt * a;
    }
    int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
        int x, y, g;
        if (!find_any_solution(a, b, c, x, y, g))
            return 0;
        a /= g;
        b /= g;
    
        int sign_a = a > 0 ? +1 : -1;
        int sign_b = b > 0 ? +1 : -1;
    
        shift_solution(x, y, a, b, (minx - x) / b);
        if (x < minx)
            shift_solution(x, y, a, b, sign_b);
        if (x > maxx)
            return 0;
        int lx1 = x;
    
        shift_solution(x, y, a, b, (maxx - x) / b);
        if (x > maxx)
            shift_solution(x, y, a, b, -sign_b);
        int rx1 = x;
    
        shift_solution(x, y, a, b, -(miny - y) / a);
        if (y < miny)
            shift_solution(x, y, a, b, -sign_a);
        if (y > maxy)
            return 0;
        int lx2 = x;
    
        shift_solution(x, y, a, b, -(maxy - y) / a);
        if (y > maxy)
            shift_solution(x, y, a, b, sign_a);
        int rx2 = x;
    
        if (lx2 > rx2)
            swap(lx2, rx2);
        int lx = max(lx1, lx2);
        int rx = min(rx1, rx2);
    
        if (lx > rx)
            return 0;
        return (rx - lx) / abs(b) + 1;
    }
    //sieve of Eratosthenes
    vector<bool> Primes(int n)
    {                                               //Time complexity:-O(nloglogn^1/2)
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                        is_prime[j] = false;
                }
            }
        return is_prime;
            // for(int i=0;i<n;i++)                     //no of prime numbers less than or equal to n is n/ln(n)
            // {                                        //The Kth Prime number is approx K*ln k
            //     if(is_prime[i])
            //     {
            //         prm.push_back(i);
            //     }
            // }
            // return prm;
    }
    //totient function for calculating the number of co primes of a number i from 1 to n
    void phi_1_to_n(int n) {
        vector<int> phi(n + 1);
        for (int i = 0; i <= n; i++)
            phi[i] = i;
    
        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= n; j += i)
                    phi[j] -= phi[j] / i;
            }
        }
    }
