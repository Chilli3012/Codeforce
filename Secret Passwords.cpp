#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n");
#define N 600
#define inf 100000000

#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<int,int>

using namespace std;

vector<int> adj[30];
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

class DisjointSetUnion
{
    int n;
    int *p, *r;
public:
    DisjointSetUnion(int n)
    {
        this->n = n;
        p = new int[n + 1];
        r = new int[n + 1];

        for (int i = 0; i <= n; i++)
            r[i] = 1, p[i] = i;
    }

    void Union(int a,int b)
    {
        int x = Find(a);
        int y = Find(b);

        if (r[x] > r[y])
        {
            p[y] = x;
            r[x] += r[y];
        }

        else
        {
            p[x] = y;
            r[y] += r[x];
        }
    }

    int Find(int x)
    {
        if (p[x] == x)
            return x;

        return p[x] = Find(p[x]);
    }
};


int main()
{
    int k;
    int n, m, t;
    char mn;

    sf(n);
    string s[n + 1];
    node*root5=buildtree();
    DisjointSetUnion dsu(n);
    for(int i = 1; i <= n; i++)
        cin >> s[i];

    for(int i = 1; i <= n; i++)
    {
        m = s[i].length();
        for(int j = 0; j < m; j++)
            adj[s[i][j] - 'a'].pb(i);
    }
    solver2(14);
    for(int i = 0; i < 26; i++)
    {
        m = adj[i].size();
        for(int j = 0; j < m - 1; j++)
        {
            dsu.Union(adj[i][j], adj[i][j + 1]);
        }
    }

    set<int> rwe;
    int yuh=finaler(8,10,12,14,16,18);
    for(int i = 1; i <= n; i++)
        rwe.insert(dsu.Find(i));

    cout<<rwe.size();

    return 0;
}
