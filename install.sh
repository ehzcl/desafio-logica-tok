#!/bin/sh

set -e

sudo yum install -y nginx 1>/dev/null
[ -e /usr/sbin/nginx ] && sudo service nginx start

echo "PS1='Ewerton@server$ '" >> $HOME/.bashrc

sudo wget -q -O /usr/share/nginx/html/index.html https://raw.githubusercontent.com/ehzcl/desafio-logica-tok/devops/index.html
sudo wget -q -O /usr/share/nginx/html/style.css  https://raw.githubusercontent.com/ehzcl/desafio-logica-tok/devops/style.css

