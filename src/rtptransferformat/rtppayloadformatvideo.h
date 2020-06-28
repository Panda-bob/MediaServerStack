#ifndef RTPPAYLOADFORMATVIDEO_H
#define RTPPAYLOADFORMATVIDEO_H
#pragma once
namespace rtppayloadformat
{
    #define  RTP_HEADLEN 12
    
    // the doc reference rfc3984
    class RTPPayloadFormatH264{
        public:
            RTPPayloadFormatH264();
            ~RTPPayloadFormatH264();
            bool  UnpackRTPH264FUA( void  *  bufIn,  int len,   void **  pBufOut,  int   * pOutLen);

        private:

    };

     // the doc reference rfc7798
    class RTPPayloadFormatH265{

    };
}
#endif