/*******************************************************************************
 *                              5003
 *                            Module: AVE recorder
 *                 Copyright(c) 2003-2008 Actions Semiconductor,
 *                            All Rights Reserved. 
 *
 * History:         
 *      <author>    <time>           <version >             <desc>
 *       noahkong    2009-06-08 15:00     1.0             build this file 
*******************************************************************************/
#ifndef __ALENC_PLUGIN_H__
#define __ALENC_PLUGIN_H__

//#ifdef _OS_UX_
#include "./common/al_libc.h"
#include "./common/stream_input.h"
//#endif

/*disk manager seek*/
#define		DSEEK_SET		0x01
#define		DSEEK_END		0x02
#define		DSEEK_CUR		0x03

#ifndef NULL
#define		NULL		        0
#endif

/* used by muxer packet flag */
#define		IS_AUDIO				0x01			//contains only audio
#define		IS_VIDEO				0x02			//contains only video	
#define		IS_AV					  0x03			//contains audio and video

/* �����˲�ͬ�Ĳ�����ͳ�������Щ�������ڲ����Ϣ��type�ֶ� */
#define 	PLUGIN_MUX		        0x05			//plugin for muxer
#define		PLUGIN_VIDEO_ENCODER	0x07			//plugin for video encoder
#define 	PLUGIN_IMAGE_ENCODER	0x08			//plugin for img encoder
//#define (_SIG_TEST_)||(_SDK_227D_)
//#ifdef _SIG_TEST_
//  #include "./common/al_libc.h"
//  #include "./common/stream_input.h"
//#else
//  
//  #ifdef _USDK_227D_
//    #include "./common/al_libc.h"
//    #include "./common/stream_input.h"    
//  #else
//    #ifdef _OS_UC_
//      typedef struct stream_input_s
//      {
//              int(*read)(struct stream_input_s *manager, char *buf, unsigned int len);
//              int(*write)(struct stream_input_s *manager, char *buf, unsigned int len);
//              int(*seek)(struct stream_input_s *manager, long long offset, int original);
//              long long(*tell)(struct stream_input_s *manager);
//      }stream_input_t;
//    #endif
//  #endif
  
//#endif

/*!
 * \brief
 *      ͼ�����ݸ�ʽ
 */         
typedef struct{		
	unsigned int formate;
	unsigned int bpp;		
	unsigned int width;
	unsigned int height;		
	unsigned char *buf;
	unsigned int len;
	/*! rgb565����ͼ + alpha ͼ����bk_width*bk_height*2 + bk_width*bk_height*/
	unsigned int bk_buf;
	/*����ͼ��*/ 
	unsigned int bk_width;
	/*����ͼ��*/
	unsigned int bk_height;
}image_info_t;

/*!
 * \brief
 *      ���ճ�ʼ����Ϣ
 */
typedef struct
{
         /*! ��־��Ƭ�Ƿ�������� */  
         unsigned int photo_data_flag;
         /*! ������Ϣ(����) */
         unsigned char *photo_data; 
         /*! ������Ϣ(����)�� */
         unsigned int  pd_width;
         /*! ������Ϣ(����)�� */
         unsigned int  pd_height;
         /*! exif������Ϣ */
         unsigned char *exif_info; 
         /*! �Ƿ�����,0: normal; 1: scaler */
         unsigned int   scale_mode;
         /*! �Ƿ�������ͷ��, 0: ��; 1: ���� */
         unsigned int   func_mode;
         /*! ͼƬ�����Ŀ� */
         unsigned int dst_width; 
         /*! ͼƬ�����ĸ� */
         unsigned int dst_height;
         /*! ����佹�����ķ��� */
         unsigned int fr; 
         /*! ����佹�����ķ�ĸ */
         unsigned int br; 
}camera_init_t;


#define SET_FACE_MASK_ON 0xb100
#if 0
/*!
 * \brief
 *      ����ʱ������������Ϣ������Ч���
 */
typedef struct {  
        /*! ����������Ϣ */
        ALFace_appout_t *face_app;
        /*! ���մ�ͼָ�� */
        image_info_t img;
        /*! ������Ϣ */
        unsigned int bk_info;
}ALFace_info_t;
#endif
/*!
 * \brief
 *      ���սӿ�
 */
typedef struct camera_plugin_s{
	int (*init)(void *plugin, camera_init_t *param);
	int (*encode_img)(void *plugin, image_info_t *img);
	int (*dispose)(void *plugin);
//#ifdef _USDK_227D_
	int (*exop)(void *plugin,int cmd,unsigned int args);
//#endif
}camera_plugin_t;                                                         


/*!
 * \brief
 *      ��ʾʹ�ܽӿڣ���ʹ�ã�
 */ 
