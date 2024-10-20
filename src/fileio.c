#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

/* 全局或靜態變量來保存文件指針 */
static FILE* g_file = NULL;

/**
 * @brief 用於中序遍歷時保存數據到文本文件的輔助函數
 *
 * @param data 節點數據
 */
void inorder_save(int data) {
    if (g_file) {
        fprintf(g_file, "%d\n", data);
    }
}

/**
 * @brief 用於中序遍歷時保存數據到二進制文件的輔助函數
 *
 * @param data 節點數據
 */
void inorder_save_binary(int data) {
    if (g_file) {
        fwrite(&data, sizeof(int), 1, g_file);
    }
}

/**
 * @brief 保存堆疊到文件
 *
 * 將堆疊的內容保存到指定的文本或二進制文件中。
 *
 * @param stack 指向要保存的堆疊
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 成功則返回 true，否則返回 false
 */
bool save_stack(Stack* stack, const char* filename, FileType type) {
    if (!stack || !filename) return false;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "w");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        StackNode* current = stack->top;
        while (current) {
            fprintf(file, "%d\n", current->data);
            current = current->next;
        }
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "wb");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        StackNode* current = stack->top;
        while (current) {
            fwrite(&(current->data), sizeof(int), 1, file);
            current = current->next;
        }
    }
    fclose(file);
    return true;
}

/**
 * @brief 加載堆疊從文件
 *
 * 從指定的文本或二進制文件中加載堆疊內容。
 *
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 指向加載後的堆疊，如果加載失敗則返回 NULL
 */
Stack* load_stack(const char* filename, FileType type) {
    if (!filename) return NULL;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "r");
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "rb");
    }
    if (!file) {
        perror("Failed to open file for reading");
        return NULL;
    }

    Stack* stack = create_stack();
    if (!stack) {
        fclose(file);
        return NULL;
    }

    int data;
    while (1) {
        if (type == FILE_TYPE_TEXT) {
            if (fscanf(file, "%d", &data) != 1) break;
        } else { // FILE_TYPE_BINARY
            if (fread(&data, sizeof(int), 1, file) != 1) break;
        }
        push(stack, data);
    }

    fclose(file);
    return stack;
}

/**
 * @brief 保存佇列到文件
 *
 * 將佇列的內容保存到指定的文本或二進制文件中。
 *
 * @param queue 指向要保存的佇列
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 成功則返回 true，否則返回 false
 */
bool save_queue(Queue* queue, const char* filename, FileType type) {
    if (!queue || !filename) return false;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "w");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        QueueNode* current = queue->front;
        while (current) {
            fprintf(file, "%d\n", current->data);
            current = current->next;
        }
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "wb");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        QueueNode* current = queue->front;
        while (current) {
            fwrite(&(current->data), sizeof(int), 1, file);
            current = current->next;
        }
    }
    fclose(file);
    return true;
}

/**
 * @brief 加載佇列從文件
 *
 * 從指定的文本或二進制文件中加載佇列內容。
 *
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 指向加載後的佇列，如果加載失敗則返回 NULL
 */
Queue* load_queue(const char* filename, FileType type) {
    if (!filename) return NULL;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "r");
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "rb");
    }
    if (!file) {
        perror("Failed to open file for reading");
        return NULL;
    }

    Queue* queue = create_queue();
    if (!queue) {
        fclose(file);
        return NULL;
    }

    int data;
    while (1) {
        if (type == FILE_TYPE_TEXT) {
            if (fscanf(file, "%d", &data) != 1) break;
        } else { // FILE_TYPE_BINARY
            if (fread(&data, sizeof(int), 1, file) != 1) break;
        }
        enqueue(queue, data);
    }

    fclose(file);
    return queue;
}

/**
 * @brief 保存雙向鏈表到文件
 *
 * 將雙向鏈表的內容保存到指定的文本或二進制文件中。
 *
 * @param list 指向要保存的雙向鏈表
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 成功則返回 true，否則返回 false
 */
bool save_linkedlist(LinkedList* list, const char* filename, FileType type) {
    if (!list || !filename) return false;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "w");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        ListNode* current = list->head;
        while (current) {
            fprintf(file, "%d\n", current->data);
            current = current->next;
        }
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "wb");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        ListNode* current = list->head;
        while (current) {
            fwrite(&(current->data), sizeof(int), 1, file);
            current = current->next;
        }
    }
    fclose(file);
    return true;
}

/**
 * @brief 加載雙向鏈表從文件
 *
 * 從指定的文本或二進制文件中加載雙向鏈表內容。
 *
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 指向加載後的雙向鏈表，如果加載失敗則返回 NULL
 */
