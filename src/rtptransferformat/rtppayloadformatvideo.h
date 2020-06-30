#ifndef RTPPAYLOADFORMATVIDEO_H
#define RTPPAYLOADFORMATVIDEO_H
#pragma once
namespace rtppayloadformat
{
    #define  RTP_HEADLEN 12
    #define MAX_H264_NALU 1024*1024
    // the doc reference rfc3984
    class RTPPayloadFormatH264{
        public:
            RTPPayloadFormatH264();
            ~RTPPayloadFormatH264();
            bool UnpackRTPH264FUA( void  *  bufIn,  int len,void** pBufOut,  int* pOutLen);// mpeg ts  
            bool PackRTPH264ToFUA(void * bufin, int len,void * rtpsession );  
        private:
            unsigned char* m_buf;
            uint32_t m_buflen;
    };

     // the doc reference rfc7798
    class RTPPayloadFormatH265{

    };
}
#endif