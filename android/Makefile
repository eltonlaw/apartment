# Termux Build
install: deps configs

deps:
	@echo "android/$@"
	pkg install -y make vim tmux python neofetch
	python -m pip install requests

configs:
	@echo "android/$@"
	cp bashrc $(HOME)/.bashrc
	cp tmux.conf $(HOME)/.tmux.conf
