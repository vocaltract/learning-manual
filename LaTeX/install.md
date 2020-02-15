# Personal Installation Guide for Texlive
    To see more detailed information, please refer to the official guide located in the image, the location of which might be 

    /mnt/texlive-doc/texlive-zh-cn

    Certainly, you should download and load the image at first, and I'll introduce the procedure as follows.


## Requisites
    Platform: 
    Ubuntu18.04
    Tools: 
    1.bash
    2.perl-tk(optional, only when you want to use the GUI installation), installed by 
    sudo apt install perl-tk

## 1.Download the image
[click here](https://mirrors.tuna.tsinghua.edu.cn/CTAN/systems/texlive/Images/)

    choose the texlive2019.iso

## 2.Mount
    sudo mount -o loop texlive.iso /mnt
    After that, you can check the official document as I mentioned above.

## 3.Install
    cd /mnt && ./install-tl

    If you want to use the GUI installation, you should type

    cd /mnt && ./install-tl -gui

    If you use the CTI installation, I recommend you to check the function of any key before you install the software.

    And as the Texlive is quite large, please be patient!

## 4.Configure the Environment Variable
    cd ~ && vim .profile
    Append the following commands in the .profile


    # set PATH for texlive
    export PATH=/usr/local/texlive/2019/bin/x86_64-linux:$PATH                  
    export MANPATH=/usr/local/texlive/2019/texmf-dist/doc/man:$MANPATH
    export INFOPATH=/usr/local/texlive/2019/texmf-dist/doc/info:$INFOPATH

## 5. Unmount
    cd ~ && sudo unmount /mnt


## 6. Test
    First, you can type tex --version in the terminal.
    Second, here is a test tex file in the folder, you can use it with vscode.


