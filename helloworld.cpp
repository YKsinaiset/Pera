#include <iostream>
#include <wiringPiSPI.h>
#include <wiringPi.h>

int MPU9250_A_Z_H = 0;
int MPU9250_A_Z_L = 0;
int MPU9250_A_Z = 0;

int main(int argc, char const *argv[])
{

    int fd = wiringPiSPISetup(0, 10000000);
    if (fd < 0)
        std::cout << "error\n";
    unsigned char data[10] = {0xf5};
    wiringPiSPIDataRW(0, data, 3);
    std::cout << (int)data[1] << "\n";

    data[0] = 0xbf;
    wiringPiSPIDataRW(0, data, 2);
    MPU9250_A_Z_H = (int)data[1];
    std::cout << MPU9250_A_Z_H << "\n";

    data[0] = 0xc0;
    wiringPiSPIDataRW(0, data, 2);
    MPU9250_A_Z_L = (int)data[1];
    std::cout << MPU9250_A_Z_L << "\n";

    MPU9250_A_Z = MPU9250_A_Z_H * 225 + MPU9250_A_Z_L;
    std::cout <<"MPU9250_A_Z=" <<MPU9250_A_Z << "\n";
}