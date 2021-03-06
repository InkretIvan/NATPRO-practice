#include <bits/stdc++.h>
using namespace std;

int l,r;

int GCD(int a, int b){
	if(b == 0) return a;
	return GCD(b, a % b);
}


int LCA(int a, int b){
	return (a*b)/GCD(a,b);
}

void main2(){
	
	cin >> l >> r;
	int n=l+sqrt(r-l);
	
	for(int x=l;x<=n;x++){
		for(int y=x*2;y<=r;y+=x){
			int num=GCD(x,y);
			if(num>=l && num<=r){
				cout << x << " " << y << endl;
				return;
			}
		}
	}
	
	cout << -1 << " " << -1 << endl;
}

int main() {
	
	int t; cin >> t;
	while(t--) main2();
	
	
	return 0;
}
