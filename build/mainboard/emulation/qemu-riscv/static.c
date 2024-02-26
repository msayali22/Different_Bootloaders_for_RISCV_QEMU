#include <device/device.h>
#include <device/pci.h>

#include <static.h>

#if !DEVTREE_EARLY
__attribute__((weak)) struct chip_operations mainboard_ops = {};
extern struct chip_operations soc_ucb_riscv_ops;
#endif

#define STORAGE static __unused DEVTREE_CONST


/* pass 0 */
STORAGE struct bus dev_root_links[];
STORAGE struct device _dev0;
DEVTREE_CONST struct device * DEVTREE_CONST last_dev = &_dev0;

/* chip configs */

/* pass 1 */
DEVTREE_CONST struct device dev_root = {
#if !DEVTREE_EARLY
	.ops = &default_dev_ops_root,
#endif
	.bus = &dev_root_links[0],
	.path = { .type = DEVICE_PATH_ROOT },
	.enabled = 1,
	.hidden = 0,
	.mandatory = 0,
	.on_mainboard = 1,
	.link_list = &dev_root_links[0],
	.sibling = NULL,
#if !DEVTREE_EARLY
	.chip_ops = &mainboard_ops,
	.name = mainboard_name,
#endif
	.next=&_dev0,
};
STORAGE struct bus dev_root_links[] = {
		[0] = {
			.link_num = 0,
			.dev = &dev_root,
			.children = &_dev0,
			.next = NULL,
		},
	};
STORAGE struct device _dev0 = {
#if !DEVTREE_EARLY
	.ops = NULL,
#endif
	.bus = &dev_root_links[0],
	.path = {.type=DEVICE_PATH_CPU_CLUSTER,{.cpu_cluster={ .cluster = 0x0 }}},
	.enabled = 1,
	.hidden = 0,
	.mandatory = 0,
	.on_mainboard = 1,
	.link_list = NULL,
	.sibling = NULL,
#if !DEVTREE_EARLY
	.chip_ops = &soc_ucb_riscv_ops,
#endif
};

/* expose_device_names */
