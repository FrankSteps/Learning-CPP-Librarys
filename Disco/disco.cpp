#include <iostream>
#include <vector>
#include <cmath>

namespace ray{
    #include <raylib.h>
}

int song = 0;

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
        // efeito arco-iris
        float time = ray::GetTime();
        unsigned char r = (unsigned char)(127 + 127 * sin(2 * M_PI * time * 0.3));
        unsigned char g = (unsigned char)(127 + 127 * sin(2 * M_PI * time * 0.3 + 2));
        unsigned char b = (unsigned char)(127 + 127 * sin(2 * M_PI * time * 0.3 + 4));

        ray::BeginDrawing();
        ray::ClearBackground(ray::BLACK);
        ray::DrawTexture(cyan, 0, 0, ray::WHITE);

        switch(song){
            case 1:
                ray::DrawText("Neod - Frank Steps", 5, 140, 20, ray::Color{r, g, b, 255});  
                if (!ray::IsSoundPlaying(neod)) ray::PlaySound(neod);
            break;

            case 2:
                ray::DrawText("Mush - Frank Steps", 5, 140, 20, ray::Color{r, g, b});  
                if (!ray::IsSoundPlaying(mush)) ray::PlaySound(mush);
            break;

            case 3:
                ray::DrawText("World - Frank Steps", 5, 140, 20, ray::Color{r, g, b});  
                if (!ray::IsSoundPlaying(world)) ray::PlaySound(world);
            break;

            case 4:
                ray::DrawText("Cooper - Frank Steps", 5, 140, 20, ray::Color{r, g, b});  
                if (!ray::IsSoundPlaying(cooper)) ray::PlaySound(cooper);
            break;

            case 5:
                ray::DrawText("Sweet - Frank Steps", 5, 140, 20, ray::Color{r, g, b});  
                if (!ray::IsSoundPlaying(sweet)) ray::PlaySound(sweet);
            break;

            default:
                ray::DrawText("Hello, world!", 5, 140, 20, ray::Color{r, g, b});
                ray::StopSound(neod);
                ray::StopSound(mush);
                ray::StopSound(world);
                ray::StopSound(cooper);
                ray::StopSound(sweet);
            break;
        }

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
