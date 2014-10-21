#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 10005
using namespace std;



int N;
bool mark[MAXN];
int pai[MAXN];
vector<int> inc[MAXN];
vector<int> road;
int dist[MAXN];

int bfs(int s){
	memset(dist,-1,sizeof(dist));
	queue<int> que;
	int top;
	int k =s;
	que.push(s);
	road.clear();
	dist[s] = 0;
	while(!que.empty()){
		top = que.front(); que.pop();
		int tam = inc[top].size();
		for(int i = 0; i < tam; i++){
			int v = inc[top][i];
			if(dist[v] == -1){
				dist[v] = dist[top] + 1;
				pai[v] = top;
				if(dist[v] > dist[k]){
					k = v;
				}
				que.push(v);
			}		
		}
	}
	int tmp = k;
	while(tmp != s){
		road.push_back(tmp);
		tmp = pai[tmp];
	}
	road.push_back(s);
	return k;
}



int main(){
	while(scanf("%d", &N) > 0){
		int u;
		for(int i = 0; i <= N + 3; i++){
			inc[i].clear();
		}
		
		for(int i = 2; i <= N; i++){
			scanf("%d", &u);
			inc[u].push_back(i);
			inc[i].push_back(u);	
		}
		bfs(bfs(1));
		
		int sz = road.size();
		
		if(sz & 1) printf("%d\n", road[sz/2]);
		else{
			printf("%d %d\n", min(road[sz/2],road[sz/2]-1), max(road[sz/2],road[sz/2]-1));
		}	
	}
	return 0;
}
