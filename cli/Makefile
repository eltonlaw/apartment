BINARY_NAME = qq
BINARY_PATH = $$HOME/bin

build:
	cd src && $(MAKE) $@ BINARY_NAME=$(BINARY_NAME) BINARY_PATH=$(BINARY_PATH)

# yay -S bear
# Tool to generate a compile_commands.json for ccls
tooling:
	bear make

.PHONY: clean
clean:
	cd src && $(MAKE) $@ BINARY_NAME=$(BINARY_NAME) BINARY_PATH=$(BINARY_PATH)

install: local-bin-dir
	cp ./$(BINARY_NAME) $(BINARY_PATH)/$(BINARY_NAME)
	@echo "If first time install, make sure to source ~/.bashrc"

local-bin-dir:
	mkdir -p $(BINARY_PATH)
	chown -R $(shell whoami) $(BINARY_PATH)
	echo 'export PATH=$(BINARY_PATH):$$PATH' >> ~/.bashrc
