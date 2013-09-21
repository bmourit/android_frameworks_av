/*******************************************************************************
 *                              5003
 *                            Module: WAV
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-20 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     parser_pcm.h
 * \brief    �����˱����ṩ��pcm��Ƶ����ĳ�ʼ�����ݽṹ
 * \author   kkli
 * \version 1.0
 * \date  2008/09/20
*******************************************************************************/
#ifndef __PARSER_PCM_H__
#define __PARSER_PCM_H__
#ifdef __cplusplus
extern "C" {
#endif

#define WAV_LPCM        0x1
#define WAV_MS_ADPCM    0x2
#define WAV_ALAW        0x6
#define WAV_ULAW        0x7
#define WAV_IMA_ADPCM   0x11
#define WAV_BPCM        0x21  /* */

typedef struct
{    
    int32_t format;             /* pcm������ */
    int32_t channels;           /* ������ */
    int32_t samples_per_frame;  /* ÿ֡������������ */
    int32_t bits_per_sample;    /* ÿ���������������Ӧ������bit�� */
    int32_t bytes_per_frame;    /* ÿ֡������bytes�� */
} parser_pcm_t;

#ifdef __cplusplus
}
#endif
#endif // __PARSER_PCM_H__
