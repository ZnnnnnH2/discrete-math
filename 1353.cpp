#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

const int INPUT_SIZE = 2000 + 5;
const int LIMIT = 512 / 8;
u8 init[LIMIT];
u32 h[] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19,
};
int addtional_length = 0;
char input[INPUT_SIZE];
void Message_Padding(int string_index, int length)
{
    memset(init, 0, sizeof(init));
    int index = 0;
    for (; index + string_index < length; index++)
    {
        init[index] = (u8)input[index + string_index];
    }
    if (addtional_length == 0)
    {
        init[index] = 0x80;
        index++;
    }
    while (index < LIMIT - 8)
    {
        init[index] = 0x00;
        index++;
    }
    u64 bit_length = (length - addtional_length) * 8;
    for (int i = 0; i < 8; i++)
    {
        init[LIMIT - 1 - i] = (u8)(bit_length & 0xFF);
        bit_length >>= 8;
    }
}
u32 w[64];
u32 from_u8_to_u32(int index)
{
    u32 result = 0;
    for (int i = 0; i < 4; i++)
    {
        result = (result << 8) | (u32)init[index + i];
    }
    return result;
}
u32 ROTR(u32 x, int n)
{
    while (n--)
    {
        x = (x >> 1) | (x << (32 - 1));
    }
    return x;
}
u32 SHR(u32 x, int n)
{
    return x >> n;
}
u32 sigma0(u32 x)
{
    return ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3);
}
u32 sigma1(u32 x)
{
    return ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10);
}
void Block_and_Schedule()
{
    // memset(w, 0, sizeof(w));
    for (int i = 0; i < 16; i++)
    {
        w[i] = from_u8_to_u32(i * 4);
    }
    for (int i = 16; i < 64; i++)
    {
        w[i] = sigma1(w[i - 2]) + w[i - 7] + sigma0(w[i - 15]) + w[i - 16];
    }
}
const u32 k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
u32 Sigma_0(u32 x)
{
    return ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22);
}
u32 Sigma_1(u32 x)
{
    return ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25);
}
u32 Ch(u32 x, u32 y, u32 z)
{
    return (x & y) ^ (~x & z);
}
u32 Maj(u32 x, u32 y, u32 z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}
void main_compression_loop()
{
    u32 a = h[0];
    u32 b = h[1];
    u32 c = h[2];
    u32 d = h[3];
    u32 e = h[4];
    u32 f = h[5];
    u32 g = h[6];
    u32 hh = h[7];
    for (int j = 0; j < 64; j++)
    {
        u32 T1 = hh + Sigma_1(e) + Ch(e, f, g) + k[j] + w[j];
        u32 T2 = Sigma_0(a) + Maj(a, b, c);
        hh = g;
        g = f;
        f = e;
        e = d + T1;
        d = c;
        c = b;
        b = a;
        a = T1 + T2;
    }
    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += hh;
}
int main()
{
    scanf("%s", input);
    int length = strlen(input);
    if (length % LIMIT > 55)
    {
        addtional_length = LIMIT - length % LIMIT;
        input[length] = 0x80;
        for (int i = 1; i < addtional_length; i++)
        {
            input[length + i] = 0x00;
        }
        length += addtional_length;
        input[length] = '\0';
    }
    int index = 0;
    while (length - index >= LIMIT)
    {
        // memset(init, 0, sizeof(init));
        for (int i = 0; i < LIMIT; i++)
        {
            init[i] = (u8)input[index + i];
        }
        index += LIMIT;
        Block_and_Schedule();
        main_compression_loop();
    }
    // memset(init, 0, sizeof(init));
    Message_Padding(index, length);
    Block_and_Schedule();
    main_compression_loop();
    for (int i = 0; i < 8; i++)
    {
        printf("%08x", h[i]);
    }
    return 0;
}