typedef  struct{
        /* encoder��ʾ�����Ƿ�ʹ�� 1��ʹ�ܣ�0����ʹ�� */
        int    enable_display;     
        int    width;
        int    height;
} display_resolution_t;


/*!
 * \brief
 *      ��Ƶ��������ʼ������
 */ 
typedef struct{
        /* fmt of audio output */
        char *audio_fmt;		         
        /* ��ǰ��Ƶ���ݵķֱ��� */
        unsigned int bpp;
        /* �����ı����� */		         
        unsigned int bitrate;	
        /* ������ */
        unsigned int sample_rate;	   	
        /* ��ǰ��ͨ���� */
        unsigned int channels;		   
        /* ����ģʽ�������������������ȵ� */
        unsigned int encode_mode;	   
}ae_param_t;

/*!
 * \brief
 *      ��Ƶ��������ʼ������
 */ 
typedef struct{
        /* �����Ŀ� */
        int width;
        /* �����ĸ� */
        int height;
        /* ����Դ�Ŀ� */
        int src_width;  
        /* ����Դ�ĸ� */              
        int src_height;    
        /* Ĭ��1 */            
        int fincr;  
        /* ��framerate��ͬ */                   
        int fbase; 
        /* ֡�� */                    
        int framerate;	
        /* I֡��࣬��ǿ�ƣ� xvid��3��mjpg��1 */	             
        int max_key_interval;	
        /* ��ʼ������ */         
        int quanty;
        /* frame dropping: 0=drop none... 100=drop all */ 		                 
        int frame_drop_ratio;  
        /* B���ĸ���,��ǿ�ƣ���0 */       
        int max_bframes;
        /* ��ʱ��Ч��0 */             
        int video_bitrate;
        /* ��ʱ��Ч��0 */             
        int bQOffset;	
        /* ��ʱ��Ч��0 */                 
        int bQRatio;	
        /* �洢���� */	               
        int cardtype;
        /* reserved[2] is used for backup vidfmt*/
        int reserved[9];
}ve_param_t;

/*!
 * \brief
 *      mux��ʼ������
 */ 
typedef struct{
        /* �ļ���ʽ */
        char file_fmt[12];
        /* ������ */
        unsigned int streamer_type;	
        /* ��Ƶ���� */	
        ae_param_t audio_param;
        /* ��Ƶ���� */
        ve_param_t video_param;
        /* ��Ƶ��ʽ��*/
        char audio_fmt[12];
        /* ��Ƶ��ʽ��*/
        char video_fmt[12];
        /* no use��*/
        unsigned char *tbl_buf; 		
        unsigned int tbl_buf_len;
}ave_param_t;

/*!
 * \brief
 *      �������ݸ�ʽ
 */ 
typedef struct{
	unsigned char *data;
	int  data_len;
	/* ��Ƶ����ʱΪ 0����Ƶ 0 - �ǹؼ�����1 - �ؼ��� */
	int  is_key_frame; 
	/* ʱ��� */	
	int  encode_type;	
}encode_frame_t;

/*!
 * \brief
 *      ������ݸ�ʽ
 */ 
typedef struct{
        /*chunk���ͣ�ʹ�ó�������IS_AUDIO//IS_VIDEO// */
	int media_type; 	
	char *data;
	int data_len;	
	int is_key_frame;
	/* ʱ��� */
	int  time_stamp;	
	int reserved[9];
}av_chunk_t;


typedef struct {
  ave_param_t *ave_param;
  stream_input_t *input;
	unsigned int 	 reserved[2];
}mux_input_attr_t;	
					
/* mux��ǰ��Ҫaudio packet����video packet */
#define GET_PACKET_TYPE     0xc001    
/* ��ȡmux״̬��Ϣ */                                  
#define GET_MUXER_STATUS    0xc002   
/* ���³�ʼ�� */
#define RESET_MUXER         0xc003


/*!
 * \brief
 *      mux��ǰ�ı�����Ϣ
 */
typedef  enum{
    EITHER_OK,
    AUDIO_PACKET,
    VIDEO_PACKET	
}packet_type_t;

/*!
 * \brief
 *      mux��ǰ��״̬��Ϣ
 */
typedef struct {
        /* including audio and video frames or other */
	unsigned int     total_frames;		 
	unsigned int     video_frames;
	unsigned int     audio_frames;
	/* �ļ�λ�� ��32λ */
	unsigned int     movi_length_L;	
	/* �ļ�λ�� ��32λ */     
	unsigned int     movi_length_H;		 
	unsigned int 	 reserved[5];	
}mux_output_attr_t;						         

/*!
 * \brief
 *      �����������
 */
