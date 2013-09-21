/*******************************************************************************
 *                              5003
 *                            Module: decoder linker
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2009-01-01 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     link_decoder.c
 * \brief    �ṩ��ͬƽ̨�½��������������Ŀ�
 * \author   kkli
 * \par      GENERAL DESCRIPTION:
 *               ������ļ���������
 * \par      EXTERNALIZED FUNCTIONS:
 *               �����������õ������ģ��
 * \version 1.0
 * \date  2009/1/1
*******************************************************************************/

extern int audiodec_plugin_info;

void *get_plugin_info(void)
{
    return (void *)&audiodec_plugin_info;
}
