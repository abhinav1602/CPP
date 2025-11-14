/**
 * @file BinaryTreeImplementation.cpp
 * @brief Simple BST insert/search/inorder traversal.
 * @date 2025-11-15
 */

#include <iostream>
#include <memory>

struct TNode {
    int key;
    std::unique_ptr<TNode> left, right;
    explicit TNode(int k) : key(k) {}
};

class BST {
    std::unique_ptr<TNode> root;
    void insertRec(std::unique_ptr<TNode>& node, int k) {
        if (!node) { node = std::make_unique<TNode>(k); return; }
        if (k < node->key) insertRec(node->left, k); else if (k > node->key) insertRec(node->right, k);
    }
    bool searchRec(TNode* node, int k) const {
        if (!node) return false;
        if (node->key == k) return true;
        return k < node->key ? searchRec(node->left.get(), k) : searchRec(node->right.get(), k);
    }
    void inorderRec(TNode* node) const {
        if (!node) return;
        inorderRec(node->left.get());
        std::cout << node->key << ' ';
        inorderRec(node->right.get());
    }
public:
    void insert(int k) { insertRec(root, k); }
    bool contains(int k) const { return searchRec(root.get(), k); }
    void inorder() const { inorderRec(root.get()); std::cout << '\n'; }
};

int main() {
    BST tree;
    for (int k : {5,3,7,2,4,6,8}) tree.insert(k);
    tree.inorder();
    std::cout << "Contains 4? " << tree.contains(4) << '\n';
    std::cout << "Contains 10? " << tree.contains(10) << '\n';
    return 0;
}

/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 BinaryTreeImplementation.cpp -o BinaryTreeImplementation */

