#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#define MAXN 115
#define MAXL 20
using namespace std;

typedef struct no{
	int x,y,z,t;
	no(){}
	no(int X, int Y, int Z, int T) : x(X), y(Y), z(Z), t(T){}
}No;

typedef struct dno{
	int x,y,z,s;
	dno(){}
	dno(int X, int Y, int Z, int S) : x(X), y(Y), z(Z), s(S){}
}Dno;

int L, W, H, N, S;

char grid[MAXL][MAXN][MAXN];
int mark[MAXL][MAXN][MAXN];
int mark2[MAXL][MAXN][MAXN];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int ex,ey,ez;
int sx,sy,sz;
//map<No, int> myMap;
vector<Dno> inc;
pair<int,int> ans[105];
int size = 1;
int idx;
int passo = 3;
int passo2 = 3;
int x,y,z,p;
int dp[105][10005];

bool isValid(int x, int y, int z){
	
	return (z >= 1 && z <= L) && (x >= 1 && x <= H) && (y >= 0 && y < W) && (grid[z][x][y] != 'X'); 
}

int process2(int x, int y, int z, int t){
	//printf("TOOO AQUI NO PROCESS 2\n\n");
	queue<No> que;
	No top;
	que.push(No(x,y,z,t));
	while(!que.empty()){
		top = que.front(); que.pop();
		//printf("G2 %c\n", grid[top.z][top.x][top.y]);
		//printf("C2 %d %d %d %d\n", top.z, top.x, top.y, top.t);
		if(grid[top.z][top.x][top.y] == 'U' && isValid(top.x, top.y, top.z + 1) && mark2[top.z + 1][top.x][top.y] != passo2){
			que.push(No(top.x,top.y,top.z + 1, top.t + 2));	
		}else if(grid[top.z][top.x][top.y] == 'D' && isValid(top.x, top.y, top.z - 1) && mark2[top.z - 1][top.x][top.y] != passo2){
			que.push(No(top.x,top.y,top.z - 1, top.t + 2));
		}
		if(grid[top.z][top.x][top.y] == 'S'){
			//printf("E consegui chegar em S\n");
			return top.t;
		}
		if(mark2[top.z][top.x][top.y] == passo2) continue;
		mark2[top.z][top.x][top.y] = passo2;
		for(int i = 0; i < 4; i++){
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			if(isValid(nx, ny, top.z)){
				que.push(No(nx,ny,top.z, top.t + 2));
			}
		}
	}
	return -1;
}

void printa(){
	for(int i = 1; i <= L; i++){
		for(int j = 1; j <= H; j++){
			printf("%s\n", grid[i][j]);
		}
		printf("\n");
	}
}


void process(){
	queue<No> que;
	No top;
	que.push(No(sx,sy,sz, 0));
	while(!que.empty()){
		top = que.front(); que.pop();
		//printf("G %c\n", grid[top.z][top.x][top.y]);
		//printf("C %d %d %d %d\n", top.z, top.x, top.y, top.t);
		if(grid[top.z][top.x][top.y] == 'U' && isValid(top.x, top.y, top.z + 1) && mark[top.z + 1][top.x][top.y] != passo){
			que.push(No(top.x,top.y,top.z + 1, top.t + 1));
		}else if(grid[top.z][top.x][top.y] == 'D' && isValid(top.x, top.y, top.z - 1) && mark[top.z - 1][top.x][top.y] != passo){
			que.push(No(top.x,top.y,top.z - 1, top.t + 1));
		}else if(grid[top.z][top.x][top.y] == 'V'){
			//int res = process2(top.x, top.y, top.z, top.t);
			
			ans[size] = make_pair(p, 3*top.t);
			size++;
			grid[top.z][top.x][top.y] = '.';
			passo2++;
			//printa();
		}
		
		if(mark[top.z][top.x][top.y] == passo) continue;
		//printf("MAAAAOEEE\n");
		mark[top.z][top.x][top.y] = passo;
		for(int i = 0; i < 4; i++){
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];
			//printf("NG %c\n", grid[top.z][nx][ny]);
			//printf("NC %d %d %d\n", nx, ny, top.z);
			if(isValid(nx, ny, top.z)){
				
				//printf("Nunca?\n");
				que.push(No(nx,ny,top.z, top.t + 1));
			}
		}
	}
}




int main(){
	memset(mark, 0, sizeof(mark));
	//memset(mark2, 0, sizeof(mark2));
	int NC; scanf("%d", &NC);
	while(NC-->0){
		//idx = 0;
		size = 1;
		scanf("%d %d %d %d %d", &L, &H, &W, &N, &S);
		for(int i = 1; i <= L; i++){
			for(int j = 1; j <= H; j++){
				scanf("%s", grid[i][j]);
			}
		}
		//printa();	
		for(int i = 1; i <= L; i++){
			for(int j = 1; j <= H; j++){
				for(int k = 0; k < W; k++){
					if(grid[i][j][k] == 'S'){
						sz = i;
						sx = j;
						sy = k;
					}
				}
			}
		}
		//printa();		
		for(int i = 0; i < N; i++){
			scanf("%d %d %d %d", &z, &x, &y, &p);
			
			//printa();
			//printf("******************************\n"); 
			grid[z][x][y] = 'V';
			printa();
			//printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
			process();
			passo++;
			grid[z][x][y] = '.';
			//inc.push_back(Dno(x,y,z,p));
			
			//myMap[No(x,y,z,0)] = idx;
			//myMap.insert(make_pair(No(x,y,z,0), idx);
			//idx++;
		}
		/*map<No, int> :: iterator it;
		for(it = myMap.begin(); it != myMap.end(); it++){
			printf(" kkk%d %d %d %d\n", it->first.z, it->first.x, it->first.y, it->second);
		}*/
		
		
		//passo++;
		
		//sint tam = ans.size();
		//printf("TAM %d\n", tam);
		
		
		size--;
		for(int i = 0; i <= S + 3; i++){
			dp[0][i] = 0;
		}
		
		for(int i = 0; i <= size + 3; i++){
			dp[i][0] = 0;
		}
		printf("S %d\n", size);
		for(int i = 1; i <= size; i++){
			printf("%d %d\n", ans[i].first, ans[i].second);
			for(int j = 0; j <= S; j++){
				if(j >= ans[i].second){
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ans[i].second] + ans[i].first);
				}else{
					dp[i][j] = dp[i - 1][j];
				}
			}	
		}
		printf("%d\n", dp[size][S]);		
	}
	return 0;
}
