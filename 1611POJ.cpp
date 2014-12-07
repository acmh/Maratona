#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#define MAXN 30005
using namespace std;

int N,M,K;

int vetRep[MAXN];
int rep;

int findSet(int x){
	if(vetRep[x] != x) return vetRep[x] = findSet(vetRep[x]);
	return x;
}

int main(){
	while(scanf("%d %d", &N, &M) > 0 && (N||M)){
		//Inicia os conjuntos disjuntos
		for(int i = 0; i < N + 3; i++){
			vetRep[i] = i;
		}
		
		int A;
		vector<int> groups;
		for(int i = 0; i < M; i++){
			groups.clear();
			scanf("%d", &K);
			for(int j = 0; j < K; j++){
				scanf("%d", &A);
				groups.push_back(A);
			}
			sort(groups.begin(), groups.end());
			if(K > 1) rep = findSet(groups[0]);
			for(int j = 1; j < K; j++){
				int b = findSet(groups[j]);
				if(rep > b) swap(rep,b);
				if(rep != b) vetRep[b] = rep;
			}
		}
		
		
		int h;
		int ans = 0;
		for(int i = 0; i < N; i++){
			h = findSet(i);
			if(h == 0) ans++;
			
		}
		printf("%d\n", ans);
	}	
	return 0;
}
