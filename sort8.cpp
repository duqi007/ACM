#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct rectangle{
	int num, l, w;
	
	bool operator< (const rectangle &T){
		if(num != T.num)
			return num < T.num;
		if(l != T.l)
			return l < T.l;
		if(w != T.w)
			return w < T.w;
	}
	bool operator==(const rectangle &T) 
	{
		if(num == T.num && l == T.l && w == T.w)
			return true;
		return false;
	}
}rectangle; 

int main(int argc, char** argv) {
	
	int N ;	
	cin >> N;	
	while(N--){
		int K;	
		cin >> K;	
		rectangle r;
		vector<rectangle>  R ;
		for(int i = 0; i < K ; i++){
			cin >> r.num >> r.l >>r.w ;
			if(r.l < r.w)
				swap(r.l, r.w);
			R.push_back(r);
		}
		sort(R.begin(), R.end());
		vector<rectangle>::iterator new_end = unique(R.begin(), R.end());
		R.erase(new_end, R.end());
		vector<rectangle>::iterator it;
		for(it = R.begin(); it != R.end(); it++){
			cout << (*it).num << " "<< it->l << " " << it->w <<endl;
		}
	}
	return 0;
}
