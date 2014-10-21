#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int grid[8][8];
int row[8];


bool can(int r,int c){
	for(int i = 0; i < c; i++){
		if(row[i] == r || abs(row[i] - r) == abs(i - c)){
			return false;
		}
	}
	return true;
}

int process(int c){
	if(c == 8){
		int sum = 0; 
		for(int i = 0; i < 8; i++){
			sum += grid[row[i]][i];
		}
		return sum;
	}
	int ans = -1;
	for(int r = 0; r < 8; r++){
		if(can(r,c)){
			row[c] = r; ans = max(ans,process(c + 1));	
		}
	}
	return ans;
}

int main(){
	int numc; scanf("%d", &numc);
	while(numc-->0){
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				scanf("%d", &grid[i][j]);
			}
		}
		printf("%5d\n",process(0));
		
	}
	return 0;
}
