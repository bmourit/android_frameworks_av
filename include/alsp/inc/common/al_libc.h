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
 * \file     al_libc.h
 * \brief    C library function for al_libc internal implementation.
 * \author   kkli
 * \version 1.0
 * \date  2009/1/1
*******************************************************************************/
#ifndef __AL_LIBC_H__
#define __AL_LIBC_H__

#ifdef __cplusplus
extern "C" {
#endif

#define INLINE      inline

typedef int64_t mmm_off_t;

/*!
 * \brief
 *      Memory-related operating statement
 */
void *actal_memcpy(void *, const void *, int32_t);
void *actal_memset(void *, int32_t, int32_t);

/*!
 * \brief
 *      Memory management related operations Statement
 */
/*! Apply logical address parameters for the length */
void *actal_malloc(int32_t);
void actal_free(void *);
/*! Consecutive addresses for the physical address of the application. The first argument is the length and the second parameter is the physical address of output */
void *actal_malloc_dma(int32_t, int32_t *);
void actal_free_dma(void *);
/*! Apply physical address. Address consecutive write-through, the first argument is the length and the second parameter is the physical address output.
     Write-through features are: to ensure the read speed, not just the write speed to the cache update.
 */
void *actal_malloc_wt(int32_t, int32_t *);
void actal_free_wt(void *);
void actal_cache_flush(void *, int);
void actal_cache_env(void *, int);
/*! Continuous application without a physical address for cache address. The first parameter is the length and the second parameter is the output of the physical address.
     Without cache features are: dma functions can be performed directly after the operation of the address.
 */
void *actal_malloc_uncache(int32_t, int32_t *);
void actal_free_uncache(void *);
/*! Get the physical address */
int actal_get_phyaddr(void *);
void * actal_get_virtaddr(int );
/*!
 * \brief
 *      print the memory address 
 */
void actal_dump(int *, int32_t);

/*!
 * \brief
 *      Get the current system time in ms, for measuring performance
 */
int64_t actal_get_ts(void);

/*!
 * \brief
 *      Set the print output to be turned on or off uniformly
 */
int32_t actal_printf(const char *format, ...);
/*!
 * \brief
 *      Set the print output, always open, limited to 256 characters
 */
int32_t actal_error(const char *format, ...);
/*!
 * \brief
 *      Set print output off and release
 */
int32_t actal_info(const char *format, ...);

/*!
 * \brief
 *      Set the sleep time. The input parameters in milliseconds, will lead the task switching
 */
void actal_sleep_ms(int32_t);
/*!
 * \brief
 *      Get IC information, 0 ~ 7bit = ic type, 8 ~ 15bit = ic version, such as: 0x4303 indicates 5003 C version
 */
int actal_get_icinfo(void);

int actal_check_utf8(const char *utf8, int length);
int actal_convert_ucnv(char *from_charset, char *to_charset, const char *inbuf, int inlen,
		char *outbuf, int outlen);
int actal_encode_detect(const char *src, char *encoding);
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __AL_LIBC_H__
