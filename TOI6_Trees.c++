/*
TASK: tree
LANG: C++
AUTHOR: YourName YourLastName
CENTER: Home
*/
#include<bits/stdc++.h>
using namespace std ;
int main(){
	ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
	int num ;
	for(int i=1 ; i<=5 ; i++){
		cin >> num ;
		pair<int,int> koo1[num-1],koo2[num-1] ;
		for(int j=0 ; j<num-1 ;j++){
			cin >> koo1[j].first >> koo1[j].second ;
			if(koo1[j].first<koo1[j].second) swap(koo1[j].first,koo1[j].second) ;
		}
		for(int j=0 ; j<num-1 ;j++){
			cin >> koo2[j].first >> koo2[j].second ;
			if(koo2[j].first<koo2[j].second) swap(koo2[j].first,koo2[j].second) ;
		}
		sort(koo1,koo1+(num-1)) ;
		sort(koo2,koo2+(num-1)) ;
		for(int j=0 ; j<num-1 ;j++){
			if(koo1[j].first!=koo2[j].first||koo1[j].second!=koo2[j].second){
				cout << 'N' ;
					goto haa;
			}
		}
		cout << 'Y' ;
		haa :;
	}
	return 0 ;
}