#include <bits/stdc++.h>
using namespace std;

namespace Trie {
	struct node {
		bool endmark;
		node *next[52];
		node() {	
			endmark = 0; 
			for(int i = 0; i < 52; i++) next[i] = NULL; 
		}
	}*root = new node();
	inline int  ID(char ch){ return ('a' <= ch && ch <= 'z') ? ch-'a' : 26+ch-'A';}
	inline void Insert(string s) {
		node *curr = root;
		for(int ln = s.length(),i = 0; i < ln; i++) {
			int id = ID(s[i]);
			if(curr -> next[id] == NULL) curr -> next[id] = new node();
			curr = curr -> next[id];
		}
		curr -> endmark = 1;
	}
	inline bool Query(string s) {
		node *curr = root;
		for(int ln = s.length(),i = 0;i < ln; i++) {
			int id = ID(s[i]);	
			if(curr -> next[id] == NULL) return 0;
			curr = curr -> next[id];
		}
		return curr -> endmark;
	}
	void del(node *curr) {
		for(int i = 0; i < 52; i++)	if(curr->next[i] != NULL) del(curr->next[i]);
		delete(curr);
	}
}

namespace TrieA { // array Implementation 
	struct node {
	    int endmark,next[52];
	    void clear() {   
	    	endmark = 0;  
	    	memset(next,-1,sizeof(next));
	    }
	} root[100009];
	int All = -1;
	inline int ID(char ch){ return ('a' <= ch && ch <= 'z') ? ch-'a' : 26+ch-'A';}
	inline int InsertOrQuery(string s, bool query = 0) {
	    int id, ln = s.length(),curr = 0;
	    if(All < 0) All = 0, root[0].clear();
	    for(int i = 0; i < ln; i++) {
	        id = ID(s[i]);
	        if(root[curr].next[id] == -1) {
	            if(query)   return 0;
	            root[curr].next[id] = ++All;
	            root[All].clear();
	        }
	        curr = root[curr].next[id];
	    }
	    if(query)   return root[curr].endmark;
	    else        root[curr].endmark++;
	}
}

int main()
{


	return 0;
}
