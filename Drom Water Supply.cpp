#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define dbg printf("in\n")
#define nl printf("\n");
#define N 1010
#define pp pair<int,int>
#define inf 10000000
#define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)
#define pf(n) printf("%d\n",n)
#define pfl(n) printf("%I64d ",n)
#define pfs(s) printf("%s\n",s)
#define pb(n) push_back(n)
using namespace std;
int x;
bool falser[N], in[N], out[N];
vector<pp> aj[N];
vector<pair<pp,int>> res;
void dfs(int s, int d)
{
	falser[s] = 1;
	if (in[s] and !out[s])
	{
		pp a = { x,s };
		res.push_back({ a,d });
	}

	for (pp e : aj[s])
	{
		if (!falser[e.first])
			dfs(e.first, min(e.second, d));
	}
}
int main()
{
	int i, j, k;
	int n, m;
	int u, v, w;
	memset(falser, 0, sizeof(falser));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	sff(n, m);
	for (i = 0; i < m; i++)
	{
		sff(u, v);
		sf(w);

		in[v] = 1;
		out[u] = 1;
		aj[u].push_back({ v,w });
	}
	vector<int> ve;
	for (i = 1; i <= n; i++)
	{
		if (out[i] and !in[i])
			ve.pb(i);
	}
	for (int e : ve)
	{
		x = e;
		if(!falser[e])
			dfs(e,inf);
	}
	n=res.size();
	pf(n);
	for (i = 0; i < n; i++)
		printf("%d %d %d\n", res[i].first.first, res[i].first.second, res[i].second);
	return 0;
}
