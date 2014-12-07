#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N;

int ha,ma,hc,mc;
int qtd;
int sum;
int A,B;

int main(){
	while(scanf("%d", &N) > 0){
		qtd = 0;
		sum = 0;
		//printf("A\n");
		for(int i = 0; i < N; i++){
			scanf("%d %d %d %d", &hc, &mc, &ha, &ma);
			//printf("B\n");
			//printf("%d %d %d %d\n", hc, mc, ha, ma);
			//printf("C\n");
			
			A = (hc*60) + mc;
			B = (ha*60) + ma;
			
			//printf("B - A %d\n", B - A);
			
			if(B-A > 0){
				sum += B - A;
		
			}
			//printf("QTD %d\n", qtd);
			//printf("D\n");
			
		}
		printf("%d\n", (int)(sum/N));
		
	}
	return 0;
}
