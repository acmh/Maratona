	#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int N,R,C,K;
int grid[105][105][2];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int mark[105][105];
int passo = 1;
void print(int idx){
	printf("------------\n");
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			printf("%d ", grid[i][j][idx]);
		}
		printf("\n");
	}
	printf("------------\n");
}

bool isValid(int x, int y){
	return (x >= 0 && x < R) && (y >= 0 && y < C);
}

int main(){
	while(scanf("%d %d %d %d", &N, &R, &C, &K) > 0){
		memset(mark, 0, sizeof(mark));
		passo = 1;
		if(N == 0 && R == 0 && C == 0 && K == 0){
			break;
		}
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				scanf("%d", &grid[i][j][0]);
			}
		}
		
		int nx;
		int ny; 
		int a;
		int b;
		
		
		
		for(int i = 0; i < K; i++){
			a = i%2;
			b = !a;
			//print(0);
			for(int j = 0; j < R; j++){
				for(int k = 0; k < C; k++){
					//bool flag = false;
					for(int t = 0; t < 4; t++){
						nx = j + dx[t];
						ny = k + dy[t];
						if(isValid(nx,ny)){
							if(((grid[j][k][a] + 1)%N) == grid[nx][ny][a]){	
								//printf("LOG %d %d ---> %d %d V %d A %d B %d\n", j,k,nx,ny, grid[j][k][a], a, b);
								mark[nx][ny] = passo;
								grid[nx][ny][b] = grid[j][k][a];
							}
						}
					}
					if(mark[j][k] != passo){
						//printf("E %d %d\n", j, k);
							grid[j][k][b] = grid[j][k][a];
					}
				}	
			}
			passo++;
			//print(1);
		}
		a = K%2;
		for(int i = 0; i < R; i++){
			if(i > 0) printf("\n");
			for(int j = 0; j < C; j++){
				if(j > 0) printf(" ");
				printf("%d", grid[i][j][a]);
			}
		}
		printf("\n");		
		
	}
	return 0;
}
