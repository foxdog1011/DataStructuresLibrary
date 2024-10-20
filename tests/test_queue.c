#include <stdio.h>
#include <assert.h>
#include "queue.h"

/**
 * @brief 測試創建佇列
 */
void test_create_queue() {
    Queue* queue = create_queue();
    assert(queue != NULL);
    assert(is_queue_empty(queue));
    free_queue(queue);
    printf("test_create_queue passed.\n");
}

/**
 * @brief 測試入佇列和出佇列操作
 */
void test_enqueue_dequeue() {
    Queue* queue = create_queue();
    assert(enqueue(queue, 100) == true);
    assert(enqueue(queue, 200) == true);
    assert(enqueue(queue, 300) == true);
    assert(!is_queue_empty(queue));

    int data;
    assert(dequeue(queue, &data) == true);
    assert(data == 100);
    assert(dequeue(queue, &data) == true);
    assert(data == 200);
    assert(dequeue(queue, &data) == true);
    assert(data == 300);
    assert(is_queue_empty(queue));

    free_queue(queue);
    printf("test_enqueue_dequeue passed.\n");
}

/**
 * @brief 測試查看前端元素
 */
void test_peek_queue() {
    Queue* queue = create_queue();
    enqueue(queue, 400);
    int data;
    assert(peek_queue(queue, &data) == true);
    assert(data == 400);
    assert(!is_queue_empty(queue));
    free_queue(queue);
    printf("test_peek_queue passed.\n");
}

/**
 * @brief 測試從空佇列中出佇列
 */
void test_dequeue_empty() {
    Queue* queue = create_queue();
    int data;
    assert(dequeue(queue, &data) == false);
    free_queue(queue);
    printf("test_dequeue_empty passed.\n");
}

int main() {
    test_create_queue();
    test_enqueue_dequeue();
    test_peek_queue();
    test_dequeue_empty();
    printf("All queue tests passed.\n");
    return 0;
}
