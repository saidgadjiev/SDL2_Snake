#include "CTexture.h"
#include "CBodyItem.h"
#include "CSnake.h"
#include "CFood.h"
#include "CGameLogic.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

bool init()
{
    bool success = true;
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "SDL_Init Error: " << SDL_GetError() << endl;
        success = false;
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            cout << "Warning: linear texture filtering not enabled" << endl;
        }
        window = SDL_CreateWindow("Battle City", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
            success = false;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL) {
                cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
                success = false;
            } else {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
                int imgFlags = IMG_INIT_PNG;
                
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    cout << "IMG_INIT_PNG Error: " << SDL_GetError() << endl;
                    success = false;
                }
            }
        }
    }
    return success;
}

void close(CGameLogic *gameLogic)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = NULL;
    renderer = NULL;
    
    IMG_Quit();
    SDL_Quit();
}

int main ( int argc, char** argv )
{
    CGameLogic *gameLogic = new CGameLogic();
    
    if (!init()) {
        cout << "Failed to initialize SDL" << endl;
        return -1;
    } else {
        if (!gameLogic->loadMedia("/Users/said/Desktop/SDL2_Desctop/head.png", "/Users/said/Desktop/SDL2_Desctop/point.png", "/Users/said/Desktop/SDL2_Desctop/head.png")) {
            cout << "Failed to loaded media" << endl;
            return -1;
        } else {
            bool quit = false;
            SDL_Event event;
            const Uint8 *keyState;
            
            while(!quit && !gameLogic->getStatusGame()) {
                while(SDL_PollEvent(&event) != 0) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                }
                keyState = SDL_GetKeyboardState( NULL );
                gameLogic->logicGame(keyState);
                SDL_RenderClear(renderer);
                gameLogic->drawMap();
                SDL_RenderPresent(renderer);
                SDL_Delay(100);
            }
        }
    }
    close(gameLogic);
    return 0;
}
