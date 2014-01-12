/********************************************************************************
*                              5003
*                            Module: storage io
*                 Copyright(c) 2003-2008 Actions Semiconductor,
*                            All Rights Reserved.
*
* History:
*      <author>    <time>           <version >             <desc>
*       kkli     2008-09-02 10:00     1.0             build this file
********************************************************************************/
/*!
* \file     storageio.h
* \brief    Defines the storage io interfaces for the device
* \author   kkli
* \version 1.0
* \date  2008/09/02
*******************************************************************************/
#ifndef __STORAGEIO_H__
#define __STORAGEIO_H__

/*!
 * \brief
 *      Provide a consistent and standard file system interface storage devices operating input and output interfaces
 */
typedef struct storage_io_s {
    /*! Read data */
    int (*read)(void *buf, int size, int count, struct storage_io_s *io);
    /*! Write data */
    int (*write)(void *buf, int size, int count, struct storage_io_s *io);
    /*! Positioning */
    int (*seek)(struct storage_io_s *io, mmm_off_t offset, int whence);
    /*! File location */
    mmm_off_t (*tell)(struct storage_io_s *io);
} storage_io_t;

#endif // __STORAGEIO_H__
