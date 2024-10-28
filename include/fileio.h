#ifndef FILEIO_H
#define FILEIO_H

#include "stack.h"
#include "queue.h"           
#include "linkedlist.h"
#include "hashtable.h"
#include "tree.h"

#include <stdbool.h>


typedef enum {
    FILE_TYPE_TEXT,
    FILE_TYPE_BINARY
} FileType;


bool save_stack(Stack* stack, const char* filename, FileType type);
Stack* load_stack(const char* filename, FileType type);


bool save_queue(Queue* queue, const char* filename, FileType type);
Queue* load_queue(const char* filename, FileType type);


bool save_linkedlist(LinkedList* list, const char* filename, FileType type);
LinkedList* load_linkedlist(const char* filename, FileType type);


bool save_hashtable(HashTable* table, const char* filename, FileType type);
HashTable* load_hashtable(const char* filename, FileType type);


bool save_tree(Tree* tree, const char* filename, FileType type);
Tree* load_tree(const char* filename, FileType type);

#endif 
