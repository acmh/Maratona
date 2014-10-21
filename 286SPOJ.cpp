#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 105
#define INF 0x3f3f3f3f

using namespace std;

int cost[MAXN][MAXN];
int N, max_match;
int lx[MAXN], ly[MAXN];
bool S[MAXN], T[MAXN];
int slack[MAXN];            
int slackx[MAXN];
int prev[MAXN];             
int xy[MAXN];
int yx[MAXN];               

void init_labels(){
	memset(ly, 0, sizeof(ly));
	memset(lx, 0, sizeof(lx));
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++)
		lx[i] = max(lx[i],cost[i][j]);
	}
}

void add_to_tree(int x, int prevx){
    S[x] = true;                    
    prev[x] = prevx;                
    for (int y = 0; y < N; y++){    
        if (lx[x] + ly[y] - cost[x][y] < slack[y]){
            slack[y] = lx[x] + ly[y] - cost[x][y];
            slackx[y] = x;
        }
    }
}

void update_labels(){
    int x, y, delta = INF;             //init delta as infinity
    for (y = 0; y < N; y++)            //calculate delta using slack
        if (!T[y])
            delta = min(delta, slack[y]);
    for (x = 0; x < N; x++)            //update X labels
        if (S[x]) lx[x] -= delta;
    for (y = 0; y < N; y++)            //update Y labels
        if (T[y]) ly[y] += delta;
    for (y = 0; y < N; y++)            //update slack array
        if (!T[y])
            slack[y] -= delta;
}

void augment(){
	if(max_match == N) return;
	int x,y,root;
	int q[MAXN], wr = 0, rd = 0;
	memset(S, false, sizeof(S));
	memset(T, false, sizeof(T));
	memset(prev,-1, sizeof(prev));
	
	for(x = 0; x < N; x++){
		if(xy[x] == -1){
			q[wr++] = root = x;
			prev[x] = -2;
			S[x] = true;
			break;
		}
	}
	for(y = 0; y < N; y++){
		slack[y] = lx[root] + ly[y]  - cost[root][y];
		slackx[y] = root;
	}
    while (true){
        while (rd < wr){
            x = q[rd++];
            for (y = 0; y < N; y++)
                if (cost[x][y] == lx[x] + ly[y] &&  !T[y])
                {
                    if (yx[y] == -1) break;
                    T[y] = true;
                    q[wr++] = yx[y];
                    add_to_tree(yx[y], x);
                }
            if (y < N) break;
        }
        if (y < N) break;
        update_labels();
        wr = rd = 0;                
        for (y = 0; y < N; y++)        
            if (!T[y] &&  slack[y] == 0){
                if (yx[y] == -1){
                    x = slackx[y];
                    break;
                }
                else{
                    T[y] = true;
                    if (!S[yx[y]])    
                    {
                        q[wr++] = yx[y];
                        add_to_tree(yx[y], slackx[y]);
                    }
                }
            }
        if (y < N) break;
    }
    if (y < N){
        max_match++;
        for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty)
        {
            ty = xy[cx];
            yx[cy] = cx;
            xy[cx] = cy;
        }
        augment();
    }
}
	
int hungarian(){
    int ret = 0;                      
    max_match = 0;                    
    memset(xy, -1, sizeof(xy));    
    memset(yx, -1, sizeof(yx));
    init_labels();                    
    augment();                        
    for (int x = 0; x < N; x++)       
        ret += cost[x][xy[x]];
    return ret;
}



int main(){
	int NC; scanf("%d", &NC);
	while(NC-->0){
		int A, B;
		scanf("%d %d", &A, &B);
		N = A + B;
		int a,b,c;
		memset(cost, 0, sizeof(cost));
		while(scanf("%d %d %d", &a, &b, &c) && (a || b || c)){
			cost[a - 1][b - 1] = c;		
		}
		printf("%d\n", hungarian());
	}			
	return 0;
}
