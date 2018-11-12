#include <iostream>

using namespace std;

#define MAX 	100
int R, C, temp;
const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
struct node{
	int va, we;
};
node M[MAX][MAX];
int DFS(int cr, int cc){
	int r,c , max = 0;
	if(M[cr][cc].we)
		return M[cr][cc].we;
	for (int i = 0; i < 4; i++)
	{
		r = cr + dir[i][0]; c = cc +dir[i][1];
		if (r >= 0 && r < R && c >= 0 && c < C && M[r][c].va < M[cr][cc].va)
		{
			temp = DFS(r,c);
			if (temp > max)max = temp;
		}
	}
	M[cr][cc].we = max +1;
	return max+1;
}

int DFSTRAVERSE(){
	int max = 0;
	for(int i = 0; i < R ; i++){
		for(int j = 0; j < C ; j++){
			temp = DFS( i, j);
			if(temp > max)
				max = temp;
		}
	}
	return max;
} 

int main(){
	int N;
	cin >> N;
	while(N--){
		cin >> R >> C ;
		for(int i = 0; i < R ; i++){
			for(int j = 0; j < C ; j++){
				cin >> M[i][j].va;
				M[i][j].we = 0;
			}
		}		
		cout << DFSTRAVERSE() << endl;
	}
	return 0;
}
