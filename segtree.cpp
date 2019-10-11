#include<bits/stdc++.h>
using namespace std;

/*
    This is a code to build segment tree.
    It can be use to do query over range like min in a range
    also it support point update
    both functions have worst time complexity O(logn) where n are number of elements in tree
    It takes O(nlogn) time and O(4*n) space to build
*/

void build(int node,int start,int end,int tree[],int A[]){
	if(start == end){
		tree[node] = A[start];
	}
	else{
	int mid = (start+end)/2;

	build(2*node,start,mid,tree,A);
	build(2*node + 1,mid+1,end,tree,A);

	if(tree[2*node] < tree[2*node+1])
		tree[node] = tree[2*node];
	else
		tree[node] = tree[2*node+1];

	}

}

void update(int node,int start,int end,int idx,int val,int tree[],int A[])
{
	if(start == end){
		A[idx] = val;
		tree[node] = val;
	}
	else{
		int mid = (start+end)/2;
		if(idx >= start && idx <= mid)
			update(2*node,start,mid,idx,val,tree,A);
		else
			update(2*node+1,mid+1,end,idx,val,tree,A);

		if(tree[2*node] < tree[2*node+1])
			tree[node] = tree[2*node];
		else
			tree[node] = tree[2*node+1];
	}
}


int query(int node,int start,int end,int l,int r,int tree[])
{
	if(l > end || start > r)
	{	return 1000005;}
	if(l <= start && r >= end)
	{	return tree[node]; }

	int p1,p2;
	int mid = (start+end)/2;

    /* calculating answer for [start,mid] and [mid+1,end] separately */
	p1 = query(2*node,start,mid,l,r,tree);
	p2 = query(2*node+1,mid+1,end,l,r,tree);

	if(p1 < p2)
	{	return p1;}
	else
	{	return p2;}

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tree[400005],A[100002];

	int N,Q;
	cin >> N >> Q;

	for(int i=1;i<=N;i++){
		cin >> A[i];
	}

	build(1,1,N,tree,A); // build segment tree with initial values as array A.

	while(Q--)
	{
		char a;
		int b,c;
		cin >> a >> b >> c;

		if(a == 'q'){
			int w = query(1,1,N,b,c,tree); // minimum element in range [b,c]
			cout << w << endl;
		}
		else if(a == 'r'){
			update(1,1,N,b,c,tree,A); // update value of element at index b to c
		}
	}

	return 0;
}


/*
    Testcase to check:
    6 6
    10 3857 7 385 984 5
    q 1 3
    r 3 5
    q 2 6
    r 5 -1
    q 1 6
    q 2 2

    Output:
    7
    5
    -1
    3857
*/
