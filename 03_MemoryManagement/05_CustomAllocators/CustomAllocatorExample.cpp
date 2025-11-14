/**
 * @file CustomAllocatorExample.cpp
 * @brief Minimal custom allocator with std::vector usage.
 * @date 2025-11-15
 */
#include <iostream>
#include <memory>
#include <vector>

template<class T>
struct SimpleAllocator {
    using value_type = T;
    SimpleAllocator() noexcept {}
    template<class U> SimpleAllocator(const SimpleAllocator<U>&) noexcept {}
    T* allocate(std::size_t n){ auto p = static_cast<T*>(::operator new(n*sizeof(T))); std::cout<<"allocate "<<n<<"\n"; return p; }
    void deallocate(T* p, std::size_t n) noexcept { std::cout<<"deallocate "<<n<<"\n"; ::operator delete(p); }
};
template<class T, class U>
bool operator==(const SimpleAllocator<T>&, const SimpleAllocator<U>&){ return true; }

template<class T, class U>
bool operator!=(const SimpleAllocator<T>&, const SimpleAllocator<U>&){ return false; }

int main(){
    std::vector<int, SimpleAllocator<int>> v;
    for(int i=0;i<5;++i) v.push_back(i*10);
    std::cout << "Vector: "; for(int x: v) std::cout<<x<<' '; std::cout<<'\n';
    return 0;
}
/* Compilation: g++ -std=c++17 -Wall -Wextra -O2 CustomAllocatorExample.cpp -o CustomAllocatorExample */

