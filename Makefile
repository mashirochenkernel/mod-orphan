# SPDX-License-Identifier: GPL-2.0
#
# Out-of-tree build for hamradio modules (AX.25, NET/ROM, ROSE, drivers)
#
# Usage:
#   make                    # build against running kernel
#   make KDIR=/path/to/src  # build against specific kernel source
#   make install            # install modules
#   make clean
#

KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules

install:
	$(MAKE) -C $(KDIR) M=$(CURDIR) modules_install

clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) clean

.PHONY: all install clean
