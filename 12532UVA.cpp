#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <cstring>
#define MAXN 100005
using namespace std;

 
int N,C;
int A[MAXN];
int st[4*MAXN];

int left(int p){ return p << 1; }
int right(int p){ return (p << 1) + 1;}

void build(int p, int L, int R){
	if(L == R){
		st[p] = A[L];
	}else{
		build(left(p), L, (L+R)/2);
		build(right(p),(L+R)/2 + 1, R);
		int p1 = st[left(p)], p2 = st[right(p)];
		//printf("B %d %d %d %d\n", p1, p2, L, R);
		st[p] = p1*p2;
	}
}

int update(int p, int L, int R, int idx, int val){
	//printf("U %d %d %d %d %d\n",p,L,R,idx, val);
	int i = idx, j = idx;
	if(i > R || j < L) return st[p];
	if(L == i && R == j){
		A[i] = val;
		return st[p] = val;
	}
	int p1, p2;
	
	p1 = update(left(p), L, (L+R)/2, idx, val);
	p2 = update(right(p), (L+R)/2 + 1, R, idx, val);
	return st[p] = p1 * p2;
}

int query(int p, int L, int R, int i, int j){
	if(i > R || j < L) return 1;
	if(L >= i && R <= j) return st[p];
	
	int p1 = query(left(p), L, (L+R)/2, i, j);
	int p2 = query(right(p), (L+R)/2 + 1, R, i,j);
	
	//if(p1 == 30) return p2;
	//if(p2 == 30) return p1;
	return p1*p2;
}

int I, J;
char T[4];

int main(){
	while(scanf("%d %d", &N, &C) > 0){
		for(int i = 0; i < N; i++){
			scanf("%d", &A[i]);
			if(A[i] != 0) A[i] /= abs(A[i]);
		}
		/*for(int i = 0; i < N; i++){
			printf("%d ", A[i]);
		}*/
		//printf("\n");
		//memset(st, 1, sizeof(st));
		build(1,0, N - 1);
		string ans; ans.clear();
		for(int i = 0; i < C; i++){
			scanf("%1s %d %d", T,&I, &J);
			if(T[0] == 'C'){
				//printf("NEW UPDATE\n");
				if(J != 0) J /= abs(J);
				I--, update(1,0, N-1, I, J);
			 	
			}
			else{
				I--; J--;
				int res = query(1,0,N-1,I,J);
				if(res == 0) ans.push_back('0'); 
				else if(res < 0) ans.push_back('-');
				else ans.push_back('+');
			}		
		}
		cout << ans << endl;		
	}
	return 0;
}
