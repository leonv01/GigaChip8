//
// Created by leonv on 21/08/2023.
//


#include <sdoias.h>
#include "include/CPU.h"


void initCPU(CPU *cpu) {
    cpu->PC = 0x0200;
    cpu->I = 0x0;
    cpu->SP = 0x0;
    cpu->opcode = 0x0;
    cpu->SP = 0x00;
}

void cpuExecute(CPU *cpu) {
    cpu->opcode = readMemoryWord(&cpu->memory, &cpu->PC);
    cpu->PC++;
    parseOpcode(cpu, cpu->opcode);
}

void cpuPush(CPU *cpu, uint16_t value) {
    cpu->stack[cpu->SP++] = value;
}

uint16_t cpuPop(CPU *cpu) {
    return cpu->stack[--cpu->SP];
}

void parseOpcode(CPU *cpu, uint16_t opcode) {
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x0F00) >> 4;

    switch (opcode & 0xF000) {
        case 0x0000:
            if (opcode == 0x00E0) {
                // TODO Clear Screen
            } else if (opcode == 0x00EE) {
                cpu->PC = cpuPop(cpu);
            } else {

            }
            break;
        case 0x1000:
            cpu->PC = opcode & 0x0FFF;
            break;
        case 0x2000:
            cpuPush(cpu, cpu->PC);
            cpu->PC = opcode & 0x0FFF;
            break;
        case 0x3000:
            if (cpu->V[x] == (opcode & 0x00FF)) {
                cpu->PC += 2;
            }
            break;
        case 0x4000:
            if (cpu->V[x] != (opcode & 0x00FF)) {
                cpu->PC += 2;
            }
            break;
        case 0x5000:
            if (cpu->V[(opcode & 0x0F00) >> 8] == (cpu->V[(opcode & 0x00F0) >> 8])) {
                cpu->PC += 2;
            }
            break;
        case 0x6000:
            cpu->V[x] = opcode & 0x00FF;
            break;
        case 0x7000:
            cpu->V[x] += opcode & 0x00FF;
            break;
        case 0x8000:
            switch (opcode & 0x000F) {
                case 0x0000:
                    cpu->V[x] = cpu->V[y];
                    break;
                case 0x0001:
                    cpu->V[x] |= cpu->V[y];
                    break;
                case 0x0002:
                    cpu->V[x] &= cpu->V[y];
                    break;
                case 0x0003:
                    cpu->V[x] ^= cpu->V[y];
                    break;
                case 0x0004:
                    if(cpu->V[x] > (0xFF - cpu->V[y]))
                        cpu->V[0xF] = 1;
                    else
                        cpu->V[0xF] = 0;

                    cpu->V[x] += cpu->V[y];
                    break;
                case 0x0005:
                    if(cpu->V[x] >= cpu->V[y])
                        cpu->V[0xF] = 1;
                    else
                        cpu->V[0xF] = 0;

                    cpu->V[x] -= cpu->V[y];
                    break;
                case 0x0006:
                    cpu->V[0xF] = cpu->V[x] & 0x01;
                    cpu->V[x] >>= 1;
                    break;
                case 0x0007:
                    cpu->V[x] = cpu->V[y] - cpu->V[x];
                    break;
                case 0x000E:
                    cpu->V[0xF] = (cpu->V[x] & 0x80) >> 7;
                    cpu->V[x] <<= 1;
                    break;
                default:
                    break;
            }
            break;
        case 0x9000:
            if (cpu->V[x] != (cpu->V[y])) {
                cpu->PC += 2;
            }
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
            switch (opcode & 0x00FF) {
                case 0x001E:
                    cpu->I += cpu->V[(opcode & 0x0F00) >> 8];
                    break;

                case 0x0029:

                    break;
                case 0x0033:
                    writeMemory(&cpu->memory, cpu->I, (cpu->V[x] / 100));
                    writeMemory(&cpu->memory, cpu->I + 1, (cpu->V[x] / 10) % 10);
                    writeMemory(&cpu->memory, cpu->I + 2, (cpu->V[x] % 100) % 10);

                    break;
                case 0x0055:
                    for(size_t i = 0; i <= ((opcode & 0x0F00) >> 8); i++){
                        writeMemory(&cpu->memory, cpu->I + i, cpu->V[i]);
                    }
                    break;
                case 0x0065:
                    for(size_t i = 0; i <= ((opcode & 0x0F00) >> 8); i++){
                        cpu->V[i] = readMemory(&cpu->memory, cpu->I + i);
                    }
                    break;
            }
            break;
    }
}