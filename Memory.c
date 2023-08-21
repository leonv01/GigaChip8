//
// Created by leonv on 21/08/2023.
//

#include "Memory.h"

void initMemory(Memory* memory){

}

uint8_t readMemory(Memory* memory, uint16_t address){
    return memory->memory[address];
}

void writeMemory(Memory* memory, uint16_t address, uint8_t value){
    memory->memory[address] = value;
}