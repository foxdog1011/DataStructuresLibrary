/**
 * @file stack.h
 * @brief 堆疊模組的頭文件
 */

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * @struct StackNode
 * @brief 堆疊節點結構體
 */
typedef struct StackNode {
    int data;               /**< 節點數據 */
    struct StackNode* next; /**< 指向下一個節點的指針 */
} StackNode;

/**
 * @struct Stack
 * @brief 堆疊結構體
 */
typedef struct Stack {
    StackNode* top; /**< 指向堆疊頂部的指針 */
} Stack;

/**
 * @brief 初始化一個新的堆疊
 *
 * @return 指向新堆疊的指針，如果分配失敗則返回 NULL
 */
Stack* create_stack();

/**
 * @brief 判斷堆疊是否為空
 *
 * @param stack 指向要檢查的堆疊
 * @return 如果堆疊為空則返回 true，否則返回 false
 */
bool is_empty(Stack* stack);

/**
 * @brief 將元素推入堆疊
 *
 * @param stack 指向要操作的堆疊
 * @param data 要推入的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool push(Stack* stack, int data);

/**
 * @brief 從堆疊中彈出元素
 *
 * @param stack 指向要操作的堆疊
 * @param data 用於存儲彈出元素的指針
 * @return 成功則返回 true，否則返回 false
 */
bool pop(Stack* stack, int* data);

/**
 * @brief 獲取堆疊頂部元素而不彈出
 *
 * @param stack 指向要操作的堆疊
 * @param data 用於存儲頂部元素的指針
 * @return 成功則返回 true，否則返回 false
 */
bool peek(Stack* stack, int* data);

/**
 * @brief 釋放堆疊佔用的內存
 *
 * @param stack 指向要釋放的堆疊
 */
void free_stack(Stack* stack);

#endif // STACK_H
