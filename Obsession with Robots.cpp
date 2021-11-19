#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define dbg printf("in\n")
#define nl printf("\n")
#define N 500
#define inf 1e9
#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)
#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)
#define pp pair<int, int>
using namespace std;
int adj[N][N];
bool vis[N][N];
int dist[N][N];
int main()
{
    int i, j, k;
    int n, m, t;
    string s;
    cin>>s;
    i=110,j=110;
    n=s.length();
    memset(adj, 0, sizeof(adj));
    memset(vis, 0, sizeof(vis));
    for(k = 0; k < n; k++)
    {
        if(s[k] == 'R')
            j++;
        else if(s[k] == 'L')
            j--;
        else if(s[k] == 'U')
            i--;
        else
            i++;
        adj[i][j] = 1;
    }
    int ti = i;
    int tj = j;
    i = 110, j = 110;
    queue<pp> que;
    que.push({i, j});
    vis[i][j] = true;
    dist[i][j] = 0;
    int move1[] = {1, -1, 0, 0};
    int move2[] = {0, 0, 1, -1};
    while(!que.empty())
    {
        pair<int, int>u = que.front();
        que.pop();
        for(k = 0; k < 4; k++)
        {
            int x = u.first + move1[k];
            int y = u.second + move2[k];
            if(adj[x][y] && !vis[x][y])
            {
                dist[x][y] = 1 + dist[u.first][u.second];
                vis[x][y] = true;
                que.push({x, y});
            }
        }
    }
    if(dist[ti][tj] == n)
        cout<<"OK\n";
    else
        cout<<"BUG\n";
    return 0;
}
