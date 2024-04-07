#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


class WordDictionary {
private:
    vector<WordDictionary*> child;
    bool isEnd;
public:
    WordDictionary(): child(26), isEnd(false) {}
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(char c: word)
        {
            c = c - 'a';
            if(node->child[c] == nullptr)
            {
                node->child[c] = new WordDictionary();
            }
            node = node->child[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return bfs(this, word);
    }

    bool bfs(WordDictionary* node, string word)
    {
        if(word.length() == 1)
        {
            if(word[0] == '.')
            {
                for(int i = 0; i<26; i++)
                    if(node->child[i] != nullptr && node->child[i]->isEnd == true)
                        return true;
                return false;
            }
                
            else
            {
                int i = word[0] - 'a';
                if(node->child[i] != nullptr && node->child[i]->isEnd == true)
                        return true;
                    else
                        return false;
            }    
        }
        else
        {
            if(word[0] == '.')
            {
                for(int i = 0; i<26; i++)
                    if(node->child[i] != nullptr && bfs(node->child[i], word.substr(1, word.length())))
                        return true;
                return false;
            }   
            else
            {
                int i = word[0] - 'a';
                if(node->child[i] == nullptr) return false;
                else return bfs(node->child[i], word.substr(1, word.length()));
            }         
        }
        return true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */