

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int grid[29][201];
int R, C, Z, F;
vector<int> inc[40];
char op[5], sin[5];
int tam;

bool process(int fil, int sz){
	/*printf("INIT %d %d %d %d\n", fil, inc[fil][sz], sz, tam);
   	for(int i = 0; i < 2*C; i++) printf("%d ", grid[fil][i]);
    printf("\n\n");*/
    bool flag = true;
    bool flag2 = true;
    if(sz >= tam){
    	//printf("Entrei\n");
        return true;
    }
    
    int l = inc[fil][sz]*2 - 2, r = inc[fil][sz]*2 - 1;
    
    //printf("L %d R %d\n\n", l, r);

    if(l == 0 || l == 2*C - 2){
    	//printf("A\n");
    	if(grid[fil][l] == 1 || grid[fil][l] == -1) flag2 = false;
    	else{
    		//printf("A1\n");
    		grid[fil][l] = 1;
    		flag2 = flag2 & process(fil, sz + 1);
    		grid[fil][l] = 0;
    	}	
    }else{
    	//printf("B\n");
    
    	if(grid[fil][l] == -1) flag2 = false;
    	if(grid[fil][l] == 1) flag2 = false;
    	
    	//printf("F %d\n", flag2);
    	if(flag2){
    		//printf("B1\n");
    		grid[fil][l] = 1;
    		flag2 = flag2 & process(fil, sz + 1);
    		grid[fil][l] = 0;
    	}
    }
    if(flag2) return true;
    //printf("FLAG2 = %d\n", flag2);
    if(r == 2*C - 1){
    	//printf("C\n");
    	if(grid[fil][r] == 1 || grid[fil][r] == -1) flag = false;
    	else{
    		grid[fil][r] = 1;
    		flag = flag & process(fil, sz + 1);
    		grid[fil][r] = 0;
    	}
    }else{
    	//printf("D\n");
    		
        if(grid[fil][r] == -1 || grid[fil][r + 1] == -1) flag = false;
    	if(grid[fil][r] == 1 || grid[fil][r + 1] == 1) flag = false;
    	
    	if(flag){
			grid[fil][r] = 1;
			if(grid[fil][r + 1] != -1) grid[fil][r + 1] = 1; 
			flag = flag & process(fil, sz + 1);
			grid[fil][r] = 0;
			if(grid[fil][r + 1] != -1) grid[fil][r + 1] = 0; 
		}
    }
    //printf("FLAGS %d %d %d\n", flag, flag2, flag | flag2);
    return flag | flag2;
}

void read(){
	int u,v;
	 for(int i = 0; i < Z; i++){
            scanf("%s %1s", op, sin);
            //printf("%s %s\n",op, sin);
            int num = 0;
            if(strlen(op) > 2){
				num = (op[2]-'0') + (op[1]-'0')*10;
			}else num = op[1] - '0';	
         
            
            u = op[0] - 'A';
            if(sin[0] == '-'){
                v = (num*2) - 2;
            }else{
                v = (num*2) - 1;
            }
           //	 printf("%d %d\n", u,v);
           	if(v % 2 != 0) grid[u][v + 1] = -1;
            grid[u][v] = -1;
        }
}

int main(){
    while(scanf("%d %d", &R, &C) > 0 && (R || C)){
    	//printf("UHAUIEHAUIEH %d %d\n", R, C);
        scanf("%d", &Z);
        //printf("Z %d\n", Z);
		for(int i = 0; i < R; i++){
			for(int j = 0; j < 2*C + 2; j++){
				grid[i][j] = 0;
			}
		}
        for(int i = 0; i < 29; i++) inc[i].clear();
       	read(); 
       int num = 0;
        scanf("%d", &F);
        //printf("%d\n",F);
        for(int i = 0; i < F; i++){
            scanf("%s", op);
            //printf("%c\n", op[0]);
           	//printf("KKK %s\n", op);
           	if(strlen(op) > 2){
				num = (op[2]-'0') + (op[1]-'0')*10;
			}else num = op[1] - '0';	
            inc[op[0] - 'A'].push_back(num);
        }
        bool flag = true;
        for(int i = 0; i < R; i++){
            tam = inc[i].size();
            //printf("TAM %d\n", tam);
            if(tam > 0){   
            	sort(inc[i].begin(), inc[i].end());
            	//for(int j = 0; j < tam; j++) printf("%d ", inc[i][j]);
            	//printf("\n");
                if(!process(i,0)){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


