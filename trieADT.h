#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(struct TrieNode* root, const char* word) {
    struct TrieNode* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            curr->children[index] = createNode();

        curr = curr->children[index];
    }

    curr->isEndOfWord = true;
}

int search(struct TrieNode* root, const char* word) {
    struct TrieNode* curr = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (curr->children[index] == NULL)
            return 0;

        curr = curr->children[index];
    }

    return curr->isEndOfWord ? 1 : 0;
}

int isEmptyNode(struct TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i] != NULL)
            return 0;
    return 1;
}

struct TrieNode* deleteWord(struct TrieNode* root, const char* word, int depth) {
    if (root == NULL)
        return NULL;

    // If end of word reached
    if (word[depth] == '\0') {
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // If node has no children, free it
        if (isEmptyNode(root)) {
            free(root);
            root = NULL;
        }
        return root;
    }

    int index = word[depth] - 'a';
    root->children[index] = deleteWord(root->children[index], word, depth + 1);

    // After recursive deletion, if current node becomes useless, free it
    if (isEmptyNode(root) && root->isEndOfWord == false) {
        free(root);
        root = NULL;
    }

    return root;
}