LinkedList* load_linkedlist(const char* filename, FileType type) {
    if (!filename) return NULL;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "r");
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "rb");
    }
    if (!file) {
        perror("Failed to open file for reading");
        return NULL;
    }

    LinkedList* list = create_linkedlist();
    if (!list) {
        fclose(file);
        return NULL;
    }

    int data;
    while (1) {
        if (type == FILE_TYPE_TEXT) {
            if (fscanf(file, "%d", &data) != 1) break;
        } else { // FILE_TYPE_BINARY
            if (fread(&data, sizeof(int), 1, file) != 1) break;
        }
        insert_back(list, data);
    }

    fclose(file);
    return list;
}

/**
 * @brief 保存哈希表到文件
 *
 * 將哈希表的內容保存到指定的文本或二進制文件中。
 *
 * @param table 指向要保存的哈希表
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 成功則返回 true，否則返回 false
 */
bool save_hashtable(HashTable* table, const char* filename, FileType type) {
    if (!table || !filename) return false;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "w");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        for (int i = 0; i < table->size; i++) {
            HashNode* node = table->table[i];
            while (node) {
                fprintf(file, "%d,%d\n", node->key, node->value);
                node = node->next;
            }
        }
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "wb");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        for (int i = 0; i < table->size; i++) {
            HashNode* node = table->table[i];
            while (node) {
                fwrite(&(node->key), sizeof(int), 1, file);
                fwrite(&(node->value), sizeof(int), 1, file);
                node = node->next;
            }
        }
    }
    fclose(file);
    return true;
}

/**
 * @brief 加載哈希表從文件
 *
 * 從指定的文本或二進制文件中加載哈希表內容。
 *
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 指向加載後的哈希表，如果加載失敗則返回 NULL
 */
HashTable* load_hashtable(const char* filename, FileType type) {
    if (!filename) return NULL;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "r");
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "rb");
    }
    if (!file) {
        perror("Failed to open file for reading");
        return NULL;
    }

    // 假設哈希表大小為 10，您可以根據需要調整
    HashTable* table = create_hashtable(10);
    if (!table) {
        fclose(file);
        return NULL;
    }

    int key, value;
    while (1) {
        if (type == FILE_TYPE_TEXT) {
            if (fscanf(file, "%d,%d", &key, &value) != 2) break;
        } else { // FILE_TYPE_BINARY
            if (fread(&key, sizeof(int), 1, file) != 1) break;
            if (fread(&value, sizeof(int), 1, file) != 1) break;
        }
        hashtable_insert(table, key, value);
    }

    fclose(file);
    return table;
}

/**
 * @brief 保存二叉樹到文件（中序遍歷）
 *
 * 將二叉樹的中序遍歷結果保存到指定的文本或二進制文件中。
 *
 * @param tree 指向要保存的二叉樹
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 成功則返回 true，否則返回 false
 */
bool save_tree(Tree* tree, const char* filename, FileType type) {
    if (!tree || !filename) return false;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "w");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        g_file = file;
        inorder_traverse(tree, inorder_save);
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "wb");
        if (!file) {
            perror("Failed to open file for writing");
            return false;
        }
        g_file = file;
        inorder_traverse(tree, inorder_save_binary);
    }
    fclose(file);
    g_file = NULL;
    return true;
}

/**
 * @brief 加載二叉樹從文件（中序遍歷）
 *
 * 從指定的文本或二進制文件中加載二叉樹內容。此實現假設數據是按照中序遍歷順序存儲的。
 *
 * @param filename 文件名
 * @param type 文件類型（文本或二進制）
 * @return 指向加載後的二叉樹，如果加載失敗則返回 NULL
 */
Tree* load_tree(const char* filename, FileType type) {
    if (!filename) return NULL;

    FILE* file;
    if (type == FILE_TYPE_TEXT) {
        file = fopen(filename, "r");
    } else { // FILE_TYPE_BINARY
        file = fopen(filename, "rb");
    }
    if (!file) {
        perror("Failed to open file for reading");
        return NULL;
    }

    Tree* tree = create_tree();
    if (!tree) {
        fclose(file);
        return NULL;
    }

    int data;
    while (1) {
        if (type == FILE_TYPE_TEXT) {
            if (fscanf(file, "%d", &data) != 1) break;
        } else { // FILE_TYPE_BINARY
            if (fread(&data, sizeof(int), 1, file) != 1) break;
        }
        insert_tree(tree, data);
    }

    fclose(file);
    return tree;
}
