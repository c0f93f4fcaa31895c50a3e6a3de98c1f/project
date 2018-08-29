#=================================
# Auth: Simons<liyulinga@qq.com>
# Date: 2018/8/25
# Desc: Global Makefile
#=================================

export TOPDIR:=$(subst $(prefix),,$(shell pwd))
include comm.mk

libev:=$(TOPDIR)/lib/libev
libev_config:=$(libev)
libev_install:=$(libev)
libev_clean:=$(libev)

libevtest:=$(TOPDIR)/src/libevtest
libevtest_config:=$(libevtest)
libevtest_install:=$(libevtest)
libevtest_clean:=$(libevtest)

sklist:=$(TOPDIR)/src/sklist
sklist_config:=$(sklist)
sklist_install:=$(sklist)
sklist_clean:=$(sklist)

.PHONY:all libev libevtest sklist
all:libev libevtest sklist
libevtest:libev libev_install libevtest_config
	$(MAKE) --directory=$($@)

libev:libev_config
	$(MAKE) --directory=$($@)

sklist:sklist_config
	$(MAKE) --directory=$($@)

.PHONY:config libev_config lievtest_config sklist_config
config:libev_config libevtest_config sklist_config
libevtest_config sklist_config:
	@echo "\033[41;37mNo configure for $($@).\033[0m"

libev_config:
	cd $($@) && CFLAGS= && LDFLAGS= && CC= && CPP= && ./configure --prefix=$(INSTALL_DIR) 

.PHONY:install libev_install libevtest_install sklist_install
libevtest_install:
	$(MAKE) --directory=$($@) install

libev_install:
	$(MAKE) --directory=$($@) install

sklist_install:
	$(MAKE) --directory=$($@) install

.PHONY:clean libev_clean libevtest_clean sklist_clean
clean:libev_clean libevtest_clean sklist_clean
libevtest_clean:
	$(MAKE) --directory=$($@) clean
libev_clean:
	$(MAKE) --directory=$($@) distclean
sklist_clean:
	$(MAKE) --directory=$($@) clean
