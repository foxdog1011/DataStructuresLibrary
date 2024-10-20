#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

/**
 * @struct HashNode
 * @brief 哈希表節點結構體
 */
typedef struct HashNode {
    int key;                    /**< 鍵 */
    int value;                  /**< 值 */
    struct HashNode* next;      /**< 指向下一個節點的指針 */
} HashNode;

/**
 * @struct HashTable
 * @brief 哈希表結構體
 */
typedef struct HashTable {
    int size;                   /**< 哈希表的大小 */
    HashNode** table;           /**< 哈希表陣列，指向每個桶的鏈表 */
} HashTable;

/**
 * @brief 創建一個新的哈希表
 *
 * 分配內存並初始化哈希表的各個桶為 NULL。
 *
 * @param size 哈希表的大小
 * @return 指向新哈希表的指針，如果分配失敗則返回 NULL
 */
HashTable* create_hashtable(int size);

/**
 * @brief 哈希函數
 *
 * 根據鍵和哈希表大小計算哈希索引。
 *
 * @param key 鍵
 * @param size 哈希表的大小
 * @return 鍵對應的桶索引
 */
int hash_function(int key, int size);

/**
 * @brief 插入鍵值對到哈希表
 *
 * 根據鍵插入或更新鍵值對。
 *
 * @param table 指向要操作的哈希表
 * @param key 要插入的鍵
 * @param value 要插入的值
 * @return 成功則返回 true，否則返回 false
 */
bool hashtable_insert(HashTable* table, int key, int value);

/**
 * @brief 搜索哈希表中的鍵
 *
 * 根據鍵查找值。
 *
 * @param table 指向要操作的哈希表
 * @param key 要查找的鍵
 * @param value 用於存儲找到的值的指針
 * @return 如果找到則返回 true，否則返回 false
 */
bool hashtable_search(HashTable* table, int key, int* value);

/**
 * @brief 刪除哈希表中的鍵
 *
 * 根據鍵刪除鍵值對。
 *
 * @param table 指向要操作的哈希表
 * @param key 要刪除的鍵
 * @return 如果刪除成功則返回 true，否則返回 false
 */
bool hashtable_delete(HashTable* table, int key);

/**
 * @brief 釋放哈希表佔用的內存
 *
 * 釋放哈希表中所有節點的內存，然後釋放哈希表本身。
 *
 * @param table 指向要釋放的哈希表
 */
void free_hashtable(HashTable* table);

#endif // HASHTABLE_H
