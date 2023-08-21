//
// Created by leonv on 21/08/2023.
//

#ifndef GIGACHIP8_MEMORY_H
#define GIGACHIP8_MEMORY_H

#define MEMORY_SIZE 0x1000

#include <stdint.h>

typedef struct{
    uint8_t memory[MEMORY_SIZE];
} Memory;

void initMemory(Memory* memory);
uint8_t readMemory(Memory* memory, uint16_t address);
void writeMemory(Memory* memory, uint16_t address, uint8_t value);

#endif //GIGACHIP8_MEMORY_H
