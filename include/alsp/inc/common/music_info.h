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
 * \brief    ����parser����ĸ�����Ϣ�ṹ
 * \author   kkli
 * \version 1.0
 * \date  2008/09/05
*******************************************************************************/
#ifndef __MUSIC_INFO_H__
#define __MUSIC_INFO_H__

/*!
 * \brief  
 *      parser����ⷵ�ص���Ϣ�ṹ
 */
typedef struct
{
    /*! �����ĺ�׺����д������"COOK" */
    char extension[8];
    /*! ����chunk��С����λbyte */
    int max_chunksize;
    /*! ��ʱ�䣬��λseconds */
    int total_time;
    /*! ƽ�������ʣ���λkbps */
    int avg_bitrate;
	/*! �����ʣ���λhz */
    int sample_rate;
    /*! ������ */
    int channels;
    /*! ����Ƶ���������������������ṹ���ض���ʽԼ�� */
    void *buf;
} music_info_t;

#endif // __MUSIC_INFO_H__
