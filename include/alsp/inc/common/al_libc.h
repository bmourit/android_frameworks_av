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
 * \brief    al�ڲ�ʵ�ֵ�C�⺯����������Ӧ����һ��ȷ����ʵ��
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
 *      �ڴ���ز�������
 */
void *actal_memcpy(void *, const void *, int32_t);
void *actal_memset(void *, int32_t, int32_t);

/*!
 * \brief
 *      �ڴ������ز�������
 */
/*! �����߼���ַ������Ϊ���� */
void *actal_malloc(int32_t);
void actal_free(void *);
/*! ���������ַ�����ĵ�ַ����һ������Ϊ���ȣ��ڶ�������Ϊ����������ַ */
void *actal_malloc_dma(int32_t, int32_t *);
void actal_free_dma(void *);
/*! ���������ַ������write-through��ַ����һ������Ϊ���ȣ��ڶ�������Ϊ����������ַ
    write-through���ص��ǣ���֤�˶����ٶȣ�д��ʱ��ֻ�Ǹ��µ�cache
 */
void *actal_malloc_wt(int32_t, int32_t *);
void actal_free_wt(void *);
void actal_cache_flush(void *, int);
void actal_cache_env(void *, int);
/*! ���������ַ�����Ĳ�����cache�ĵ�ַ����һ������Ϊ���ȣ��ڶ�������Ϊ����������ַ
    ������cache���ص��ǣ��Ըõ�ַ���в��������ֱ�ӽ���dma����
 */
void *actal_malloc_uncache(int32_t, int32_t *);
void actal_free_uncache(void *);
/*! ��ȡ�����ַ */
int actal_get_phyaddr(void *);
void * actal_get_virtaddr(int );
/*!
 * \brief
 *      �������ӡһ���ڴ��ַ
 */
void actal_dump(int *, int32_t);

/*!
 * \brief
 *      ��ȡϵͳ��ǰʱ�䣬��λms�����ڲⶨ����
 */
int64_t actal_get_ts(void);

/*!
 * \brief
 *      �趨��ӡ������ɱ�ͳһ�򿪻�ر�
 */
int32_t actal_printf(const char *format, ...);
/*!
 * \brief
 *      �趨��ӡ�����ʼ�մ򿪣��ַ�����Ϊ256��
 */
int32_t actal_error(const char *format, ...);
/*!
 * \brief
 *      �趨��ӡ���������ʱ�ر�
 */
int32_t actal_info(const char *format, ...);

/*!
 * \brief
 *      ����˯��һ��ʱ�䣬����������룬�ᵼ�������л�
 */
void actal_sleep_ms(int32_t);
/*!
 * \brief
 *      ��ȡIC��Ϣ��0~7bit��ʾic���ͣ�8~15bit��ʾic�汾���磺0x4303��ʾ5003 C��
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
