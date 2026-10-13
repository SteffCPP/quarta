#include <iostream>
#include <thread>
#include <chrono>

int main(){
    std::jthread thread([](std::stop_token stoken){
        while(!stoken.stop_requested()){
            std::cout << "Hello World!\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::cout << "Stopped printing!\n";
    });

    std::getchar();
    thread.request_stop();
    std::cout << "Stop requested...\n";
}