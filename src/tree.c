#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/**
 * @brief 創建一個新的二元樹
 */
Tree* create_tree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (!tree) {
        perror("Failed to create tree");
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

/**
 * @brief 插入節點到二元樹
 */
bool insert_tree(Tree* tree, int data) {
    if (!tree) return false;

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!node) {
        perror("Failed to insert into tree");
        return false;
    }
    node->data = data;
    node->left = node->right = NULL;

    if (!tree->root) {
        tree->root = node;
        return true;
    }

    TreeNode* current = tree->root;
    TreeNode* parent = NULL;

    while (current) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else { // Duplicate data not allowed
            free(node);
            return false;
        }
    }

    if (data < parent->data) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    return true;
}

/**
 * @brief 前序遍歷輔助函數
 */
void preorder_traverse_node(TreeNode* node, void (*func)(int)) {
    if (!node) return;
    func(node->data);
    preorder_traverse_node(node->left, func);
    preorder_traverse_node(node->right, func);
}

/**
 * @brief 前序遍歷二元樹
 */
void preorder_traverse(Tree* tree, void (*func)(int)) {
    if (!tree || !func) return;
    preorder_traverse_node(tree->root, func);
}

/**
 * @brief 中序遍歷輔助函數
 */
void inorder_traverse_node(TreeNode* node, void (*func)(int)) {
    if (!node) return;
    inorder_traverse_node(node->left, func);
    func(node->data);
    inorder_traverse_node(node->right, func);
}

/**
 * @brief 中序遍歷二元樹
 */
void inorder_traverse(Tree* tree, void (*func)(int)) {
    if (!tree || !func) return;
    inorder_traverse_node(tree->root, func);
}

/**
 * @brief 後序遍歷輔助函數
 */
void postorder_traverse_node(TreeNode* node, void (*func)(int)) {
    if (!node) return;
    postorder_traverse_node(node->left, func);
    postorder_traverse_node(node->right, func);
    func(node->data);
}

/**
 * @brief 後序遍歷二元樹
 */
void postorder_traverse(Tree* tree, void (*func)(int)) {
    if (!tree || !func) return;
    postorder_traverse_node(tree->root, func);
}

/**
 * @brief 查找最小值節點
 */
TreeNode* find_min(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

/**
 * @brief 刪除節點輔助函數
 */
TreeNode* delete_tree_node_helper(TreeNode* root, int data, bool* success) {
    if (!root) {
        *success = false;
        return root;
    }

    if (data < root->data) {
        root->left = delete_tree_node_helper(root->left, data, success);
    } else if (data > root->data) {
        root->right = delete_tree_node_helper(root->right, data, success);
    } else {
        *success = true;
        // 節點有一個或無子節點
        if (!root->left) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 節點有兩個子節點
        TreeNode* temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_tree_node_helper(root->right, temp->data, success);
    }

    return root;
}

/**
 * @brief 刪除二元樹中的節點
 */
bool delete_tree_node(Tree* tree, int data) {
    if (!tree) return false;
    bool success = false;
    tree->root = delete_tree_node_helper(tree->root, data, &success);
    return success;
}

/**
 * @brief 釋放二元樹佔用的內存
 */
void free_tree_node(TreeNode* node) {
    if (!node) return;
    free_tree_node(node->left);
    free_tree_node(node->right);
    free(node);
}

/**
 * @brief 釋放二元樹佔用的內存
 */
void free_tree(Tree* tree) {
    if (!tree) return;
    free_tree_node(tree->root);
    free(tree);
}
