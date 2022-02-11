#include <bits/stdc++.h>

using namespace std;

void solve(){
	string input;
	cin >> input;
	
	bool hasZero=false;
	bool hasEvenDigit=false;
	int sum=0;
	
	while(input!=""){
		char c=input[0];
		input.erase(0,1);
		int digit=c-'0';
		sum+=digit;	
		
		if(!hasEvenDigit){
			if(digit%2==0){
			 hasEvenDigit=true;
			 continue;
			 }
		}	
	
		if(!hasZero){
			if(digit==0) hasZero=true;
		}			
	}
	
	sum%=3;
	
	if(hasZero && hasEvenDigit && !sum){
		cout << "red" << endl;
		return;
	}
	
	
	cout << "cyan" << endl;
}

int main() {
	int n;
	cin >> n;
	while(n--) solve();	
	return 0;
}
