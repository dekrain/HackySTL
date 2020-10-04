#include "../../cpp/Time.hpp"
#include "../../cpp/Io.hpp"

#include <iostream>

int main()
{
    hsd::clock c1;
    const hsd::u32 iterations = 4000000;
    
    for(hsd::u32 i = 0; i < iterations; i++)
        hsd::io::print("Hello World\r");

    hsd::io::print("hsd IO elapsed time: {}ns\n", c1.restart().to_nanoseconds() / iterations);
    c1.restart();

    for(hsd::u32 i = 0; i < iterations; i++)
        std::cout << "Hello World\r";

    hsd::io::print("std IO elapsed time: {}ns\n", c1.restart().to_nanoseconds() / iterations);
}