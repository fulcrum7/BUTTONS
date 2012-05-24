    obj-m   :=   fma1125dc_alarm.o
    KERNELDIR   := ../linux-omap3
all:
	$(MAKE)  -C  $(KERNELDIR)   M=$(shell pwd)   modules
clean:
	rm   -rf   *.o
	rm   -rf   *.ko
