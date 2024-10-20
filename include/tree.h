#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

/**
 * @struct TreeNode
 * @brief 二叉樹節點結構體
 */
typedef struct TreeNode {
    int data;                   /**< 節點數據 */
    struct TreeNode* left;      /**< 左子節點指針 */
    struct TreeNode* right;     /**< 右子節點指針 */
} TreeNode;

/**
 * @struct Tree
 * @brief 二叉樹結構體
 */
typedef struct Tree {
    TreeNode* root;             /**< 指向樹根的指針 */
} Tree;

/**
 * @brief 創建一個新的二叉樹
 *
 * 分配內存並初始化樹根為 NULL。
 *
 * @return 指向新二叉樹的指針，如果分配失敗則返回 NULL
 */
Tree* create_tree();

/**
 * @brief 插入節點到二叉樹
 *
 * 根據數據值插入節點，保持二叉搜索樹的性質。
 *
 * @param tree 指向要操作的二叉樹
 * @param data 要插入的節點數據
 * @return 成功則返回 true，否則返回 false
 */
bool insert_tree(Tree* tree, int data);

/**
 * @brief 前序遍歷二叉樹
 *
 * @param tree 指向要遍歷的二叉樹
 * @param func 用於處理每個節點數據的函數指針
 */
void preorder_traverse(Tree* tree, void (*func)(int));

/**
 * @brief 中序遍歷二叉樹
 *
 * @param tree 指向要遍歷的二叉樹
 * @param func 用於處理每個節點數據的函數指針
 */
void inorder_traverse(Tree* tree, void (*func)(int));

/**
 * @brief 後序遍歷二叉樹
 *
 * @param tree 指向要遍歷的二叉樹
 * @param func 用於處理每個節點數據的函數指針
 */
void postorder_traverse(Tree* tree, void (*func)(int));

/**
 * @brief 刪除二叉樹中的節點
 *
 * 根據數據值刪除節點，保持二叉搜索樹的性質。
 *
 * @param tree 指向要操作的二叉樹
 * @param data 要刪除的節點數據
 * @return 成功則返回 true，否則返回 false
 */
bool delete_tree_node(Tree* tree, int data);

/**
 * @brief 釋放二叉樹佔用的內存
 *
 * 釋放二叉樹中所有節點的內存，然後釋放樹本身。
 *
 * @param tree 指向要釋放的二叉樹
 */
void free_tree(Tree* tree);

#endif // TREE_H
