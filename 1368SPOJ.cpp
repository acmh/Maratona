#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <string>
#define MAXN 1005

using namespace std;

map<string, int> myMap;
map<int, string> myMap2;
vector<int> ts;
vector<int> inc[MAXN];
int N;
string nome;
int idx;
int indegree[MAXN];


bool bfs(){
	queue<int> q;
	int top;
	for(int i = 0; i < N; i++){
		if(indegree[i] == 0) q.push(i);
	}
	while(!q.empty()){
		top = q.front(); q.pop();
		ts.push_back(top);
		int tam = inc[top].size();
		for(int i = 0; i < tam; i++){
			int v = inc[top][i];
			indegree[v]--;
			if(indegree[v] == 0){
				q.push(v);
			}
		}
	}
	return (ts.size() == N);
}

int main(){
	int casen = 1;
	while(cin >> N && N){
		for(int i = 0; i < N + 3; i++){
			inc[i].clear();
			indegree[i] = 0;
		}
		ts.clear();
		myMap.clear();
		myMap2.clear();
		idx = 0;
		for(int i = 0; i < N; i++){
			cin >> nome;
			if(myMap.find(nome) == myMap.end()){
				myMap[nome] = idx;
				myMap2[idx] = nome;
				idx++;
			}
		}
		int aux;
		string nome2;
		for(int i = 0; i < N; i++){
			cin >> nome >> aux;
			for(int i = 0; i < aux; i++){
				cin >> nome2;
				int a = myMap[nome];
				int b = myMap[nome2];
				inc[b].push_back(a);
				indegree[a]++;
			}
		}
	
		
		cout << "Teste " << casen++ << endl;
		bool flag = bfs();
		int tam = ts.size();
		if(!flag){
			printf("impossivel");
		}else{
			cout << myMap2[ts[0]];
			for(int i = 1; i < tam; i++){
				cout << " " << myMap2[ts[i]];
			}
		}
		cout << endl << endl;
			
	}
	return 0;
}

