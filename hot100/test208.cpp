#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        vector<Trie*> children(26);
        isEnd = false;
    }

    Trie* searchPrefis(string prefix)
    {
        Trie* node = this;
        for(char c: prefix)
        {
            c = c - 'a';
            if(node->children[c] == nullptr)
                return nullptr;
            node = node->children[c];
        }
        return node;
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c: word)
        {
            c = c - 'a';
            if(node->children[c] == nullptr)
            {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchPrefis(word);
        return node!=nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefis(prefix)!=nullptr;
    }
};