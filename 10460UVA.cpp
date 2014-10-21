#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int I;
char str[30];
int SZ;
bool flag = false;
void process(int L, int R, int D, int IT,string s){
	//printf("IN %d %d %d %s\n", L, R, D, s.c_str());
	if(D == SZ && !(I >= L && I <= R)){
		return;
	}else if(D == SZ){
		string a; a.push_back(str[D - 1]);
		a += s;
		int l = L;
		int i = 0;
		while(l != I){
			swap(a[i],a[i + 1]);
			l++;
			i++;
		}
		flag = true;
		printf("%s\n", a.c_str());
	}
	else{
		//Ver se eh D ou D - 1
		string a; a.push_back(str[D - 1]);
		a += s;
		/*int l = 1;
		int r = R + 1;*/
		int l;
		int r;
		if(IT == 1){
			 l = 1;
			r = R + 1;
		}else{
			r = L*(a.size()+1);
			l = r - (a.size()+1) + 1;	
		}
		
		int tam = a.size();
		for(int i = 0; i < tam; i++){
			//printf("V %d %d %d %s\n", l, r, D, a.c_str());
			if(!flag){
				process(l,r, D+1,IT,a);			
				l = r + 1;
				r += D + 1;
				swap(a[i],a[i + 1]);
				IT++;
			}
		}
	}
	
}	


int main(){
	int NC; scanf("%d", &NC);
	while(NC-->0){
		scanf("%s", str);
		SZ = strlen(str);
		scanf("%d", &I);
		flag = false;
		string aux; aux.push_back(str[0]);
		process(1,2,2,1,aux);	
		
	}
	return 0;
}
