#ifndef RTPPAYLOADFORMATAUDIO_H
#define RTPPAYLOADFORMATAUDIO_H
namespace rtppayloadformat
{
    class RTPPayloadFormatAAC
    {
        public:
            RTPPayloadFormatAAC(uint32_t samprate,uint8_t channel,uint8_t bit);
            ~RTPPayloadFormatAAC();
            bool UnpackRTPAAC(void * bufIn, int recvLen, void** pBufOut,  int* pOutLen);
        private:
            int m_audioSamprate ;//= 32000;//音频采样率
            int m_audioChannel ;//= 2;//音频声道 1或2
            int m_audioBit; // = 16;//16位 固定
    };
    
}

#endif