#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX		100
#define INIFITY 	65535

int X[MAX],Y[MAX];

int main(){
	
	int N;
	cin >> N;
	memset(X, 0, sizeof(X));
	memset(Y , 0, sizeof(Y));
	while(N--){
		int K;
		int MIN =  0;
		int max = INIFITY;
		cin >> K;
		for(int i= 0; i < K ;i++){
			cin >>X[i] >> Y[i];
		}
		for(int x = 0; x < MAX ; x++){
			for(int y= 0 ; y < MAX ;y++){
				
				for(int k = 0  ; k < K ; k++){
					MIN += fabs(x - X[k]) + fabs(y - Y[k]);
				}
				if(MIN < max)
					max = MIN;
				MIN = 0;
			}
		}
		cout << max <<endl;
		
	}
	
	return 0;
	
}
