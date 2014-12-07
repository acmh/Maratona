#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#define MAXN 50005
using namespace std;

int N, M;
int vetRep[MAXN];

int findSet(int x){
	if(vetRep[x] != x) return vetRep[x] = findSet(vetRep[x]);
	return x;
}

void make_set(){
	for(int i = 0; i < N + 3; i++){
		vetRep[i] = i; 
	}
}

void uniao(int x, int y){
	x = findSet(x);
	y = findSet(y);
	vetRep[x] = y;
}


int main(){
	int casen = 1;
	while(scanf("%d %d", &N, &M) > 0 && (N || M)){
		make_set();
		int a,b;
		for(int i = 0; i < M; i++){
			scanf("%d %d", &a, &b);
			uniao(a,b);
		}
		map<int,int> ans;
		ans.clear();
		int cnt = 0;
		for(int i = 1; i <= N; i++){
			int h = findSet(i);
			if(ans.find(h) == ans.end()){
				ans[h] = cnt;
				cnt++;
			}
		}
		
		printf("Case %d: %d\n",casen++, cnt);
	}
	return 0;
}
