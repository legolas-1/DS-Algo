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
    Kosaraju algorithm is use to find all strongly connected com in a graph , it
    is very fast and uses two dfs but slower than Tarjan's algorithm. it takes
    O(V+E) time to find it , where V is number of vertices and E is number of edges
*/

struct Node{
    vector<int> adj;
    vector<int> radj;
};

Node g[maxn];
stack<int> stk;
bool visited[maxn];
int val[maxn];
int component[maxn];
vector<int> scc[maxn];
int numscc;

void dfs1(int x){
    visited[x] = true;
    for (int i=0;i<g[x].adj.size();i++){
        if(!visited[g[x].adj[i]])
            dfs1(g[x].adj[i]);
    }
    stk.push(x);
}

void dfs2(int x){
    component[x] = numscc;
    scc[numscc].push_back(x);
    visited[x] = true;
    for(int i=0;i<g[x].radj.size();i++)
    {
        if(!visited[g[x].radj[i]])
            dfs2(g[x].radj[i]);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        g[x].adj.push_back(y);
        g[y].radj.push_back(x);
    }

    memset(val,0,sizeof(val));
    for (int i=0;i<n;i++){
        if (!visited[i])
            dfs1(i);
    }

    for (int i=0;i<n;i++){
        visited[i] = false;
    }

    while (!stk.empty()){
        int v = stk.top();
        stk.pop();
        if (!visited[v]){
            dfs2(v);
            numscc++;
        }
    }

    int comp = 1;
    for(int i=0;i<n;i++){
        if(scc[i].size() == 0)
            continue;
        cout << comp << " : " ;
        for(auto e:scc[i]){
            cout << e << " ";
        }
        cout << "\n";
        comp++;
    }

    return 0;
}


/*
    Testcase to check:
    5 5
    2 1
    1 3
    3 2
    1 4
    4 5

    Output:
    1 : 0 1 2
    2 : 3
    3 : 4
*/
