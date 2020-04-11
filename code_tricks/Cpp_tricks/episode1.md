# Some rules and tricks
## 结构类型
    结构类型可以整体赋值，相同类型可以直接用=来赋值
## 可以将整型强制类型转化为枚举
    enum DAY {SAT, SUN};
    int i = 0;
    DAY day = (DAY)i;

## 丢人办法实现getch

#include <termios.h>
#include <unistd.h>
#include <iostream>
char getch(void)  //网上抄来的代码，自己研究了一下意思。
{
    struct termios oldt, newt;//结构体中包含各种mode flag/
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    //tcgetattr() gets the parameters associated with the object referred by 
    //fd and stores them in the termios structure referenced by termios_p. 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);// c_lflag指local modes,
    //ECHO flag表示echo input character
    //ICANON表示Enable canonical mode
    //In canonical mode, input is made available line by line, while in 
    //noncanical mode input is available immediately 
    //换言之，将local mode设置为不echo加立即读取的形式
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    //tcsetattr() sets the parameters associated with the terminal from the 
    //structure referred by termios_p
    //Optional_actions  specifies when the changes take effect
    //TCSANOW means the change occurs immediately
    ch = getchar();//标准库函数
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);//将模式改回原样，以免影响
    return ch;
}

## 更好的办法（用别人的）
http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/helloworld.html

https://invisible-island.net/ncurses/man/ncurses.3x.html#h3-Initialization

    sudo apt-get install libncurses5-dev libncursesw5-dev
    #include <ncurses.h>
    To link the program with ncurses the flag -lncurses should be added.