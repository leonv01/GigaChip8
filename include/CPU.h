//
// Created by leonv on 21/08/2023.
//

#ifndef GIGACHIP8_CPU_H
#define GIGACHIP8_CPU_H

#define WIDTH 64
#define HEIGHT 32

#include <stdint.h>
#include "Memory.h"
#include "SDL2/SDL.h"
#include <time.h>


typedef struct{
    uint8_t V[16];
    uint16_t I;
    uint16_t PC;

    uint16_t SP;
    uint16_t stack[16];

    uint16_t opcode;

    Memory memory;

    uint8_t pixelMap[HEIGHT * WIDTH];

    uint8_t updateScreen;
} CPU;

void initCPU(CPU* cpu);
void cpuExecute(CPU* cpu);
void inline nextInstruction(CPU* cpu);

void cpuPush(CPU* cpu, uint16_t value);
uint16_t cpuPop(CPU* cpu);

void parseOpcode(CPU* cpu);

#endif //GIGACHIP8_CPU_H
