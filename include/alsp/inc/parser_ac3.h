/*******************************************************************************
 *                              5003
 *                            Module: ac3
 *                 Copyright(c) 2003-2009 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       chenzhan    2009-11-13 10:08   1.0             build this file 
*******************************************************************************/
/*!
 * \file     parser_ac3.h
 * \brief    ������parser�����ṩ��ac3�����ĳ�ʼ�����ݽṹ
 * \author   chenzhan
 * \version 1.0
 * \date  2009/11/13
*******************************************************************************/
#ifndef __PARSER_AC3_H__
#define __PARSER_AC3_H__
#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    int32_t little_endian_flag; //Ĭ�������ʽ��littleģʽ=0 bigģʽ=1
} parser_ac3_t;

#ifdef __cplusplus
}
#endif
#endif // __PARSER_AAC_H__
