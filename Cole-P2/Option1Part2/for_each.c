#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>


int list_init(void)
{
    printk(KERN_INFO "Loading Module\n");

    struct task_struct *task;

    for_each_process(task)
    {
        printk(KERN_INFO "Task Command: %s \n State: %ld \n Process ID: %d \n", task->comm, task->state, task->pid);
    }

    return 0;
}

void list_exit(void)
{
    printk(KERN_INFO "Removing Module\n");
}

module_init(list_init);
module_exit(list_exit);