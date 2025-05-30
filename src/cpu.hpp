#ifndef CPU_HPP
#define CPU_HPP

#include <cstdint>
#include <array>
#include <vector>
#include <cstring>

class GBA_CPU {
public:
	std::array<uint32_t, 16> registers;
	// 16 registers r0 to r15
	uint32_t cpsr;
	//current prog. status reg.
	std::std::vector<uint8_t> memory;
	// emulated mem 32mb (i kinda doubt how is it 32 mb ?)
	GBA_CPU();
	void load_rom(const std::vector<uint8_t>& rom_data);
	void run();
};

#endif