#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		int n;
		cin >> n;
		for(int i = 1; i <= n ;i += 2)
			cout << i << " ";	
		cout << endl;
		for(int i = 2; i <= n ;i += 2)
			cout << i << " ";	
		cout << endl << endl;
	}
	return 0;
}
