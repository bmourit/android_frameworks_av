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
 * \brief    definition of the information required to open an audio encoding library
 * \author   kkli
 * \version 1.0
 * \date  2008/9/18
*******************************************************************************/
#ifndef __ENC_AUDIO_H__
#define __ENC_AUDIO_H__

/*!
 * \brief  
 *      Open the information required for the audio encoding library
 */
typedef struct
{
	/*! Sampling rate, in Hz */
    int sample_rate;
    /*! Number of channels */
    int channels;
    /*! Audio bitrate */
    int bitrate;
    /*! Encoding library format. Encoding a loaded library may contain
     * more than 1 formate, for example: IMADPCM */
    int audio_format;
    /*! Encoded data length to get Audio playback. 0 indicates no limit. Unit is in ms */
    int chunk_time;   
} enc_audio_t;

#endif // __ENC_AUDIO_H__
