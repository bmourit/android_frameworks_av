#ifndef __BUF_HEADER_H__
#define __BUF_HEADER_H__

#ifdef __cplusplus
extern "C" {
#endif

/*������*/
typedef enum
{
    AUDIO_PACKET = 0x100,
    VIDEO_PACKET = 0x200,
    SUBPIC_PACKET = 0x300
} packet_type_t;

//����Ƶ����Ԥ����28��bytesͷδ�ã��ֽ���28bytes���ݽṹ��
typedef struct{
	/*������*/
	unsigned int header_type;
	/*���غɳ���*/
	unsigned int block_len;
	/*�����ļ�λ��*/
	unsigned int packet_offset;
	/*����ʱ���*/
	unsigned int packet_ts;
	/*�����ֶ�1*/
	unsigned int reserved1;
	/*�����ֶ�2*/
	unsigned int reserved2;
	/*h264�õ���ȷʱ�����Ҫ����Ϣ*/
	unsigned char stream_end_flag;/*1Ϊ������ 0Ϊ��*/
	unsigned char parser_format;
	unsigned char seek_reset_flag;
	unsigned char reserved_byte2;
}packet_header_t;
#ifdef __cplusplus
}
#endif
#endif // __BUF_HEADER_H__
