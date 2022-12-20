# 实验一 文件IO

## 1. 实验目的

1. 掌握Linux应用程序命令行参数传递机制
2. 掌握Linux文件读写操作方法
3. 掌握Linux目录操作方法
4. 掌握Linux文件属性获取方法

## 2. 实验任务

实现一个代码行统计工具 **lc** （line counter），该工具统计给定目录或文件的代码行数。**lc**命令参数如下：

```bash
$ lc --help
Usage: lc [OPTION] ... [FILE | DIR] ...
Print newline counts for each FILE or DIR, and a total line if more than one FILE is specified.

With no FILE, or when FILE is -, read standard input.

The options below may be used to control print msg
    -A, --all                     print the total line number only
    -b                            ignore the Blank line when counting
    -r                            count directory Recursively
    -s, --suffix=FILE-SUFFIX    only count the file with specified Suffix
    -h, --help                    display this Help and exit
```

### 输出样例结果

程序执行目录假定如下，文件名称为方便实验结果验证，定义为（非空行数_空行数）。

```bash
$ tree . -L 10
.
├── 1000_20.txt            # 表示有1000行非空行，20行空行，总共1020行
├── 10_5.txt
└── cpp-proj
    ├── 100_15.cpp
    ├── 20_10.txt
    ├── 50_10.h
    └── 80_25.cpp
    └── sub_dir
        └── 10_5.txt
```

### 测试1   单文件

```bash
$ lc 1000_20.txt
line     file
----    ----
1020     1000_20.txt        # 行数右对齐 文件名左对齐
```

### 测试2 多文件

```bash
$ lc 1000_20.txt 10_5.txt
line    file
----    ----
1020     1000_20.txt
  15     10_5.txt
1035     total            # 当不只一个文件时输出总行数
```

### 测试3 文件夹

```bash
$ lc cpp-proj            # 输出文件夹中所有文件行数
line    file
----    ----
 115     cpp-proj/100_15.cpp
 105     cpp-proj/80_25.cpp
  60     cpp-proj/50_10.h
  30     cpp-proj/20_10.txt
 310     total
```

### 测试4  --all选项

```bash
$ lc -A 1000_20.txt 10_5.txt
line    file
----    ----
1035    total

$ lc cpp-proj
line    file
----    ----
 310     total

$ lc --all 10_5.txt  # 如果只有一个文件则选项不起作用
line    file
----    ----
  15    10_5.txt
```

### 测试5  -b选项 忽略空行

```bash
$ lc -b 1000_20.txt
line     file
----    ----
1000     1000_20.txt

$ lc -b 1000_20.txt 10_5.txt
line    file
----    ----
1000     1000_20.txt
  10     10_5.txt
1010     total

$ lc -b cpp-proj
line    file
----    ----
 100     cpp-proj/100_15.cpp
  80     cpp-proj/80_25.cpp
  50     cpp-proj/50_10.h
  20     cpp-proj/20_10.txt
 250     total
```

### 测试6 --suffix选项

```bash
$ lc -s cpp cpp-proj
line    file
----    ----
 115     cpp-proj/100_15.cpp
 105     cpp-proj/80_25.cpp
 220     total

$ lc --suffix=h cpp-proj
line    file
----    ----
  60     cpp-proj/50_10.h
```

### 测试7 -r选项

```bash
$ lc -r cpp-proj                # 递归遍历子文件夹文件
line    file
----    ----
 115    cpp-proj/100_15.cpp
 105     cpp-proj/80_25.cpp
  60    cpp-proj/50_10.h
  30     cpp-proj/20_10.txt
  15     cpp-proj/sub_dir/10_5.txt
 325    total
```

### 测试8 混合选项

```bash
$ lc -r --suffix=txt .            # 递归统计当前文件夹下后缀为txt的文件的行数
line    file
----    ----
  15     ./10_5.txt
1020     ./1000_20.txt
  30     ./cpp-proj/20_10.txt
  15     ./cpp-proj/sub_dir/10_5.txt
1080     total

$ lc -A -r --suffix=txt .        # 递归统计当前文件夹下后缀为txt的文件的总行数
line    file
----    ----
1080     total

$ lc -r -b --suffix=txt .        # 递归统计当前文件夹下后缀为txt的文件的非空行数
  10     ./10_5.txt
1000     ./1000_20.txt
  20     ./cpp-proj/20_10.txt
  10     ./cpp-proj/sub_dir/10_5.txt
1040     total
```

扩展任务（选做）：

1. 提供异常处理，如文件权限不可读。
2. 使用 `wc`命令（Linux下的文件行或字节统计命令）与 `lc`分别统计一个大文件行数（>20w行），对比两个命令的执行时间，系统调用数。

## 3. 实验要求

1. 使用（C/C++/Rust）中任意两种语言完成本实验，并分析两种实现方案的差异（可从代码、二进制大小、执行效率等方面分析）。
2. C/C++ 使用CMake或Makefile构建；Rust使用Cargo构建。
3. 实验报告用markdown文件编写，放置于仓库的doc目录下。