#include <iostream>
#include <chrono>
#include <thread>

void Sleep(int sleep)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
}

void pause()
{
    #ifdef _WIN64
        system("pause");
    #elif __linux__
        system("read -n1 -r -p \"Press any key to continue...\" key; echo -e \"\n\"");
    #else
        std::cout << "Неизвестная платформа, был вызван Sleep на 30 секунд" << std::endl;
        Sleep(30000);
    #endif
}



int main()
{
    std::cout << "hello linux + windows" << std::endl;
    
    pause();
}