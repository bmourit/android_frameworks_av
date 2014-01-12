/********************************************************************************
*                              5003
*                            Module: storage
*                 Copyright(c) 2003-2008 Actions Semiconductor,
*                            All Rights Reserved. 
*
* History:         
*      <author>    <time>           <version >             <desc>
*       kkli     2008-08-26 11:00     1.0             build this file
********************************************************************************/
/*!
* \file     format_dev.h
* \brief    
* \author   kkli
* \version 1.0
* \date  2008/08/26
*******************************************************************************/
#ifndef __FORMAT_DEV_H__
#define __FORMAT_DEV_H__

#include "./common/extdef.h"
#include "./common/storageio.h"

#ifdef __cplusplus
extern "C" {
#endif
/*                  
 * \par  Description:
 *	  
 * \param[in]   storage_io_t 
 * \param[out]  
 * \return      
 * \retval           0 sucess 
 * \retval           -1 failed     
 */   
int format_check(storage_io_t *, const char *);

#ifdef __cplusplus
}
#endif

#endif // __FORMAT_DEV_H__
