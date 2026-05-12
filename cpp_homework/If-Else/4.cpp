#include <iostream>

int main(void) {
    int AH, AM, AS;
    int BH, BM, BS;

    std::cin >> AH >> AM >> AS
             >> BH >> BM >> BS;

    int H = AH + BH;
    int M = AM + BM;    
    int S = AS + BS;
    
    if (S > 60) {
        S %= 60;
        M += 1;

        if (M > 60) {
            M %= 60 ;
            H += 1;
        }
    } else if (M > 60) {
        M %= 60 ;
        H += 1;
    }
    
    std::cout << H << " " << M << " " << S << std::endl;
            
    return 0;
}