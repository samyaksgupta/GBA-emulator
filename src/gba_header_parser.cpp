#include <iostream>
#include <fstream>
#include <iomanip>  // for std::hex and std::setw

void printGBAHeader(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Failed to open GBA file: " << filename << std::endl;
        return;
    }

    char header[192] = {};
    file.read(header, sizeof(header));

    // Game Title is at offset 0xA0, length 12
    std::string gameTitle(header + 0xA0, 12);

    // Entry Point (4 bytes) at offset 0x00
    uint32_t entryPoint = *(uint32_t*)(header + 0x00);

    // Game Code at offset 0xAC, 4 bytes
    std::string gameCode(header + 0xAC, 4);

    // Maker Code at offset 0xB0, 2 bytes (ASCII)
    std::string makerCode(header + 0xB0, 2);

    std::cout << "Game Title: " << gameTitle << "\n";
    std::cout << "Entry Point: 0x" << std::hex << entryPoint << std::dec << "\n";
    std::cout << "Game Code: " << gameCode << "\n";
    std::cout << "Maker Code: " << makerCode << "\n";
}
int main() {
    const char* gba_file = "C:/GAMES/GameDev/GBA emulator/rom/Super Mario Advance 4 - Super Mario Bros. 3 (U) (V1.1).gba";
    printGBAHeader(gba_file);
    return 0;
}
