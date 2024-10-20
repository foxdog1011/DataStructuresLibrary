#include <stdio.h>
#include <assert.h>
#include "hashtable.h"

/**
 * @brief 測試創建哈希表
 */
void test_create_hashtable() {
    HashTable* ht = create_hashtable(10);
    assert(ht != NULL);
    assert(ht->size == 10);
    for (int i = 0; i < 10; i++) {
        assert(ht->table[i] == NULL);
    }
    free_hashtable(ht);
    printf("test_create_hashtable passed.\n");
}

/**
 * @brief 測試插入和查找操作
 */
void test_insert_search() {
    HashTable* ht = create_hashtable(5);
    assert(hashtable_insert(ht, 1, 100) == true);
    assert(hashtable_insert(ht, 6, 600) == true); // 1 and 6 will collide if size=5
    int value;
    assert(hashtable_search(ht, 1, &value) == true);
    assert(value == 100);
    assert(hashtable_search(ht, 6, &value) == true);
    assert(value == 600);
    assert(hashtable_search(ht, 11, &value) == false); // 不存在
    free_hashtable(ht);
    printf("test_insert_search passed.\n");
}

/**
 * @brief 測試刪除操作
 */
void test_delete() {
    HashTable* ht = create_hashtable(5);
    hashtable_insert(ht, 2, 200);
    hashtable_insert(ht, 7, 700);
    assert(hashtable_delete(ht, 2) == true);
    int value;
    assert(hashtable_search(ht, 2, &value) == false);
    assert(hashtable_search(ht, 7, &value) == true);
    assert(value == 700);
    assert(hashtable_delete(ht, 2) == false); // 已刪除
    free_hashtable(ht);
    printf("test_delete passed.\n");
}

int main() {
    test_create_hashtable();
    test_insert_search();
    test_delete();
    printf("All hash table tests passed.\n");
    return 0;
}
