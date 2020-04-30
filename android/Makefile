# Termux Build

SCRIPT_NAME = dostuff
BINARY_NAME = qq
BINARY_PATH = /data/data/com.termux/files/usr/local/bin

all: build install

build: deps configs
install: install-bin

deps:
	@echo "android/$@"
	pkg install -y make vim tmux python neofetch nmap
	python -m pip install requests

configs:
	@echo "android/$@"
	cp bashrc $(HOME)/.bashrc
	cp tmux.conf $(HOME)/.tmux.conf

install-bin: local-bin-dir
	chmod +x $(SCRIPT_NAME).py
	cp $(SCRIPT_NAME).py $(BINARY_PATH)/$(BINARY_NAME)

local-bin-dir:
	mkdir -p $(BINARY_PATH)
	chown -R $(shell whoami) $(BINARY_PATH)
	echo 'export PATH=$(BINARY_PATH):$$PATH' >> ~/.bashrc
