#include <bits/stdc++.h>
#define cl(a,b) memset((a),(b),sizeof(a))
#define fr(a,b,c) for(int a=b;a<c;a++)
#define rp(a,b) fr(a,0,b)
#define db(x) cerr << #x " == " << x << endl;
#define _ <<", "<<
#define pb push_back
#define MAXN 400
#define INF 0x3f3f3f3f

using namespace std;

int cap[MAXN][MAXN];
int layer[MAXN];
int magic[MAXN];
vector<int> inc[MAXN];
int b;
int N;

bool bfs(int s, int t){
    queue<int> que;
    memset(layer, 0, sizeof(layer));
    que.push(s);
    layer[s] = 1;
    while(!que.empty()){
        int top = que.front(); que.pop();
        //printf("Top %d\n", top);
        for (int i = 0; i < (int) inc[top].size(); i++){
            int v = inc[top][i];
            if (cap[top][v] > 0 && layer[v] == 0){
                que.push(v);
                    layer[v] = layer[top] + 1;
            }
        }
    }
    return layer[t] != 0;
}


int dinic(int s, int t, int bf){
    //printf("S %d\n", s);
    int auxf = 0;
    //Cheguei no sink, retorne o blocking flow
    if (s == t) return bf;
    for (int &i = magic[s]; i < (int) inc[s].size(); i++){
        int v = inc[s][i];
        //printf("V %d\n", v);
        //Eh uma aresta elegivel? Se sim...
        if (layer[v] == layer[s] + 1 && cap[s][v] > 0){
            //Qual a menor quantidade de fluxo que eu posso passar?
            auxf = dinic(v, t, (bf < cap[s][v]) ? bf : cap[s][v]);
               
            //printf("ATUAL %d AUXF %d\n", s, auxf);
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
    //Divide em camadas
    while(bfs(0,N-1)){
        memset(magic, 0, sizeof(magic));
        do{
            ans = dinic(0,N-1, INF);
            mf += ans;
        }while(ans > 0);
    }
    return mf;
}

void read(){
	 	scanf("%d", &N);
	 	fr(i,0,N+3){
	 		fr(j,0,N+3){
	 			cap[i][j] = 0;
	 		}
	 		inc[i].clear();
	 	}
	 	
       	int sz,v;   
        for (int i = 0; i < N - 1; i++){
    		scanf("%d",&sz);
    		for(int j = 0; j < sz; j++){
    			scanf("%d", &v);
    			//printf("ADJ %d %d\n", i,v);
				v--;
    			//printf("uaheiuha\n");
    			inc[i].pb(v);
    			inc[v].pb(i);
    			if(v == N - 1 || i == 0){
    				cap[i][v] = 1;
    			}else{
    				cap[i][v] = INF;
    			}
    		}  		
        }
}

int main(){
    int numc; scanf("%d", &numc);
    while(numc-->0){
       read();
       printf("%d\n",maxFlow()); 
    }
    return 0;       
}	
