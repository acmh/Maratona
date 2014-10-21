#include <cstdio>
#include <cstdlib>
#include <cmath>
#define sqr(x) (x)*(x) 
using namespace std;

double x2,y2,x3,y3,x4,y4;
double Ax, Ay, Bx, By, Cx,Cy;

double xc,yc;

int main(){
	while(scanf("%lf %lf %lf %lf %lf %lf", &x2,&y2,&x3,&y3,&x4,&y4) > 0){
		if(x2 == -1.0 && y2 == -1.0 && x3 == -1.0 && y3 == -1.0 && x4 == -1.0 && y4 == -1.0) break;
		
		/*Pontos que estao na circunferencia*/
		Ax = (x2 + x3)/2.0; Ay = (y2 + y3)/2.0;
		Bx = (x2 + x4)/2.0; By = (y2 + y4)/2.0;
		Cx = (x4 + x3)/2.0; Cy = (y4 + y3)/2.0;
		
		/*Pontos de teste*/
		//Ax = 5; Ay = 5;
		//Bx = 6; By = -2;
		//Cx = 2; Cy = -4;
		//O centro tem que ser 2,1
		
		double mr = (By - Ay)/(Bx - Ax);
		//printf("MR %lf\n", mr);
		double mt = (Cy - By)/(Cx - Bx);
		//printf("MT %lf\n", mt);
		
		xc = ((mr*mt*(Cy - Ay)) + (mr*(Bx + Cx)) - (mt*(Ax + Bx)))/(2*(mr - mt));
		
		
		
		
		if(mt != 0.0){
			double A = (-1/mt);
			//printf("A %lf\n", A);
			double B = xc - (Bx + Cx)/2;
			//printf("B %lf\n", B);
			double C = (By + Cy)/2;
			//printf("C %lf\n", C);
			yc = A*B + C;
		}else{
			double A = (-1/mr);
			//printf("A %lf\n", A);
			double B = xc - (Bx + Ax)/2;
			//printf("B %lf\n", B);
			double C = (By + Ay)/2;
			//printf("C %lf\n", C);
			yc = A*B + C;
		}
		//printf("%lf\n", yc);
		
		
		//printf("RES %lf %lf\n", Ax - xc, sqr(Ax-xc));		
		double r = sqrt(sqr(Ax - xc) + sqr(Ay - yc));
		printf("%0.6lf %0.6lf %0.6lf\n", xc, yc,r);
		
	}
	
	
	return 0;
}
