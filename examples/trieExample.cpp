#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

typedef struct trie_node {
    struct trie_node *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

/* returns new trie node */
TrieNode *getNode(void) {
    TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

/* if not present, inserts key into trie.
  If the key is prefix of trie node, just
 marks leaf mode */
void insert(TrieNode *root, string key) {
    TrieNode *crawl = root;
    int index;

    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';
        if (!(crawl->children[index]))
            crawl->children[index] = getNode();
        crawl = crawl->children[index];
    }

    crawl->isEndOfWord = true;
}

/* returns true if key presents in trie,
  false otherwise */
bool search(TrieNode *root, string key) {
    TrieNode *crawl = root;
    int index;

    for (int i = 0; i < key.length(); i++) {
        index = key[i] - 'a';
        if ((!crawl->children[index]))
            return false;
        crawl = crawl->children[index];
    }
    return (crawl->isEndOfWord);
}

int main(void) {
    string keys[] = {
        "the",
        "a",
        "there",
        "answer",
        "any",
        "by",
        "bye",
        "their"
    };
    int n = sizeof(keys)/sizeof(keys[0]);

    TrieNode *root = getNode();

    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    cout << "Is the key \"the\" present? ";
    cout << ((search(root, "the")) ? "Yes" : "No") << endl;
    cout << "Is the key \"these\" present? ";
    cout << ((search(root, "these")) ? "Yes" : "No") << endl;
    cout << "Is the key \"their\" present? ";
    cout << ((search(root, "their")) ? "Yes" : "No") << endl;
    cout << "Is the key \"foo\" present? ";
    cout << ((search(root, "foo")) ? "Yes" : "No") << endl;
    return 0;
}
