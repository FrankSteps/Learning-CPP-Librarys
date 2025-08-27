/*
Desenvolvedor desta blasfêmia: Francisco Passos
Arrependimento em: 27/080/2025

Este programa foi desenvolvido para ver o quão longe um ser consegue chegar com a biblioteca Raylib no C++
Para ver o quão distante Deus está da humanidade e o quanto a mesma se encontra perdida

Se seres humanos tivessem tal conhecimento, quais desgraças poderiam ser feitas? Quantas blasfêmias poderiam ser ditas?
Este projeto procura responder isso...
Nenhuma criatura merece perdão divino, principalmente quem desenvolveu esta escória. 

Me perdoe, raysan5; me perdoe, Bjarne Stroustrup; me perdoe, Santo Deus pois eu não mereço seu perdão. 
Não sou digno de ser teu filho, oh meu pai! Não sou digno de tua herança

"O apocalípse deixou de ser um medo e se tornou uma esperança..."
~ Desconhecido

"Não tive filhos. Não passei a nenhuma criatura o legado de nossa miséria..."
~ Assis, Machado - 1800 e não sei o que
*/

#include <iostream>
#include <string>
#include <vector>

namespace ray{
    #include <raylib.h>
}

int main(){
    ray::InitWindow(224, 224, "Milos");
    
    //Responsável por tocar a música
    ray::InitAudioDevice();
    ray::Sound sound = ray::LoadSound("sounds/milos.wav");
    ray::PlaySound(sound);

    //responsável pela imagem do projeto 
    const int frame_count = 48;
    std::vector<ray::Texture> frames(frame_count);
    for(int i = 0; i < frame_count; i++){
        frames[i] = ray::LoadTexture(("image/frame_" + std::to_string(i) + ".png").c_str());
    }

    int current_frame = 0;
    float frame_timer = 0.0f;
    const float frame_duration = 0.07f; // tempo de cada frame

    while (!ray::WindowShouldClose()) {
        // Atualiza a 1imagem
        frame_timer += ray::GetFrameTime();
        if (frame_timer >= frame_duration) {
            current_frame = (current_frame + 1) % frame_count; 
            frame_timer = 0.0f;
        }
        ray::BeginDrawing();
        ray::ClearBackground(ray::RAYWHITE);
        ray::DrawTexture(frames[current_frame], 0, 0, ray::WHITE);
        ray::EndDrawing();
    }

    for (auto &t : frames) ray::UnloadTexture(t);
    ray::UnloadSound(sound);
    ray::CloseAudioDevice();
    ray::CloseWindow();
    return 0;    
}