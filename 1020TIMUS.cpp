#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define PI acos(-1)
#define EPS 10e-9
using namespace std;

double xc,yc;

typedef struct point{
	double x,y;
	point(){}
	point(double X, double Y) : x(X), y(Y){}
	bool operator<(const struct point &lhs)const{
		return atan2(yc - y,xc - x) - atan2(yc - lhs.y,xc - lhs.x) < 0.0;
	}
}P;

int N;
double R;

P ps[105];

double dist(P a, P b){
	return hypot(a.x - b.x, a.y - b.y);
}

double process(){
	double ans = 0;
	for(int i = 0; i < N - 1; i++){
		ans += dist(ps[i], ps[i + 1]);
	}
	ans += dist(ps[0], ps[N - 1]);
	double DN = (double)N;
	ans += 2*PI*R;
	return ans;
}

int main(){
	while(scanf("%d %lf", &N, &R) > 0){
		for(int i = 0; i < N; i++){
			scanf("%lf %lf", &ps[i].x, &ps[i].y);			
			xc += ps[i].x;
			yc += ps[i].y;			
		}
		xc /=(double) N; yc /= (double) N;
		sort(ps, ps + N);
		//for(int i = 0; i < N; i++) printf("%lf %lf\n", ps[i].x, ps[i].y);
		if(N == 1) printf("0.00\n");
		else printf("%.2lf\n", process());
	}	
	return 0;
}
