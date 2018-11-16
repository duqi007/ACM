#include <iostream>
#include <cstring>

using namespace std;
int max(int a,int b ){
	return a>b?a:b;
}

int main(){
	int N;
	cin >> N;
	int tr[N][N], dp[N][N], m;
	memset(dp, 0, sizeof(dp));
	memset(tr, 0, sizeof(tr));
	for(int i = 0 ; i < N ; i++){
		for(int j = 0; j <= i ;j++){
			cin >> tr[i][j] ;
		}
	}
	m = dp[0][0] = tr[0][0];
	for(int i = 1 ; i < N ; i++){
		for(int j = 0; j <= i ;j++){
			if(j != 0 && j != i)		
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + tr[i][j];
			if(j == 0)
				dp[i][j] = dp[i-1][j] + tr[i][j];
			if(j == i)
				dp[i][j] = dp[i-1][j-1] + tr[i][j];
		}
	}
	for(int i = 0 ; i < N; i++){
		if(dp[N-1][i] > m)
			m = dp[N-1][i];
	}
	cout << m <<endl;
	return 0;
}
