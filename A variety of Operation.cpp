#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
ll mod=1000000007;
using namespace std;
void solve(ll c,ll d)
{
    ll a=0,b=0;
    ll p=abs(c-d);
    if(p%2!=0)
    {
        cout<<-1<<"\n";
        return;
    }
    if(c==d)
    {
        if(c==0)
        {
            cout<<0<<"\n";
        }
        else
        {
            cout<<1<<"\n";
        }
    }
    else
    {
        cout<<2<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll c,d;
        cin>>c>>d;
        solve(c,d);
    }
    return 0;
}
