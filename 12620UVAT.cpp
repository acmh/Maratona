	

    #include <cstdio>
    #include <cstdlib>
     
    using namespace std;
     
    long long a,b;
     
    int fib[310];
    long long sum[300] = {0};
     
    void teste(){
            //long long f,f1,aux;
            //f = 0;
            //f1 = 1;
           
            //long long len = 300;
            /*do{
                    len++;
                    aux = f;
                    f = f1 % 100;	
                    f1 = (f%100 + aux%100)%100;
                    //printf("F %lld\n", f);
                    printf("F1 %lld\n", f1);
            }while(f1 != 0 || f != 1);*/
           
            fib[0] = 0;
            fib[1] = 1;
            sum[1] += fib[1];
            for(int i = 2; i <= 300; i++){
                    fib[i] = (fib[i - 1]%100 + fib[i - 2]%100)%100;
                    sum[i] = sum[i - 1]  + fib[i];
            }
           
    }      
     
    int main(){
            int NC; scanf("%d", &NC);      
            teste();
     
            while(NC-->0){
                    scanf("%lld %lld", &a, &b);
                    if(a >= 1 && b <= 300){
                            //printf("Entrei\n");
                            printf("%lld\n", sum[b] - sum[a - 1]);
                    }else{
                            long long na = a % 300;
                            long long nb = b % 300;
                           
                            //printf("HUE %lld %lld\n", na, nb);
                            long long  A = 0,B = 0;
                            //for(long long i = na; i <= 300; i++){
                                    A = sum[300] - sum[na - 1];   
                             
                            //for(long long i = 1; i <= nb; i++){
                                    B = sum[nb];
                            
                            a += 300 - na;
                            b -= nb;
                          //  printf("%lld %lld\n", a, b);
                            //printf("%lld\n", sum);
                            long long val = (b-a)/300;
                            printf("%lld\n", A + B + val*sum[300]);
                    }
                           
            }
            return 0;
    }


