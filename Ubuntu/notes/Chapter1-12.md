# Harley Hahn's Guide to Unix and Linux
## Warning
    在本文中我混用了shell 和terminal两个概念，实际上这是不同的两个东西。
    Ubuntu18.04的默认的是X terminal
    可以通过查看环境变量TERM来观察。 echo $TERM

## Chapter2
    Microsoft Windows is a multitasking, single-user operating system.
    Unix is a multitasking, multiuser operating system.
## Chapter3
    COMPUTER = TERMINAL + HOST
    TERMINAL = INPUT FACILITY + OUTPUT FACILITY
## Chapter5
    layers of abstraction:
    Desktop Environment eg.GNOME, KDE
    Window Manager eg.Metacity, kwm
    X Window
    Device drivers in the kernel
    Hardware
## Chapter6
### runlevel
    0: Halt(shutdown)
    1: Single-user mode: command line
    2: Not standardized
    3: Multiuser mode: command line
    4: Not standardized
    5: Multiuser mode: GUI
    6: Reboot
### 窗口控制
    <Alt-F4>                  关闭窗口
    <Alt-Tab>                 Task Switching
### desktop切换
    With KDE, the desktop shortcut keys are <Ctrl-Tab> and <Ctrl-Shift-Tab>.
    With Gnome, they are <Ctrl-Alt-Left>, <Ctrl-Alt-Right>, <Ctrl-Alt-Up> and <Ctrl-Alt-Down>.
### 切换runlevel
    sudo init 6 重启
    sudo init 0 关机
### 关机
    sudo shutdown  30秒后关机
    sudo shutdown now  立刻关机
### 重启
    sudo reboot  立刻重启
### 一个查看boot messages的方法
    dmesg | less
    boot messages就是开机时闪过的内容

## Chapter7
### knowledge
    <Ctrl-C>  intr signal 即interrupt
    A environment variable is an entity with a name and a value, which is always available to the shell and to any programs you may run.
    ^C 等价于 <Ctrl-C>  ^是Ctrl的助记符
    Alt and Ctrl are called modifier keys

    三种signal erase werase kill
    erase 删除最后一个字符  <Backspace>或<Delete>或^H
    werase 删除最后一个词   <Ctrl-W>
    kill 删除整行   <Ctrl-U>(Ubuntu18.04) 其他上可能是<Ctrl-X>

    ^? is simply a two-character abbreviation that means “whichever key on your keyboard that sends the code that used to be called DEL”.
    ^\ is mapping to quit signal


### tty相关
    tty 全称teletype，用于代指terminal
    tty     print the file name of the terminal connected to standard input
    stty    设置terminal的相关信息  
    getty   to open communication with a terminal and start the login process

### 输出所有环境变量
    printenv

### ^C的两重用法
    ^C会发送intr, 即interrupt signal
    1.可以用来退出程序的运行，但有些程序trap it（捕获它使其失效，如vim）
    2.可以用来放弃当前command line的输入内容，功能上类似^U发送的kill signal，尽管效果上不相同。
    因为kill是删除字符，但interrupt是放弃当前命令
### ^\
    send quit signal, which is seldom used today.

### ^D
    send EOF signal

### 防止过多的输出屏幕信息干扰阅读
    1. less工具 或 cat工具
    2. ^S sends stop signal.This tells Unix to pause the screen display temporarily. And use ^Q to send
    start signal to continue.

    题外话： 莫名其妙停了应该按^Q试试
### 默认高精度计算器
    bc 跟python3比就是个弟弟。

### stty
    stty -a 查看key mapping
    修改key mapping   eg.  stty kill ^A

### return and linefeed
    linefeed 在过去是将纸上移一行
    return  在过去是将carriage 移到最左边
    linefeed is mapping to ^J
    return is mapping to ^M
    
    In general, every line of text must end with a newline(即^J)

    First, as you type, whenever you press<Return>, Unix changes the return into a newline. That is, it changes the ^M into ^J.
    Second, when data is being written to the terminal, Unix changes each newline to a  return+linefeed. That is, it changes ^J to ^M^J

    第一条是在输入的时候进行转化，第二条是在输出的时候进行转化

## Chapter8

### which 或 type
    which 或 type 可以展示工具的路径
    eg. which vim
    用来查看在path中是否存在某个program

### 日历
    cal
    eg. cal 7 2020 即2020年7月
    eg. cal 2022 即2022年全年
    eg. cal -j 7 2020 展示每日为那年的第某天

### 一些没用的玩意儿
    calendar
    hostname  展示hostname
    uptime  展示时间
    uname 展示OS的名字，加-a获取更多信息
    whoami 你懂得。
    users 或who  所有user的name，who提供更多信息

### w 展示详细

## Chapter 9
    
