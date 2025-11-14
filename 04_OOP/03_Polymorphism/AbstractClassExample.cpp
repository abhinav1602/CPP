/**
 * @file AbstractClassExample.cpp
 * @brief Abstract interface usage.
 * @date 2025-11-15
 */
#include <iostream>

struct Runner { virtual void run()=0; virtual ~Runner()=default; };
struct AppRunner : Runner { void run() override { std::cout<<"Running app...\n"; } };

int main(){ AppRunner r; r.run(); return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 AbstractClassExample.cpp -o AbstractClassExample */
