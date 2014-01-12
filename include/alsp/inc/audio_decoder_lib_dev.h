/*******************************************************************************
 *                              5003
 *                            Module: musicdec
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved.
 *
 * History:
 *      <author>    <time>           <version >             <desc>
 *       kkli     2008-09-18 15:00     1.0             build this file
*******************************************************************************/
/*!
 * \file     audio_decoder_lib_dev.h
 * \brief    Audio decoding library header files
 * \author   kkli
 * \version 1.0
 * \date  2008/09/18
*******************************************************************************/
#ifndef __AUDIO_DECODER_LIB_DEV_H__
#define __AUDIO_DECODER_LIB_DEV_H__

#include "./common/audiout_pcm.h"
#include "./common/extdef.h"

typedef enum
{
    EX_OPS_SPDIF_OUTPUT     = 0x455801,
    EX_OPS_CHUNK_RESET      = 0x455802,
} audiodec_ex_ops_cmd_t;
/*!
 * \brief
 * Type definition audio decoding plug-in returns
 */
typedef enum
{
    /*! unknown error */
    AD_RET_UNEXPECTED = -3,
    /*! Insufficient memory space */
    AD_RET_OUTOFMEMORY,
    /*! Format is not supported, can't continue decoding */
    AD_RET_UNSUPPORTED,
    /*! Normal */
    AD_RET_OK,
    /*! Insufficient input data */
    AD_RET_DATAUNDERFLOW,
} audiodec_ret_t;
/*!
 * \brief
 * Structure definitions required by the audio decoding plug-in
 */
typedef struct
{
    /*! Plug-in library suffix, uppercase, for example: \ "COOK \", a reference header files define */
    char extension[MAX_EXT_SIZE];

    /*!
     * \par  Description:
     * Open the plug-in
     * \ \ Param [in] init_buf initialization information, determined by the parser and decoder library data structure itself
     * \ \ Return plug-in handles
     * \ \ Retval others sucess
     * \ \ Retval NULL failed
     */
    void *(*open)(void *init_buf);
    /*!
     * \\ Par Description:
     * Decoded data
     * \\ Param [in] handle plug-in handles
     * \\ Param [in] input start address of the input data
     * \\ Param [in] length input_bytes input data
     * \\ Param [out] aout decoded output, structure reference audiout_pcm_t
     * \\ Param [out] bytes_used decodes the number of bytes used in the current frame
     * \\ Return the result (audiodec_ret_t)
     */
    int (*frame_decode)(void *handle, const char *input, const int input_bytes, audiout_pcm_t *aout, int *bytes_used);
    /*!
     * \\ Par Description:
     * Extended commands do not need this feature can be implemented as empty
     * \\ Param [in] handle plug-in handles
     * \\ Param [in] cmd command word
     * \\ Param [in] args parameter
     * \\ Return the result (audiodec_ret_t)
     */
    int (*ex_ops)(void *handle, int cmd, int args);
	/*!
     * \par  Description:
     *	  Close the plug-in
     * \param[in]   handle plug-in handles
     */
    void (*close)(void *handle);
} audiodec_plugin_t;

#endif  // __AUDIO_DECODER_LIB_DEV_H__
