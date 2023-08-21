//
// Created by leonv on 21/08/2023.
//

#include "CPU.h"


void initCPU(CPU* cpu){
    cpu->PC = 0x0200;
    cpu->I = 0;
    cpu->SP = 0;
    cpu->opcode = 0;
}

void cpuExecute(CPU* cpu){

}