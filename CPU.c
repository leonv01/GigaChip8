//
// Created by leonv on 21/08/2023.
//


#include "include/CPU.h"


void initCPU(CPU* cpu){
    cpu->PC = 0x0200;
    cpu->I = 0x0;
    cpu->SP = 0x0;
    cpu->opcode = 0x0;
    cpu->SP = 0xF;
}

void cpuExecute(CPU* cpu){
    cpu->opcode = readMemoryWord(&cpu->memory, &cpu->PC);
    cpu->PC++;
    parseOpcode(cpu, cpu->opcode);
}

void cpuPush(CPU* cpu, uint8_t value){
    cpu->stack[cpu->SP--] = value;
}
uint8_t cpuPop(CPU* cpu){
    return cpu->stack[cpu->SP++];
}

void parseOpcode(CPU* cpu, uint16_t opcode){
    switch (opcode & 0xF000) {
        case 0x0000:
            if(opcode == 0x00E0){
                // TODO Clear Screen
            }
            else if(opcode == 0x00EE){

            }
            else{

            }
            break;
        case 0x1000:
            break;
        case 0x2000:
            break;
        case 0x3000:
            break;
        case 0x4000:
            break;
        case 0x5000:
            if(cpu->V[opcode & 0x0F00] == (cpu->V[opcode & 0x00F0]){

            }
            break;
        case 0x6000:
            cpu->V[opcode & 0x0F00] = opcode & 0x00FF;
            break;
        case 0x7000:
            cpu->V[opcode & 0x0F00] += opcode & 0x00FF;
            break;
        case 0x8000:
            switch (opcode & 0x000F) {
                case 0x0000:
                    cpu->V[opcode & 0x0F00] = cpu->V[opcode & 0x00F0];
                    break;
                case 0x0001:
                    cpu->V[opcode & 0x0F00] |= cpu->V[opcode & 0x00F0];
                    break;
                case 0x0002:
                    cpu->V[opcode & 0x0F00] &= cpu->V[opcode & 0x00F0];
                    break;
                case 0x0003:
                    cpu->V[opcode & 0x0F00] ^= cpu->V[opcode & 0x00F0];
                    break;
                case 0x0004:
                    cpu->V[opcode & 0x0F00] += cpu->V[opcode & 0x00F0];
                    break;
                case 0x0005:
                    cpu->V[opcode & 0x0F00] -= cpu->V[opcode & 0x00F0];
                    break;
                case 0x0006:
                    cpu->V[opcode & 0x0F00] >>= 1;
                    break;
                case 0x0007:
                    cpu->V[opcode & 0x0F00] = cpu->V[opcode & 0x00F0] - cpu->V[opcode & 0x0F00];
                    break;
                case 0x000E:
                    cpu->V[opcode & 0x0F00] <<= 1;
                    break;
                default:
                    break;
            }
            break;
        case 0x9000:
            break;
        case 0xA000:
            cpu->I = opcode & 0x0FFF;
            break;
        case 0xB000:
            cpu->PC = cpu->V[0] + (opcode & 0x0FFF);
            break;
        case 0xC000:
            cpu->V[opcode & 0x0F00];
            //TODO RANDOM
            break;
        case 0xD000:
            break;
        case 0xE000:
            break;
        case 0xF000:
            break;
    }
}