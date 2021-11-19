#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(int n)
{
    vector<int>a(n);
    vector<int>b(n);
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      b[i]=a[i];
      mp[a[i]]=0;
    }
    sort(b.rbegin(),b.rend());
    int j=0;
    vector<int>res;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=b[j])
        {
          res.push_back(a[i]);
          mp[a[i]]=1;
        }
        else
        {
            res.push_back(a[i]);
            mp[a[i]]=1;
            for(int j=(int)res.size()-1;j>=0;j--)
            {
                cout<<res[j]<<" ";
            }
            while(mp[b[j]]==1)
            {
              j++;
            }
            res.clear();
        }
    }
    for(int j=(int)res.size()-1;j>=0;j--)
    {
        cout<<res[j]<<" ";
    }
    cout<<"\n";
}
int main()
{
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
