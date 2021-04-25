#include "data_structure.hpp"
#include <vector>
#include <iostream>
// файл с определениями

namespace itis {

    Node::Node(int k) {
        key = k;
        height = 1;
        left = nullptr;
        right = nullptr;
    }

    bool AVLTree::is_empty() {
        return head_ == nullptr;
    }

    int AVLTree::height(Node *node) {
        if(node == nullptr) return 0;
        return node->height;
    }

    int AVLTree::balance_factor(Node *node) {
        if(node == nullptr) return 0;
        return height(node->right)-height(node->left);
    }

    void AVLTree::set_height(Node *node) {
        int left_height = height(node->left);
        int right_height = height(node->right);

        if(left_height > right_height) node->height = left_height + 1;
        else node->height = right_height + 1;
    }

    void AVLTree::insert(int key) {
        head_ = insert_(key, head_);
    }

    Node *AVLTree::insert_(int key, Node *node) {
        if(node == nullptr) {
            return new Node(key);
        }

        if(key >= node->key) {
            node->right = insert_(key, node->right);
        }
        else{
            node->right = insert_(key, node->right);
        }

        return balance(node);
    }

    Node *AVLTree::find_min(Node *node) {
        if(node->left != nullptr) return find_min(node->left);
        return node;
    }

    Node *AVLTree::remove_min(Node *node) {
        if(node->left==0)
            return node->right;
        node->left = remove_min(node->left);
        return balance(node);
    }

    void AVLTree::remove(int key) {
        head_ = remove_(key, head_);
    }

    Node *AVLTree::remove_(int key, Node *node) {
        if(node == nullptr) return nullptr;
        if(key < node->key)
            node->left = remove_(key, node->left);
        else if(key > node->key)
            node->right = remove_(key, node->right);
        else
        {
            Node* left = node->left;
            Node* right = node->right;
            delete node;
            if(right == nullptr) return left;
            Node* min = find_min(right);
            min->right = remove_min(right);
            min->left = left;
            return balance(min);
        }
        return balance(node);
    }

    Node *AVLTree::balance(Node *node) {
        set_height(node);
        if(balance_factor(node) == 2)
        {
            if( balance_factor(node->right) < 0) {
                node->right = rotate_right(node->right);
            }
                return rotate_left(node);
        }
        if(balance_factor(node) == -2)
        {
            if( balance_factor(node->left) > 0) {
                node->left = rotate_left(node->left);
            }
                return rotate_right(node);
        }
        return node;
    }

    Node *AVLTree::search(int key) {
        return search_(key, head_);
    }

    Node *AVLTree::search_(int key, Node *node) {
        if(node == nullptr) return nullptr;
        if(key == node->key) return node;

        if(key > node->key) return search_(key, node->right);
        return search_(key, node->left);
    }

    Node *AVLTree::rotate_left(Node *left) {
        Node* right = left->right;
        left->right = right->left;
        right->left = left;
        set_height(left);
        set_height(right);
        return right;
    }

    Node *AVLTree::rotate_right(Node *right) {
        Node* left = right->left;
        right->left = left->right;
        left->right = right;
        set_height(left);
        set_height(right);
        return left;
    }

    void AVLTree::clear() {
        AVLTree::clear_(head_);
        head_ = nullptr;
    }

    void AVLTree::clear_(Node *node) {
        if(node != nullptr){
            AVLTree::clear_(node->left);
            AVLTree::clear_(node->right);
            delete node;
        }
    }

    AVLTree::~AVLTree() {
        clear();
    }

}  // namespace itis
