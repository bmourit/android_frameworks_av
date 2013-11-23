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
 * \file     enc_audio.h
 * \brief    �����һ����Ƶ������������Ϣ
 * \author   kkli
 * \version 1.0
 * \date  2008/9/18
*******************************************************************************/
#ifndef __ENC_AUDIO_H__
#define __ENC_AUDIO_H__

/*!
 * \brief  
 *      ����Ƶ������������Ϣ
 */
typedef struct
{
	/*! �����ʣ���λhz */
    int sample_rate;
    /*! ������ */
    int channels;
    /*! ���������� */
    int bitrate;
    /*! ������ʽ��һ�����صı��������ܰ��������ʽ������IMADPCM */
    int audio_format;
    /*! һ�λ�ȡ������Ƶ��������ݲ���ʱ����0˵�������ƣ���λms */
    int chunk_time;   
} enc_audio_t;

#endif // __ENC_AUDIO_H__
