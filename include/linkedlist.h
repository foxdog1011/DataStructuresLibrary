#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

/**
 * @struct ListNode
 * @brief 雙向鏈表節點結構體
 */
typedef struct ListNode {
    int data;               /**< 節點數據 */
    struct ListNode* prev;  /**< 指向前一個節點的指針 */
    struct ListNode* next;  /**< 指向下一個節點的指針 */
} ListNode;

/**
 * @struct LinkedList
 * @brief 雙向鏈表結構體
 */
typedef struct LinkedList {
    ListNode* head; /**< 指向鏈表頭部的指針 */
    ListNode* tail; /**< 指向鏈表尾部的指針 */
} LinkedList;

/**
 * @brief 初始化鏈表
 *
 * 分配內存並初始化鏈表的頭部和尾部為 NULL。
 *
 * @return 指向新鏈表的指針，如果分配失敗則返回 NULL
 */
LinkedList* create_linkedlist();

/**
 * @brief 判斷鏈表是否為空
 *
 * 檢查鏈表的頭部是否為 NULL。
 *
 * @param list 指向要檢查的鏈表
 * @return 如果鏈表為空則返回 true，否則返回 false
 */
bool is_linkedlist_empty(LinkedList* list);

/**
 * @brief 前插節點
 *
 * 在鏈表頭部插入一個新的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要插入的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool insert_front(LinkedList* list, int data);

/**
 * @brief 後插節點
 *
 * 在鏈表尾部插入一個新的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要插入的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool insert_back(LinkedList* list, int data);

/**
 * @brief 刪除節點（根據值）
 *
 * 刪除鏈表中第一個匹配的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要刪除的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool delete_node(LinkedList* list, int data);

/**
 * @brief 查找節點
 *
 * 查找鏈表中第一個匹配的節點。
 *
 * @param list 指向要操作的鏈表
 * @param data 要查找的元素數據
 * @return 指向找到的節點的指針，如果未找到則返回 NULL
 */
ListNode* find_node(LinkedList* list, int data);

/**
 * @brief 釋放鏈表佔用的內存
 *
 * 釋放鏈表中所有節點的內存，然後釋放鏈表本身。
 *
 * @param list 指向要釋放的鏈表
 */
void free_linkedlist(LinkedList* list);

#endif // LINKEDLIST_H
