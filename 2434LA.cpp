#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

typedef struct pessoa{
	char nome[20];
	int c;
	pessoa();
	pessoa(char NOME[20], int amnt){
		strcpy(this->nome, NOME);
		this->c = amnt;
	}
	bool operator<(const struct pessoa &lhs)const{
		return c < lhs.c;
	}	
}P;

int a,b,c;
vector<P> v;
char str[20];
int N;

int main(){
	while(scanf("%d", &N) > 0 && N > 0){
		v.clear();
		for(int i = 0; i < N; i++){
			scanf("%s %d %d %d", str, &a, &b, &c);
			v.push_back(P(str,(5*a) + (10*b) + (20*c)));
		}
		
		sort(v.begin(), v.end());
		
		bool flag = false;
		for(int i = 1; i < N; i++){
			if(v[i].c != v[0].c){flag = true; break;}
			}
		
		if(flag){
			printf("%s has most, %s has least money.\n", v[N - 1].nome, v[0].nome);
		}else{
			printf("All have the same amount.\n");
		}
	}
	return 0;
}
