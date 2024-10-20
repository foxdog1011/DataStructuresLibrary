#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

/**
 * @brief 哈希函數
 *
 * 根據鍵和哈希表大小計算哈希索引。
 *
 * @param key 鍵
 * @param size 哈希表的大小
 * @return 鍵對應的桶索引
 */
int hash_function(int key, int size) {
    return key % size;
}

/**
 * @brief 創建一個新的哈希表
 */
HashTable* create_hashtable(int size) {
    if (size <= 0) return NULL;

    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) {
        perror("Failed to create hash table");
        return NULL;
    }

    table->size = size;
    table->table = (HashNode**)malloc(sizeof(HashNode*) * size);
    if (!table->table) {
        perror("Failed to create hash table buckets");
        free(table);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }

    return table;
}

/**
 * @brief 插入鍵值對到哈希表
 */
bool hashtable_insert(HashTable* table, int key, int value) {
    if (!table) return false;

    int index = hash_function(key, table->size);
    HashNode* node = table->table[index];

    // 檢查鍵是否已存在，若存在則更新值
    while (node) {
        if (node->key == key) {
            node->value = value;
            return true;
        }
        node = node->next;
    }

    // 如果鍵不存在，創建新節點並插入到鏈表頭部
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    if (!new_node) {
        perror("Failed to insert into hash table");
        return false;
    }
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->table[index];
    table->table[index] = new_node;

    return true;
}

/**
 * @brief 搜索哈希表中的鍵
 */
bool hashtable_search(HashTable* table, int key, int* value) {
    if (!table) return false;

    int index = hash_function(key, table->size);
    HashNode* node = table->table[index];

    while (node) {
        if (node->key == key) {
            if (value) {
                *value = node->value;
            }
            return true;
        }
        node = node->next;
    }

    return false;
}

/**
 * @brief 刪除哈希表中的鍵
 */
bool hashtable_delete(HashTable* table, int key) {
    if (!table) return false;

    int index = hash_function(key, table->size);
    HashNode* node = table->table[index];
    HashNode* prev = NULL;

    while (node) {
        if (node->key == key) {
            if (prev) {
                prev->next = node->next;
            } else {
                table->table[index] = node->next;
            }
            free(node);
            return true;
        }
        prev = node;
        node = node->next;
    }

    return false;
}

/**
 * @brief 釋放哈希表佔用的內存
 */
void free_hashtable(HashTable* table) {
    if (!table) return;

    for (int i = 0; i < table->size; i++) {
        HashNode* node = table->table[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(table->table);
    free(table);
}
