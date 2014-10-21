#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n,m;

int main(){
    scanf("%d %d", &n, &m);
    if(m > n){
        printf("%d\n",n);
    }else{
        int cnt = n;
        int aux = 0;
        int days = 0;
        while(1){
        	if(aux == m){
                cnt++;
                aux = 0;
            }
            if(cnt == 0) break;
            cnt--;
            aux++;
            days++;
            //printf("%d %d %d\n", days, aux, cnt);
        }
        printf("%d\n", days);
    }   
    return 0;
}
