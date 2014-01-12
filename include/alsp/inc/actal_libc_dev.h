/*******************************************************************************
 *                              5003
 *                            Module: common
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2009-01-01 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     actal_libc_dev.h
 * \brief    C库函数声明，屏蔽操作系统以及方案的差别
 * \author   kkli
 * \version 1.0
 * \date  2009/1/1
*******************************************************************************/
#ifndef __ACTAL_LIBC_DEV_H__
#define __ACTAL_LIBC_DEV_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef long long int64_t;
typedef int int32_t;
typedef unsigned int uint32_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef signed char int8_t;
typedef unsigned char uint8_t;

#include "./common/al_libc.h"

#define NULL        0
#define TRUE        1
#define FALSE       0

/*!
 * \brief  
 *      File system related operations statement applies only to debug
 */
typedef int FILE;

#define SEEK_SET    0
#define SEEK_CUR    1
#define SEEK_END    2

FILE *fopen(const char *, const char *);
int fread(void *, int, int, FILE *);
int fwrite(void *, int, int, FILE *);
int fseek(FILE *, int, int);
int ftell(FILE *);
int feof(FILE *);
int fprintf(FILE *, const char *, ...);
char *fgets(char *, int, FILE *);
int fclose(FILE *);

void *memcmp(const void *, const void *, int);
void *memmove(void *, const void *, int);
/*!
 * \brief  
 *      String statement related operations
 */
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, int);
char *strcat(char *, const char *);
char *strchr(const char *, int);
char *strstr(const char *, const char *);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, int);
int strlen(const char *);
int sprintf(char *, const char *, ...);
int sscanf(const char *, const char *, ... );
int atoi(const char *);
/*!
 * \brief  
 *      Statement printing operation
 */
int printf(const char *, ...); 

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __ACTAL_LIBC_DEV_H__
