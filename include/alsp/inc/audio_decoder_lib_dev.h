/*******************************************************************************
 *                              5003
 *                            Module: musicdec
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved.
 *
 * History:
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-18 15:00     1.0             build this file
*******************************************************************************/
/*!
 * \file     audio_decoder_lib_dev.h
 * \brief    ��Ƶ���������Ҫ��ͷ�ļ�
 * \author   kkli
 * \version 1.0
 * \date  2008/09/18
*******************************************************************************/
#ifndef __AUDIO_DECODER_LIB_DEV_H__
#define __AUDIO_DECODER_LIB_DEV_H__

#include "./common/audiout_pcm.h"
#include "./common/extdef.h"

typedef enum
{
    EX_OPS_SPDIF_OUTPUT     = 0x455801,
    EX_OPS_CHUNK_RESET      = 0x455802,
} audiodec_ex_ops_cmd_t;
/*!
 * \brief
 *      ������Ƶ���������ص�����
 */
typedef enum
{
    /*! һ��δ֪���� */
    AD_RET_UNEXPECTED = -3,
    /*! �ڴ�ռ䲻�� */
    AD_RET_OUTOFMEMORY,
    /*! ��ʽ��֧�֣����ܼ������� */
    AD_RET_UNSUPPORTED,
    /*! ���� */
    AD_RET_OK,
    /*! �������ݲ��� */
    AD_RET_DATAUNDERFLOW,
} audiodec_ret_t;
/*!
 * \brief
 *      ������Ƶ���������ṩ�����ݽṹ
 */
typedef struct
{
    /*! ������׺����д������"COOK"���ο�ͷ�ļ����� */
    char extension[MAX_EXT_SIZE];

    /*!
     * \par  Description:
     *	  �򿪲��
     * \param[in]   init_buf ��ʼ����Ϣ����parser�ͽ��������Լ�����ݽṹ
     * \return      ������
     * \retval           others sucess
     * \retval           NULL failed
     */
    void *(*open)(void *init_buf);
    /*!
     * \par  Description:
     *	  ����һ֡����
     * \param[in]   handle ������
     * \param[in]   input �������ݵ���ʼ��ַ
     * \param[in]   input_bytes �������ݵĳ���
     * \param[out]  aout ����������ṹ�ο�audiout_pcm_t
     * \param[out]  bytes_used ���뵱ǰ֡�õ��ֽ���
     * \return      the result (audiodec_ret_t)
     */
    int (*frame_decode)(void *handle, const char *input, const int input_bytes, audiout_pcm_t *aout, int *bytes_used);
    /*!
     * \par  Description:
     *	  ��չ�������Ҫ�˹��ܵ�ʵ��Ϊ�ռ���
     * \param[in]   handle ������
     * \param[in]   cmd ������
     * \param[in]   args ����
     * \return      the result (audiodec_ret_t)
     */
    int (*ex_ops)(void *handle, int cmd, int args);
	/*!
     * \par  Description:
     *	  �رղ��
     * \param[in]   handle ������
     */
    void (*close)(void *handle);
} audiodec_plugin_t;

#endif  // __AUDIO_DECODER_LIB_DEV_H__
