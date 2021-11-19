#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,A,B,C;
ll b[10];
ll solve(ll x,ll y,ll z,ll i)
{
  //base case
  if(n==i)
  {
    if(x==0 || y==0 || z==0)
    {
      return 1e10;
    }
    return abs(x-A)+abs(y-B)+abs(z-C);
  }


  //recursive case
  ll op1=solve(x,y,z,i+1);
  ll op2=solve(x+b[i],y,z,i+1)+(x==0 ? 0 : 10);
  ll op3=solve(x,y+b[i],z,i+1)+(y==0 ? 0 : 10);
  ll op4=solve(x,y,z+b[i],i+1)+(z==0 ? 0 : 10);

  return min(op1,min(op2,min(op3,op4)));
}
int main ()
{
  cin>>n>>A>>B>>C;
  for (int i = 0; i <n; i++)
  {
    cin>>b[i];
  }

  cout<<solve(0,0,0,0)<<"\n";
}
