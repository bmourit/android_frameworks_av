/*******************************************************************************
 *                              5003
 *                            Module: musicenc
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved.
 *
 * History:
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-18 11:00     1.0             build this file
*******************************************************************************/
/*!
 * \file     audio_encoder_lib_dev.h
 * \brief    ������audioenc���ͨ�õĽӿ�
 * \author   kkli
 * \version 1.0
 * \date  2008/9/18
*******************************************************************************/
#ifndef __AUDIO_ENCODER_LIB_DEV_H__
#define __AUDIO_ENCODER_LIB_DEV_H__

#include "./common/audioin_pcm.h"
#include "./common/enc_audio.h"
#include "./common/extdef.h"

typedef enum
{
    /*! һ��δ֪���� */
    AE_RET_UNEXPECTED = -7,
    /*! �������س��� */
    AE_RET_LIBLOAD_ERROR,
    /*! �����˷Ƿ��ı���� */
    AE_RET_LIB_ERROR,
     /*! ������� */
    AE_RET_ENCODER_ERROR,
     /*! �����ʴ��� */
    AE_RET_FS_ERROR,
    /*! �ڴ�ռ䲻�� */
    AE_RET_OUTOFMEMORY,
    /*! ��ʽ��֧�֣����ܼ������� */
    AE_RET_UNSUPPORTED,
    /*! ���� */
    AE_RET_OK,
    /*! ������ݳ�����������С */
    AE_RET_DATAOVERFLOW,
} audioenc_ret_t;

typedef struct
{
    /*! ����һ֡����������� */
    int samples_per_frame;
    /*! payload/packet��С����λ�ֽ� */
    int chunk_size;
    /*! ��ʼд���ļ���ʼ������ */
    /*! ����ָ�� */
    void *buf;
    /*! ���ݳ��� */
    int buf_len;
} audioenc_attribute_t;

typedef struct
{
    char extension[MAX_EXT_SIZE];

    void *(*open)(enc_audio_t *enc_audio);
    int (*get_attribute)(void *handle, audioenc_attribute_t *attribute);
    int (*update_header)(void *handle, char **header_buf, int *header_len);
    int (*frame_encode)(void *handle, audioin_pcm_t *ain, char *output, int *bytes_used);
    void (*close)(void *handle);
} audioenc_plugin_t;

#endif // __AUDIO_ENCODER_LIB_DEV_H__
