#ifndef ALDEC_PLUGIN_H
#define ALDEC_PLUGIN_H

#ifdef WIN32
#include "al_libc_dll.h"
#endif
#include "./common/stream_input.h"
#include "./common/extdef.h"
#include "./common/buf_header.h"

#define _ISPRAM_CODE_
#define _ISPRAM_SECTION_NAME_

#ifdef __cplusplus
extern "C" {
#endif

/*ͼ���ʽ����*/
#define YUV420_SEMI_PLANAR         0x00
#define YUV420_PLANAR              0x01

/*���audio��video������*/
#define AUDIO_MAX_PKT_SIZE        204800
#define VIDEO_MAX_PKT_SIZE        2048000

/* ���������ش����*/
typedef enum
{
	PLUGIN_RETURN_ERR = -1,
	PLUGIN_RETURN_NORMAL = 0,
	PLUGIN_RETURN_FILE_END,
	PLUGIN_RETURN_NOT_SUPPORT,
	PLUGIN_RETURN_PKT_NOTEND,
	PLUGIN_RETURN_SEEK_ERR
}plugin_err_no_t;


/*parser��decoder֮��Ĵ��ݰ������ݽṹ*/
typedef struct
{
	unsigned char *data;
	unsigned int data_len;
}av_buf_t;

/*�м���������ex_ops�ӿڵ������֣�����������չ��*/
typedef enum
{
	SET_SUBPIC,
	SET_TRACK,
	NORMAL_PLAY,
	DISCARD_FRAMES,
	NOTIFY_REF_FRAME_NUM,
	NOTIFY_FIFO_RESET,
	WAIT_FOR_HANTRO,
	SET_FOURCC,
	FLUSH_BUFFERS_REMAINING
}plugin_ex_ops_cmd_t;

typedef struct{
	unsigned int a_pos;	
	unsigned int v_pos;	
	int a_pts;
	int v_pts;
	int cur_time;
	int subpic_num;
}subpic_param_t;

typedef struct{
	unsigned int a_pos;	
	unsigned int v_pos;	
	int a_pts;
	int v_pts;
	int cur_time;
	int track_num;	
	int out_basetime;//����ֵ
}track_param_t;

/*parser_format��ѡֵ*/
typedef enum
{
	AVI = 0,
	MP4,
	MKV
} fileFormat_t;

//�м��������/��Ļʱ����parser�����ݽṹ
typedef struct{
	unsigned int audio_offset;
	unsigned int audio_ts;
	unsigned int video_offset;
	unsigned int video_ts;
	unsigned int subpic_offset;
	unsigned int subpic_ts;
}switch_audio_subpic_t;

typedef enum
{
	IS_AUDIO = 1,
	IS_VIDEO,
	IS_AV
}media_type_t;

typedef struct
{
    char extension[8];      /* �����ĺ�׺ */	
    unsigned int sample_rate;		/* �����ʣ���λhz */
    unsigned int channels;			/* ������ */
    void *buf;  
    void *private_data;            /* ָ���ض�����Ƶ��ʽ���ݽṹ */
    unsigned int audio_bitrate;
    unsigned int a_max_pkt_size;
} parser_audio_t;

typedef struct{
	char extension[8];
	unsigned int width;
	unsigned int height;
	unsigned int frame_rate;
	void *buf;		
	unsigned int video_bitrate;
	unsigned int v_max_pkt_size;	
}parser_video_t;

typedef struct{
	unsigned int drm_flag;
	char *license_info;
	char *special_info;
}parser_drm_t;

typedef struct
{
    char extension[8];      /* �����ĺ�׺ */    
    void *buf;  
    void *private_data;            /* ָ���ض�����Ƶ��ʽ���ݽṹ */
} parser_subtitle_t;

typedef struct{	
	parser_audio_t parser_audio[16];//���16������
	parser_video_t parser_video;
	parser_drm_t parser_drm;
	parser_subtitle_t parser_subtitle[16];
	unsigned int sub_num;
	unsigned int audio_num;		
    unsigned int media_type;
	unsigned int total_time;
	unsigned int first_audio_time;	
	unsigned int index_flag;    	
	unsigned int a_len_array[32];
	unsigned int v_len_array[32];
}media_info_t;


/* ����codec��֧������*/
typedef enum
{
	PLUGIN_SUPPORTED,//֧��
	PLUGIN_NOT_SUPPORTED_FIELDMOD,//h264/xvid��ģʽ��֧��
	PLUGIN_NOT_SUPPORTED_YUV444,//h264��yuv444��֧��
	PLUGIN_NOT_SUPPORTED_GMC,//xvid sprite,gmc���Բ�֧��
	PLUGIN_NOT_SUPPORTED_RPR,//rv��ֱ��ʲ�֧��
	PLUGIN_NOT_SUPPORTED_ADVANCED,//vc1��advanced profile��֧��
	PLUGIN_NOT_SUPPORTED_OTHER//������֧��
}video_plugin_supported_t;

typedef struct{
         unsigned int width;//��
         unsigned int height;//��
         unsigned int src_width;//Դ��
         unsigned int src_height;//Դ��
         unsigned int xpos;//��ʼˢ����x��,��padding��Ϊ0
         unsigned int ypos;//��ʼˢ����y��,��padding��Ϊ0 
         unsigned int ref_num; //�ο�֡����
         unsigned int extra_frame_size;//���ݸ�ֵ�м��������Ӧ�ڴ�
         video_plugin_supported_t supported; // ����spec���õ������
}video_codec_info_t;

typedef struct fb_port_s 
{
    void *(*get_wbuf)(struct fb_port_s *port,unsigned int buf_size);     
    void *(*try_get_wbuf)(struct fb_port_s *port,unsigned int buf_size);     
} fb_port_t;


typedef struct {
	unsigned int display_flag;    //��֡������ʾ--1��������ʾ--0
	unsigned int use_flag;  //��֡���ڱ�ʹ��--1��û��ʹ��--0    
	unsigned int time_stamp;    //��֡��ʱ���
	unsigned int width;        //��
	unsigned int height;         //��
	unsigned int format;         //���ݸ�ʽ����Ȼ��open�ӿڴ���format�ظ��������Ǳ���   
	unsigned int reserved1;
	unsigned int reserved2;
}dec_buf_t;

/*���������м��֮�䴫�ݵĿհ�֡�����ݽṹ*/
typedef struct
{
	dec_buf_t *vo_frame_info;
	unsigned char* vir_addr;
	unsigned char* phy_addr;
	unsigned int size;
}frame_buf_handle;
/*parser��decoder֮��Ĵ��ݰ������ݽṹ*/
typedef struct
{
	unsigned char *vir_addr;
	unsigned char *phy_addr;
	unsigned int data_len;
	void *reserved;
}stream_buf_handle;

typedef struct{
		char file_extension[8];
		void *(*open)(void *input,void *media_info);		/*open���ʱ��Ҫ���ߵ�ǰ������������*/		
		int (*parse_stream)(void *handle,av_buf_t *ao_buf,av_buf_t *vo_buf);
		int (*seek)(void *handle,void *time4seek);
		int (*dispose)(void *handle);	
		int (*ex_ops)(void *handle,int cmd,unsigned int arg);
}demux_plugin_t;

typedef struct{
		char extension[8];
		void *(*open)(void *ap_param,void *init_param,void *fb_vo);		
		int (*decode_data)(void *handle,stream_buf_handle *bitstream_buf);
		int (*dispose)(void *handle); 
		int (*ex_ops)(void *handle,int cmd,unsigned int arg);
		int (*probe)(void *init_buf,stream_buf_handle *bitstream_buf,video_codec_info_t *info);          
}videodec_plugin_t;

typedef struct
{
/*��������*/
  unsigned int seek_time;// ��Ҫ������ʱ��
  unsigned int cur_time; // ��ǰ�����ŵ���ʱ�䣬����������index��������������Ĳ��ø���
/*�������*/
  unsigned int found_audio_time;//�������ļ�λ�õ�audioʱ��
  unsigned int found_video_time;//�������ļ�λ�õ�videoʱ��
} time_stuct_t;

#ifdef __cplusplus
}
#endif
#endif
