#ifndef __ALSP_INCLUDES_H__
#define __ALSP_INCLUDES_H__

// ϵͳ��ص��ⲿͷ�ļ�, ��Ҫ�����м����ϵͳ���ģ��




#if defined(_OS_UC_)
#include <libc/stdio.h>
#include <libc/stdlib.h>
#include <libc/stdarg.h>
#include <libc/string.h>
#include <libc/pthread.h>
#include <libc/fcntl.h>
#include <libc/time.h>
#include <libc/sys/ioctl.h>
#include <libc/sys/types.h>
#include <libc/sys/mman.h>
#include <libc/dlfcn.h>
#include <libc/unistd.h>
#include <libc/semaphore.h>
#include "asm-mips/mach-atj228x/actions_reg_gl5005.h"
#include "ucos/page.h"
#include "act_mem.h"
#include "fb.h"
#endif



#ifdef _OS_UX_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <dlfcn.h>
#include <unistd.h>
#include <semaphore.h>
#include "actions_reg_gl5005.h"
#include "dma_mem.h"
#include "fb_drv.h"                /////////atv600x framebuffer��ͷ�ļ�
#include "asoc_ioctl.h"            /////////�÷�����ioctl�����ֶ���

#endif

extern int actal_error(const char *format, ...);
extern int actal_printf(const char *format, ...);

#endif //#ifndef __ALSP_INCLUDES_H__
