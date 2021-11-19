#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
int main()
{
  ll tc;
  cin>>tc;
	while(tc--)
	{
    ll n,k;
    cin>>n>>k;
		ll res=1;
		for(int i=0;i<k;i++)
    {
      res=(res*n)%mod;
    }
    cout<<res<<"\n";
	}
}
