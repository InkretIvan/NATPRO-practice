#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

	int n,m;
	vector<string> library;

int minn(int x, int y, int z) {

  int smallest = INT_MAX;

  if (x < smallest)
    smallest=x;
  if (y < smallest)
    smallest=y;
  if(z < smallest)
    smallest=z;

  return smallest;
}

bool provjeri(string s){
	
	for(int c=0;c<library.size();c++){
		
		string book=library[c];
		int x=book.length();
		int y=s.length();
		int distance;
		
		
		
		
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
