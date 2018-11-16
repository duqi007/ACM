#include <iostream>
#include <cstring>
using namespace std;

int visit[10],a[10];
int n, m;
void dfs(int pos){
	if(pos == m){
		for(int i = 0; i < m ; i++){
			cout << a[i];
		}
		cout << endl;
		return ;
	}
	
	for(int i = 0; i < n ; i++){
		if(!visit[i]){
			visit[i] = 1;
			a[pos] = i +1;
			dfs(pos+1);
			visit[i]=0;
		}
	}
}
int main(){
	int N;
	cin >> N;
	while(N--){
		cin >> n >>m;
		memset(visit, 0, sizeof(visit));
		memset(a, 0, sizeof(a));
		dfs(0);
	}
	return 0;
} 
