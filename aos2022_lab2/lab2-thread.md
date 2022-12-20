# 实验二 多线程实验

## 1. 实验目的

1. 掌握Linux多线程程序编写方法
2. 掌握Linux pthread库使用方法
3. 掌握互斥锁与信号量机制

## 2. 实验任务

在实验1基础上扩展 **lc** （line counter）命令，添加参数`-t`指定多线程数量，当有多个文件时使用多线程统计，**lc**命令参数如下：

```bash
$ lc --help
Usage: lc [OPTION] ... [FILE | DIR] ...
Print newline counts for each FILE or DIR, and a total line if more than one FILE is specified. 

With no FILE, or when FILE is -, read standard input.

The options below may be used to control print msg
    -A, --all                     print the total line number only
    -b,                         ignore the blank line when counting
    -r                            count directory Recursively
    -s, --suffix=FILE-SUFFIX    only count the file with specified suffix
    -t, --thread=NUMBER            use multithread to count 
    -h, --help                    display this help and exit
```

## 3. 实验要求

1. 使用（C/C++/Rust）中任意两种语言完成本实验，并分析两种实现方案的差异（可从代码，二进制大小，执行效率等方面分析）
2. C/C++编程使用**pthread** API完成，Rust编程采用语言支持的线程标准库
3. 分析在不同线程数量情况下执行效率与加速比
4. 实验报告用markdown文件编写，放置于仓库的doc目录下