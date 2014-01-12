#ifndef __BUF_HEADER_H__
#define __BUF_HEADER_H__

#ifdef __cplusplus
extern "C" {
#endif

/*Packet type*/
typedef enum
{
    AUDIO_PACKET = 0x100,
    VIDEO_PACKET = 0x200,
    SUBPIC_PACKET = 0x300
} packet_type_t;

//Audio and video packets have an unused reserved of 28 bytes in the header.
//We'll use them for structured data
typedef struct{
	/*Packet type*/
	unsigned int header_type;
	/*Packet payload length*/
	unsigned int block_len;
	/*File packet location*/
	unsigned int packet_offset;
	/*Packet timestamp*/
	unsigned int packet_ts;
	/*Reserved field 1*/
	unsigned int reserved1;
	/*Reserved field 2*/
	unsigned int reserved2;
	/*h264 get the information needed to correct timestamp*/
	unsigned char stream_end_flag;/* 1 end of stream, 0 No */
	unsigned char parser_format;
	unsigned char seek_reset_flag;
	unsigned char reserved_byte2;
}packet_header_t;
#ifdef __cplusplus
}
#endif
#endif // __BUF_HEADER_H__
