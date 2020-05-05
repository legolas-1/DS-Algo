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
    this algorithm is use to find pattern in string
    it works in O(n+p) where n is length of string
    and p is length of pattern
*/

vector<int> calcZ(string s)
{
    int start = 0,end = 0;
    vector<int> Z(s.size()+1,0);

    for(int k=1;k<s.size();k++){
        if(k > end){
            start = end = k;
            while(end < s.size() && s[end] == s[end-start]){
                end++;
            }
            Z[k] = end-start;
            end--;
        }
        else{
            int k1 = k-start;
            if(Z[k1] < end - k + 1)
                Z[k] = Z[k1];
            else{
                start = k;
                while(end < s.size() && s[end] == s[end-start]){
                    end++;
                }
                Z[k] = end-start;
                end--;
            }
        }
    }

    return Z; // all the indexes of where pattern is matching with string
}

/*
use with int
*/
vector<int> zFunction(vector<int> &s) {
    int n = (int) s.size();
    vector<int> z (n);
    for (int i=1, start=0, end=0; i<n; ++i) {
        if (i <= end)
            z[i] = min (end-i+1, z[i-start]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > end)
            start = i,end = i+z[i]-1;
    }
    return z;
}


int main()
{
    string s,pat;
    cin >> s >> pat;

    string s1 = pat + '$' + s;   // character that is not present in strings
    cout << s1 << "\n";
    vector<int> Z = calcZ(s1),indexes;

    for(int i=0;i<Z.size();i++){
        if(Z[i] == pat.size())
            indexes.push_back(i-pat.size()-1);
    }

    for(auto index:indexes)
        cout << index << " ";

    return 0;
}


/*
    Testcase to check:
    abcdabcdabcd abcd

    Output:
    0 4 8
*/
