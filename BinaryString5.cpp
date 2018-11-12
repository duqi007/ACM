#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		string S, T;
		int i, j ,count;
		cin >> T >> S;
		i = j = count = 0;
		while(i < S.length()){
			while(i <S.length() && j < T.length()){
				if(S[i] == T[j]){
					i++;j++;
				}else{
					i = i - j +1;
					j = 0;
				}
			}
			if(j == T.length()){
				count++;
				i = i- j +1;
				j = 0;
			}
		}
		cout << count << endl;
	}
	
	return 0;
}
