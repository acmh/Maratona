#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define PI acos(-1)

using namespace std;

double L, R;

int main(){
	//printf("%lf\n", PI);
	//printf("%lf\n", M_PI);
	while(scanf("%lf %lf", &L, &R) > 0){
		if(R <= L/2.0){
			printf("%0.3lf\n", PI*R*R);
		}else if(R >= (L*sqrt(2.0))/2.0){
			printf("%0.3lf\n", L*L);
		}
		else{
			double NR = L/2.0;
			double ang = 2*acos(NR/R);
			double A = (R*R/2.0)*((ang) - sin(ang));
			printf("%0.3lf\n",PI*R*R - 4.0*A);
		}
	}
	return 0;
}
