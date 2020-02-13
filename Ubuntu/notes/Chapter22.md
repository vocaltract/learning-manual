# Notes for Harley Hahn's Guide to Unix and Linux
    This chapter is about vim.

## 打开文件的基本语法

**vim** [**-C**] [**-rR**] [*file*...]

    -C表示compatible mode，让vim表现得更像vi
    -R 表示readonly version
    -r recover 使用缓存文件(在异常退出时保存的)

## 查看文件行数及光标所在位置
    ^G
## 输入字面意思的控制符号
    前面加^V
    eg. ^V^V即可得到^V
## 删除行
    1,5d
    删除一到五行

## Cursor moving
Input | Action 
:-:|:-:
0 | move cursor to beginning of current line
$ | move cursor to end of current line
^ | move cursor to first non-space/tab in current line
w | move cursor forward to first character of next word
e | move cursor forward to last character of current word
b | move cursor backward to first character of current word
W | same as w; ignore punctuation
E | same as e; ignore punctuation
B | same as b; ignore punctuation
H | move cursor to top line of screen
M | move cursor to middle line of screen
L | move cursor to last line of screen

均支持counting

## Screen moving
Input | Action
:-: | :-:
^F | move down (forward) one screenful
^B | move up (back) one screenful
^D | move down a half screenful
^U | move up a half screenful
 
 均支持counting

 ## Flexible Cursor moving
 