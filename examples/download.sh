#!/bin/bash
path=/usr/share/texlive/texmf-dist/tex/generic/hauke96/
url=https://raw.githubusercontent.com/hauke96/LaTeX/master/

# colors
red="\033[0;31m"
green="\033[0;32m"
default="\033[0m"

install() {
    echo -n "INSTALL $1 $2"
    header=$(curl -s --head $url$1)
    valid=$(echo "$header" | grep "HTTP\/1\.1\s200\sOK")
    content=$(curl -s $1)
    if [ -z "$valid" ]
    then
        echo "$red FAILED : "$(echo "$header" | grep "HTTP/1\.1")""
    else
        echo "$content" > ./$1
        echo "$green finished"
    fi
    echo -n $default
}

# echo $(echo $header | grep "HTTP/1\.1")

# execute first echo call with sudo to get the necessary root permissions
echo "DOWNLOADING NEWEST PACKAGES..."

install dadp.sty "........"
install gail.sty "........"
install makrocol.sty "...."
install p4.sty ".........."
install uniscript.cls "..."

echo ""
echo "DONE"
echo "(does not mean that everything just worked fine :P )"
echo ""
echo "You can also use \"git clone https://github.com/hauke96/LaTeX.git\" to get get everything."
