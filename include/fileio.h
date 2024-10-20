#ifndef FILEIO_H
#define FILEIO_H

#include "stack.h"
#include "queue.h"           // 確保包含 queue.h
#include "linkedlist.h"
#include "hashtable.h"
#include "tree.h"

// 定義文件操作的類型
typedef enum {
    FILE_TYPE_TEXT,
    FILE_TYPE_BINARY
} FileType;

// 保存堆疊到文件
bool save_stack(Stack* stack, const char* filename, FileType type);

// 加載堆疊從文件
Stack* load_stack(const char* filename, FileType type);

// 保存佇列到文件
bool save_queue(Queue* queue, const char* filename, FileType type);

// 加載佇列從文件
Queue* load_queue(const char* filename, FileType type);

// 保存雙向鏈表到文件
bool save_linkedlist(LinkedList* list, const char* filename, FileType type);

// 加載雙向鏈表從文件
LinkedList* load_linkedlist(const char* filename, FileType type);

// 保存哈希表到文件
bool save_hashtable(HashTable* table, const char* filename, FileType type);

// 加載哈希表從文件
HashTable* load_hashtable(const char* filename, FileType type);

// 保存二叉樹到文件
bool save_tree(Tree* tree, const char* filename, FileType type);

// 加載二叉樹從文件
Tree* load_tree(const char* filename, FileType type);

#endif // FILEIO_H
