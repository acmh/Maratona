#include <cstdio>
#include <cstdlib>

using namespace std;

int a,b,c,d,e;

int main(){
	while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &e) > 0 && a){
		int x = 180 - c - e;
		int g = 180 - x;
		int h = 180 - g - d;
		printf("%d\n", 180 - g - h);
		
	}
	return 0;
}
