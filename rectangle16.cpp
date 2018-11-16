#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct node{
	int l,w;
	bool operator< (const node &T){
		if(l < T.l)
			return true;
		else
			if(l == T.l && w < T.w)
				return true;
			else
				return false;
	}
};
 

int main(){
	int N; 
	cin>> N;
	while(N--){
		int n , l, w;
		cin >> n;
		node R[n];
		int si[n];
		for(int i = 0; i < n ;i++){
			cin >> l >> w ;
			if(l < w)
				swap(l, w );
			R[i].l = l;R[i].w = w;
		}
		sort(R,R + n);
		memset(si, 0, sizeof(si));
		for(int i = 1; i < n ; i++){
			for(int j = 0; j < i; j++){
				if(R[j].l < R[i].l && R[j].w<R[i].w && si[i] < si[j] + 1){
					si[i] = si[j] + 1;
				}
			}
		}
		int max = si[0];
		for(int i = 0; i < n ;i++){
			if(si[i] > max)
				max = si[i];
		}
		cout << max+1 <<endl;
	}
	return 0;
} 
