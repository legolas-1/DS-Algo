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
ll power(ll x,ll y,ll mod2) {ll res=1; x%=mod2; while(y) {if(y&1) res=(res*x)%mod2; y>>=1; x=(x*x)%mod2; }return res;}
ll inv(ll x,ll mod){return power(x,mod-2,mod);}

// freopen("testfile.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// order_of_key , find_by_order

/* Look at the stars , look how they shine for you ! */

/* This algorithm is use to find minimum spanning tree
   in a graph. It greedily takes nodes with least cost
   and build spanning tree using it. If two nodes are
   alredy in same set they are skipped next nodes are
   choosen, till all nodes are connected to eachother.
   We can negative the weights and find maximum spanning
   tree also using this algorithm. Overall complexity is
   O(ElogV) E are edges and V are vertices.
*/

pair<int,pair<int,int>> adj[maxn];  // graph adj list with {weight, {node1, node2}} and {weight, {node2, node1}}
int id[maxn];
void makezero(){
    for(int i=0;i<maxn;i++)
        id[i] = i;
}

// disjoint set implementation
int root(int node){
    while(id[node] != node){
        id[node] = id[id[node]];
        node = id[node];
    }
    return node;
}

// union function of disjoint set
void un(int node,int node1){
    id[root(node)] = id[root(node1)];
}

int main(){
    fast_io();
    makezero(); // disjoint set making id[i] = i in start i.e. everyone is their own parent

    int veritces, edges;
    cin >> veritces >> edges;

    for(int i=0;i<edges;i++){
        int we,x,y;
        cin >> x >> y >> we;

        adj[i] = {we,{x,y}};
        adj[i] = {we,{y,x}};
    }

    // sort so that we can greedily pick edges
    sort(adj,adj+edges);
    int cost = 0;
    for(int i=0;i<edges;i++){
        if(root(adj[i].ss.ff) != root(adj[i].ss.ss)){
            cost += adj[i].ff;  // after adding two disjoint nodes together
            un(adj[i].ss.ff,adj[i].ss.ss);
        }
    }

    cout << cost << "\n";

	cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
	// unique values or same values
	return 0;
}


/*
    Testcase to check:
    4 5
    1 2 7
    1 4 6
    4 2 9
    4 3 8
    2 3 6

    Output:
    19
*/
