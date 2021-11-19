#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n,res=LLONG_MAX,pre=0;
        cin>>n;
        vector<ll>c(n);
        vector<ll>jh;
        priority_queue<ll,vector<ll>,greater<ll>>epq,opq;
        for(ll i=0;i<n;++i)
        {
            cin>>c[i];
            jh.push_back(c[i]);
            i % 2 ? opq.push(c[i]) : epq.push(c[i]);
            pre+=c[i];
            if(i)
            {
                jh[i]-=9;
                res=min(res,pre+(n-(ll)epq.size())*epq.top()+(n-(ll)opq.size())*opq.top());
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}
