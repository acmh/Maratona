#include <cstdio>
#include <cstdlib>

using namespace std;

long long a,b;

int fib[310];
long long sum[310] = {0};

void teste(){
	//long long f,f1,aux;
	//f = 0;
	//f1 = 1;
	
	//long long len = 300;
	/*do{
		len++;
		aux = f;
		f = f1 % 100;
		f1 = (f%100 + aux%100)%100;
		//printf("F %lld\n", f);
		printf("F1 %lld\n", f1);
	}while(f1 != 0 || f != 1);*/
	
	fib[0] = 0;
	fib[1] = 1;
	sum[1] += fib[1];
	for(int i = 2; i < 305; i++){
		fib[i] = (fib[i - 1]%100 + fib[i - 2]%100)%100;
		sum[i] = sum[i- 1] + fib[i];
	}
	printf("%lld\n", sum[300]);
}	

long long solve(long long n){
	if(n < 301) return sum[n];
	long long ans = 0;
	long long temp = n/300;
	ans += sum[300]*temp;
	ans += sum[n%300];
	return ans;
}

int main(){
	int NC; scanf("%d", &NC);	
	teste();

	while(NC-->0){
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", solve(b) - solve(a - 1));
			
	}
	return 0;
}
