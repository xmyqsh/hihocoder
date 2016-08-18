#include <iostream>
#include <string>

using namespace std;

struct TrieNode {
    int count;
    TrieNode* next[26];
    TrieNode(int count) {
        this->count = count;
        for (int i = 0; i < 26; ++i)
            this->next[i] = 0;
    }
};

class TrieTree {
public:
    TrieTree() {
        root = new TrieNode(0);
    }
    ~TrieTree() {
        destroy(root);
    }

    void insert(const string& str) {
        TrieNode* cur = root;
        for (int i = 0; i < str.size(); ++i) {
            int idx = str[i] - 'a';
            if (!cur->next[idx])
                cur->next[idx] = new TrieNode(0);
            cur = cur->next[idx];
            cur->count++;
        }
    }
    int find(const string& str) {
        TrieNode* cur = root;
        int count = 0;
        for (int i = 0; i < str.size(); ++i) {
            int idx = str[i] - 'a';
            if (!cur->next[idx])
                return 0;
            cur = cur->next[idx];
            count = cur->count;
        }
        return count;
    }
private:
    void destroy(TrieNode *cur) {
        if (!cur) return;
        for (int i = 0; i < 26; ++i)
            destroy(cur->next[i]);
        delete cur;
    }
private:
    TrieNode* root;
};

int main() {
    int n, m;
    string str;
    TrieTree* trie = new TrieTree();
    cin >> n;
    while (n--) {
        cin >> str;
        trie->insert(str);
    }
    cin >> m;
    while (m--) {
        cin >> str;
        cout << trie->find(str) << endl;
    }
    return 0;
}