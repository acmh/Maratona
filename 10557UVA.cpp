#include <cstdio>
#include <queue>
using namespace std;
 
int Energy[101];
int toNxt[101][101];
 
bool SPFA(const int N);
 
int main()
{
int N;
while (scanf("%d", &N) && N != -1) {
for (int i = 1; i <= N; ++i) {
// 用toNxt[i][0]來存i能前往哪些點的數量
scanf("%d %d", &Energy[i], &toNxt[i][0]);
for (int j = 1; j <= toNxt[i][0]; ++j)
scanf("%d", &toNxt[i][j]);
}
 
if (SPFA(N))
puts("winnable");
else
puts("hopeless");
}
}
bool SPFA(const int N)
{
queue<int> Q;
int inQueue[101] = {0};
int Dis[101] = {0};
int Count = 0; // avoid infinite cycle
 
Dis[1] = 100, inQueue[1] = true;
Q.push(1);
 
while (!Q.empty()) {
int now = Q.front();
printf("%d %d\n", now, Dis[now]);
inQueue[now] = false;
Q.pop();
 
for (int i = 1; i <= toNxt[now][0]; ++i) {
int nxt = toNxt[now][i];
int tmp = Dis[now] + Energy[nxt];
if (tmp > Dis[nxt]) {
Dis[nxt] = tmp;
if (!inQueue[nxt]) {
Q.push(nxt);
inQueue[nxt] = true;
++Count;
}
}
 
}
if (Dis[N] > 0) return true;
if (Count > 1000000) return false;
}
return false;
}
