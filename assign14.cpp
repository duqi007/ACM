#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
	int be, en;
	bool operator < (const node &T)const{
		if(en != T.en)
			return en < T.en;
	};
};
int main(){
	int N;
	cin >> N;
	while(N--){
		int n; 
		cin >> n;
		node T;
		vector<node> v;
		for(int i = 0; i <n ;i++){
			cin >>T.be >>T.en;
			v.push_back(T);
		}
		sort(v.begin(), v.end());
		vector<node>::iterator it = v.begin();
		int e = it->en, s = 1;
		it++;
		for(it ; it != v.end() ; it++)
		{
			if(it->be > e){
				e = it->en;
				s++;
			}
		}		
		cout << s <<endl;
	}	
	return 0;
} 
