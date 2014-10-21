#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef struct p{
	int x,y;
	p(){}
	p(int X, int Y) : x(X), y(Y){}
}P;

int x,y,x2,y2;

int main(){
	int xn,yn,xn1,yn1;
	scanf("%d %d %d %d", &x, &y, &x2, &y2);
	if(x == x2){
		xn = x + abs(y - y2);
		printf("%d %d %d %d\n",xn, y,xn,y2);
	}else if(y == y2){
		yn = y + abs(x - x2);
		printf("%d %d %d %d\n",x, yn,x2,yn);
	}else{
		xn = x2;
		yn = y;
		xn1 = x;
		yn1 = y2;
		if(abs(xn1 - xn) == abs(yn1 - yn)){
			printf("%d %d %d %d\n", xn,yn,xn1, yn1);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}	
