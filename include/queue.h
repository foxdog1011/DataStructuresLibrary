#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/**
 * @struct QueueNode
 * @brief 佇列節點結構體
 */
typedef struct QueueNode {
    int data;                   /**< 節點數據 */
    struct QueueNode* next;     /**< 指向下一個節點的指針 */
} QueueNode;

/**
 * @struct Queue
 * @brief 佇列結構體
 */
typedef struct Queue {
    QueueNode* front;           /**< 指向佇列前端的指針 */
    QueueNode* rear;            /**< 指向佇列後端的指針 */
} Queue;

/**
 * @brief 創建一個新的佇列
 *
 * 分配內存並初始化佇列的前端和後端為 NULL。
 *
 * @return 指向新佇列的指針，如果分配失敗則返回 NULL
 */
Queue* create_queue();

/**
 * @brief 判斷佇列是否為空
 *
 * @param queue 指向要檢查的佇列
 * @return 如果佇列為空則返回 true，否則返回 false
 */
bool is_queue_empty(Queue* queue);

/**
 * @brief 進行入佇列操作
 *
 * 將一個新元素添加到佇列的後端。
 *
 * @param queue 指向要操作的佇列
 * @param data 要添加的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool enqueue(Queue* queue, int data);

/**
 * @brief 進行出佇列操作
 *
 * 從佇列的前端移除一個元素並返回其數據。
 *
 * @param queue 指向要操作的佇列
 * @param data 用於存儲移除的元素數據的指針
 * @return 成功則返回 true，否則返回 false
 */
bool dequeue(Queue* queue, int* data);

/**
 * @brief 查看佇列前端元素
 *
 * 獲取佇列前端的元素數據而不移除該元素。
 *
 * @param queue 指向要操作的佇列
 * @param data 用於存儲前端元素數據的指針
 * @return 成功則返回 true，否則返回 false
 */
bool peek_queue(Queue* queue, int* data);

/**
 * @brief 釋放佇列佔用的內存
 *
 * 釋放佇列中所有節點的內存，然後釋放佇列本身。
 *
 * @param queue 指向要釋放的佇列
 */
void free_queue(Queue* queue);

#endif // QUEUE_H
