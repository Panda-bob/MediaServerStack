
#include "rtppayloadformatvideo.h"
#include "rtpcomment.h"
#include "stdlib.h"

namespace rtppayloadformat
{



// Type   Packet    Type name                        Section
// ---------------------------------------------------------
// 0      undefined                                    -
// 1-23   NAL unit  Single NAL unit packet per H.264   5.6
// 24     STAP-A    Single-time aggregation packet     5.7.1
// 25     STAP-B    Single-time aggregation packet     5.7.1
// 26     MTAP16    Multi-time aggregation packet      5.7.2
// 27     MTAP24    Multi-time aggregation packet      5.7.2
// 28     FU-A      Fragmentation unit                 5.8
// 29     FU-B      Fragmentation unit                 5.8
// 30-31  undefined    

//


//Single NAL Unit Packet
// 0                   1                   2                   3
// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |F|NRI|  type   |                                               |
// +-+-+-+-+-+-+-+-+                                               |
// |                                                               |
// |               Bytes 2..n of a Single NAL unit                 |
// |                                                               |
// |                               +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                               :...OPTIONAL RTP padding        |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// [Start Code] [NALU Header] [NALU Payload]



// 0                   1                   2                   3
// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// | FU indicator  |   FU header   |                               |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                               |
// |                                                               |
// |                         FU payload                            |
// |                                                               |
// |                               +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                               :...OPTIONAL RTP padding        |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// nal_unit_type = (fu_indicator & 0xe0) | (fu_header & 0x1f)
// +---------------+
// |0|1|2|3|4|5|6|7|
// +-+-+-+-+-+-+-+-+
// |F|NRI|  Type   |
// +---------------+
// 0x67: SPS 
// 0x68: PPS 
// 0x65: IDR   
// 0x61: non-IDR Slice
// 0x01: B Slice
// 0x06: SEI
// 0x09: AU Delimiter
// +---------------+
// |0|1|2|3|4|5|6|7|
// +-+-+-+-+-+-+-+-+
// |S|E|R|  Type   |
// +---------------+

    // description：unpack rtp h264 fua to nal
    // return：true :the frame is end,  false: FU-A not end
    RTPPayloadFormatH264::RTPPayloadFormatH264():m_buf(NULL),m_buflen(0)
    {
        m_buf = (uint8_t *)malloc(MAX_H264_NALU*sizeof(uint8_t));
        if(m_buf == NULL)
        {
            std::cout<<" RTPPayloadFormatH264 malloc m_buf failed!" <<std::endl;
        }
        
    }
    RTPPayloadFormatH264::~RTPPayloadFormatH264()
    {
        if(m_buf != NULL)
        {
            free(m_buf);
        }
        //free()
    }

    bool  RTPPayloadFormatH264::UnpackRTPH264FUA( void  *  bufIn,  int len,   void **  pBufOut,  int   *  pOutLen)
    {
        if(m_buflen + len >= MAX_H264_NALU)
        {
            m_buflen = 0 ;
            std::cout<<" buf len is overflow : " << MAX_H264_NALU <<std::endl;
            return false;
        }
        * pOutLen  =   0 ;
        rtpHlen = GetRTPHeaderLength(bufIn,len);
        if  (len  <  rtpHlen)
        {
            return   false ;
        }

        unsigned char *  src  =  (unsigned  char* )bufIn +  rtpHlen;
        unsigned char  head1 =   * src; 
        unsigned  char  head2 =   * (src + 1 ); 
        unsigned  char  nal =  head1 &   0x1f; // FU indicator
        unsigned  char  flag =  head2 &   0xe0 ; // FU header
        unsigned  char  nal_fua =  (head1 &   0xe0 )  |  (head2 &   0x1f); // FU_A nal
        bool  bFinishFrame =   false ;
        uint32_t tmp_len = 0 ;
        if  (nal == 0x1c ) //  NAL type 0x1c=28
        { // fu-a
            if  (flag== 0x80 ) // START
            {
                tmp_len = len -  rtpHlen +   3 ;
                memcpy(m_buf + m_buflen, src - 3,tmp_len);
                * ((int *)m_buf + m_buflen)   =   0x01000000  ; //prefix {0x00,0x00,0x00,0x01} Little endian start code
                * ((char *)m_buf + m_buflen + 4 )  =  nal_fua;
                m_buflen +=  tmp_len;
            }
            else   if (flag == 0x40 ) // END
            {
                tmp_len = rtpHlen + 2;
                memcpy(m_buf + m_buflen, src + 2,tmp_len)  ;
                m_buflen += tmp_len;
            }
            else 
            {
                tmp_len = rtpHlen + 2;
                memcpy(m_buf + m_buflen, src + 2,tmp_len)  ;
                m_buflen += tmp_len;
            }
        }
        else // Single NAL
        {
            tmp_len = len - rtpHlen + 4;
            memcpy(m_buf + m_buflen, src - 4, tmp_len)
           
            * (( int * )m_buf)  =   0x01000000 ; //prefix {0x00,0x00,0x00,0x01} Little endian start code 
            m_buflen +=  tmp_len ;
        }

        unsigned char *  bufTmp  = (unsigned  char* )bufIn;
        if  (bufTmp[ 1 ]  &  0x80 )
        {
            bFinishFrame =   true ; // rtp mark
            *pBufOut = m_buf; 
            *pOutLen = m_buflen;
        }
        else
        {
            bFinishFrame =   false ;
            *pOutLen = 0;
        }
        return  bFinishFrame;
    }

}
bool RTPPayloadFormatH264::PackRTPH264ToFUA(void * bufin, int len,void * rtpsession )
{
    
    return true;
}