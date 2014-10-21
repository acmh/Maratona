#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int N, P, Q;
int A[62505],B[62505];
int aparece[62505];
int L[62505];
int sz = 0;
int dp[62505];


void read(){
	sz = 0;
	scanf("%d %d %d", &N, &P, &Q);
	++P;++Q;
	for(int i = 0; i <= P + 2; i++){
		aparece[i] = 0;
	}
	for(int i = 1; i <= P; i++){
		scanf("%d", &A[i]);
		aparece[A[i]] = i;
	}	
	for(int i = 1; i <= Q; i++){
		scanf("%d", &B[i]);
		if(aparece[B[i]] != 0){
			L[sz] = aparece[B[i]];
			sz++;	
		}	
	}
}


int process(){
	int size = 0;
	for(int i = 0; i < sz; i++){
		int k = lower_bound(dp, dp + size,L[i]) - dp;
		if(k == size) size++;
		dp[k] = L[i];
	}
	return size;
}

int main(){
	int NC; scanf("%d", &NC);
		int casen = 1;
	while(NC-->0){
		read();
		printf("Case %d: %d\n",casen++,process());		
	}
	return 0;
}
