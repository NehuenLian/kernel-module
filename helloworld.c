#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nehuen Lian");
MODULE_DESCRIPTION("A random module");

static int repeat = 1;

module_param(repeat, int, 0644);
MODULE_PARM_DESC(repeat, "Number of times the 'Hello World' string will be printed");

static int __init entry_point(void)
{
        for (int i = 0; i < repeat; i++)
                printk(KERN_INFO "Hello World n: %d\n", i + 1);

        return 0;
}

static void __exit exit_module(void)
{
        printk(KERN_INFO "Removing module\n");
}

module_init(entry_point);
module_exit(exit_module);