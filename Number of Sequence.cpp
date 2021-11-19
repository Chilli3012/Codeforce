#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
# define M_PI  3.14159265358979323846
const int M=1e9+7;
void solver(long long n)
{
    vector<pair<ll,ll>>vec;
    for(ll mv=2;mv*mv<=n;mv++)
    {
        int ctn=0;
        while(n%mv==0)
        {
            ctn++;
            n/=mv;
        }
        if(ctn>0)
            vec.push_back({ctn,mv});
    }
    if(n>1)
        vec.push_back({1,n});
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    vector<long long>ans;
    for(int mv=0;mv<vec[0].first;mv++)
    {
        ans.push_back(vec[0].second);
    }
    for(int mv=1;mv<(int)vec.size();mv++)
    {
        for(int j=0;j<vec[mv].first;j++)
        {
            ans[vec[0].first-1]*=vec[mv].second;
        }
    }
    cout<<vec[0].first<<"\n";
    for(auto mv : ans)
    {
        cout<<mv<<" ";
    }
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin>>tc;
    while(tc--)
    {
        long long n;
        cin>>n;
        solver(n);
    }
    return 0;
}
