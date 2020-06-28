
#include "rtppayloadformatvideo.h"
#include "rtpcomment.h"

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
// +---------------+
// |0|1|2|3|4|5|6|7|
// +-+-+-+-+-+-+-+-+
// |S|E|R|  Type   |
// +---------------+

    // description：unpack rtp h264 fua to nal
    // return：true :the frame is end,  false: FU-A not end
    RTPPayloadFormatH264::RTPPayloadFormatH264()
    {

    }
    RTPPayloadFormatH264::~RTPPayloadFormatH264()
    {

    }
    bool  RTPPayloadFormatH264::UnpackRTPH264FUA( void  *  bufIn,  int len,   void **  pBufOut,  int   *  pOutLen)
    {
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
        if  (nal == 0x1c ) //  NAL type 0x1c=28
        { // fu-a
            if  (flag== 0x80 ) // START
            {
                * pBufOut =  src - 3 ;
                * (( int * )( * pBufOut))  =   0x01000000  ; //prefix {0x00,0x00,0x00,0x01} Little endian 
                * ((char * )( * pBufOut) + 4 )  =  nal_fua;
                *  pOutLen =  len -  RTP_HEADLEN +   3 ;
            }
            else   if (flag == 0x40 ) // END
            {
                * pBufOut =  src + 2 ;
                * pOutLen =  len -  RTP_HEADLEN -   2 ;
            }
            else 
            {
                * pBufOut =  src + 2 ;
                * pOutLen =  len -  RTP_HEADLEN -   2 ;
            }
        }
        else // Single NAL
        {
            * pBufOut =  src - 4 ;
            * (( int * )( * pBufOut))  =   0x01000000 ; ////prefix {0x00,0x00,0x00,0x01} Little endian 
            *  pOutLen =  len -  RTP_HEADLEN +   4 ;
        }

        unsigned char *  bufTmp  = (unsigned  char* )bufIn;
        if  (bufTmp[ 1 ]  &  0x80 )
        {
            bFinishFrame =   true ; // rtp mark
        }
        else
        {
            bFinishFrame =   false ;
        }
        return  bFinishFrame;
    }

}