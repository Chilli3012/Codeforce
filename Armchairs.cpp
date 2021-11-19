#include<bits\stdc++.h>
#include<vector>
using namespace std;
long long dp[5005][5005];
vector<int>v,v1;
long long msp(int i,int j)
{
    if(i>=v.size())
    {
        return 0;
    }
    if(j>=v1.size())
    {
        return 1e15;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    dp[i][j]=min(abs(v[i]-v1[j])+msp(i+1,j+1),msp(i,j+1));


    return dp[i][j];
}
int main()
{
    int num;
    cin>>num;
    int a[num];
    for(int i=0;i<5005;i++)
    {
        for(int j=0;j<5005;j++)
        {
            dp[i][j]=-1;
        }
    }
    int cn=0;
    for(int i=0;i<num;i++)
    {
        cin>>a[i];
        if(a[i])
        {
            v.push_back(i);
            cn++;
        }
        else
        {
            v1.push_back(i);
        }
    }
    if(cn==0)
    {
        cout<<"0\n";
        return 0;
    }
    cout<<msp(0,0)<<"\n";
}
