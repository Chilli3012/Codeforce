#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std;
void solve()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int fer;
        cin>>fer;
        mp[fer]++;
    }
    vector<int> a;
    for(auto p:mp)
    a.push_back(p.second);
    sort(a.begin(),a.end());
    int ans=INT_MAX;
    int size=mp.size();
    for(int i=0;i<size;i++)
    {
        int greater_equal_element_count= size-i;
        ans=min(ans,n-(a[i]*greater_equal_element_count));
    }
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
      solve()
    }
    return 0;
}
