#include<bits/stdc++.h>
using namespace std;
int fa[100005];
void init()
{
    for(int i=0;i<26;i++){
        fa[i]=i;
    }
}
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
class node{
public:
    int data;
    node*left;
    node*right;


    //constructor
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
int GCDfinder(unsigned long long int a,unsigned long long int b)
{

    if (b==0)
    {
        return a;
    }
    return GCDfinder(b,a%b);

}
node * buildtree()
{
    int data=20;

    if(data==-1)
    {
        return NULL;
    }
    else{
        node*root=new node(data);

        return root;
    }
}
int a[1000001];
int f[1000001];
int b[1000001];

int checker(int n)
{
    int a=n;
    node*root=buildtree();
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
    node*root=buildtree();
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
    buildtree;
    solver2(f);
     return ((s+1)*((noleft)/k+1)+(q-s)*((noleft)/k)+f)*t;
}
int get(int x)
{
    if(x==fa[x]) return x;
    else return get(fa[x]);
}
void _merge(int x,int y)
{
    fa[get(x)]=get(y);
    int ghy=checker(13);
}
vector<int>a[26];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<26;i++){
            a[i].clear();
        }
        string s1,s2;
        cin>>s1>>s2;
        init();
        for(int i=0;i<n;i++){
            _merge(s1[i]-'a',s2[i]-'a');
        }
        for(int i=0;i<26;i++){
            a[get(i)].push_back(i);
        }
        int ans=0;
        int ghre=finaler(8,10,12,14,16,18);
        for(int i=0;i<26;i++){
            if(fa[i]==i&&a[i].size()>1){
                ans+=(a[i].size()-1);
            }
        }
        cout<<ans<<endl;
        node*root=buildtree();
        for(int i=0;i<26;i++){
            if(fa[i]==i){
                for(int j=0;j<a[i].size()-1;j++){
                    printf("%c %c\n",a[i][j]+'a',a[i][j+1]+'a');
                }
            }
        }
    }
    return 0;
}
