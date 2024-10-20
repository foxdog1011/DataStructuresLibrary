#include <stdio.h>
#include <assert.h>
#include "linkedlist.h"

/**
 * @brief 測試創建鏈表
 */
void test_create_linkedlist() {
    LinkedList* list = create_linkedlist();
    assert(list != NULL);
    assert(is_linkedlist_empty(list));
    free_linkedlist(list);
    printf("test_create_linkedlist passed.\n");
}

/**
 * @brief 測試前插和後插操作
 */
void test_insert_front_back() {
    LinkedList* list = create_linkedlist();
    assert(insert_front(list, 5) == true);
    assert(insert_back(list, 10) == true);
    assert(insert_front(list, 3) == true);
    assert(insert_back(list, 15) == true);
    assert(!is_linkedlist_empty(list));

    // 檢查順序：3, 5, 10, 15
    assert(list->head->data == 3);
    assert(list->head->next->data == 5);
    assert(list->tail->data == 15);

    free_linkedlist(list);
    printf("test_insert_front_back passed.\n");
}

/**
 * @brief 測試刪除節點
 */
void test_delete_node() {
    LinkedList* list = create_linkedlist();
    insert_back(list, 20);
    insert_back(list, 30);
    insert_back(list, 40);
    assert(delete_node(list, 30) == true);
    assert(find_node(list, 30) == NULL);
    assert(list->head->next->data == 40);
    assert(list->tail->data == 40);
    free_linkedlist(list);
    printf("test_delete_node passed.\n");
}

/**
 * @brief 測試查找節點
 */
void test_find_node() {
    LinkedList* list = create_linkedlist();
    insert_back(list, 50);
    insert_back(list, 60);
    ListNode* node = find_node(list, 60);
    assert(node != NULL);
    assert(node->data == 60);
    node = find_node(list, 70);
    assert(node == NULL);
    free_linkedlist(list);
    printf("test_find_node passed.\n");
}

int main() {
    test_create_linkedlist();
    test_insert_front_back();
    test_delete_node();
    test_find_node();
    printf("All linked list tests passed.\n");
    return 0;
}
