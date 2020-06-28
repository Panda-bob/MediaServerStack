#include "rtppayloadformataudio.h"
#include "rtpcomment.h"

namespace rtppayloadformat
{
    RTPPayloadFormatAAC::RTPPayloadFormatAAC(uint32_t samprate,uint8_t channel,uint8_t bit):m_audioSamprate(samprate),m_audioChannel(channel),m_audioBit(bit)
    {
        // int m_audioSamprate ;//= 32000;//音频采样率
        // int m_audioChannel ;//= 2;//音频声道 1或2
        // int m_audioBit; // = 16;//16位 固定
    }
    RTPPayloadFormatAAC::~RTPPayloadFormatAAC():
    {

    }
    
    //功能：解RTP AAC音频包，声道和采样频率必须知道。
    //参数：1.RTP包缓冲地址 2.RTP包数据大小 3.H264输出地址 4.输出数据大小
    //return：true:表示一帧结束  false:帧未结束 一般AAC音频包比较小，没有分片。
    bool RTPPayloadFormatAAC::UnpackRTPAAC(void * bufIn, int recvLen, void** pBufOut,  int* pOutLen)
    {
        unsigned char*  bufRecv = (unsigned char*)bufIn;
        //char strFileName[20];
        
        unsigned char ADTS[] = {0xFF, 0xF1, 0x00, 0x00, 0x00, 0x00, 0xFC}; 
       
        switch(m_audioSamprate)
        {
        case  16000:
            ADTS[2] = 0x60;
            break;
        case  32000:
            ADTS[2] = 0x54;
            break;
        case  44100:
            ADTS[2] = 0x50;
            break;
        case  48000:
            ADTS[2] = 0x4C;
            break;
        case  96000:
            ADTS[2] = 0x40;
            break;
        default:
            break;
        }
        ADTS[3] = (m_audioChannel==2)?0x80:0x40;

        int len = recvLen - 16 + 7;
        len <<= 5;//8bit * 2 - 11 = 5(headerSize 11bit)
        len |= 0x1F;//5 bit    1            
        ADTS[4] = len>>8;
        ADTS[5] = len & 0xFF;
        *pBufOut = (char*)bufIn+16-7;
        memcpy(*pBufOut, ADTS, sizeof(ADTS));
        *pOutLen = recvLen - 16 + 7;

        unsigned char* bufTmp = (unsigned char*)bufIn;
        bool bFinishFrame = false;
        if (bufTmp[1] & 0x80)
        {
            //DebugTrace::D("Marker");
            bFinishFrame = true;
        }
        else
        {
            bFinishFrame = false;
        }
        return true;
    }
}


