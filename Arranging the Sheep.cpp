#include <bits/stdc++.h>
using namespace std;
#define ll long long int
char v[1000003];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll tc;
  cin>>tc;
  while(tc--)
  {
    ll i,j;
    ll n;
    cin>>n;
    cin>>(v+1);
    ll ctn=0;
    for(i=1;i<=n;++i)
      if(v[i]=='*')
        ++ctn;
    ctn=(ctn+1)/2;
    ll w=0;
    for(i=1;i<=n;++i)
      if(v[i]=='*')
      {
        ++w;
        if(w==ctn)
          break;
      }
    ctn=0;
    ll res=0;
    for(j=i;j>=1;--j)
    {
      if(v[j]=='.')
        ++ctn;
      else
        res+=ctn;
    }
    ctn=0;
    for(j=i+1;j<=n;++j)
      if(v[j]=='.')
        ++ctn;
      else
        res+=ctn;
    cout<<res<<'\n';
  }
}
