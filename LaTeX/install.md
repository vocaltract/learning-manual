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


## 4. Unmount
    cd ~ && sudo unmount /mnt

## 4.Configure the Environment Variable
    cd ~ && vim .profile
    Append the following commands in the .profile


    # set PATH for texlive
    export PATH=/usr/local/texlive/2019/bin/x86_64-linux:$PATH                  
    export MANPATH=/usr/local/texlive/2019/texmf-dist/doc/man:$MANPATH
    export INFOPATH=/usr/local/texlive/2019/texmf-dist/doc/info:$INFOPATH

## 5.Get fonts from windows

    cd /usr/share/fonts/truetype
    sudo mkdir myfont
    cd /usr/share/fonts/opentype
    sudo mkdir myfont
    cd /media/你的用户名/0/Windows/Fonts
    sudo cp *.TTF *.ttf /usr/share/fonts/truetype/myfont
    sudo cp *.ttc /usr/share/fonts/opentype/myfont
    可能会提示找不到部分文件，不用担心，查看一下目标文件夹下是否有大部分字体就行 
    sudo fc-cache -fsv(这一步很慢，要耐心哦)

## 6.Configure the downloading source and update(optional)
    This step is quite slow, please be patient.
    sudo tlmgr option -repository https://mirrors.tuna.tsinghua.edu.cn/CTAN/systems/texlive/tlnet
    sudo tlmgr update --self --all

    Sometimes, root account may still not contain the PATH of Texlive, and you will see tlmgr is not found.
    Alternatively, you can login in the root account, and type

    export PATH=/usr/local/texlive/2019/bin/x86_64-linux:$PATH
    
    Then tlmgr is available to you.  

    Besides, update is quite slow, too.

## Configure the VScode
    Install the LaTeX Workshop extension.
    Invoke the shortcut Ctrl-Shift-P.
    Type:    settings.json     and switch into the settings.json file.
    Substitute the content of the file with the following content.


    {
    "latex-workshop.view.pdf.viewer": "tab",
    "latex-workshop.latex.autoBuild.onTexChange.enabled": true,
    "latex-workshop.latex.tools": [
    {
    "name": "latexmk",
    "command": "latexmk",
    "args": [
    "-synctex=1",
    "-interaction=nonstopmode",
    "-file-line-error",
    "-pdf",
    "%DOC%"
    ]
    },
    {
    "name": "xelatex",
    "command": "xelatex",
    "args": [
    "-synctex=1",
    "-interaction=nonstopmode",
    "-file-line-error",
    "%DOC%"
    ]
    },
    {
    "name": "pdflatex",
    "command": "pdflatex",
    "args": [
    "-synctex=1",
    "-interaction=nonstopmode","-file-line-error",
    "%DOC%"
    ]
    },
    {
    "name": "bibtex",
    "command": "bibtex",
    "args": [
    "%DOCFILE%"
    ]
    }
    ],
    "latex-workshop.latex.recipes": [
    {
    "name": "xelatex",
    "tools": [
    "xelatex"
    ]
    },
    {
    "name": "latexmk",
    "tools": [
    "latexmk"
    ]
    },
    {
    "name": "pdflatex -> bibtex -> pdflatex*2",
    "tools": [
    "pdflatex",
    "bibtex",
    "pdflatex",
    "pdflatex"
    ]
    }
    ],
    "editor.wordWrap": "bounded"
    }   


## 7. Test
    First, you can type tex --version in the terminal.
    Second, here is a test tex file called OS.tex in the folder, you can use it with vscode extensions.

## Addtional
    查看系统中有哪些中文字体
    fc-list :lang=zh