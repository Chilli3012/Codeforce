#include <bits/stdc++.h>
#define int long long
#define float double
//#define sz 100005
#define all(a) a.begin(), a.end()
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define debug cout << "here" << endl;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
using namespace std;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void enumerateSubmasks(int m)
{
    // visits submasks without repetition and in descending order
    for (int s = m;; s = (s - 1) & m)
    {

        if (s == 0)
        {
            //...
            break;
        }
    }
}

int mpow(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int x = mpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
    {
        x = (x * a) % m;
    }
    return x;
}

void printBinaryString(int n)
{
    vi temp;
    while (n)
    {
        if (n & 1)
            temp.pb(1);
        else
            temp.pb(0);
        n = n >> 1;
    }
    reverse(temp.begin(), temp.end());
    for (auto node : temp)
    {
        cout << node << " ";
    }
    cout<<"\n";
}
void readVector(vi &a)
{
    int n = a.size();
    rep(i, n)
    {
      cin>>a[i];
    }
}
int build(int s,int e,int index, vi &seg,vi &arr)
{
    if(s > e)
    {
      return 0;
    }
    if(s==e)
    {
        return seg[index] = arr[s];
    }
    int mid = (s+e)/2;

    return seg[index] = __gcd(build(s,mid,2*index,seg,arr),build(mid+1,e,2*index+1,seg,arr));
}
int query(int s,int e,int qs,int qe,int index, vi &seg)
{
    if(qs > e || qe < s)
    {
      return 0;
    }
    if(s > e)
    {
      return 0;
    }

    if(qs <=s && qe >= e) return seg[index];

    int mid = (s+e)/2;

    return __gcd(query(s,mid,qs,qe,2*index,seg),query(mid+1,e,qs,qe,2*index+1,seg));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vvi adj(n);
        map<int,int> indexer;
        rep(i,n)
        {
            int k;
            cin>>k;
            rep(j,k)
            {
                int chap;
                cin>>chap;
                chap--;
                adj[chap].pb(i);
                indexer[i]++;
            }
        }
        queue<int> q;
        rep(i,n)
        {
            if(indexer[i] == 0 ) q.push(i);
        }
        int read = 0;
        vi readingTime(n,1);
        while(!q.empty())
        {
            read++;
            int node = q.front();
            q.pop();
            for(auto child : adj[node])
            {

                if(child > node)
                {
                    readingTime[child] = max(readingTime[child],readingTime[node]);
                }
                else
                {
                  readingTime[child] = max(readingTime[child],1 + readingTime[node]);
                }
                indexer[child]--;
                if(indexer[child] == 0)
                {
                    q.push(child);
                }

            }
        }
        if(read!=n)
        {
          cout<<-1<<"\n";
        }
        else
        {
            int v = 0;
            for(auto node: readingTime)
            {
              v=max(v,node);
            }
            cout<<v<<"\n";

        }

    }
    return 0;
}
