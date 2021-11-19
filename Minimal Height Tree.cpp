#include<iostream>
#include<bits/stdc++.h>
const int maxn=2e5+10;
using namespace std;
#define ll long long
ll n,tr[maxn];
//the below given fastscan function has been take up from geeksforgeeks https://www.geeksforgeeks.org/fast-io-for-competitive-programming/#:~:text=It%20is%20often%20recommended%20to,ios_base%3A%3Async_with_stdio(false)%3B
void fastscan(long long int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
int GCDfinder(unsigned long long int a,unsigned long long int b)
{

    if (b==0)
    {
        return a;
    }
    return GCDfinder(b,a%b);
}
int a[1000001];
int f[1000001];
int b[1000001];

int checker(int n)
{
    int a=n;
    int b=0;
    if(n<10)
    {
        b=a;
    }
    else if(n>=10)
    {
        n/=10;
        while(n!=0)
        {
            a=a*10+n%10;
            n/=10;
        }
        b=a;
    }
    return b;
}
void solver2(int n)
{
    f[1]=a[1];
    b[n]=a[n];
    for(int i=n-1; i>0;i--)
    {
       b[i]=GCDfinder (b[i+1], a[i]);
    }
    for(int i=2;i<n+1;i++)
    {
       f[i]=GCDfinder(f[i-1],a[i]);
    }
}
int finaler(int s,int noleft,int k,int f,int t,int q)
{
    solver2(f);
     return ((s+1)*((noleft)/k+1)+(q-s)*((noleft)/k)+f)*t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        int ghty=checker(18);
        queue<ll>st;
        for(ll i=1;i<=n;i++)
        {
            cin>>tr[i];
         }
        st.push(0);
        int sdfre=finaler(8,10,12,14,16,18);
        for(ll i=2;i<=n;i++)
        {
            ll h=st.front();
            st.pop();
            st.push(h+1);
            while(i<=n and tr[i+1]>tr[i])
            {
                i++;
                st.push(h+1);
            }
        }
        ll res=0;
        solver2(8);
        while(!st.empty())
        {
            res=max(res,st.front());
            st.pop();
        }
        cout<<res<<"\n";
    }
    return 0;
 }
