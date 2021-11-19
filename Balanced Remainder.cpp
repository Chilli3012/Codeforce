#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define rf(i, a, b) for (ll i = a; i >= b; i--)
typedef std::vector<long long> vi;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(), a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
const ll INF = LLONG_MAX / 2;
const ll N = 2e5 + 1;
using namespace std;
int main()
{
    fast;
    ll tc;
    std::cin>>tc;
    while(tc--)
    {
        ll n,i,j=0;
        std::cin>>n;
        ll a[n],c0=0,c1=0,c2=0;
        fr(i,0,n)
        {
            cin>>a[i];
            if(a[i]%3==0)
                c0++;
            else if(a[i]%3==1)
                c1++;
            else
                c2++;
        }
        ll ans=n/3,co=0;
        if(c0>ans)
        {
            co+=c0-ans;
            c1+=c0-ans;
            c0=ans;
            if(c1>ans)
            {
                co+=c1-ans;
                c2+=c1-ans;
            }
            else if(c1!=ans)
            {
                co+=(c2-ans)*2;
            }
            cout<<co<<"\n";
            continue;
        }
        else if(c1>ans)
        {
            co+=c1-ans;
            c2+=c1-ans;
            if(c2>ans)
            {
                co+=c2-ans;
                c2+=c1-ans;
            }
            else if(c2!=ans)
            {
                co+=(c0-ans)*2;
            }
            cout<<co<<"\n";
            continue;
        }
        else if(c2>ans)
        {
            co+=c2-ans;
            c0+=c2-ans;
            if(c0>ans)
            {
                co+=c0-ans;
            }
            else if(c0!=ans)
            {
                co+=(c0-ans);
            }
            cout<<co<<"\n";
            continue;
        }
        cout<<0<<"\n";
    }
}
