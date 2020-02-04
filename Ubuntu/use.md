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

### 