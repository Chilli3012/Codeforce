#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        ll *a=new ll[n+2];
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(x%2==0)
            {
                even.push_back(x);
            }
            else
            {
                odd.push_back(x);
            }
        }
        int odder=odd.size();
        int ever=n-odder;
        long long int res=ever*odder;
        for(int i=0;i<odder;i++)
        {
            for(int j=i+1;j<odder;j++)
            {
                if((__gcd(odd[i], 2*odd[j]))>1)
                {
                    res++;
                }
            }
        }
        res+=(ever*(ever-1)/2);
        cout<<res<<"\n";
    }
    return 0;
}
