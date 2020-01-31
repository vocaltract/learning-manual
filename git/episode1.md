
## 写在前面
    由于github与git常常一起使用，因此以下教程中会涉及大量github的内容
    本文适用于linux下，windows下需要下载gitbash，在gitbash中输入对应命令
    以及，gitbash存在一些设置存放地址的操作，本文不会提及。
    本文将分章节撰写，每一节的重点会写在前面。
    由于作者水平较差，各章节耦合度较高，建议从头看起。

# git learning ————github交互相关

## 注册你的github账号
    这个就不用教了吧，别忘记注册邮箱、用户名以及密码即可。

## 安装
    sudo apt-get install git即可

## 设置用户名与邮箱
    在terminal中键入 git config --global user.name "你的用户名"，建议与github的用户名相同。
    键入 git config --global user.email "你注册github的邮箱"

## 创建SSH key
    SSH是一种加密方式，生成并使用这个key能让你的电脑连接上你的github上的远程仓库
    命令行输入
    ssh-keygen -t rsa -b 4096 -C "你注册github的email"
    例如
    ssh-keygen -t rsa -b 4096 -C "1531821358@qq.com"
    接下来全部按回车（使用默认值）即可

## 在提示路径下获得你的key
    由于key所在的文件为隐藏文件，要用ls的-a选项来查看
    默认地址在/home/用户名/.ssh下
    用vim打开.ssh文件中的id_rsa.pub，复制其中所有内容

## 在github添加该key
    在github的setting界面找到SSH 相关内容。
    
    点击New SSH Key将刚刚的所有内容键入即可。 
    
## 连接github
    在命令行中键入ssh -T git@github.com
    
    如果你是第一次连接，会显示

    The authenticity of host 'github.com (13.250.177.223)' can't be established.

    按它的说法一路操作或回车即可

## 将github上的repository clone到本地
    实际上本地也可以新建repository，但是bash脚本有一坨，我比较懒。
    可以在github上新建一个新的repository，再clone到本地。
    以某个repository为例

    将其对应网址https://github.com/vocaltract/learning-manual加上.git后缀
    在你决定安放文件的地址下，在terminal中键入
    git clone https://github.com/vocaltract/learning-manual.git 当然，你可以clone别的repository


[^_^]:
    ![avatar](/pictures/123.png)











