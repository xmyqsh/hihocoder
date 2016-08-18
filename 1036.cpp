#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TrieNode {
    bool tail;
    TrieNode* next[26];
    TrieNode* prev;
    TrieNode() {
        this->tail = false;
        for (int i = 0; i < 26; ++i)
            this->next[i] = NULL;
        this->prev = NULL;
    }
};

class TrieGraph {
public:
    TrieGraph() {
        root = new TrieNode();
    }
    ~TrieGraph() {
        destroy(root);
    }

    void insert(const string& s) {
        TrieNode* cur = root;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (!cur->next[idx])
                cur->next[idx] = new TrieNode();
            cur = cur->next[idx];
        }
        cur->tail = true;
    }
    void build() {
        queue<TrieNode*> q;
        TrieNode* cur = root;
        for (int i = 0; i < 26; ++i) {
            if (root->next[i]) {
                root->next[i]->prev = root;
                q.push(root->next[i]);
            }
        }
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            for (int i = 0; i < 26; ++i) {
                TrieNode* pNext = cur->next[i];
                if (pNext) {
                    TrieNode* pPrev = cur->prev;
                    while (pPrev) {
                        if (pPrev->next[i]) {
                            pNext->prev = pPrev->next[i];
                            break;
                        } else {
                            pPrev = pPrev->prev;
                        }
                    }
                    if (!pNext->prev)
                        pNext->prev = root;
                    q.push(pNext);
                }
            }
        }
    }
    bool search(const string& s) {
        TrieNode* cur = root;
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            while (cur && !cur->next[idx])
                cur = cur->prev;
            if (!cur) {
                cur = root;
                continue;
            }
            cur = cur->next[idx];
            if (cur->tail) return true;
        }
        return false;
    }
private:
    void destroy(TrieNode* cur) {
        for (int i = 0; i < 26; ++i)
            if (cur->next[i])
                destroy(cur->next[i]);
        delete cur;
    }
private:
    TrieNode* root;
};

int main() {
    int N;
    cin >> N;
    TrieGraph TG;
    string word;
    while (N--) {
        cin >> word;
        TG.insert(word);
    }
    TG.build();
    cin >> word;
    cout << (TG.search(word) ? "YES" : "NO") << endl;
    return 0;
}