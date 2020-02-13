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