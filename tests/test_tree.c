#include <stdio.h>
#include <assert.h>
#include "tree.h"

/**
 * @brief 用於遍歷時打印節點數據
 *
 * @param data 節點數據
 */
void print_node(int data) {
    printf("%d ", data);
}

/**
 * @brief 測試創建樹
 */
void test_create_tree() {
    Tree* tree = create_tree();
    assert(tree != NULL);
    assert(tree->root == NULL);
    free_tree(tree);
    printf("test_create_tree passed.\n");
}

/**
 * @brief 測試插入節點
 */
void test_insert() {
    Tree* tree = create_tree();
    assert(insert_tree(tree, 50) == true);
    assert(insert_tree(tree, 30) == true);
    assert(insert_tree(tree, 70) == true);
    assert(insert_tree(tree, 20) == true);
    assert(insert_tree(tree, 40) == true);
    assert(insert_tree(tree, 60) == true);
    assert(insert_tree(tree, 80) == true);
    // 嘗試插入重複值
    assert(insert_tree(tree, 70) == false);
    free_tree(tree);
    printf("test_insert passed.\n");
}

/**
 * @brief 測試遍歷
 */
void test_traverse() {
    Tree* tree = create_tree();
    insert_tree(tree, 50);
    insert_tree(tree, 30);
    insert_tree(tree, 70);
    insert_tree(tree, 20);
    insert_tree(tree, 40);
    insert_tree(tree, 60);
    insert_tree(tree, 80);

    printf("Preorder traversal: ");
    preorder_traverse(tree, print_node);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traverse(tree, print_node);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traverse(tree, print_node);
    printf("\n");

    free_tree(tree);
    printf("test_traverse passed.\n");
}

/**
 * @brief 測試刪除節點
 */
void test_delete() {
    Tree* tree = create_tree();
    insert_tree(tree, 50);
    insert_tree(tree, 30);
    insert_tree(tree, 70);
    insert_tree(tree, 20);
    insert_tree(tree, 40);
    insert_tree(tree, 60);
    insert_tree(tree, 80);

    // 刪除葉子節點
    assert(delete_tree_node(tree, 20) == true);
    // 刪除節點有一個子節點
    assert(delete_tree_node(tree, 30) == true);
    // 刪除節點有兩個子節點
    assert(delete_tree_node(tree, 50) == true);

    // 確認刪除後的結構
    printf("Preorder traversal after deletions: ");
    preorder_traverse(tree, print_node);
    printf("\n");

    printf("Inorder traversal after deletions: ");
    inorder_traverse(tree, print_node);
    printf("\n");

    printf("Postorder traversal after deletions: ");
    postorder_traverse(tree, print_node);
    printf("\n");

    free_tree(tree);
    printf("test_delete passed.\n");
}

/**
 * @brief 主測試函數
 */
int main() {
    test_create_tree();
    test_insert();
    test_traverse();
    test_delete();
    printf("All tree tests passed.\n");
    return 0;
}
