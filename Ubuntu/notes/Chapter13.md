# Notes for Harley Hahn's Guide to Unix and Linux
## Quotation
    quote的意思是literally interpret a matacharacter
    There are three ways to quote characters: using a backslash, using a pair of single
    quotes, or using a pair of double quotes.
    With the shell, we use the word “escape” a bit differently, as a synonym for quote.
    \转义一个metacharacter，''转义所有的metacharacter，""转义除了$,\,`以外所有metacharacter

    ''称为strong quotes，""称为weak quotes

    \可以quote <Return>，从而实现shell中分行输入，但是''和""不行，但是在输入时，bash进行了一些friendly的处理
    允许'sdads可以在下一行继续输入，直到有'

## built-in
    built-in工具没有单独的man page，可以apropos built-in来看包含所有的built-in工具的man page

    或用help工具,-s选项表示仅查看使用语法

help [-s] *name*

## modify the search path
    bash从PATH变量中查找external tool的路径。
    export PATH="/bin:/usr/bin:/usr/ucb:/usr/local/bin"         colons serve as separator

    以下可以在PATH中添加地址$HOME/bin
    export PATH="$PATH:$HOME/bin"

    以下可以在PATH中添加当前地址
    export PATH="$PATH:."

## command substituion
    用backquote ``告诉shell来调用工具
    如  echo "The time and date are `date`."
    更为复杂的，可以这样
    echo "`basename ${SHELL}`", basename是一个工具

## shell的历史输入
    fc command
    fc -l查看过去的编号
    fc -s 编号 执行对应语句   fc -s 执行上一条语句

    进一步的，有语法

fc -s *pattern*=*replacement number*

## 修改缓存的过去指令数
    export HISTSIZE=你想要的数字

## ls配合正则表达式
    ls XXX*     展示所有以XXX开头，有0个或更多后缀字母的文件
    ls XXX?     展示所有以XXX开头，有且仅有一个后缀字母的文件

## 取别名/取消别名

**alias** [*name*=*commands*]

    例如
    alias lt='ls -l temp*'

    取消别名

**unalias** *name*

    例如
    unalias lt

    backslash can suspend alias temporarily