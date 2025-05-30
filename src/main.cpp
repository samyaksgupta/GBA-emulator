#define SDL_MAIN_HANDLED
#include <C:/SDL2-w64/include/SDL2/SDL.h>
#include <C:/SDL2-w64/include/SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "cpu.hpp"

int main() {
    // Load ROM
    std::ifstream file("test_rom.gba", std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open ROM file.\n";
        return 1;
    }
    std::vector<uint8_t> rom_data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Init emulator
    GBA_CPU cpu;
    cpu.load_rom(rom_data);

    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("GBA Emulator", 100, 100, 240 * 2, 160 * 2, SDL_WINDOW_SHOWN);
    if (!win) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // (Eventually this will display frames from the GBA VRAM)
    SDL_Delay(2000);

    // Cleanup ok
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
