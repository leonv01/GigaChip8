#include <stdio.h>
#include "include/CPU.h"
#include "SDL2/SDL.h"

void drawGraphics(uint8_t* pixelMap);

int main(int argc, char* argv[]) {

    CPU cpu;
    initCPU(&cpu);

    if((SDL_Init(SDL_INIT_VIDEO)) == -1){ exit(-1);}

    SDL_Window* window = SDL_CreateWindow("GigaChip", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    SDL_Event event;
    int quit = 0;

    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                quit = 1;
        }
        parseOpcode(&cpu);

        if(cpu.updateScreen){
            drawGraphics(cpu.pixelMap);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawGraphics(uint8_t* pixelMap){

}