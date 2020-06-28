#ifndef RTPCOMMENT_H
#define RTPCOMMENT_H
#pragma once
namespace rtppayloadformat
{


// RTP Header according to RFC3550
// 0                   1                   2                   3
// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |V=2|P|X|  CC   |M|     PT      |       sequence number         |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                           timestamp                           |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |           synchronization source (SSRC) identifier            |
// +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
// |            contributing source (CSRC) identifiers             |
// |                             ....                              |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

// 0                   1                   2                   3
// 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |      defined by profile       |           length              |
// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// |                        header extension                       |
// |                             ....                              |

    int GetRTPHeaderLength(void * bufin,int len)
    {
        int rtpHeaderLen = 0;
        if( len < RTP_HEADLEN )
        {
            return rtpHeaderLen;
        }

        uint8_t  rtph = (uint8_t *)bufin[0];
        if(rtph & 0x10 == 0x10)
        {
            uint16_t rtpExLen = 0;
		    rtpExLen = ntohs(*(uint16_t *)(Pack + RTP_HEADLEN + 2));
		    rtpHeaderLen = 16 + rtpExLen * sizeof(uint32_t);
        }
        if( rtpHeaderLen > len)
        {
            rtpHeaderLen = 0;
        }
        return rtpHeaderLen;
    }
}
#endif