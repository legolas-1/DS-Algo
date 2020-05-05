#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ldb;
typedef vector<ll> vll;
typedef ll __T;
typedef tree<__T, null_type, less<__T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ff first
#define ss second
#define pll pair<ll,ll>
#define CL(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)x.size())
#define lp0(i,n) for(ll i=0;i<n;i++)
#define lp1(i,n) for(ll i=1;i<=n;i++)
#define pb push_back
#define mpr make_pair
#define op(a) cout << a << "\n";
#define tc ll testcase; cin>>testcase; while(testcase--)
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(x)                     cout <<"lol"<<x<<"\n";
#define trace1(x)                cout <<#x<<":"<<x<< endl;
#define trace2(x, y)             cout <<#x<<":"<<x<<" | "<<#y<<":"<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<":"<<x<<" | "<<#y<<":"<<y<<" | "<<#z<<":"<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<endl;

const ll mod = 1e9+7;
const ldb PI = acos(-1);
const ll maxn = 1e6+4;
ll POWER[65];
void precompute() {POWER[0]=1; for(ll i=1;i<63;i++) POWER[i]=POWER[i-1]<<1LL; }
ll fastMul(ll a,ll b,ll mod){ll res = 0; a %= mod; while (b){   if (b & 1){res = (res + a) % mod;} a = (2 * a) % mod; b >>= 1;} return res;}
ll power(ll x,ll y,ll mod2) {ll res=1; x%=mod2; while(y) {if(y&1) res=fastMul(res,x,mod2); y>>=1; x=fastMul(x,x,mod2); }return res;}
ll inv(ll x,ll mod){return power(x,mod-2,mod);}

// freopen("testfile.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// order_of_key , find_by_order

/* Look at the stars , look how they shine for you ! */

/*
    dijkstra algorithm is use to find shortest path between a point and
    all other point , it do this in O(V+logV*E) which is much faster than
    brute force.
*/

vector<pair<int,int>> adj[maxn];   // node and their connecitivity with other node and wight of it
int dist[maxn];
bool vis[maxn];

void dijkstra(){                            // set the vertices distances as infinity
    memset(vis,false,sizeof(vis));            // set all vertex as unvisited
    dist[1] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > que;
    que.push({0,1});
    while(!que.empty()){
        pair<int,int> val = que.top();
        que.pop();

        int node = val.second;

        if(vis[node])
            continue;
        vis[node] = true;

        for(int i=0;i<adj[node].size();i++){
            int nxt = adj[node][i].first;
            int weight = adj[node][i].second;

            if(dist[node] + weight < dist[nxt]){
                dist[nxt] = dist[node] + weight;
                que.push({dist[nxt],nxt});
            }

        }
    }
}

int main()
{
    fast_io();
	int n,m;
	cin >> n >> m;

	for(int i=1;i<m;i++){
		int a,b,w;
		cin >> a >> b >> w;
		adj[a].push_back({b,w});
	}

    dijkstra();
    for(int i=1;i<=n;i++)
        cout << dist[i] << " ";

	return 0;
}
