#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define PI 3.1415926535
#define EPS 10e-7
using namespace std;

double V, a, K;

double xMax;

int main(){
	while(scanf("%lf %lf %lf", &V, &a, &K) > 0){
		double ang = (a*PI)/180;
		xMax = ((V*V)*sin(2*ang))/10;
		//printf("%lf", xMax);
		double ans = 0;
		//printf("%lf %lf\n", xMax, EPS);
		while(xMax > EPS){
			//printf("Entrei\n");
			ans += xMax;
			xMax /= K;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}	
