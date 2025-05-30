#include "cpu.hpp"
#include <iostream>

GBA_CPU::GBA_CPU() {
	registers.fill(0);
	cpsr = 0;
}