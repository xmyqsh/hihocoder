#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void postOrder(TreeNode* root, vector<int>& postorder) {
    if (!root) return;
    postOrder(root->left, postorder);
    postOrder(root->right, postorder);
    postorder.push_back(root->val);
}

TreeNode* convert(const vector<int>& preorder, const vector<int>& inorder, int bPre, int bIn, int len) {
    if (len <= 0) return NULL;
    TreeNode* root = new TreeNode(preorder[bPre]);
    int i;
    for (i = bIn; inorder[i] != preorder[bPre]; ++i);
    root->left = convert(preorder, inorder, bPre + 1, bIn, i - bIn);
    root->right = convert(preorder, inorder, bPre + i - bIn + 1, i + 1, len - 1 - (i - bIn));
    return root;
}

vector<int> calc(const vector<int>& preorder, const vector<int>& inorder) {
    vector<int> postorder;
    TreeNode* root = convert(preorder, inorder, 0, 0, preorder.size());
    postOrder(root, postorder);
    return postorder;
}

int main() {
    vector<int> preorder;
    vector<int> inorder;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        preorder.push_back(str[i] - 'A');
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        inorder.push_back(str[i] - 'A');
    vector<int> postorder = calc(preorder, inorder);

    for (int i = 0; i < postorder.size() - 1; ++i)
        cout << (char)(postorder[i] + 'A');
    cout << (char)(postorder[postorder.size() - 1] + 'A') << endl;
    return 0;
}