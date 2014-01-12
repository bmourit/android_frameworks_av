/*******************************************************************************
 *                              5003
 *                            Module: musicdec
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-05 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     music_info.h
 * \brief    Defines the stucture of the song info parser output
 * \author   kkli
 * \version 1.0
 * \date  2008/09/05
*******************************************************************************/
#ifndef __MUSIC_INFO_H__
#define __MUSIC_INFO_H__

/*!
 * \brief  
 *      Returns the parser plug-in library info structure
 */
typedef struct
{
    /*! codec library suffix, in uppercase. For example: "COOK" */
    char extension[8];
    /*! Large chunk size in bytes */
    int max_chunksize;
    /*! Total time in seconds */
    int total_time;
    /*! Average bitrate kbps */
    int avg_bitrate;
	/*! Sampling rate in Hz */
    int sample_rate;
    /*! Number of channels */
    int channels;
    /*! Open the audio decoder plug-in input parameters for the format */
    void *buf;
} music_info_t;

#endif // __MUSIC_INFO_H__
