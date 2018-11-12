#include <iostream>

using namespace std;

int Fibonacii(int n){
	if(n == 1 || n == 2)
		return 1;
	else
		return Fibonacii(n-1) + Fibonacii(n - 2);
}

int main(){
	int N;
	cin >> N;
	while(N--){
		int m;
		cin >> m;
		cout << Fibonacii(m) <<endl;
	}
	
	return 0;
} 
