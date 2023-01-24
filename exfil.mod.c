#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x64491f21, "module_layout" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0xf4a53588, "filp_close" },
	{ 0x8e0cdd8f, "kernel_write" },
	{ 0xb9c81f9d, "kernel_read" },
	{ 0x76d64ce4, "filp_open" },
	{ 0xc687b2c, "kmem_cache_alloc_trace" },
	{ 0x2f6390d, "kmalloc_caches" },
	{ 0xa7eedcc4, "call_usermodehelper" },
	{ 0xc5850110, "printk" },
	{ 0x3e4faeee, "current_task" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "F1F98198951F9075A6D9022");
