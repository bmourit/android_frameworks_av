/*******************************************************************************
 *                              5003
 *                            Module: musicdec
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved.
 *
 * History:
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-12 15:00     1.0             build this file
*******************************************************************************/
/*!
 * \file     music_parser_lib_dev.h
 * \brief    �����parser����йص����ݽṹ
 * \author   kkli
 * \version 1.0
 * \date  2008/09/18
*******************************************************************************/
#ifndef __MUSIC_PARSER_LIB_DEV_H__
#define __MUSIC_PARSER_LIB_DEV_H__

#include "./common/al_libc.h"
#include "./common/storageio.h"
#include "./common/music_info.h"
#include "./common/extdef.h"

typedef enum
{
    EX_OPS_GET_RESTIME     = 0x555801,
} audioparser_ex_ops_cmd_t;
/*!
 * \brief
 *      ����parser������ص�����
 */
typedef enum
{
    /*! һ��δ֪���� */
    MP_RET_UNEXPECTED = -3,
    /*! �ڴ�ռ䲻�� */
    MP_RET_OUTOFMEMORY,
    /*! ��ʽ��֧�� */
    MP_RET_UNSUPPORTED,
    /*! ���� */
    MP_RET_OK,
    /*! �ļ����� */
    MP_RET_ENDFILE
} music_parser_ret_t;
/*!
 * \brief
 *      ����parser������ṩ�����ݽṹ
 */
typedef struct
{
    /*! ������׺����д������"RM" */
    char extension[MAX_EXT_SIZE];

    /*!
     * \par  Description:
     *	  �򿪲��
     * \param[in]   storage_io ��������ж�/д/��λ���ļ������ĺ���ָ�룬�ṹ�ο�storage_io_t
     * \return      ������
     * \retval           others sucess
     * \retval           NULL failed
     */
    void *(*open)(storage_io_t *storage_io);
    /*!
     * \par  Description:
     *	  �����ļ�ͷ
     * \param[in]   handle ������
     * \param[out]  music_info �ɲ�����ص�������Ϣ���ṹ�ο�music_info_t
     * \return      the result (music_parser_ret_t)
     */
    int (*parser_header)(void *handle, music_info_t *music_info);
    /*!
     * \par  Description:
     *	  ��ȡһ��chunk������(chunk������Ϊ�Ƕ��֡�ļ��ϣ��������ʱ��һ��������)
     * \param[in]   handle ������
     * \param[in]  output �����������ʼ��ַ
     * \param[out]  chunk_bytes ��ǰ���chunk���ֽ���
     * \return      the result (music_parser_ret_t)
     */
    int (*get_chunk)(void *handle, char *output, int *chunk_bytes);
    /*!
     * \par  Description:
     *	  ��λ���ļ���Ӧ��ʱ�䣨���룩
     * \param[in]   handle ������
     * \param[in]   time_offset ʱ��ƫ����
     * \param[in]   whence ����λ�ã�ȡֵͬ�ļ�seek��
     * \param[out]  chunk_start_time ���֮�����ʼ����ʱ��
     * \return      the result (music_parser_ret_t)
     */
    int (*seek_time)(void *handle, int time_offset, int whence, int *chunk_start_time);
    /*!
     * \par  Description:
     *	  ��չ�������Ҫ�˹��ܵ�ʵ��Ϊ�ռ���
     * \param[in]   handle ������
     * \param[in]   cmd ������
     * \param[in]   args ����
     * \return      the result (music_parser_ret_t)
     */
    int (*ex_ops)(void *handle, int cmd, int args);
    /*!
     * \par  Description:
     *	  �رղ��
     * \param[in]   handle ������
     */
    void (*close)(void *handle);
} music_parser_plugin_t;

#endif // __MUSIC_PARSER_LIB_DEV_H__
