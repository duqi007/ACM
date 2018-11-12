#include <iostream>
#include <cmath>
#include <set> 


using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		int num;
		double m;
		multiset<double> set;
		cin >>num;
		for(int i = 0; i < num ;i++){
			cin >>m;			
			set.insert(m);
		}
		multiset<double> ::iterator it = set.end();
		double sum = 0;
		int count = 0;
		it--;
		while(sum < 20){
			sum += 2*sqrt(*it * *it -1);
			it --;
			count ++;
		}
		cout << count <<endl; 
	}
	
	return 0;
}
