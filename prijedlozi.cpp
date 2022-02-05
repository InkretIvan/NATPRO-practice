#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

	int n;
	
	const int ALPHABET_SIZE = 27;
 
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    int longest;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(int len)
{
    struct TrieNode *pNode =  new TrieNode;
 
    pNode->isEndOfWord = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 	pNode->longest=len;
    return pNode;
}
 
// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
    	int index;
    	if(key[i]==' '){
    	  index=26;	
		}
		else{
		  index = key[i] - 'a';
		}
       
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode(key.length());
 		pCrawl->longest=max(pCrawl->longest,(int)key.length());
 		//cout << pCrawl->longest << endl;
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
 
// Returns true if key presents in trie, else
// false
int search(struct TrieNode *root, string key)
{
	int ret=0;
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
       	int index;
    	if(key[i]==' '){
    	  index=26;	
		}
		else{
		  index = key[i] - 'a';
		}
		
        if (!pCrawl->children[index])
            return ret;
 		//ret = max(pCrawl->longest,ret);
 		ret=pCrawl->longest;
 		//cout << pCrawl->longest << " " << ret << endl;
        pCrawl = pCrawl->children[index];
    }
 
    return ret;
}
	



int main() {
	
	cin >> n;
    struct TrieNode *root = getNode(0);
	string s;
	char c;
	while(n--){
		cin >> c;
		getline(cin,s);
		s.erase(0,1);
		insert(root,s);
		
		if(c=='q') continue;
		cout << search(root, s) << endl;
	}
	
	
	
	return 0;
}
