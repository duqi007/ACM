#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct Node{
	int a,b,c;
	int step;
	Node(){
		step = 0;
	}
};
int sta[3];
int Ends[3];
int Cur[3];
int visit[100][100][100];
int s;
void bfs(){
	queue<Node> q;
	s = -1;
	Node cur,node;
	node.a = sta[0];
	node.b = 0;
	node.c = 0;
	q.push(node);
	visit[node.a][node.b][node.c] = 1;
	while(!q.empty()){
		node = cur = q.front();
		q.pop();
		Cur[0] = cur.a;
		Cur[1] = cur.b;
		Cur[2] = cur.c;
		if(Cur[0] == Ends[0] && Cur[1] == Ends[1] && Cur[2] == Ends[2]){
			s = cur.step;
			break;
		}
		for(int i = 0; i < 3 ;i++){
			for(int j = 0; j < 3 ;j++){
				if(i != j && Cur[i] != 0 && Cur[j] != sta[j]){
					if(Cur[i] > sta[j]-Cur[j]){
						Cur[i] = Cur[i]-sta[j] + Cur[j];
						Cur[j] = sta[j];
					}else{
						Cur[j] = Cur[j] + Cur[i];
						Cur[i] = 0;
					}
					if(visit[Cur[0]][Cur[1]][Cur[2]] == 0){
						visit[Cur[0]][Cur[1]][Cur[2]] = 1;
						cur.step++;
						cur.a = Cur[0];cur.b = Cur[1];cur.c = Cur[2];
						q.push(cur);
					}
					cur = node;
					Cur[0] = cur.a;
					Cur[1] = cur.b;
					Cur[2] = cur.c;
				}
			}
		}
	}	
}

int main(){
	int N;
	cin >> N;
	while(N--){
		memset(sta, 0, sizeof(sta));
		memset(Ends, 0, sizeof(Ends));
		memset(Cur, 0, sizeof(Cur));
		memset(visit, 0, sizeof(visit));
		cin >> sta[0] >> sta[1] >> sta[2];
		cin >> Ends[0] >> Ends[1] >> Ends[2];
	    Cur[0]=sta[0];
		bfs();
		cout << s << endl;
	}
	return 0;
} 
