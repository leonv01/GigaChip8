//
// Created by leonv on 21/08/2023.
//

#ifndef GIGACHIP8_CPU_H
#define GIGACHIP8_CPU_H

#include <stdint.h>
#include "Memory.h"

typedef struct{
    uint8_t V[16];
    uint16_t I;
    uint16_t PC;

    uint16_t SP;
    uint16_t stack[16];

    uint8_t opcode;

    Memory memory;
} CPU;

void initCPU(CPU* cpu);
void cpuExecute(CPU* cpu);

#endif //GIGACHIP8_CPU_H
