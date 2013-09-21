#ifndef __UCONV_DEV_H__
#define __UCONV_DEV_H__

#ifdef __cplusplus
extern "C" {
#endif
/*!
 * \brief
 *		����ucnv����ת��
 * */
int convert_ucnv(char *from_charset, char *to_charset, char *inbuf, int inlen,
		char *outbuf, int outlen);
/*!
 * \brief
 *		����Ƿ���Ч��utf-8��ʽ
 * */
int check_valid_utf8(char *utf8, int length);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif
