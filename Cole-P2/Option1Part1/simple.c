/**
 * simple.c
 *
 * A simple kernel module.
 *
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <linux/jiffies.h>
#include <asm/param.h>

 /* This function is called when the module is loaded. */
static int simple_init(void)
{
    printk(KERN_INFO "Loading Module\n");
    printk(KERN_INFO "Golden Ratio: %lu\n", GOLDEN_RATIO_PPRIME);
    unsigned long y = jiffies;
    printk(KERN_INFO "Jiffies: %lu\n", y);
    int z = HZ;
    printk(KERN_INFO "Tick Rate: %d\n", z);

    return 0;
}

/* This function is called when the module is removed. */
static void simple_exit(void) {
    printk(KERN_INFO "Removing Module\n");
    unsigned long x = gcd(3300, 24);
    printk(KERN_INFO "GCD: %lu\n", x);
    unsigned long j = jiffies;
    printk(KERN_INFO "Jiffies Exit: %lu\n", j);
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");