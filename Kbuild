# SPDX-License-Identifier: GPL-2.0

LINUXINCLUDE := -I$(src)/include -I$(src)/include/uapi $(LINUXINCLUDE)
subdir-ccflags-y := -include $(src)/include/hamradio_compat.h

obj-m += net/ax25/
obj-m += net/netrom/
obj-m += net/rose/
obj-m += drivers/net/hamradio/
