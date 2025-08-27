#include <iostream>
#include <vector>
#include <cmath>

namespace ray{
    #include <raylib.h>
}

int main(){
    ray::InitWindow(294, 211, "Cyan Chemistry - Frank Steps");
    ray::SetConfigFlags(ray::FLAG_WINDOW_RESIZABLE);
    
    ray::Texture cyan = ray::LoadTexture("image/discos/cyan.png");

    // Bloco do código responsável por carregar as músicas
    ray::InitAudioDevice();
    ray::Sound neod   = ray::LoadSound("sounds/neod.wav");
    ray::Sound mush   = ray::LoadSound("sounds/mush.wav");
    ray::Sound world  = ray::LoadSound("sounds/world.wav");
    ray::Sound cooper = ray::LoadSound("sounds/cooper.wav");
    ray::Sound sweet  = ray::LoadSound("sounds/sweet.wav");

    // Loop principal
    while (!ray::WindowShouldClose()) {
        ray::BeginDrawing();
        ray::ClearBackground(ray::BLACK);
        ray::DrawTexture(cyan, 0, 0, ray::WHITE);
        ray::EndDrawing();
    }
    // Limpeza
    ray::UnloadTexture(cyan);
    ray::UnloadSound(neod);
    ray::UnloadSound(mush);
    ray::UnloadSound(world);
    ray::UnloadSound(cooper);
    ray::UnloadSound(sweet);

    ray::CloseAudioDevice();
    ray::CloseWindow();
    return 0;
}
