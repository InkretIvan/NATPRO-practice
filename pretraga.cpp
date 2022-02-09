#include <bits/stdc++.h>
using namespace std;
  
   int lpss[400001];
   int n;
   string pat;
  
void computeLPSArray(char* pat, int M);
  
// Prints occurrences of txt[] in pat[]
void KMPSearch(string txt)
{
    int M = pat.length();
    int N = txt.length();
	
	int lps[M];
	
	for(int i=0;i<M;i++) lps[i]=lpss[i];
    
  
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            printf("%d\n", i - j);
            j = lps[j - 1];
            return;
        }
  
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    printf("%d\n",-1);
}
  
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(string pat, int M)
{
    // length of the previous longest prefix suffix
    int len = 0;
  
    lpss[0] = 0; // lps[0] is always 0
  
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lpss[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lpss[len - 1];
  
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lpss[i] = 0;
                i++;
            }
        }
    }
}

int main() {
	
	getline(cin,pat);
	cin >> n;	
    computeLPSArray(pat, pat.length());
    
    cin.ignore();
    
    while(n--){
    	string txt;
    	
    	getline(cin,txt);
    	KMPSearch(txt);
	}
   
	
	
	return 0;
}
