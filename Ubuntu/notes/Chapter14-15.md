# Notes for Harley Hahn's Guide to Unix and Linux

## Initialization File

### Login File
    all the commands you want executed every time you log in
### Environment File
    the commands you want executed every time a new shell starts
### Logout File
    commands that are run automatically whenever you log out

## GUI编辑工具
    gedit     (for Gnome)
    kedit     (for KDE)

## Initialization files' location
    Initialization files are kept in your home directory

## Sequence
    Login file runs first.(Bourne Shell)

##  Redirect　(only correct for Bourne Shell)
    The default file descriptors are 0 for standard input,
    1 for standard output, and 2 for standard error.

### 重定向输出    
    >和>>
    共同点：重定向的文件不存在会为你创建。
    区别：在关闭noclobber的情况下，>原来数据会丢失，而>>是在原来的数据末尾附加

    开启：set -o noclobber
    关闭：set +o noclobber

    一旦开启noclobber
    >的覆盖功能会被禁止。覆盖需要写成 >|
### 重定向输入
    
    <
    一个例子：sort < rawdata > report
    This command reads data from a fi le named rawdata, sorts it, and writes the output to
    a file called report.
### 利用文件描述符进行重定向
*command*  0<  *inputfile*     重定向标准输入

*command*  1>  *outputfile*    重定向stdout

*command*  2>  *outputfile*    重定向stderr

    上述的0,1可以省略，但2不可省略。>可以换为>>

## Subshell 
    When a subshell is created, it inherits the environment of the parent.
    However, any changes the subshell makes to the environment are not passed back to the
    parent.

    Enclosing the commands in parentheses can force the commands to run in a subshell.
    eg. (date)
    好处是不用开一个新的shell

## Combined Output(Bourne Shell)
    redirect both standard output and standard error to the same place
### syntax
*command x*> *outputfile y*>&*x*, 

where the *command* is a command, *x* and *y* are file descriptors, and *outputfile* is the name of a file.


