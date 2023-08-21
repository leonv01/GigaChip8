//
// Created by leonv on 21/08/2023.
//

#include "include/Memory.h"

void initMemory(Memory* memory){

}

uint8_t readMemory(Memory* memory, uint16_t address){
    return memory->memory[address];
}

void writeMemory(Memory* memory, uint16_t address, uint8_t value){
    memory->memory[address] = value;
}

uint16_t readMemoryWord(Memory* memory, uint16_t* address){
    uint8_t highByte = readMemory(memory, *(address++));
    uint8_t lowByte = readMemory(memory, *(address));
    return (highByte << 8) | lowByte;
}
void writeMemoryWord(Memory* memory, uint16_t* address, uint16_t value){
    writeMemory(memory, (*address++), value >> 8);
    writeMemory(memory, (*address), value & 0xFF);
}
