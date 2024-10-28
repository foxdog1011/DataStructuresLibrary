#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/**
 * @brief 創建一個新的雙向鏈表
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
 */
bool is_linkedlist_empty(LinkedList* list) {
    if (!list) return true;
    return (list->head == NULL);
}

/**
 * @brief 前插節點到鏈表
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

    if (list->head) {
        list->head->prev = node;
    } else {
        list->tail = node;
    }
    list->head = node;
    return true;
}

/**
 * @brief 後插節點到鏈表
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

    if (list->tail) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
    return true;
}

/**
 * @brief 刪除鏈表中的節點
 */
bool delete_node(LinkedList* list, int data) {
    if (!list) return false;

    ListNode* node = find_node(list, data);
    if (!node) return false;

    if (node->prev) {
        node->prev->next = node->next;
    } else { // node is head
        list->head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else { // node is tail
        list->tail = node->prev;
    }

    free(node);
    return true;
}

/**
 * @brief 查找鏈表中的節點
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
