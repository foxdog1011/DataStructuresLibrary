#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "hashtable.h"
#include "tree.h"
#include "fileio.h"

/**
 * @brief 用於遍歷時打印節點數據
 *
 * @param data 節點數據
 */
void print_node(int data) {
    printf("%d ", data);
}

int main() {
    // 示例：操作堆疊
    Stack* stack = create_stack();
    if (!stack) {
        fprintf(stderr, "Failed to create stack\n");
        return 1;
    }

    // 推入元素
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    // 查看頂部元素
    int top;
    if (peek(stack, &top)) {
        printf("Stack Top: %d\n", top);
    }

    // 彈出元素
    if (pop(stack, &top)) {
        printf("Popped from stack: %d\n", top);
    }

    // 保存堆疊到文件
    if (save_stack(stack, "stack_data.txt", FILE_TYPE_TEXT)) {
        printf("Stack saved to stack_data.txt\n");
    }

    // 釋放堆疊
    free_stack(stack);

    // 加載堆疊從文件
    Stack* loaded_stack = load_stack("stack_data.txt", FILE_TYPE_TEXT);
    if (loaded_stack) {
        printf("Loaded stack from stack_data.txt\n");
        while (!is_empty(loaded_stack)) {
            if (pop(loaded_stack, &top)) {
                printf("Loaded stack element: %d\n", top);
            }
        }
        free_stack(loaded_stack);
    }

    // 示例：操作佇列
    Queue* queue = create_queue();
    if (!queue) {
        fprintf(stderr, "Failed to create queue\n");
        return 1;
    }
    enqueue(queue, 100);
    enqueue(queue, 200);
    enqueue(queue, 300);

    int front;
    if (peek_queue(queue, &front)) {
        printf("Queue Front: %d\n", front);
    }

    if (dequeue(queue, &front)) {
        printf("Dequeued from queue: %d\n", front);
    }

    // 保存佇列到文件
    if (save_queue(queue, "queue_data.txt", FILE_TYPE_TEXT)) {
        printf("Queue saved to queue_data.txt\n");
    }

    // 釋放佇列
    free_queue(queue);

    // 加載佇列從文件
    Queue* loaded_queue = load_queue("queue_data.txt", FILE_TYPE_TEXT);
    if (loaded_queue) {
        printf("Loaded queue from queue_data.txt\n");
        while (!is_queue_empty(loaded_queue)) {
            if (dequeue(loaded_queue, &front)) {
                printf("Loaded queue element: %d\n", front);
            }
        }
        free_queue(loaded_queue);
    }

    // 示例：操作雙向鏈表
    LinkedList* list = create_linkedlist();
    if (!list) {
        fprintf(stderr, "Failed to create linked list\n");
        return 1;
    }
    insert_back(list, 1000);
    insert_front(list, 500);
    insert_back(list, 1500);

    // 查找節點
    ListNode* node = find_node(list, 1000);
    if (node) {
        printf("Found node with data: %d\n", node->data);
    }

    // 刪除節點
    if (delete_node(list, 500)) {
        printf("Deleted node with data: 500\n");
    }

    // 保存鏈表到文件
    if (save_linkedlist(list, "linkedlist_data.txt", FILE_TYPE_TEXT)) {
        printf("Linked list saved to linkedlist_data.txt\n");
    }

    // 釋放鏈表
    free_linkedlist(list);

    // 加載鏈表從文件
    LinkedList* loaded_list = load_linkedlist("linkedlist_data.txt", FILE_TYPE_TEXT);
    if (loaded_list) {
        printf("Loaded linked list from linkedlist_data.txt\n");
        ListNode* current = loaded_list->head;
        while (current) {
            printf("Linked list element: %d\n", current->data);
            current = current->next;
        }
        free_linkedlist(loaded_list);
    }

    // 示例：操作哈希表
    HashTable* table = create_hashtable(10);
    if (!table) {
        fprintf(stderr, "Failed to create hash table\n");
        return 1;
    }
    hashtable_insert(table, 1, 100);
    hashtable_insert(table, 2, 200);
    hashtable_insert(table, 3, 300);

    if (hashtable_search(table, 2, &front)) {
        printf("HashTable Search: Key 2, Value %d\n", front);
    }

    if (hashtable_delete(table, 1)) {
        printf("Deleted key 1 from hash table\n");
    }

    // 保存哈希表到文件
    if (save_hashtable(table, "hashtable_data.txt", FILE_TYPE_TEXT)) {
        printf("Hash table saved to hashtable_data.txt\n");
    }

    // 釋放哈希表
    free_hashtable(table);

    // 加載哈希表從文件
    HashTable* loaded_table = load_hashtable("hashtable_data.txt", FILE_TYPE_TEXT);
    if (loaded_table) {
        printf("Loaded hash table from hashtable_data.txt\n");
        if (hashtable_search(loaded_table, 3, &front)) {
            printf("Loaded HashTable Search: Key 3, Value %d\n", front);
        }
        free_hashtable(loaded_table);
    }

    // 示例：操作二叉樹
    Tree* tree = create_tree();
    if (!tree) {
        fprintf(stderr, "Failed to create tree\n");
        return 1;
    }
    insert_tree(tree, 50);
    insert_tree(tree, 30);
    insert_tree(tree, 70);
    insert_tree(tree, 20);
    insert_tree(tree, 40);
    insert_tree(tree, 60);
    insert_tree(tree, 80);

    // 前序遍歷
    printf("Preorder traversal: ");
    preorder_traverse(tree, print_node);
    printf("\n");

    // 中序遍歷
    printf("Inorder traversal: ");
    inorder_traverse(tree, print_node);
    printf("\n");

    // 後序遍歷
    printf("Postorder traversal: ");
    postorder_traverse(tree, print_node);
    printf("\n");

    // 刪除節點
    if (delete_tree_node(tree, 20)) {
        printf("Deleted node with data: 20\n");
    }
    if (delete_tree_node(tree, 30)) {
        printf("Deleted node with data: 30\n");
    }
    if (delete_tree_node(tree, 50)) {
        printf("Deleted node with data: 50\n");
    }

    // 中序遍歷後確認刪除
    printf("Inorder traversal after deletions: ");
    inorder_traverse(tree, print_node);
    printf("\n");

    // 保存樹到文件
    if (save_tree(tree, "tree_data.txt", FILE_TYPE_TEXT)) {
        printf("Tree saved to tree_data.txt\n");
    }

    // 釋放樹
    free_tree(tree);

    // 從文件加載樹
    Tree* loaded_tree = load_tree("tree_data.txt", FILE_TYPE_TEXT);
    if (loaded_tree) {
        printf("Loaded tree from tree_data.txt\n");
        printf("Inorder traversal of loaded tree: ");
        inorder_traverse(loaded_tree, print_node);
        printf("\n");
        free_tree(loaded_tree);
    }

    return 0;
}
