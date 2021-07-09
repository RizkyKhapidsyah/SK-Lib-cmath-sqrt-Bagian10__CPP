#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::cout << "sqrt(100) = " << std::sqrt(100) << '\n'
        << "sqrt(2) = " << std::sqrt(2) << '\n'
        << "golden ratio = " << (1 + std::sqrt(5)) / 2 << '\n';
    
    std::cout << "sqrt(-0) = " << std::sqrt(-0.0) << '\n';
    // Penanganan Error
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "sqrt(-1.0) = " << std::sqrt(-1) << '\n';
    
    if (errno == EDOM) {
        std::cout << "    errno = EDOM " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_INVALID)) {
        std::cout << "    FE_INVALID raised\n";
    }
        
    _getch();
    return 0;
}