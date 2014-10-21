#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

ll s[3];

bool isValid(){
	if(s[0] <= 0 || s[1] <= 0 || s[2] <= 0) return false;
	else if(s[2] > s[0] + s[1]){
		return false;
	}
	return true;
}



int main(){
	int NC; scanf("%d", &NC);
	int casen = 1;
	while(NC-->0){
		printf("Case %d: ",casen++);
		scanf("%lld %lld %lld", &s[0], &s[1], &s[2]);
		sort(s,s+3);
		//printf("V %d %d %d\n",s[0],s[1],s[2]);
		if(!isValid()){
			printf("Invalid\n");
		}else if(s[0] == s[1] && s[2] == s[1]){
	 		printf("Equilateral\n");
		}else if(s[0] == s[1] || s[1] == s[2] || s[0] == s[2]){
			printf("Isosceles\n");
		}else{
			printf("Scalene\n");
		}
	}
	return 0;
}
