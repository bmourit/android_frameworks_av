/*******************************************************************************
 *                              5003
 *                            Module: audio in
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-05 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     audioin_pcm.h
 * \brief    ������������ݽṹ
 * \author   kkli
 * \version 1.0
 * \date  2008/09/05
*******************************************************************************/
#ifndef __AUDIOIN_PCM_H__
#define __AUDIOIN_PCM_H__

/*!
 * \brief  
 *      ������������������
 */
#define MAX_CHANNEL_IN     2
/*!
 * \brief  
 *      ��Ƶ������֡������������Ƶ����ģ������
 */
typedef struct
{
    /*! pcm����ָ������ */
    int pcm[MAX_CHANNEL_IN];
    /*! ��ǰ�����channel�� */
    int channels;
    /*! ��ǰ�����sample�� */
    int samples;
} audioin_pcm_t;

#endif // __AUDIOIN_PCM_H__
