#include<bits/stdc++.h>
using namespace std;
int B=73;
const int maxN=1e6+6;  //define the size of the string u r processing
int pB[maxN];   //will store all the exponential values needed to be used
struct
{
    int bit[maxN]={0};
    void update(int k,int x)
    {
        x=((x%mod)+mod)%mod;
        for(;k<maxN;k+= k&-k)
        {
            (bit[k]+=x)%=mod;
        }
    }
    int query(int k)
    {
        int sum=0;
        for(;k>0;k-= k&-k)
        {
            (sum+=bit[k])%=mod;
        }
        return sum;
    }
}pref,suff;
