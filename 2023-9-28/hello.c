#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/fs.h>  
#include <linux/miscdevice.h>  
 
MODULE_LICENSE("GPL");  
MODULE_AUTHOR("GeneBlue");  
MODULE_DESCRIPTION("Hello Kernel Device");  
MODULE_VERSION("1.0");  
 
#define CMD_COMMAND 0x1336  
 
long hello_ioctl(struct file *filp,  //ioctl函数
    unsigned int cmd,  
    unsigned long arg){  
    switch(cmd){  
    case CMD_COMMAND:  
        printk("Hello Module hello_ioctl() exced");  
        break;  
    default:  
        printk("Hello Module unknown ioctl cmd");  
    }  
    return 0;  
}  
 
struct file_operations hello_fops = {  //设备的操作函数指针表
    unlocked_ioctl: hello_ioctl  
};  
 
static struct miscdevice hello_device = {  //注册为misc设备的基本属性
    minor: MISC_DYNAMIC_MINOR,  
    name: "hello",  
    fops: &hello_fops,  
    mode: 777
};  
 
static int __init hello_begin(void){  
    int ret;  
    ret = misc_register(&hello_device);  //注册为misc设备
    if(ret)  
        printk("Failed to register misc device");  
    else  
        printk("Hello Module successfully loaded");  
 
    return ret;  
}  
 
static void __exit hello_exit(void){  
    misc_deregister(&hello_device);  //设备卸载
    printk("Hello module exit");  
}  
 
module_init(hello_begin);  //模块初始化函数
module_exit(hello_exit);  //模块卸载函数