
#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node* child[26];
    bool endWord;
};

class Trie {
    Node *head;
public:
    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node *actual = head;
        for(int i = 0; i < word.size(); ++i){
            int letter = word[i] - 'a';
            if(actual->child[letter] == nullptr){
                actual->child[letter] = new Node();
            }
            actual = actual->child[letter];
        }
        actual->endWord = true;
    }
    
    bool search(string word) {
        Node *actual = head;
        for(int i = 0; i < word.size(); ++i){
            int letter = word[i] - 'a';
            actual = actual->child[letter];
            if(actual == nullptr) return false;
        }
        return actual->endWord;
    }
    
    bool startsWith(string prefix) {
        Node *actual = head;
        for(int i = 0; i < prefix.size(); ++i){
            int letter = prefix[i] - 'a';
            actual = actual->child[letter];
            if(actual == nullptr) return false;
        }
        return true;
    }
};


int main(){
  Trie trie = Trie();
}
