#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <cmath>

#define PI 3.14159

union Union64{
    unsigned char b[8];
    signed char   s8[8];
    unsigned char u8[8];
    signed short  s16[4];
    unsigned short u16[4];
    signed int    s32[2];
    unsigned int  u32[2];
    signed long   s64;
    unsigned long u64;
    float         f32[2];
    double        f64;
};
class EulerAngle
{
public:
    float m_fYaw , m_fPitch, m_fRoll;
public:
    EulerAngle(void): m_fYaw(0.0f) , m_fPitch(0.0f) , m_fRoll(0.0f) {}
    ~EulerAngle(void) {}
};
class Quaternion
{
public:
    float x , y , z , w;
public:
    Quaternion(void) : x(0.0f) , y(0.0f) , z(0.0f) , w(1.0f) {}
    ~Quaternion(void) {}
    void SetEulerAngle(const EulerAngle& ea);
    EulerAngle GetEulerAngle() const;
};
unsigned short CRC_Verify(unsigned short *cBuffer, unsigned int iBufLen);
unsigned short do_crc(unsigned char *message, unsigned int len);
unsigned short do_crc_MSB(unsigned char *message, unsigned int len);

#endif //ALGORITHM_H
