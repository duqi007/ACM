#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double len(double r, double h ){
	return sqrt(pow(r, 2) - pow(h, 2));
}
bool cmp(const pair<double, double> &a, const pair<double, double> &b){
	if(a.first != b.first)
		return a.first < b.first;
	if(a.first == b.first && a.second != b.second)
		return a.second > b.second;
}
int main(){
	
	int N;
	cin >>N;
	while(N--){
		vector< pair<double, double> > v;
		int n, w, h ,x, r;
		cin >> n >> w >>h;
		for(int i = 0 ; i < n ; i++){
			cin >> x >> r;
			if(r > h/2){
				double l = len(r, h/2);
				pair<double, double> p;
				p.first = x - l;
				p.second = x + l;
				v.push_back(p);
			}
		}
		sort(v.begin(), v.end(),cmp);
		double right = 0.0;
		int s = 0;
		while(right < w){
			double m = 0.0;
			for(int i = 0; i < v.size()&&v[i].first <= right; i++){
				if(v[i].second - right > m)
					m = v[i].second - right;
			}
			if(m != 0){
				s ++;
				right += m;
			}
			else
				break;
		}
		if(right < w)
			cout << 0 << endl;
		else
			cout << s <<endl;		
	} 
	
	return 0;
} 
