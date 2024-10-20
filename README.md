markdown
複製程式碼
# DataStructuresLibrary

## 專案簡介
DataStructuresLibrary 是一個用 C 語言實現的資料結構庫，包含堆疊、佇列、雙向鏈表、哈希表和二叉樹等常用資料結構。每個資料結構都支持基本操作，如插入、刪除、查找和遍歷，並提供了將資料結構保存到文件和從文件加載的功能。

## 目錄結構
```plaintext
DataStructuresLibrary/
├── include/
│   ├── stack.h
│   ├── queue.h
│   ├── linkedlist.h
│   ├── hashtable.h
│   ├── tree.h
│   └── fileio.h
├── src/
│   ├── stack.c
│   ├── queue.c
│   ├── linkedlist.c
│   ├── hashtable.c
│   ├── tree.c
│   └── fileio.c
├── tests/
│   ├── test_stack.c
│   ├── test_queue.c
│   ├── test_linkedlist.c
│   ├── test_hashtable.c
│   └── test_tree.c
├── Makefile
├── build.ps1
└── README.md
使用方法
編譯專案
使用 make 命令編譯專案：

powershell
複製程式碼
make
運行主程式
編譯完成後，運行生成的 main.exe：

powershell
複製程式碼
.\main.exe
運行測試用例
運行所有測試用例：

powershell
複製程式碼
make test_all
或者運行特定的測試：

powershell
複製程式碼
make test_queue
功能列表
堆疊（Stack）
創建：初始化一個新的堆疊。
判斷是否為空：檢查堆疊是否為空。
推入：將元素推入堆疊頂部。
彈出：從堆疊頂部彈出元素。
查看頂部元素：查看堆疊頂部的元素而不彈出。
釋放：釋放堆疊佔用的內存。
佇列（Queue）
創建：初始化一個新的佇列。
判斷是否為空：檢查佇列是否為空。
入佇列：將元素加入佇列尾部。
出佇列：從佇列前端移除元素。
查看前端元素：查看佇列前端的元素而不移除。
釋放：釋放佇列佔用的內存。
雙向鏈表（LinkedList）
創建：初始化一個新的雙向鏈表。
判斷是否為空：檢查鏈表是否為空。
前插：在鏈表前端插入元素。
後插：在鏈表後端插入元素。
刪除節點：刪除指定的節點。
查找節點：查找鏈表中的特定節點。
釋放：釋放鏈表佔用的內存。
哈希表（HashTable）
創建：初始化一個新的哈希表。
插入：在哈希表中插入鍵值對。
搜索：在哈希表中搜索特定的鍵。
刪除：從哈希表中刪除指定的鍵。
釋放：釋放哈希表佔用的內存。
二叉樹（Tree）
創建：初始化一個新的二叉樹。
插入：在二叉樹中插入節點。
前序遍歷：以前序方式遍歷二叉樹。
中序遍歷：以中序方式遍歷二叉樹。
後序遍歷：以後序方式遍歷二叉樹。
刪除節點：刪除二叉樹中的指定節點。
釋放：釋放二叉樹佔用的內存。
文件操作（FileIO）
保存和加載：將各種資料結構保存到文本或二進制文件中，並從文件加載資料結構。
編譯系統
Makefile：使用 GNU Make 工具來編譯專案和運行測試用例。
build.ps1：PowerShell 腳本，用於自動化編譯和構建過程。
貢獻
歡迎提交問題（issues）和拉取請求（pull requests），以改進此專案。請確保在提交之前檢查現有的問題，以避免重複。

步驟
Fork 此專案。
創建您的特性分支 (git checkout -b feature/YourFeature)。
提交您的更改 (git commit -m 'Add some feature')。
推送到分支 (git push origin feature/YourFeature)。
打開一個 Pull Request。
授權
本專案採用 MIT 許可證。詳情請參閱 LICENSE 文件。

聯繫方式
如有任何問題或建議，請通過 GitHub Issues 與我們聯繫。

感謝您使用 DataStructuresLibrary！希望這個庫能夠幫助您在項目中更輕鬆地使用各種資料結構。