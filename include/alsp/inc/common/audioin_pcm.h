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
 * \brief    Decoder output data structure
 * \author   kkli
 * \version 1.0
 * \date  2008/09/05
*******************************************************************************/
#ifndef __AUDIOIN_PCM_H__
#define __AUDIOIN_PCM_H__

/*!
 * \brief  
 *      Define the max num of input channels
 */
#define MAX_CHANNEL_IN     2
/*!
 * \brief  
 *      Outout audio encoding plug-frame decoding input or audio input module
 */
typedef struct
{
    /*! PCM data pointer array */
    int pcm[MAX_CHANNEL_IN];
    /*! Number of channels currently input */
    int channels;
    /*! Few sample current input */
    int samples;
} audioin_pcm_t;

#endif // __AUDIOIN_PCM_H__
