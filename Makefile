.PHONY: scan android
SUBDIRS := scan android

all: $(SUBDIRS)
$(SUBDIRS):
	echo $@
	cd $@ && $(MAKE) build && $(MAKE) install

android: scan
