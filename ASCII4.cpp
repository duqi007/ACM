#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		string s;
		cin >>s;
		if(s[0] > s[1])
			swap(s[0], s[1]);
		if(s[0] > s[2])
			swap(s[0], s[2]);
		if(s[1] > s[2])
			swap(s[1], s[2]);
		cout << s[0] <<" "<< s[1] <<" "<<s[2]<<endl;
	}
	
	return 0;
}
