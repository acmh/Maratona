#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N,P;
int dir[4] = {1,1,2,2};

int idx;

int main(){	
	while(scanf("%d %d", &N, &P) > 0 && (N || P)){
		int i = 1;
		int x = N/2 + 1, y = N/2 + 1;
		dir[0] = 1;
		dir[1] = 1;
		dir[2] = 2;
		dir[3] = 2;
		int dx[4] = {1,0,-1,0};
		int dy[4] = {0,-1,0,1};
		while(i*i <= P){
			i+=2;
			dir[0] += 2;
			dir[1] += 2;
			dir[2] += 2;
			dir[3] += 2;
			//dir[4] += 2;
			x++; y++;
			//printf("PPP %d\n", i);
		}
		i-= 2;
		dir[0] -= 2;
		dir[1] -= 2;
		dir[2] -= 2;
		dir[3] -= 2;
		x--; y--;
		idx = i*i;
		//printf("%d %d %d\n", idx, x, y);
		//printf("%d\n", idx);
		//printf("VAL %d\n", dir[0]);
		int ptr = 0;
		int aux = dir[ptr] - 1;
		//printf("A %d\n", aux);
		while(idx != P){
			for(int j = aux; j < dir[ptr] && idx != P; j++){
				//printf("PTR %d DX %d DY %d\n", ptr, dx[ptr], dy[ptr]);
				//printf("X %d  Y %d\n", x, y);
				x = x + dx[ptr];
				y = y + dy[ptr];
				//printf("L %d %d\n", x, y);
				idx++;
			}
			//printf("%d %d\n", ptr, dir[ptr]);
			dir[ptr] += 2;
			ptr++;
			ptr %= 4;
			aux = 0;
		}
		
		
		printf("Line = %d, column = %d.\n", x, y);
	}
	return 0;
}
