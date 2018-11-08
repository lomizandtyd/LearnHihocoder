#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

struct TreeNode {
    char val;
    TreeNode* lchild;
    TreeNode* rchild;

    TreeNode() {
        val = 0;
        lchild = NULL;
        rchild = NULL;
    }
};

TreeNode* build_tree(string preOrder, string midOrder) {
    if (preOrder.empty() || midOrder.empty()) {
        return NULL;
    }

    TreeNode* root = new TreeNode();
    root->val = preOrder[0];

    int pos = 0, lpos = 1, rpos = 0;
    while (pos < midOrder.size() && midOrder[pos] != root->val)
        pos++;

    if (pos != 0) {
        char mark[26] = {0};
        lpos = pos;

        while (--lpos>=0) {
            mark[midOrder[lpos]-'A'] = 1;
        }

        lpos = 1;
        while (lpos < preOrder.size() && mark[preOrder[lpos]-'A'])
            lpos ++;


        root->lchild = build_tree(preOrder.substr(1, lpos-1), midOrder.substr(0, pos));
    }

    if (pos < midOrder.size()-1) {
        root->rchild = build_tree(preOrder.substr(lpos, preOrder.size() - lpos), midOrder.substr(pos+1, midOrder.size() - pos - 1));
    }

    return root;
}

string get_post_order(TreeNode* r) {
    if (r == NULL)
        return "";

    string i = "";
    i += get_post_order(r->lchild);
    i += get_post_order(r->rchild);
    i += r->val;

    return i;
}

void delete_tree(TreeNode* p) {
    if (p == NULL)
        return;
    
    if (p->lchild) {
        delete_tree(p->lchild);
        p->lchild = NULL;
    }

    if (p->rchild) {
        delete_tree(p->rchild);
        p->rchild = NULL;
    }

    delete p;
    return;
}


int main() {
    string preOrder;
    string midOrder;

    cin >> preOrder;
    cin >> midOrder;

    TreeNode* p = build_tree(preOrder, midOrder);
    cout << get_post_order(p) << endl;

    delete_tree(p);
    p = NULL;
    return 0;
}
