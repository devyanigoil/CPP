#include <iostream>
#include <string>
#include <vector>
using namespace std;

//input: 6
// he h hello helo hello hell
// he
// output: he
//hello
//helo
//hell
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
    bool search(TrieNode* root, string word) {
        // Write your code here
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        
        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else{
            return false;
        }
        return search(child,word.substr(1));
    }
    
    bool search(string word) {
        return search(root,word);
    }
    
	TrieNode* findNode(TrieNode* root, string pattern)
    {
        if(pattern.size()==0)
        {
            return root;
        }
        int index = pattern[0]-'a';
        if(root->children[index]!=NULL)
        {
            return findNode(root->children[index],pattern.substr(1));
        }
        else 
            return NULL;
    }
    
    void printCombo(TrieNode* node,string word,string output)
    {
    	if(node->isTerminal)
        {
            cout << word + output << endl;
        }
    	for(int i=0;i<26;i++)
        {
            if(node->children[i])
            {
        		output += node->children[i]->data;
            	printCombo(node->children[i],word,output);
                output=output.substr(0,output.size()-1);
            }
        }
        return;
    }
    
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i=0;i<input.size();i++)
        {
            if(search(input[i]))
	            continue;
            insertWord(input[i]);
        }
        TrieNode* child;
        child = findNode(root,pattern);
        if(child==NULL)
            return;
        printCombo(child,pattern,"");
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}