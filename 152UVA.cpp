#include <cstdio>
#include <cstdlib>
#include <alorithm>
#define MAXN 5005
using namespace std;

typedef struct point{
	double x,y,z;
	point(){}
	point(double X, double Y, double Z) : x(X), y(Y), z(Z){}
}P;

P pt[MAXN];
double x,y,z;
int cnt;

double dist(P a, P b){
	double A = a.x - b.x;
	A *= A;
	double B = a.y - b.y;
	B *= B;
	double C = a.z - b.z;
	C *= C;
	return sqrt(A+B+C);
}


int main(){
	cnt = 0;
	while(scanf("%lf %lf %lf", &x, &y, &z) > 0 && (x || y || z) ){
		pt[cnt].x = x;
		pt[cnt].y = y;
		pt[cnt].z = z;
		cnt++;
	}
	
	return 0;
}
