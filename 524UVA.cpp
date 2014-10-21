#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

int N;
bool isPrime[105];
int A[20];
map<string, int> ans;

void sieve(){
	memset(isPrime, true, sizeof(isPrime));
	int lim = sqrt(100);
	for(int i = 2; i <= lim; i++){
		if(isPrime[i] == true){
			for(int j = 2*i; j <= 100; j+=i){
				isPrime[j] = false;
			}
		}
	}
}


void process(int sz, int mask){
	//printf("I %d %d\n", sz, mask);
	//string aux;
	if(sz == N - 1){
		
		for(int i = 2; i <= N; i++){
			int t = mask & (1 << i);
			//printf("i %d SZ %d A %d IN %d\n",i,sz,A[sz - 1], A[0]);
			
			if(isPrime[A[sz- 1] + i] && isPrime[A[0] + i] && ( t== 0)){
				//printf("Olar\n");
				A[sz] = i;
				printf("%d", A[0]);
				for(int i = 1; i < N; i++){
					printf(" %d", A[i]);
				}
				printf("\n");							
			}	
		}	
		return;
	}
	//printf("A\n");
	for(int i = 2; i <= N; i++){
		int T = mask & (1<<i);
		if(isPrime[A[sz - 1] + i] && T == 0){
			A[sz] = i;
			process(sz + 1, mask |= (1 << i));
			mask &= ~(1<<i);
		}
	}
		
}


int main(){
	sieve();	
	isPrime[1] = false;
	//printf("A\n");
	int casen = 0;
	while(scanf("%d", &N) > 0){
		A[0] = 1;
		if(casen >= 1) printf("\n");
		casen++;
		printf("Case %d:\n", casen);
		//ans.clear();
		if(N == 1) printf("1\n");
		else process(1,1);	
	}
	
	return 0;
}	
