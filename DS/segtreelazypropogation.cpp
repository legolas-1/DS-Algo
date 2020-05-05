#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Look at the stars , look how they shine for you ! */

/*
    Segment tree with lazy propogation
    It support operations like query in range with O(logn)
    also it supprt update in range with O(logn)
    which is faster than O(n*logn) in normal segment tree
    It takes O(nlogn) and O(4*n+n) space complexity to build
*/

int tree[400005],A[100005];
int lazy[100005];

void build(int node,int start,int end){
	if(start == end){
        tree[node] = A[start];
        return ;
    }
	int mid = (start+end)/2;

	build(2*node,start,mid);
	build(2*node + 1,mid+1,end);

    tree[node] = max(tree[2*node],tree[2*node+1]);
}

void updateRange(int node, int start, int end, int l, int r, int val){
    if(lazy[node] != 0){
        tree[node] += (end - start ) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r){
        tree[node] += (end - start) * val;
        if(start != end){
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = max(tree[node*2],tree[node*2+1]);
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l) // not in range
        return 0;
    if(lazy[node] != 0){
        tree[node] += (end - start ) * lazy[node];
        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
    return max(p1,p2);
}

int main()
{
    //freopen("testfile.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int N,Q;
	cin >> N >> Q;

    for(int i=1;i<=N;i++)
        cin >> A[i];

    build(1,1,N);

	while(Q--)
	{
		int type;
		cin >> type;

		if(type == 0)
		{
            int startindex,endindex;
            cin >> startindex >> endindex;
			int ans = queryRange(1,1,N,startindex,endindex); // it gives answer to range query [b,c]
			cout << ans << "\n";
		}
		else
		{
            int startindex,endindex,value;
            cin >> startindex >> endindex >> value;
			updateRange(1,1,N,startindex,endindex,value); // update range indexes to given value
		}
	}

	return 0;
}


/*
    Testcase to check:
    7 6
    10 3857 7 385 984 5 100
    0 4 4
    1 3 5 -10
    0 2 6
    1 5 7 20
    1 1 6 3
    0 2 2

    Output:
    7
    5
    -1
    3857
*/
