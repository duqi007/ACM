#include <iostream>
#include <cstring>
#include <stack>

using namespace std;


int main(){
	
	int N;
	cin >> N;
	while(N--){
		stack<char> S;
		string str;
		cin >> str ;
		for(int i = 0 ; i < str.length() ; i++){
			if(!S.empty()){
				if(S.top() == '[' && str[i] == ']' || S.top() == '(' && str[i] == ')')
					S.pop();
				else
					S.push(str[i]);
			}
			else
				S.push(str[i]);
		}
		if(!S.empty()){
			cout << "No" << endl;
			while(!S.empty()){
				S.pop();
			}
		}
		else
			cout << "Yes" <<endl;
		
	}
	
	return 0;
} 
