#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

int main() {
    int count = 0;
    while (true) {
        std::cout << "\x1b[H"; 
        std::vector<char> b;
        int startChr = 41 + count;
        int currentChr = startChr;

        for (std::size_t i = 0; i < 1760; ++i) {
            currentChr++;
            if (currentChr > 123) {
                currentChr = startChr;
            }
            b.push_back(char(currentChr));
        }

        for (int k = 0; k < 1761; ++k)  {
            std::cout.put(k % 80 ? b[k] : '\n');
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        count++;
        if (count > 123) { 
            count = 0;
        }
    }

    return 0;
}
