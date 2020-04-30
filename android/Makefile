# Termux Build

SCRIPT_NAME = dostuff
BINARY_NAME = qq
BINARY_PATH = $$HOME/bin

all: build install

build: deps configs
install: install-bin

deps:
	@echo "android/$@"
	pkg install -y make vim tmux python neofetch nmap
	python -m pip install requests

configs:
	@echo "android/$@"
	cp cfg/vimrc $(HOME)/.vimrc
	cp cfg/bashrc $(HOME)/.bashrc
	cp cfg/tmux.conf $(HOME)/.tmux.conf

install-bin: local-bin-dir
	chmod +x $(SCRIPT_NAME).py
	cp $(SCRIPT_NAME).py $(BINARY_PATH)/$(BINARY_NAME)
	@echo "If first time install, make sure to source ~/.bashrc"

local-bin-dir:
	mkdir -p $(BINARY_PATH)
	chown -R $(shell whoami) $(BINARY_PATH)
	echo 'export PATH=$(BINARY_PATH):$$PATH' >> ~/.bashrc
