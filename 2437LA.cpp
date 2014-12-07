#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

int grid[105][105];
bool mark[105][105];
int dx[4] ={1,-1,0,0};
int dy[4] ={0,0,1,-1};
int N,M;

vector<pair<int, int> > s;

typedef struct no{
	int x,y,c;
	no(){}
	no(int X, int Y, int C) : x(X), y(Y), c(C){}
}No;

int vmax = -1,vmin = 3000005;
int xmax,ymax,xmin,ymin;

bool isValid(int x, int y, int sum){
	return (x >= 0 && x < N) && (y >= 0 && y < M) && grid[x][y] == sum;
}

int bfs(int inc){
	No top;
	queue<No> que;
	int tam = s.size();
	
	for(int i = 0; i < tam; i++){
		que.push(No(s[i].first, s[i].second, vmin));
	}
	for(int i = 0; i < N + 3; i++) for(int j = 0; j < M + 3; j++) mark[i][j] = false;
	
	while(!que.empty()){
		top = que.front();
		que.pop();	
		if(top.c == vmax){
			return vmax;
		}
		if(mark[top.x][top.y] == true) continue;
		mark[top.x][top.y] = true;
		for(int i = 0; i < 4; i++){
			int nx = top.x + dx[i]; 
			int ny = top.y + dy[i];
			int nc = top.c + inc;
			if(isValid(nx,ny,nc)){
				que.push(No(nx,ny,nc));
			}
		}
	}
	
	
}

int main(){
	while(scanf("%d %d", &N, &M) > 0 && N > 0 && M > 0){
		s.clear();
		vmax = -30000005;
		vmin = 30000005;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				scanf("%d",&grid[i][j]);
				if(vmax < grid[i][j]){ vmax = grid[i][j];}
				if(vmin >= grid[i][j]){ vmin = grid[i][j]; }
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(vmin == grid[i][j]) s.push_back(make_pair(i,j));
			}
		}
		//printf("S %d\n",(int)s.size());
		
		bool flag = false;
		for(int i = 1; i <= vmax && !flag; i++){
			int val = bfs(i);
			if(val == vmax){
				flag = true;
				break;
			}
		}
		
		if(flag) printf("At least one pattern exists.\n");
		else printf("No pattern can be found.\n");
	}
	return 0;
}		
