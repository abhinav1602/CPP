/**
 * @file RuleOfFiveExample.cpp
 * @brief Complete Rule of Five demonstration (copy/move ctor & assignment + dtor).
 * @date 2025-11-15
 */
#include <iostream>
#include <utility>

class Buffer {
    int* data=nullptr; std::size_t n=0;
public:
    Buffer()=default;
    explicit Buffer(std::size_t sz):data(new int[sz]),n(sz){ std::cout<<"ctor size="<<n<<"\n"; }
    ~Buffer(){ delete[] data; }
    Buffer(const Buffer& o):data(o.n?new int[o.n]:nullptr),n(o.n){ std::cout<<"copy ctor\n"; for(std::size_t i=0;i<n;++i) data[i]=o.data[i]; }
    Buffer& operator=(const Buffer& o){
        if(this!=&o){ int* nd = o.n? new int[o.n]: nullptr; for(std::size_t i=0;i<o.n;++i) nd[i]=o.data[i]; delete[] data; data=nd; n=o.n; std::cout<<"copy assign\n"; }
        return *this; }
    Buffer(Buffer&& o) noexcept : data(o.data), n(o.n){ o.data=nullptr; o.n=0; std::cout<<"move ctor\n"; }
    Buffer& operator=(Buffer&& o) noexcept { if(this!=&o){ delete[] data; data=o.data; n=o.n; o.data=nullptr; o.n=0; std::cout<<"move assign\n"; } return *this; }
};

int main(){ Buffer a(10); Buffer b=a; Buffer c=std::move(a); b=c; c=Buffer(5); return 0; }
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 RuleOfFiveExample.cpp -o RuleOfFiveExample */
