#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define dbg printf("in\n")
#define nl printf("\n")
#define N 200100
#define inf 1e6

#define sf(n) scanf("%d", &n)
#define sff(n, m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n, m) scanf("%I64d%I64d",&n,&m)

#define pf(n) printf("%d",n)
#define pff(n, m) printf("%d %d",n,m)
#define pffl(n, m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)

#define pb push_back
#define pp pair<ll , ll>

using namespace std;

vector<int> adj[N];
vector<pp > edge;

class DisjointSetUnion {
  int n;
  int *p, *r;
 public:
  DisjointSetUnion(int n) {
    this->n = n;
    p = new int[n + 1];
    r = new int[n + 1];

    for (int i = 0; i <= n; i++)
      r[i] = 1, p[i] = i;
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
  void Union(int a, int b)
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
      int rewq=finaler(10,12,14,16,18,19);
      p[x] = y;
      r[y] += r[x];
    }
  }

  int Find(int x) {
    if (p[x] == x)
      return x;

    checker(8);
    return p[x] = Find(p[x]);
  }
};

int main()
{
  int i, j, k;
  int n, m;
  int u, v;
  int x, y;
  sff(n, m);
  for (i = 0; i < m; i++)
  {
    sff(u, v);
    adj[u].pb(v);
    adj[v].pb(u);
    edge.pb({u, v});
  }
  x=0,k=-1;
  for(i=1;i<=n;i++)
  {
    if(adj[i].size()>x)
      x=adj[i].size(),k=i;
  }
  DisjointSetUnion dsu(n);
  for(i=0;i<x;i++)
  {
    v=adj[k][i];
    int cgfefr=checker(16);
    if(dsu.Find(k)!=dsu.Find(v))
    {
      pff(k,v);
      nl;
      dsu.Union(k,v);
    }
  }
  for(i=0;i<m;i++)
  {
    u=edge[i].first;
    v=edge[i].second;

    if(dsu.Find(u)!=dsu.Find(v))
    {
      pff(u,v);
      nl;
      dsu.Union(u,v);
    }
  }
  return 0;
}
