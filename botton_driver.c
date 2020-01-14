#include<stdio.h>
#include<linux/fs.h>
#include<linux/wait.h>
#include<linux/init.h>
#include<linux/uaccess.h>
#include<linux/irq.h>
#include<asm/gpio.h>
#include<plat/gpio-cfg.h>
//2.头文件







//3.定义按键数据结构
struct btn_resource {
    int irq;
    int gpio;
    char *name;
    int code; //按键值
}

//定义上报按键的信息数据结构
struct btn_event{
    int code;
    int state;//1表示按下，0表示松开
}
//分配初始化按键信息
static struct btn_resource btn_info[] = {
    [0] = {
        .irq = 
        .gpio = 
        .name = 
        .code = 
    },

    [1] = {
        .irq = 
        .gpio = 
        .name = 
        .code = 0x51 
    },
}

static struct btn_event g_btn;//记录操作信息，传用户空间
static int isPressed;//记录是否有按键操作，有1，无0
static dev_t dev;
static struct cdev btn_cdev;
static struct class *cls;
static struct btn_read(struct file *file,
                       char __user *buf,
                       size_t count,
                       loff_t *ppos){
//6.1判断按键是否有操作，如有操作，上报按键信息，如果没有进入休眠 
    wait_event_interruptible(btn_wq,isPressed);//第一个参数等待队列头，第二个参数按键操作
//6.2上报按键信息    





}
static struct file_operation btn_fops = {
    .owner = THIS_MODULE,
    .read = btn_read //获取按键信息

}


//7.中断处理函数
static irqreturn_t button_isr(int irq,void *dev_id){
//7.1通过dev_id获取按键对应的硬件信息
    struct btn_resource *pdata =

//7.2获取按键信息按下1


}
static int btn_init(){
    //4
    //4.1申请设备号
    //4.2初始化字符设备对象
    //4.3注册字符对象设备
    //4.4自动创建设备文件
    //4.5申请gpio资源和中断资源注册中断函数
    //4.6初始化等待队列头
    return 0;




}

static int btn_exit(){






}




//1.驱动入口
module_init(btn_init)
module_exit(btn_exit)
MODULE_LICENSE("GPL")
