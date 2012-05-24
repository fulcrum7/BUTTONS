#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7d40d1b5, "module_layout" },
	{ 0x3c5c4750, "i2c_del_driver" },
	{ 0x4c0c5f0f, "i2c_register_driver" },
	{ 0xb9e52429, "__wake_up" },
	{ 0x859c6dc7, "request_threaded_irq" },
	{ 0x167e6672, "i2c_smbus_write_byte_data" },
	{ 0xf9a482f9, "msleep" },
	{ 0x98c45d1a, "cdev_add" },
	{ 0x4e7735b7, "cdev_init" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0x153c4539, "i2c_smbus_read_byte_data" },
	{ 0x8893fa5d, "finish_wait" },
	{ 0x1000e51, "schedule" },
	{ 0x75a17bed, "prepare_to_wait" },
	{ 0x5f754e5a, "memset" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xeae409f7, "cdev_del" },
	{ 0xf20dabd8, "free_irq" },
	{ 0x11f447ce, "__gpio_to_irq" },
	{ 0xea147363, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("i2c:fma_alarm_btn");
