#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#define MAXN 30005
#define fr(a,b,c) for(int a = b; a < c; a++)
#define fre(a,b,c) for(int a = b; a <= c; a++)
using namespace std;


int st[4*MAXN];
int v[MAXN];
int n,q;
int a,b;

int left(int p){ return p << 1; }
int right(int p){ return (p << 1) + 1; }

void build(int p, int L, int R){
	if(L == R){
		st[p] = 1;
		return;			
	}else{
		int mid = (L+R)/2;
		build(left(p), L, mid);
		build(right(p), mid + 1, R);
		vector<int> aux;
		set<int> mySet;
		mySet.clear();
		fre(i,L,R){
			mySet.insert(v[i]);
		}
		st[p] = mySet.size();
	}
}

int query(int p, int L, int R, int i, int j){
	int mid = (L+R)/2;
	if (i > R || j < L) return -1;
	if (L >= i && R <= j) return st[p];
	int p1 = query(left(p),L, mid, i, j);
	int p2 = query(right(p),mid + 1, R, i, j);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	//NUNCA SETAR ST[P] AQUI
	return p1 + p2;
}


int main(){
	while(scanf("%d", &n) > 0){
		fr(i,0,n){
			scanf("%d", &v[i]);
		}
		build(1,0,n-1);
		scanf("%d", &q);
		fr(i,0,q){
			scanf("%d %d", &a, &b);
			printf("%d\n",query(1,0,n-1,a - 1,b - 1));		
		}
	}	
	return 0;
}
