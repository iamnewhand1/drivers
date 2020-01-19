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
    //定义上报按键数据结构
struct btn_event {
    int code;//上报按键值
    int state；//上报按键状态1按下0松开
}
    //分配按键信息
static struct btn_resource btn_info[] = {
    [0] = {
        .irq = 
        .gpio = 
        .name = 
        .code = 0x50
    },
    [1] = {
        .irq = 
        .gpio = 
        .name = 
        .code = 0x51
    },

}

static struct btn_event g_btn;//记录按键信息
static int isPressed;//记录按键是否有操作
static dev_t dev;
static struct class *cls;
static file_operations btn_fops = {
    .owner = THIS_MODULE,
    .read = btn_read//获取按键信息
}
static int btn_init(){
    int ret;
    //4.4自动创建设备文件
    cls = class_create(THIS_MODULE, "button");
	if (IS_ERR(cls)) {
		ret = PTR_ERR(cls);
		goto err_class;
	}

    //4.1申请设备号
	
    ret = alloc_chrdev_region(&dev,0,1,"buttons")
    if(ret)
<<<<<<< HEAD
        goto err_botton_cdevadd


    err_botton_cdevadd:
        unregister_chrdev_region()

    //4.2初始化字符设备对象 int cdev_add(struct cdev *, dev_t, unsigned);
    //4.3注册字符对象设备
    cdev_add($btn_cdev,dev,1)
    //4.4自动创建设备文件
    cls = class_create(THIS_MODULE,"button");
    device_create(cls,NULL,dev,NULL,"button")
=======
        goto err_button_cdevadd
    err_button_cdevadd:
        unregister_chrdev_region(dev,MINORMASK)

    //4.2初始化字符设备对象 
    cdev_init(&btn_cdev,&btn_fops) 
    //4.3注册字符对象设备int cdev_add(struct cdev *, dev_t, unsigned);
    cdev_add(&btn_cdev,dev,1);
>>>>>>> f440af3104134bc6ed7d43984a45cf5b2fb3ed1e
    //4.5申请gpio资源和中断资源注册中断函数
    //4.6初始化等待队列头
    return 0;

err_cdev_add:
	unregister_chrdev_region(vfio.group_devt, MINORMASK);
err_alloc_chrdev:
	class_destroy(vfio.class);
	vfio.class = NULL;
err_class:
	misc_deregister(&vfio_dev);
	return ret;
}



}

static int btn_exit(){
    int i;
    //5
    device_destory(cls,dev);
    class_destory(cls);
    for(i=0,i<ARRAY_SIZE(btn_info),i++){
        free_irq(btn_info[i].irq,&btn_info[i]);
        gpio_free(btn_info[i].gpio);
    }
    cdev_del(&btn_cdev);

}




//1.驱动入口
module_init(btn_init)
module_exit(btn_exit)
MODULE_LICENSE("GPL")
