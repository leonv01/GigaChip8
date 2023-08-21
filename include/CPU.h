//
// Created by leonv on 21/08/2023.
//

#ifndef GIGACHIP8_CPU_H
#define GIGACHIP8_CPU_H

#include <stdint.h>
#include "Memory.h"
#include <time.h>

typedef struct{
    uint8_t V[16];
    uint16_t I;
    uint16_t PC;

    uint16_t SP;
    uint16_t stack[16];

    uint16_t opcode;

    Memory memory;
} CPU;

void initCPU(CPU* cpu);
void cpuExecute(CPU* cpu);

void cpuPush(CPU* cpu, uint8_t value);
uint8_t cpuPop(CPU* cpu);

void parseOpcode(CPU* cpu, uint16_t opcode);

#endif //GIGACHIP8_CPU_H
