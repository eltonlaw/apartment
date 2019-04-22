#!/data/data/com.termux/files/usr/bin/sh

# Termux setup script
pkg install vim tmux python -y && \
python -m pip install requests && \
python -m pip install flask
