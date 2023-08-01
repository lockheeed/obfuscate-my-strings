#pragma once
#include <stddef.h>


namespace obfstr
{
    constexpr char key[] = { 0xae, 0x60, 0x53, 0xff, 0xde, 0xda };

    template<size_t size>
    struct MetaString
    {
        char buff[size];

        constexpr MetaString() : buff{ 0 } {}

        char* deobfuscate()
        {
            for (size_t i = 0; i < size - 1; i++) 
                buff[i] ^= key[i % sizeof(key)];
            return buff;
        }
    };

    template<size_t size>
    constexpr auto obfuscate(const char plaintext[size])
    {
        MetaString<size> obfuscated;

        for (size_t i = 0; i < size - 1; i++)
            obfuscated.buff[i] = plaintext[i] ^ key[i % sizeof(key)];

        obfuscated.buff[size - 1] = 0;

        return obfuscated;
    }
}


#define ENCODE(x) []() { constexpr auto encoded = obfstr::obfuscate<sizeof(x)>(x); return encoded; }()
#define OBFSTR(x) ENCODE(x).deobfuscate()