#include<iostream>
#include<map>
using namespace std;

//trie data structue
class trieNode{
	public:
	map< char , trieNode* >	children;
	bool isWord;
	public:
	trieNode(){
		
		isWord = false;
	}
};

class trie{
	
	trieNode *root;

	public:
	trie(){
		root = new trieNode();
	}

	bool insert(string s){

		trieNode *current = root;
		for(int i = 0 ; i < s.length() ; i++){
			char ch = s[i];
			trieNode *node = new trieNode();
			if(current->children.count(ch)==0){
				
				current->children[ch]=node;

			}
			else  node = current->children[ch];

			current=node;
		}
		current->isWord=true;

	}

	bool search(string s){
		trieNode *current = root;
		for (int i = 0; i < s.length(); ++i)
		{
			char ch = s[i];
			trieNode *node = new trieNode();
			if(current->children.count(ch)==0) return false;

			node = current->children[ch];
			current = node;

		}
		return current->isWord;
	}


};

int main(){
	
	trie *t = new trie();
	
	if(t->insert("hello")) cout<<"sting inserted"<<endl;
	if(t->search("hello")) cout<<"hello found"<<endl;

	return 0;

}
