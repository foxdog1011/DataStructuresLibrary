# 定義編譯器和編譯選項
$gcc = "gcc"
$cflags = "-I./include -Wall -Wextra -std=c11"
$output = "main.exe"

# 定義源文件
$sources = @(
    "src/main.c",
    "src/stack.c",
    "src/queue.c",
    "src/linkedlist.c",
    "src/hashtable.c",
    "src/tree.c",
    "src/fileio.c"
)

# 編譯命令
$command = "$gcc $cflags -o $output " + ($sources -join " ")

# 執行編譯
Invoke-Expression $command

# 檢查編譯結果
if (Test-Path $output) {
    Write-Output "編譯成功，生成 $output"
} else {
    Write-Output "編譯失敗"
}
