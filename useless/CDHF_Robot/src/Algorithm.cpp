#include "Algorithm.h"

unsigned short CRC_Verify(unsigned short *cBuffer, unsigned int iBufLen)
{
    unsigned int i, j;
    unsigned short wCrc = 0xffff;
    unsigned short wPolynom = 0xA001;
    /*---------------------------------------------------------*/
    for (i = 0; i < iBufLen; i++)
    {
        wCrc ^= cBuffer[i];
        for (j =0; j < 8; j++)
        {
            if (wCrc &0x01){
                wCrc = (wCrc >> 1) ^ wPolynom;
            }
            else{
                wCrc = wCrc >> 1;
            }
        }
    }
    return wCrc;
}

unsigned short do_crc(unsigned char *message, unsigned int len)
{
    unsigned int i, j;
    unsigned short crc_reg = 0;
    unsigned char  index;
    unsigned short to_xor;

    for (i = 0; i < len; i++)
    {
        index = (crc_reg ^ message[i]) & 0xff;
        to_xor = index;
        for (j = 0; j < 8; j++)
        {
            if (to_xor & 0x0001)
                to_xor = (to_xor >> 1) ^ 0x8408;
            else
                to_xor >>= 1;
        }
        crc_reg = (crc_reg >> 8) ^ to_xor;
    }
    return crc_reg;
}

unsigned short do_crc_MSB(unsigned char *message, unsigned int len)
{
    unsigned int i, j;
    unsigned short crc_reg = 0;
    unsigned short current;

    for (i = 0; i < len; i++)
    {
        current = message[i] << 8;
        for (j = 0; j < 8; j++)
        {
            if ((short)(crc_reg ^ current) < 0)
                crc_reg = (crc_reg << 1) ^ 0x1021;
            else
                crc_reg <<= 1;
            current <<= 1;
        }
    }
    return crc_reg;
}

#define CLAMP(x , min , max) ((x) > (max) ? (max) : ((x) < (min) ? (min) : x))
void Quaternion::SetEulerAngle(const EulerAngle &ea)
{
    float fCosHRoll = cos(ea.m_fRoll * .5f);
    float fSinHRoll = sin(ea.m_fRoll * .5f);
    float fCosHPitch = cos(ea.m_fPitch * .5f);
    float fSinHPitch = sin(ea.m_fPitch * .5f);
    float fCosHYaw = cos(ea.m_fYaw * .5f);
    float fSinHYaw = sin(ea.m_fYaw * .5f);

    // Cartesian coordinate System
    w = fCosHRoll * fCosHPitch * fCosHYaw + fSinHRoll * fSinHPitch * fSinHYaw;
    x = fSinHRoll * fCosHPitch * fCosHYaw - fCosHRoll * fSinHPitch * fSinHYaw;
    y = fCosHRoll * fSinHPitch * fCosHYaw + fSinHRoll * fCosHPitch * fSinHYaw;
    z = fCosHRoll * fCosHPitch * fSinHYaw - fSinHRoll * fSinHPitch * fCosHYaw;
    /*
    w = fCosHRoll * fCosHPitch * fCosHYaw + fSinHRoll * fSinHPitch * fSinHYaw;
    x = fCosHRoll * fSinHPitch * fCosHYaw + fSinHRoll * fCosHPitch * fSinHYaw;
    y = fCosHRoll * fCosHPitch * fSinHYaw - fSinHRoll * fSinHPitch * fCosHYaw;
    z = fSinHRoll * fCosHPitch * fCosHYaw - fCosHRoll * fSinHPitch * fSinHYaw;
    */
}

EulerAngle Quaternion::GetEulerAngle() const
{
    EulerAngle ea;

    // Cartesian coordinate System
    ea.m_fRoll  = atan2(2 * (w * x + y * z) , 1 - 2 * (x * x + y * y));
    ea.m_fPitch = asin(2 * (w * y - z * x));
    ea.m_fYaw   = atan2(2 * (w * z + x * y) , 1 - 2 * (y * y + z * z));
    /*
    ea.m_fRoll  = atan2(2 * (w * z + x * y) , 1 - 2 * (z * z + x * x));
    ea.m_fPitch = asin(CLAMP(2 * (w * x - y * z) , -1.0f , 1.0f));
    ea.m_fYaw   = atan2(2 * (w * y + z * x) , 1 - 2 * (x * x + y * y));
    */
    return ea;
}

