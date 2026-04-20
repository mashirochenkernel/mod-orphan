/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _HAMRADIO_COMPAT_H
#define _HAMRADIO_COMPAT_H

#include <linux/slab.h>
#include <linux/overflow.h>

/*
 * Compat shims for kzalloc_obj/kmalloc_obj/kzalloc_objs which were
 * added in kernels newer than 6.x. If the kernel already has them
 * (detected via __alloc_objs), skip the definitions.
 */
#ifndef __alloc_objs

#define __default_gfp_compat(a, b, ...) b
#define default_gfp_compat(...) __default_gfp_compat(, ##__VA_ARGS__, GFP_KERNEL)

#define __alloc_objs(KMALLOC, GFP, TYPE, COUNT)				\
({									\
	const size_t __obj_size = size_mul(sizeof(TYPE), COUNT);		\
	(TYPE *)KMALLOC(__obj_size, GFP);				\
})

#define kmalloc_obj(VAR_OR_TYPE, ...) \
	__alloc_objs(kmalloc, default_gfp_compat(__VA_ARGS__), typeof(VAR_OR_TYPE), 1)

#define kzalloc_obj(P, ...) \
	__alloc_objs(kzalloc, default_gfp_compat(__VA_ARGS__), typeof(P), 1)

#define kzalloc_objs(P, COUNT, ...) \
	__alloc_objs(kzalloc, default_gfp_compat(__VA_ARGS__), typeof(P), COUNT)

#endif /* __alloc_objs */

#endif /* _HAMRADIO_COMPAT_H */
