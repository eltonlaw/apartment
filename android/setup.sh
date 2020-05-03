cp cfg/vimrc $HOME/.vimrc
cp cfg/bashrc $HOME/.bashrc
cp cfg/tmux.conf $HOME/.tmux.conf

pkg install -y make vim tmux python neofetch nmap
python -m pip install requests
