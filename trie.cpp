#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#define ALPHABETS 26


int char_to_index(char c){
	return c - 'A';
}

struct Trie{

	bool is_terminal; // string
	Trie * children[ALPHABETS];

	
	Trie(): is_terminal(false){
		memset(children, 0, sizeof(children));
	}

	// menghapus semua children
	~Trie(){
		for(int i = 0; i < ALPHABETS; ++i){
			if(children[i])
				delete children[i];
		}
	}
	
	//menambahkan string baru pada trie
	void insert(const char * key){
		if(*key == '\0'){
			is_terminal = true;
		}
		else{
			int index = char_to_index(*key);

			if(children[index] == 0)
				children[index] = new Trie();
			children[index]->insert(key + 1);
		}
	}

	//memeriksa trie memiliki key ( dalam artian melewati argumen string sebagai awalan, jika memiliki key sebagai awalan maka mengembalikan ujung simpul awalan key)
	Trie* find(const char * key){
		if(*key == 0){
			return this;
		}

		int index = char_to_index(*key);
		if(children[index] == 0){
			return NULL;
		}

		return children[index]->find(key+1);
	}

	//meriksa trie memiliki key (jika memiliki key makan mengembalikan pada true, dan jika tidak maka kembalikan false)
	bool string_exist(const char * key){
		if(*key == 0 && is_terminal){
			return true;
		}

		int index = char_to_index(*key);
		if(children[index] == 0){
			return false;
		}
		return children[index]->string_exist(key + 1);
	}

};

int main (){

	Trie * root = new Trie(); //menginisialisasi trie

	const char * words[5] = {"be", "bee", "can", "cat", "cd"}; //mendeklrasikan kata 

	for(int i = 0; i < 5; ++i){
		printf("insert: %s\n", words[i]); // menginput kata
		root->insert(words[i]); //memasukkan kata pada trie
	}

	printf("\n");

	// mencetak trie dan mengecek prefix
	printf("%s: be\n", root->find("be") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: can\n", root->find("can") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: a\n", root->find("a") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: cat\n", root->find("cat") != 0 ? "Prefix Exist" : "Prefix Not Exist");
	printf("%s: c\n", root->find("c") != 0 ? "Prefix Exist" : "Prefix Not Exist");

	printf("\n");

	printf("%s: c\n", root->string_exist("c") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: be\n", root->string_exist("be") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: bee\n", root->string_exist("bee") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: candy\n", root->string_exist("candy") != 0 ? "String Exist" : "String Not Exist");
	printf("%s: cd\n", root->string_exist("cd") != 0 ? "String Exist" : "String Not Exist");

	delete root;

	return 0;
}
