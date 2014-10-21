#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define INF 1<<30
using namespace std;

int L, U, R;

vector<int> A;



bool viz[10000];
bool flag = false;

int rev (int number){
	int reve = 0;
	for( ; number!= 0 ; ){
      reve = reve * 10;
  	    reve = reve + number%10;
      number = number/10;
   	}
   	return reve;
}

int process(){
	queue<int> 
}

int main(){
	while(scanf("%d %d %d", &L, &U, &R) > 0){
		int a;
		A.clear();
		for(int i = 0; i < R; i++){
			scanf("%d", &a);
			A.push_back(a);
			//A.push_back(-a);
		}
		memset(viz, false, sizeof(viz));
		
	}
	return 0;
} 
