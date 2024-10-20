# Makefile

CC = gcc
CFLAGS = -I./include -Wall -Wextra -std=c11

# 定義目標
all: main

main: src/main.c src/stack.c src/queue.c src/linkedlist.c src/hashtable.c src/tree.c src/fileio.c
	$(CC) $(CFLAGS) -o main src/main.c src/stack.c src/queue.c src/linkedlist.c src/hashtable.c src/tree.c src/fileio.c

# 編譯並運行堆疊測試
test_stack: tests/test_stack.c src/stack.c src/fileio.c
	$(CC) $(CFLAGS) -o test_stack tests/test_stack.c src/stack.c src/fileio.c
	./test_stack.exe

# 編譯並運行佇列測試
test_queue: tests/test_queue.c src/queue.c src/fileio.c
	$(CC) $(CFLAGS) -o test_queue tests/test_queue.c src/queue.c src/fileio.c
	./test_queue.exe

# 編譯並運行鏈表測試
test_linkedlist: tests/test_linkedlist.c src/linkedlist.c src/fileio.c
	$(CC) $(CFLAGS) -o test_linkedlist tests/test_linkedlist.c src/linkedlist.c src/fileio.c
	./test_linkedlist.exe

# 編譯並運行哈希表測試
test_hashtable: tests/test_hashtable.c src/hashtable.c src/fileio.c
	$(CC) $(CFLAGS) -o test_hashtable tests/test_hashtable.c src/hashtable.c src/fileio.c
	./test_hashtable.exe

# 編譯並運行樹測試
test_tree: tests/test_tree.c src/tree.c src/fileio.c
	$(CC) $(CFLAGS) -o test_tree tests/test_tree.c src/tree.c src/fileio.c
	./test_tree.exe

# 編譯並運行所有測試
test_all: test_stack test_queue test_linkedlist test_hashtable test_tree
	echo "All tests passed."

# 清理編譯生成的文件
clean:
	Remove-Item -Path .\main.exe, .\test_stack.exe, .\test_queue.exe, .\test_linkedlist.exe, .\test_hashtable.exe, .\test_tree.exe -ErrorAction SilentlyContinue
