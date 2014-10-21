#include <cstdio>
#include <cstdlib>

using namespace std;

int vec[7];
bool mark[15];
int qtd[15];


int main(){
	//memset(mark,false, sizeof(mark));
	memset(qtd,-1, sizeof(qtd));
	for(int i = 0; i < 6; i++){
		scanf("%d", &vec[i]);
		qtd[vec[i]]++;
	}
	int mqz = 0;
	int idx = 0;
	int tc[3];
	for(int i = 0; i < 9; i++){
		if(qtd[i] > -1) mqz++;
		if(qtd[i] != 4){
			tc[idx] = i;
			idx++;	
		} 
	}
	
	if(mqz > 3 || mqz < 3) printf("Alien\n");
	else{
		if(tc[])		
	}
	
	return 0;
}
