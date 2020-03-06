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

	void allStringsUtil(string word, trieNode* node){

		if(node->isWord)	cout<<word<<endl;

		
		for (auto it=node->children.begin();it!=node->children.end();++it)
		{
			
			allStringsUtil(word + (it->first) , it->second );

		}
	}

	void allStrings(){
		
		allStringsUtil("",root);
	}



};

int main(){
	
	trie *t = new trie();
	
	t->insert("hola");
	t->insert("is");
	t->insert("nikhil");
	t->insert("nikhilllll");
	t->insert("isa");
	

	t->allStrings();

	

}
