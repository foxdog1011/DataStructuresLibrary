#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * @brief 初始化一個新的堆疊
 *
 * 分配內存並初始化堆疊的頂部為 NULL。
 *
 * @return 指向新堆疊的指針，如果分配失敗則返回 NULL
 */
Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        perror("Failed to create stack");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

/**
 * @brief 判斷堆疊是否為空
 *
 * 檢查堆疊的頂部是否為 NULL。
 *
 * @param stack 指向要檢查的堆疊
 * @return 如果堆疊為空則返回 true，否則返回 false
 */
bool is_empty(Stack* stack) {
    if (!stack) return true;
    return stack->top == NULL;
}

/**
 * @brief 將元素推入堆疊
 *
 * 創建一個新的節點並將其推入堆疊頂部。
 *
 * @param stack 指向要操作的堆疊
 * @param data 要推入的元素數據
 * @return 成功則返回 true，否則返回 false
 */
bool push(Stack* stack, int data) {
    if (!stack) return false;
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (!node) {
        perror("Failed to push data onto stack");
        return false;
    }
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    return true;
}

/**
 * @brief 從堆疊中彈出元素
 *
 * 移除並返回堆疊頂部的元素。
 *
 * @param stack 指向要操作的堆疊
 * @param data 用於存儲彈出元素的指針
 * @return 成功則返回 true，否則返回 false
 */
bool pop(Stack* stack, int* data) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack underflow\n");
        return false;
    }
    StackNode* temp = stack->top;
    if (data) {
        *data = temp->data;
    }
    stack->top = stack->top->next;
    free(temp);
    return true;
}

/**
 * @brief 獲取堆疊頂部元素而不彈出
 *
 * 查看堆疊頂部的元素但不移除它。
 *
 * @param stack 指向要操作的堆疊
 * @param data 用於存儲頂部元素的指針
 * @return 成功則返回 true，否則返回 false
 */
bool peek(Stack* stack, int* data) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        return false;
    }
    if (data) {
        *data = stack->top->data;
    }
    return true;
}

/**
 * @brief 釋放堆疊佔用的內存
 *
 * 釋放堆疊中所有節點的內存，然後釋放堆疊本身。
 *
 * @param stack 指向要釋放的堆疊
 */
void free_stack(Stack* stack) {
    if (!stack) return;
    StackNode* current = stack->top;
    while (current) {
        StackNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}
