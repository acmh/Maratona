#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAXN 55
using namespace std;

typedef struct sector{
	int p,b,x,y;
	sector(){}
	sector(int P, int B, int X, int Y) : p(P), b(B), x(X), y(Y){}
	bool operator<(const struct sector &lhs)const{
		if(x == lhs.x) return y < lhs.y; 
		return x < lhs.x;
	}
}S;

int N;
char grid[MAXN][MAXN];
int mark[MAXN][MAXN];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int setor = 6;	
vector<S> ans;


bool isValid(int x, int y){
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}

void findGroup(int x, int y, char l, int setor){
	if(mark[x][y] == -1){
		mark[x][y] = setor;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(isValid(nx, ny) && (grid[nx][ny] == l || grid[nx][ny] == '*') && mark[nx][ny] == -1){
				findGroup(nx,ny, l, setor);
			}
		}	
	}
}


void dfs2(int x,int y, S& s, int setor){
	if(mark[x][y] == -1){

		mark[x][y] = setor;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				printf("%d ", mark[i][j]);
			}
			printf("\n");
		}printf("\n\n");
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(isValid(nx, ny) && grid[nx][ny] != '.'){
				if(grid[nx][ny] == 'P' && mark[nx][ny] == -1){
					//printf("Entrei\n");
					findGroup(nx, ny,'P', setor);
					s.p++;
				}else if(grid[nx][ny] == 'B' && mark[nx][ny] == -1){
					findGroup(nx, ny,'B', setor);
					s.b++;
				}else{
					if(nx <= s.x && ny <= s.y){
						s.x = nx;
						s.y = ny;
					}
				}
				dfs2(nx,ny,s, setor);
			}
		}
	}
}


void dfs(int x, int y){
	if(mark[x][y] == -1){
		if((grid[x][y] == '*' || grid[x][y] == 'P' || grid[x][y] == 'B') && mark[x][y] == -1){
			S sec2; sec2.p = 0; sec2.b = 0; sec2.x = x; sec2.y = y;
			dfs2(x,y, sec2, setor);
			ans.push_back(sec2);
			setor++;
		}
		mark[x][y] = -3;
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(isValid(nx,ny)){
				if((grid[nx][ny] == '*' || grid[nx][ny] == 'P' || grid[nx][ny] == 'B') && mark[nx][ny] == -1){
					//printf("Entrei %d %d\n",nx,ny);
					S sec; sec.p = 0; sec.b = 0; sec.x = nx; sec.y = ny;
					dfs2(nx,ny, sec, setor);
					ans.push_back(sec);
					setor++;
				}
			}
		}	
	}
}

int main(){
	while(scanf("%d", &N) > 0 && N > 0){
		int u;
		for(int i = 0; i < N; i++){
			scanf("%s", grid[i]);
		}
		
		for(int i = 0; i < N + 3; i++){
			for(int j = 0; j < N + 3; j++){
				mark[i][j] = -1;
			}
		}
		ans.clear();
		for(int i = 0; i < N + 3; i++){
			for(int j = 0; j < N + 3; j++){
				if(mark[i][j] == -1){
					dfs(i,j);
				}
			}
		}
		sort(ans.begin(), ans.end());
		int tam = ans.size();
		int res = 0;
		for(int i = 0; i < tam; i++){
			printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n", i + 1, ans[i].b, ans[i].p);
			if(ans[i].p != 0 && ans[i].b != 0) res++;
		}
		if(tam != 0) printf("Total %d group(s) are in fighting position.\n\n",res);
		else printf("\n\n");
	}
	return 0;
}	
