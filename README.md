# obfuscate-my-strings

## Compile time strings obfuscation header file for C++\14

This project provides a special macro `OBFSTR`, which wraps the original string inside a lambda function that utilizes template and constexpr functions, enabling compile-time obfuscation.


### Usage example
We have the following program. In this case, the 'Hello world!' string can be easily found, and a reverse engineer can understand the program logic.

```c++
#include <iostream>
#include <obfstr.h>

int main()
{
    printf("%s", "Hello world!");
    return 0;
}
```
![изображение](https://github.com/lockheeed/obfuscate-my-strings/assets/47332822/16acdb11-6053-416a-8530-e80b61c0edb2)

But if you wrap your string with a macro, it will be processed at compile-time and stored in memory in an encoded format. As a result, reverse engineers will have some problems understanding the program logic statically.

```c++
#include <iostream>
#include <obfstr.h>

int main()
{
    printf("%s", OBFSTR("Hello world!"));
    return 0;
}
```
![изображение](https://github.com/lockheeed/obfuscate-my-strings/assets/47332822/f0570ef8-2b8c-48d6-adb8-566be6f8dcea)

Compile-time encode, runtime decode.
