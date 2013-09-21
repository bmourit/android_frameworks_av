/*******************************************************************************
 *                              5003
 *                            Module: musicenc
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-20 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     muxer_wav.h
 * \brief    ������wav������Ҫ��һЩ������ֶ�
 * \author   kkli
 * \version 1.0
 * \date  2008/09/20
*******************************************************************************/
#ifndef __MUXER_WAV_H__
#define __MUXER_WAV_H__
#ifdef __cplusplus
extern "C" {
#endif

#define WAV_LPCM        0x1
#define WAV_MS_ADPCM    0x2
#define WAV_ALAW        0x6
#define WAV_ULAW        0x7
#define WAV_IMA_ADPCM   0x11

typedef struct
{
    /*! �����ʣ���λHz */
    int32_t sample_rate;
    /*! �����ʣ���λbps */
    int32_t bitrate;
    /*! ���� */
    int32_t channels;
    /*! chunkʱ�䣬��λ���� */
    int32_t chunk_time;
    /*! 0:������¼��, 1:others�������Ƿ���Ҫ��attribute��Ԥ��header�Ŀռ� */
    int32_t mode;
    /*! 0x1: linear-pcm; 0x2: ms-adpcm; 0x6: alaw; 0x7: ulaw; 0x11: ima-adpcm */
    int32_t format;
} wav_audio_t;

#ifdef __cplusplus
}
#endif
#endif // __MUXER_WAV_H__
