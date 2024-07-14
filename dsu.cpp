#include<bits/stdc++.h>
#define endll '\n'
#define int long long int
using namespace std;
const int mod=1e9+7;
class DSU {
        public:
            vector<int> size, par;
        
            DSU(int n) {
                par.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; i++) par[i] = i;
            }
        
            int findUparent(int i) {
                if (par[i] == i)
                    return i;
                return par[i] = findUparent(par[i]);
            }
        
            int set_size(int i) {
                return size[findUparent(i)];
            }
        
            void UnionBySize(int u, int v) {
                if (same(u, v))
                    return;
                if (set_size(u) < set_size(v))
                    swap(u, v);
                u = findUparent(u), v = findUparent(v);
                par[v] = u, size[u] += size[v];
            }
        
            bool same(int u, int v) {
                return findUparent(u) == findUparent(v);
            }
    };
