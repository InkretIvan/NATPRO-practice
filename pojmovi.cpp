#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

	int n,m;
	vector<string> library;



bool provjeri(string s){
	
	for(int c=0;c<library.size();c++){
		
		string book=library[c];
		int x=book.length();
		int y=s.length();
		int distance=0;
		
		if(x!=y) continue;
		
		for(int i=0;i<x;i++){
			if(book[i]!=s[i]) distance++;
		}
		
		if(distance<=1) return true;
		
		
		
		
	}
	
	return false;
}



int main() {
	
	cin >> n >> m;
	string mem;
	for(int i=0;i<n;i++){
		cin >> mem;
		library.push_back(mem);
	}
	
	for(int i=0;i<m;i++){
		cin >> mem;
		if(provjeri(mem)) cout << "DA" << endl;
		else cout << "NE" << endl;
		
	}
	
	
	
	return 0;
}
