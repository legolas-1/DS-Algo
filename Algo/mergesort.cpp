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

/* This algorithm is a standard sorting
   algorithm called merge sort. It is based
   on divide and conqure method. It takes
   an array divide it in two parts and recursively 
   sort them and merge them. Overall complexity
   is O(nlogn) where n is number of elements in 
   array.
*/
void merge(int A[],int l,int mid,int r){
	int n1 = mid-l+1;
	int n2 = r-mid;

	int L[n1],R[n2];

	for(int i=0;i<n1;i++){
		L[i] = A[l+i];
	}

	for(int i=0;i<n2;i++){
		R[i] = A[mid+i+1];
	}

	int i = 0,j = 0,k = l;
	int cnt = 0;
	while(i < n1 && j < n2){
		if(L[i] > R[j]){
			A[k] = R[j];
			j++;
		}else{
			A[k] = L[i];
			i++;
		}
		k++;
	}

	while(i < n1){
		A[k] = L[i];
		i++;
		k++;
	}

	while(j < n2){
		A[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int A[],int l,int r){
	if(l < r){
		int mid = (r+l)/2;

		mergeSort(A,l,mid);
		mergeSort(A,mid+1,r);

		merge(A,l,mid,r);
	}
}

int main(){

	int n;
	cin >> n;

	int A[n]={0};
	for(int i=0;i<n;i++){
		cin >> A[i];
	}

	mergeSort(A,0,n-1);

	for(auto e:A)
		cout << e << " ";
	cout << "\n";

	return 0;
}

/*
    Testcase to check:
    5
	5 4 3 2 1

	Output:
	1 2 3 4 5
*/
