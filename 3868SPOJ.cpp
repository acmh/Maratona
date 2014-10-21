#include <bits/stdc++.h>
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define db(x) cerr << #x " == " << x << endl;
#define _ <<", "<<
#define pb push_back
#define MAXN 60
#define INF 0x3f3f3f3f

using namespace std;

int cap[MAXN][MAXN];
int layer[MAXN];
int magic[MAXN];

vector<int> inc[MAXN];
int b;
int s,t;
map<char,int> nds;
int N;

bool bfs(int s, int t){
	queue<int> que;
	memset(layer,0,sizeof(layer));
	que.push(s);
	layer[s] = 1;
	while(!que.empty()){
		int top = que.front(); que.pop();
		for(int i = 0; i < (int) inc[top].size(); i++){
			int v = inc[top][i];
			if(cap[top][v] > 0 && layer[v] == 0){
				que.push(v);
				layer[v] = layer[top] + 1;
			}
		}
	}
	return layer[t] != 0;
}

int dinic(int s, int t, int bf){
	int auxf = 0;
	if(s == t) return bf;
	for(int &i = magic[s]; i < (int) inc[s].size(); i++){
		int v = inc[s][i];
		if(layer[v] == layer[s] + 1 && cap[s][v] > 0){
			auxf = dinic(v,t,(bf < cap[s][v]) ? bf : cap[s][v]);
			if (auxf == 0) continue;
            cap[s][v] -= auxf;
            cap[v][s] += auxf;
            return auxf;
		}
	}
	return auxf;
}

int maxFlow(){
	int mf = 0;
	int ans;
	while(bfs(s,t)){
		memset(magic,0,sizeof(magic));
		do{
			ans = dinic(s,t,INF);
			mf += ans;
		}while(ans > 0);
	}
	return mf;
}

int main(){
	char h = 'A';
	fr(i,0,29){ 
		//printf("H %c\n", h);
		nds[h] = i + 1, h++;
		
	}
	h = 'a';
	fr(i,29,54){
		nds[h] = i + 1; h++;
	}
	
	
	s = nds['A']; t = nds['Z']; 
	//printf("%d %d\n", s,t);
	while(scanf("%d", &N) > 0){
		char u[3],v[3];
		int c;
		int a,b;
		memset(cap,0,sizeof(cap));
		for(int i = 0; i < 28; i++) inc[i].clear();
		fr(i,0,N){
			scanf("%1s %1s %d\n", u,v, &c);
			//printf("%s %s\n", u,v);
			a = nds[u[0]]; b = nds[v[0]];
			//printf("%d %d\n", a,b);
			cap[a][b] += c;
			inc[a].pb(b);
			//inc[b].pb(a);
		}
		printf("%d\n", maxFlow());
	}
	return 0;
}
