#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int inc[105][105];
bool hasSoft[105];
bool mark[105];

typedef struct no{
	int t,c;
	no(){}
	no(int T, int C) : t(T), c(C){}
	bool operator<(const struct no &lhs)const{
		return c > lhs.c;
	}
}No;

int process(int s,int t){
	for(int i = 1; i <= N; i++) mark[i] = false;
	priority_queue<No> pq;
	No top;
	pq.push(No(s,1));
	while(!pq.empty()){
		top = pq.top(); pq.pop();
		//printf("TOP %d %d\n", top.t, top.c);
		if(top.t == t) return top.c;
		if(mark[top.t] == true) continue;
		mark[top.t] = true;
		for(int i = 1; i <= N; i++){
			//printf("OI\n");
			if(inc[top.t][i] == 1){
				if(hasSoft[i] == false){
					hasSoft[i] = true;
					pq.push(No(i, top.c + 1));
				}
				else{
					pq.push(No(i,top.c));	
				}
			}
		}	
	}
	return -1;
}

int main(){
	int casen = 1;
	while(scanf("%d %d", &N, &M) > 0 && (N||M)){
		for(int i = 1; i <= N + 2; i++){
			for(int j = 1; j <= N+2; j++){
				inc[i][j] = 0;
				
			}
		}
		int u,v;
		for(int i = 0; i < M; i++){
			scanf("%d %d",&u,&v);
			inc[u][v] = 1;
		}
		int ans = 0;
		for(int i = 1; i <= N + 2; i++) hasSoft[i] = false;
		hasSoft[1] = true;
		hasSoft[2] = true;
		ans = process(1,2);
		if(ans != -1){
			int ans2 = process(2,1);
			printf("Network %d\n", casen++);
			if (ans2 != -1){
				printf("Minimum number of nodes = %d\n\n", ans + ans2);
			}
			else{
				printf("Impossible\n\n");
			}
		}else{
			printf("Network %d\n", casen++);
			printf("Impossible\n\n");
		}	
					
	}
	return 0;
}	