### man的使用细节
    使用man的时候，！相当于vim的：
    man 一共分为8个部分
    1. Commands
    2. System calls
    3. Library functions
    4. Special files
    5. File formats
    6. Games
    7. Miscellaneous information
    8. System administration
    
    You may also find that a particular section contains specialized sub-sections. For
    example, on some Linux systems, if you look within Section 3 (Library functions), you
    will find several sub-sections: Section 3c, for standard C functions; Section 3f for Fortran
    functions; Section 3m for mathematical functions; Section 3s for standard I/O functions;
    and Section 3x for special functions.


    man 2 kill 查看section2中的kill
    man 数字 intro 查看各section的细节
    man -k name 展示所有section中的name
    man -f name 用一句话解释所有section中的name
### foo and bar
    The idea is that whenever you want to refer to something without a name, you can call
    it “foo”; when you want to refer to two things without a name, you call them “foo” and
    “bar”. Nobody knows for sure how this tradition got started, but it is used a lot.

### options
    single-character options can be combined. eg. -l -F is equivalent to -lF
    一般来说，顺序是无关紧要的。
    dash-dash options. 形如--help, --version.用--是为了避免歧义，否则--help可以解释为-h -e -l -p

### options' syntax
    1. Items in square brackets are optional.
    2. Items not in square brackets are obligatory.
    3. Anything in boldface must be typed exactly as written.
    4. Anything in italics must be replaced by an appropriate value.
    5. An argument followed by an ellipsis (...) may be repeated any number of times.
    6. If you see a single option grouped with an argument, the option and argument must be used together.
    7. Two or more items separated by a | (vertical bar) character, indicates that you are to choose one item from a list.

    此外，若系统不支持斜体，则会用下划线代表斜体。

## Chpater12
### environment
    As a process runs, it has access to what is called the ENVIRONMENT, a table of
    variables, each of which is used to hold information.
### variable
    When you use a Unix shell, there are two different types of variables. They are called
    “shell variables” and “environment variables”.
    
    You can create them, check their value, change their value, or destroy them.
    
    With the shell, however, variables almost always store only one type of data, a
    CHARACTER STRING, that is, a sequence of plain-text characters

### Parent process and child process
    When this happens, is called the PARENT PROCESS or PARENT; the second process is the
    CHILD PROCESS or CHILD. In this case, the parent is the shell and the child is vi.
    At the time the child process is created, it is given an environment which is a copy of
    the parent’s environment. We say that the child INHERITS the parent’s environment.
    This means that all the ENVIRONMENT variables that were accessible to the parent are
    now accessible to the child.


### Bourne shell family
    处理shell variable和environment variable的方法对于C family 和Bourne family截然不同。
    以下仅对Bourne family有效

    对于Bourne family，variable可以是shell variable 或 shell and environment variable，但不可以是
    environment variable
    Every new variable is automatically a shell variable.
    The export command changes a shell variable into a shell+environment variable.

### C shell family
    In the C-Shell family, environment variables are created by the setenv command 
    and are given uppercase names.

    Shell variables are created by the set command and are given lowercase names.

    There are certain variables that have meaning both within the shell and within
    all the child processes.The solution is to have a few special shell variables that are tied to
    environment variables. Whenever one of these variables changes, the shell automatically
    updates the other one.

Shell Variable | Environment Variable | Meaning
:-: | :-: | :-:
cwd | PWD | your current/working directory
home | HOME | your home directory
path | PATH | directories to search for programs
term | TERM | type of terminal you are using
user | USER | current userid


### 查看环境变量
**printenv | sort | less**

### 查看所有shell variable
    set指令without options and arguments.
    Strange but true: The only way to determine which Bourne shell variables are not exported is to
    compare the output of set to the output of env.

### 查看某个variable
    echo ${Variable Name} 当不引起歧义时，{}可省略。
    使用echo时，如果string内部含标点符号，需要用双引号""包裹string，以防标点符号中的metacharacter被解释。
### 创建variable(Bourne)
    形如 WCY_NAME=wcy，注意=两侧不可有空格
    如果value含空格，要用双引号包裹value

    在Bourne family中，每个新创建的变量默认为shell variable

    对于Bourne shell，利用export可以同时创建多个shell and environment变量，语法形如 

export *NAME*[*=value*]...

### 销毁变量(Bourne)

unset *NAME*...
    
    The only way to remove a Bourne shell variable from the environment is to destroy it.

### 创建Environment Variable(C)

setenv *NAME* [*value*]

    不指定value会设置为空值
    用""包裹含空格字符串

### 销毁Environment Variable(C)

unsetenv *NAME*

### 创建Shell Variable(C)

set *name*[*=value*] 

    注意！用()代替""来包裹含空格字符串。

### 销毁Shell Variable(C)
unset *variable*

### SHELL OPTIONS
    with the C-Shell family, we control various aspects of the shell’s
    behavior by using shell variables. With the Bourne shell family, we use SHELL OPTIONS

set option语法为：  

set -o *option*

    例如， set -o monitor

unset option语法为：

set +o *option*
### Display Options
    如果使用bash，可以用shopt来查看option的开关情况

    如果为Bourne Shell，可以用set +o 或set -o，两种指令仅显示格式不同


