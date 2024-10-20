#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**
 * @brief 初始化鏈表
 *
 * 分配內存並初始化鏈表的頭部和尾部為 NULL。
 *
 * @return 指向新鏈表的指針，如果分配失敗則返回 NULL
 */
LinkedList* create_linkedlist() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        perror("Failed to create linked list");
        return NULL;
    }
    list->head = list->tail = NULL;
    return list;
}

/**
 * @brief 判斷鏈表是否為空
 *
 * 檢查鏈表的頭部是否為 NULL。
 *
 * @param list 指向要檢查的鏈表
 * @return 如果鏈表為空則返回 true，否則返回 false
 */
bool is_linkedlist_empty(LinkedList* list) {
    if (!list) return true;
    return list->head == NULL;
}

/**
 * @brief 前插節點
 *
 * 在鏈表頭部插入一個新的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要插入的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool insert_front(LinkedList* list, int data) {
    if (!list) return false;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (!node) {
        perror("Failed to insert front");
        return false;
    }
    node->data = data;
    node->prev = NULL;
    node->next = list->head;
    if (list->head != NULL) {
        list->head->prev = node;
    } else { // 如果鏈表為空，尾部也指向新節點
        list->tail = node;
    }
    list->head = node;
    return true;
}

/**
 * @brief 後插節點
 *
 * 在鏈表尾部插入一個新的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要插入的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool insert_back(LinkedList* list, int data) {
    if (!list) return false;
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (!node) {
        perror("Failed to insert back");
        return false;
    }
    node->data = data;
    node->next = NULL;
    node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = node;
    } else { // 如果鏈表為空，頭部也指向新節點
        list->head = node;
    }
    list->tail = node;
    return true;
}

/**
 * @brief 刪除節點（根據值）
 *
 * 刪除鏈表中第一個匹配的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要刪除的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool delete_node(LinkedList* list, int data) {
    if (!list) return false;
    ListNode* node = find_node(list, data);
    if (!node) {
        fprintf(stderr, "Node with data %d not found\n", data);
        return false;
    }
    if (node->prev) {
        node->prev->next = node->next;
    } else { // 節點是頭部
        list->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else { // 節點是尾部
        list->tail = node->prev;
    }
    free(node);
    return true;
}

/**
 * @brief 查找節點
 *
 * 查找鏈表中第一個匹配的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要查找的元素數據
 * @return 指向找到的節點的指針，如果未找到則返回 NULL
 */
ListNode* find_node(LinkedList* list, int data) {
    if (!list) return NULL;
    ListNode* current = list->head;
    while (current) {
        if (current->data == data) return current;
        current = current->next;
    }
    return NULL;
}

/**
 * @brief 釋放鏈表佔用的內存
 *
 * 釋放鏈表中所有節點的內存，然後釋放鏈表本身。
 *
 * @param list 指向要釋放的鏈表
 */
void free_linkedlist(LinkedList* list) {
    if (!list) return;
    ListNode* current = list->head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
