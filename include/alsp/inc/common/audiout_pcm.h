/*******************************************************************************
 *                              5003
 *                            Module: audio out
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-05 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     audiout_pcm.h
 * \brief    Decoder output data structure definition
 * \author   kkli
 * \version 1.0
 * \date  2008/09/05
*******************************************************************************/
#ifndef __AUDIOUT_PCM_H__
#define __AUDIOUT_PCM_H__

/*!
 * \brief  
 *      Define the max num of output channels
 */
#define MAX_CHANNEL     6
/*!
 * \brief  
 *      Input audio decoding plug-frame decoded output or audio output module
 */
typedef struct
{
    /*! PCM data pointer array the contains the starting addr of each channel output data */
    int pcm[MAX_CHANNEL];
    /*! Contains current number of channels output */
    int channels;
    /*! Current num of sample output contains only a single channel count */
    int samples;
    /*! Current output of decimal digits, the integer value 0 */
    int frac_bits;
} audiout_pcm_t;

#endif // __AUDIOUT_PCM_H__
