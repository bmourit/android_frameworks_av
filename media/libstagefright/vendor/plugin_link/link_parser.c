/*******************************************************************************
 *                              ������д��Ŀ��
 *                            Module: ������дģ����
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       kkli     2009-01-01 15:00     1.0             build this file 
*******************************************************************************/
/*!
 * \file     link.c
 * \brief    �ṩ��ͬƽ̨�²����������Ŀ�
 * \author   kkli
 * \par      GENERAL DESCRIPTION:
 *               ������ļ���������
 * \par      EXTERNALIZED FUNCTIONS:
 *               �����������õ������ģ��
 * \version 1.0
 * \date  2009/1/1
*******************************************************************************/

extern int music_parser_plugin_info;

void *get_plugin_info(void)
{
    return (void *)&music_parser_plugin_info;
}
