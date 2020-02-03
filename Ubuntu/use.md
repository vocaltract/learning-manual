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

### tty相关
    tty 全称teletype，用于代指terminal
    tty     print the file name of the terminal connected to standard input
    stty    设置terminal的相关信息
    getty   to open communication with a terminal and start the login process

### 输出所有环境变量
    printenv