typedef struct{
	char *data;
	int data_len;
	//��Ƶ����ʱΪ 0����Ƶ 0 - �ǹؼ�����1 - �ؼ���
	int is_key_frame;
	//ʱ��� 	
	int  encode_type;	
}av_frame_t;

/* ��ȡencoder������Ϣ�������Ƿ���ж�����⹦�� */
#define GET_ENCODER_ATTR     0xb001  
/* ��ȡencoder״̬��Ϣ����ǰ֡�Ƿ��˶� */
#define GET_ENCODER_STATUS   0xb002  
/* display_resolution_t�ṹָ�룬��ʾ�ֱ��� */
#define SET_DISPLAY_PARAM    0xb005    

/*!
 * \brief
 *      ��������ǰ״̬
 */
typedef struct {
        /* current(accurately last) frame encode type I/P/B/SKip */
	unsigned int frame_type;
	/* current(accurately last) frame encode length (bytes)	*/    
	unsigned int frame_size;
	/* current(accurately last) quality */	    
	unsigned int cur_quality;	
	/* current(accurately last) I maxinterval */   
	unsigned int cur_interval;
	/* ��ǰ���õ���״̬ */	  
	unsigned int cur_suv_status; 
	/* �����display buffer */
	unsigned int display_buf; 
	/* ������м���� */    
	unsigned int inter_param;   
	/* display buffer��ͼ��Ŀ� */  
	unsigned short out_width;   
	/* display buffer��ͼ��ĸ� */ 
	unsigned short out_height;  
	/* display buffer��ͼ���ʽ; 1: 4Y4U4Y4V, 2:YUV_4_2_0_PLANAR */  
	unsigned short out_format;    
}videoenc_output_attr_t;		    

/* ���ö��������� */
#define  SET_MOTION_PARAM      0xb003   
/* ��������佹���� */
#define  SET_ZOOM_PARAM        0xb004   
/* ��������佹���� */ 
#define  SET_SOURCE_WINDOWN    0xb008
/* ����IP��� */
#define  SET_FRM_INTVAL        0xb009

/*!
 * \brief
 *      ����������
 */
typedef struct {
        /* current(accurately last) quality */
	unsigned int cur_quality;	
	/* current(accurately last) I maxinterval */     
	unsigned int cur_interval;
	/* ���ģʽ, ��������Ƿ�ʹ�� */	   
	int          sur_field_mode; 
	/* default:3 */  
	unsigned short md_throld0;
	/* default:2 */ 
	unsigned short md_throld1;
	/* default:2 */
	unsigned short md_throld2;
	/* default:2 */   
	unsigned short md_throld3;
	unsigned int   reserved[3];
}videoenc_input_attr_t;			   

/*!
 * \brief
 *      ����佹����
 */
typedef  struct{
        /* ����佹�����Ƿ�ʹ�� 1��ʹ�ܣ�0����ʹ�� */
        int    enable_zoom ;      
        int    fr;
        int    br;
} encoder_zoom_t;

/*!
 * \brief
 *      ����ͼ�񴰿ڲ���
 */
typedef  struct{
        int    width;
        int    height;
} encoder_srcwin_t;

/*!
 * \brief
 *      ����ṹ
 */
typedef struct{
        char type;
        char *extension;
        void *(*open)(void *plugio);		/*open���ʱ��Ҫ���ߵ�ǰ������������*/
        int (*get_file_info)(stream_input_t *input,void *file_info);
}plugin_info_t;

/*!
 * \brief
 *      ��Ƶ���������
 */
typedef struct video_encoder_s{
        int (*init)(struct video_encoder_s *plugin,ve_param_t *param);
        int (*encode_data)(struct video_encoder_s *plugin,av_frame_t *src_frame,av_frame_t *dest_frame);
        int (*set_attribute)(struct video_encoder_s *plugin,int attrib_id,void *param);
        int (*get_attribute)(struct video_encoder_s *plugin,int attrib_id,void *param);
        int (*get_err)(struct video_encoder_s *plugin);
        int (*dispose)(struct video_encoder_s *plugin);
}video_encoder_t;

/*!
 * \brief
 *      ����Ƶ���������
 */
typedef struct mux_plugin_s{
        int (*init)(struct mux_plugin_s *plugin,ave_param_t *param);
        int (*write_header)(struct mux_plugin_s *plugin);
        int (*write_chunk)(struct mux_plugin_s *plugin,av_chunk_t *chunk);
        int (*set_attribute)(struct mux_plugin_s *plugin,int attrib_id,void *param);
        int (*get_attribute)(struct mux_plugin_s *plugin,int attrib_id,void *param);
        int (*get_error)(struct mux_plugin_s *plugin);
        int (*dispose)(struct mux_plugin_s *plugin);
}mux_plugin_t;

#endif
