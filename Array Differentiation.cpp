#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(X) (X).begin(), (X).end()
#define allr(X) (X).rbegin(), (X).rend()
#define sz(X) (int)X.size()
#define setbits(X) __builtin_popcountll(X)
#define fix(X) fixed << setprecision(X)
#define mem0(X) memset((X), 0, sizeof((X)))
#define mem1(X) memset((X), -1, sizeof((X)))
void solver(int n)
{
    vector<int>ab(n);
    for(int i=0;i<n;++i)
    {
        cin>>ab[i];
    }
    map<int,int>bc;
    for(int i=0;i<(1<<n);++i)
    {
        int sum=0;
        for(int j=0;j<n;++j)
        {
            if(i&(1<<j))
            {
                sum+=ab[j];
            }
        }
        bc[sum]++;
    }
    for(auto x: bc)
    {
        if(x.se>1)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
      int n;
      cin>>n;
      solver(n);
    }
    return 0;
}
