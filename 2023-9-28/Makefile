obj-m := hello.o
KERNELDIR := /media/youliang/work3/Android11.0/source/rk3566-rk3568-android11.0/kernel
PWD :=$(shell pwd)  
ARCH=arm64  
CROSS_COMPILE=/media/youliang/work3/Android11.0/source/rk3566-rk3568-android11.0/prebuilts/gcc/linux-x86/aarch64/gcc-linaro-6.3.1-2017.05-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-  
CC=$(CROSS_COMPILE)gcc  
LD=$(CROSS_COMPILE)ld  
CFLAGS_MODULE=-fno-pic  
 
modules:  
	make -C $(KERNELDIR) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) M=$(PWD) modules
clean:
	rm *.o *.ko *.mod.c *.order *.symvers