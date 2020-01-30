# Ubuntu installation personal guide

## 事先准备
1. 确保磁盘至少有70G或以上的剩余空间（或许更小也行，不保证成功）
2. 一个不小于8G的U盘
3. Ubuntu官网下载18.04版的映像文件
4. windows上官网下载安装UltralSO(试用版即可)

## 空出磁盘空间
    此电脑右键->管理->磁盘管理->右键某个分区的名字->左键压缩卷
    ->输入你要为Ubuntu留出的空间大小（建议不少于70G）->点击下方的压缩即可

## 刻录镜像
    打开UltralSO，左键左上角的“文件”，点击“打开”，打开你下载的Ubuntu映像
    插入U盘
    点击左上角的“启动”，点击“写入硬盘映像……”
    点击左下角“格式化”，选择exfat格式，进行格式化，再写入即可。

## 具体安装
    不要拔出U盘，重启电脑。
    如果没有进入安装程序，查询你的电脑进BIOS的快捷键，重启电脑并进入BIOS，在boot选项中将USB的优先级调至最高。
    进入安装程序后相当无脑，记得选择语言为英文并选择minimal版进行安装即可。另外，一定要记住设置的用户名和密码哦！！！

## 软件配置
### 设置root密码
    terminal中键入sudo passwd root，按提示进行操作即可。一定要记住密码哦！！！

### 更换下载源为清华源
    nano /etc/apt/sources.list
    将其中内容修改为
    

    # 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
    deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
    # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse


    注：nano是Ubuntu的默认编辑器，Ctrl+S保存，Ctrl+X退出。

### 下载常用工具
    apt update
    sudo apt install vim
    sudo apt install gdb
    sudo apt install man
    sudo apt install build-essential
    sudo apt install git

    注： apt是一个apt-get, apt-cache, apt-config的更上层的包装，包含了这三个工具的主要功能

### 安装中文输入法
    此处笔者遭遇了一些奇妙的事情，仅供参考。
    按win键（alt左边那个窗），输入Language Support，进入相关界面。
    点击Install/Remove languages，增选Chinese(simplified)，点击apply
    在上方Language for manuals and windows:中，把下方（鼠标放到上面会有滚动提示）淡颜色的“汉语（中国）”拖到最上方。非常难拖，请反复尝试。
    原来的界面点击Apply System-Wide
    安装fcitx   sudo apt install fcitx
    从以下网址下载deb版搜狗输入法安装包。（提醒，Ubuntu是debian系发行版，安装包总应该选deb版）
    https://pinyin.sogou.com/linux/?r=pinyin
    在deb文件的存放位置，在terminal中输入sudo dpkg -i sogoupinyin_2.3.1.0112_amd64.deb
    安装完成后重启
    如果正常的话，此时搜狗输入法已经可以使用了。    
    为避免被中文环境引发的Bug坑死，重新打开语言设置窗口，将汉语（中国）重新拖到下方，并点击Apply System-Wide，再次重启即可。


### 安装python3-pip
    注意 sudo apt install python-pip默认情况下管理的是python2，下载和安装都会设置到python2
    如果要使用python3的话，请sudo apt install python3-pip，并在使用时用pip3 或 python3 -m pip来调用该命令