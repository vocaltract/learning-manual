# git learning

## 写在前面
    由于github与git常常一起使用，因此以下教程中会涉及大量github的内容
    本文适用于linux下，windows下需要下载gitbash，在那个窗口下从“初始化文件夹”开始做起即可。

## 注册你的github账号
    这个就不用教了吧，别忘记注册邮箱、用户名以及密码即可。

## 安装
    sudo apt-get install git即可

## 设置用户名与邮箱
    在terminal中键入 git config --global user.name "你的用户名"，建议与github的用户名相同。
    键入 git config --global user.email "你注册github的邮箱"


## 初始化文件夹(optional)
    选择或创建你希望的文件夹，命令行输入git init
    这样就能将该文件夹作为一个本地仓库，从实现对这个文件夹下文件的管理，但并不能起到远端保存代码、防止电脑爆炸后丢失工作项目的功能。
![](/pictures/2.png)

## 创建SSH key
    SSH是一种加密方式，生成并使用这个key能让你的电脑连接上你的github上的远程仓库
    命令行输入
    ssh-keygen -t rsa -b 4096 -C "你注册github的email"
    例如
    ssh-keygen -t rsa -b 4096 -C "1531821358@qq.com"
    接下来全部按回车（使用默认值）即可，最终得到
![](/pictures/3.png)

## 在提示路径下获得你的key
    由于key所在的文件为隐藏文件，要用ls的-a选项来查看
    默认地址在

    用vim打开.ssh文件中的id_rsa.pub，复制其中所有内容

![](/pictures/6.png)
 
## 在github添加该key
    在github的setting界面找到
    
![](/pictures/7.png)
    
    点击New SSH Key将刚刚的所有内容键入即可。 
    
## 连接github
    在命令行中键入ssh -T git@github.com

![](/pictures/8.png)
    
    如果你是第一次连接，会显示

    The authenticity of host 'github.com (13.250.177.223)' can't be established.

    按它的说法一路操作或回车即可

## 将github上的repository clone到本地
    实际上本地也可以新建repository，但是bash脚本有一坨，我比较懒。
    可以在github上新建一个新的repository，再clone到本地。
    以这个repository为例

![](/pictures/10.png)

    将其对应网址https://github.com/vocaltract/learning-manual   加上.git后缀
    在你决定安放文件的地址下，在terminal中键入
    git clone https://github.com/vocaltract/learning-manual.git 当然，你可以clone别的repository

![](/pictures/11.png)

## 使用git

    git add 文件名      将某个文件加入缓冲区，即该文件会被git工具管理的意思。
    若想将所有文件和修改加入缓冲区，则在terminal下键入git add .

[^_^]:
    ![avatar](/pictures/123.png)











