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
    Dynamic segtree are use where we can not build whole range
    segtree in one go because of memory contraints in question
    so we only build nodes when they are required to .
    all operations done in O(logn)

*/

ll n;
int queries;

struct node {
    ll from, to;
    int value, lazy;
    node *left, *right;
    /* initilizing nodes */
    node() {
        from=1LL,to=1e18+5,value=0,lazy=0;
        left=NULL,right=NULL;
    }
    void extend() {
        if(left==NULL) {
            left=new node();
            right=new node();
            left->from=from;
            left->to=(from+to)>>1LL;
            right->from=((from+to)>>1LL)+1LL;
            right->to=to;
        }
    }
};

node *root; // initial root node 

void update(node *idx, ll left, ll right,int value) {
    if(idx->lazy) {
        idx->value+=(idx->to-idx->from+1)*idx->lazy;
        if(idx->from!=idx->to) {
            idx->extend();
            idx->left->lazy+=idx->lazy;
            idx->right->lazy+=idx->lazy;
        }
        idx->lazy=0;
    }

    if((idx->from)>(idx->to) || (idx->from)>right || (idx->to)<left)
        return;

    if(idx->from>=left && idx->to<=right) {
        idx->value+=(idx->to-idx->from+1)*value;

        if(idx->from!=idx->to) {
            idx->extend();
            idx->left->lazy+=value;
            idx->right->lazy+=value;
        }
        return;
    }

    idx->extend();
    update(idx->left,left,right,value);
    update(idx->right,left,right,value);

    idx->value = idx->left->value + idx->right->value;
}

ll query(node *idx, ll left, ll right) {

    if((idx->from)>(idx->to) || (idx->from)>right || (idx->to)<left)
        return 0;

    if(idx->lazy) {
        idx->value+=((idx->to)-(idx->from)+1)*idx->lazy;
        idx->extend();
        idx->left->lazy += idx->lazy;
        idx->right->lazy += idx->lazy;
        idx->lazy = 0;
    }

    if(idx->from>=left && idx->to<=right)
        return idx->value;

    ll q1,q2;
    idx->extend();
    q1=query(idx->left,left,right);
    q2=query(idx->right,left,right);
    return q1+q2;
}

int main() {
    // freopen("testfile.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    clock_t time_taken;
    time_taken = clock();

    fast_io();
    int type;
    root = new node(); // build tree
    cin >> queries;
    ll prevans = 0;

    for(int i=1;i<=queries;i++) {
        cin >> type;
        if(type==1) {
            ll startindex,endindex;
            int value;
            cin >> startindex >> endindex >> value;
            update(root,startindex,endindex,value); // update value to index [a,b) to +val
        }
        else {
            ll startindex , endindex;
            cin >> startindex >> endindex;
            ll ans = query(root,0,endindex) - query(root,0,startindex-1); // query to find sum from range [startindex,endindex]
            cout << ans << "\n";
        }
    }

    time_taken = clock() - time_taken;
    double time_by_fun = ((double)time_taken)/CLOCKS_PER_SEC; // in seconds
    printf("\nfun() took %f seconds to execute \n", time_by_fun);

    return 0;
}

/*
    Testcase to check:
    5
    1 1 5 5
    2 1 5
    2 2 6
    1 5 5 10
    2 2 10

    Output:
    25
    20
    30
*/
