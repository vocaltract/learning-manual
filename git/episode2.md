# git learning ————git操作及其含义

## 踩到的一个坑（建议看完下面的各条再看）
    如果你的修改或新建文件没有被commit，仅仅是add到缓冲区或者根本没有加入缓冲区，你在切换到其他分支时，显示的始终是
    这些改变的最终状态，即这些改变是全局的、共享的。只有将这些改变在某个分支上commit后，你才会在不同的分支间发现区别。

## 初始化文件夹
    选择或创建你希望的文件夹，命令行输入git init
    这样就能将该文件夹作为一个本地仓库，从实现对这个文件夹下文件的管理，但并不能起到远端保存代码、防止电脑爆炸后丢失工作项目的功能。

## 将文件/文件夹添加到缓冲区
    git有缓冲区与工作区之分。添加到缓冲区就可以认为是让git对该文件/文件夹进行管理
    将某个文件加入缓冲区，terminal键入git add 文件名
    若想将当前目录下所有文件和修改加入缓冲区，则在terminal下键入git add .

## 将本地仓库连接到远程仓库
    在git init的基础上
    git remote add origin 仓库所在网址
    例如    git remote add origin https://github.com/vocaltract/learning-manual.git

## 将远程仓库下载到本地
    git clone 网址
    例如    git clone https://github.com/vocaltract/learning-manual.git

## 查看分支信息
    git branch

## 创建并切换到新分支
    git checkout -b 分支名

## 切换分支
    git checkout 分支名

## 将目标分支合并到当前分支
    git merge 分支名

## 
