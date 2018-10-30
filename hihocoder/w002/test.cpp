#include <cstring>
#include <cstdio>
#include <cstdlib>

#ifndef nullptr
#define nullptr NULL
#endif

class TrieNode 
{
    public:
        int num_child;
        int size[26];
        TrieNode* child[26];
        bool is_word;

    public:

        TrieNode() {
            num_child = 0;
            for (int i=0; i<26; ++i) {
                size[i] = 0;
                child[i] = nullptr;
            }
            is_word = false;
        }

        ~TrieNode() {
            for (int i=0; i<26; ++i) {
                if (child[i] != nullptr) {
                    delete child[i];
                    child[i] = nullptr;
                }
            }
        }

        TrieNode* setChild(char token) {
            int pos = token - 'a';
            if (pos<0 || pos >25) 
                return nullptr;

            TrieNode* p = child[pos];
            size[pos] ++;
            num_child ++;

            if (p == nullptr) {
                p = new TrieNode();
                child[pos] = p;
                return p;
            }
            return p;
        }

        TrieNode* getChild(char token) {
            int pos = token - 'a';
            if (pos<0 || pos >25) 
                return nullptr;

            TrieNode* p = child[pos];
            return child[pos];
        }
};

class Trie {
public:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }
    ~Trie() { delete root; }

public:
    bool AddWord(char* word) {
        TrieNode* p = root;

        int i=0;
        while (word[i]) {
            if (p == nullptr) {
                return false;
            }
            p = p->setChild(word[i]);
            i++;
        }

        p->is_word = true;
        return true;
    }

    TrieNode* searchBySuffix(char* suffix) {
        TrieNode* p = root;

        for (int i=0; suffix[i]; ++i) {
            if (p == nullptr)
                return nullptr;

            p = p->getChild(suffix[i]);
        }

        return p;
    }
};

int main() {
    int n=0;
    char word[100000+100];
    scanf("%d", &n);

    Trie trie;

    while (n--) {
        scanf("%s", word);
        trie.AddWord(word);
    }

    scanf("%d", &n);
    while (n--) {
        scanf("%s", word);

        TrieNode* p = trie.searchBySuffix(word);

        int num;
        if (p == nullptr)
            num = 0;
        else
            num = p->num_child;

        printf("%d\n", num);
    }

    return 0;
}
