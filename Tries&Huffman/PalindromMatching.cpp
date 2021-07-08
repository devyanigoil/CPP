#include <bits/stdc++.h>
using namespace std;

//Given 'n' number of words, you need to find if there exist any two words which can be joined to make 
//a palindrome or any word, which itself is a palindrome.
//input: 4
//abc def ghi cba
//output: true

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
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
    
    /*..................... Palindrome Pair................... */
    bool isPalin(string word)
    {
        for(int i=0,j=word.size()-1;i<j;i++,j--)
        {
            if(word[i]!=word[j])
                return false;
        }
        return true;
    }
    
    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i=0;i<words.size();i++)
        {
            int j,k;
            for(j=0,k=words[i].size()-1;j<k;j++,k--)
            {
                if(words[i][j]!=words[i][k])
                    break;
            }
            if(j>=k)
                return true;
            add(words[i]);
        }
        string palin="";
        bool ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                palin = words[i]+words[j];
                ans = isPalin(palin);
                if(ans)
                    return true;
            }
            for(int j=i+1;j<words.size();j++)
            {
                palin = words[i]+words[j];
                ans = isPalin(palin);
                if(ans)
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}