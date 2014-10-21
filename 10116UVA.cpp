#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 15
using namespace std;

typedef struct no{
	int x,y,c,px,py;
	no(){}
	no(int X, int Y, int C, int PX, int PY) :  x(X), y(Y), c(C), px(PX), py(PY){}
}No;

int N, M, C;
char grid[15][15];
bool mark[MAXN][MAXN];
int dist[MAXN][MAXN];
//char p[MAXN][MAXN];

void read(){
	//printf("HUE %d %d %d\n", N, M, C);
	for(int i = 0; i < N; i++){
		scanf("%s", grid[i]);
		//printf("%s\n",grid[i]);
	}
}

bool isValid(int x, int y){
	//printf("asuidhasiudhas %d %d\n", x, y);
	return (x >= 0 && x < N) && (y >= 0 && y < M);
}

void process(){
	memset(mark,false, sizeof(mark));
	memset(dist, 0, sizeof(dist));
	No top;
	queue<No> pq;
	pq.push(No(0,C - 1,0,0,C - 1));
	while(!pq.empty()){
		top = pq.front(); pq.pop();
		//printf("L '%c' X %d Y %d\n",grid[top.x][top.y], top.x, top.y);
		mark[top.x][top.y] = true;
		int nx,ny;
		if(grid[top.x][top.y] == 'N'){
			nx = top.x - 1; 
			ny = top.y;
			if(!isValid(nx,ny)){
				printf("%d step(s) to exit\n", top.c + 1);
				break;
			}
			if(mark[nx][ny] == true){
				printf("%d step(s) before a loop of %d step(s)\n",dist[nx][ny], top.c + 1 - dist[nx][ny]);
				break;
			}
			dist[nx][ny] = top.c + 1;
			//p[nx][ny] = grid[top.x][top.y];
			pq.push(No(nx,ny, top.c + 1, top.x,top.y));
		}else if(grid[top.x][top.y] == 'E'){
			nx = top.x; 
			ny = top.y + 1;
			if(!isValid(nx,ny)){
				printf("%d step(s) to exit\n", top.c + 1);
				break;
			}
			if(mark[nx][ny] == true){
				printf("%d step(s) before a loop of %d step(s)\n",dist[nx][ny], top.c + 1 - dist[nx][ny]);
				break;
			}
			dist[nx][ny] = top.c + 1;
			//p[nx][ny] = grid[top.x][top.y];
			pq.push(No(nx,ny, top.c + 1, top.x, top.y));
		}else if(grid[top.x][top.y] == 'W'){
			//printf("KKK\n");
			nx = top.x;
			ny = top.y - 1;
			//fprfintf("%d %d\n", top.x, top.y);
			if(!isValid(nx,ny)){
				printf("%d step(s) to exit\n", top.c + 1);
				break;
			}
			if(mark[nx][ny] == true){
				printf("%d step(s) before a loop of %d step(s)\n",dist[nx][ny], top.c + 1 - dist[nx][ny]);
				break;
			}
			dist[nx][ny] = top.c + 1;
			//p[nx][ny] = grid[top.x][top.y];
			pq.push(No(nx,ny, top.c + 1, top.x, top.y));
		}else{
			//printf("To aqui\n");
			nx = top.x + 1;
			ny = top.y;
			//printf("LL %d %d\n", nx, ny);
			if(!isValid(nx,ny)){
				printf("%d step(s) to exit\n", top.c + 1);
				break;
			}
			if(mark[nx][ny] == true){
				printf("%d step(s) before a loop of %d step(s)\n",dist[nx][ny], top.c + 1 - dist[nx][ny]);
				break;
			}
			dist[nx][ny] = top.c + 1;
			//p[nx][ny] = grid[top.x][top.y];
			pq.push(No(nx,ny, top.c + 1, top.x, top.y));
		}
	}
}

int main(){
	while(scanf("%d %d %d", &N, &M, &C) > 0 && (N || M || C)){
		//printf("INIT %d %d %d\n", N, M, C);
		read();
		process();	
	}	
	return 0;
}	
