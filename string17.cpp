#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		string s;
		cin >> s;
		int si[s.length()];
		memset(si, 0, sizeof(si));
		for(int i = 1; i < s.length(); i++){
			for(int j = 0; j< i; j++){
				if(s[j] < s[i] && si[i] < si[j] + 1)
					si[i] = si[j] + 1;
			}
		}
		int max = si[0];
		for(int i = 0; i < s.length() ; i++){
			if(si[i] > max)
				max = si[i];
		}
		s.clear();
		cout << max + 1 <<endl;
	}
	return 0;
}
