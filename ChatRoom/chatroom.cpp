#include "raylib.h"
#include <string>

int main() {
    // Inicializa janela
    InitWindow(900, 600, "Chat UP!");
    
    const char* username = "Frank Steps";     // string
    const char* date = "10/09/2025";    // string
    const char* color = "Purple";         // string

    // Carregar avatar (coloque seu PNG na pasta do projeto)
    Texture2D avatar = LoadTexture("avatar.png");

    // Fonte padrão
    Font font = LoadFont("fonts/ArialCE.ttf");

    // Caixa de texto
    Rectangle inputBox = { 10, 550, 880, 40 };
    std::string inputText = "";
    bool typing = false;

    while (!WindowShouldClose()) {
        // Entrada de texto
        if (CheckCollisionPointRec(GetMousePosition(), inputBox) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            typing = true;
        }
        if (typing) {
            int key = GetCharPressed();
            while (key > 0) {
                if (key >= 32 && key <= 125) {
                    inputText += (char)key;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE) && !inputText.empty()) {
                inputText.pop_back();
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Fundo gradiente
        DrawRectangleGradientEx(
            (Rectangle){0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
            (Color){220, 240, 255, 255}, // topo esquerda
            (Color){220, 240, 255, 255}, // topo direita
            (Color){245, 250, 255, 255}, // baixo direita
            (Color){230, 245, 250, 255}  // baixo esquerda
        );

        

        // Cabeçalho
        DrawRectangle(0, 0, GetScreenWidth(), 120, Fade(SKYBLUE, 0.2f));
        DrawTextureEx(avatar, (Vector2){10, 10}, 0, 0.3f, WHITE);
        DrawTextEx(font, username, (Vector2){120, 5}, 50, 1, BLACK);
        DrawTextEx(font, "Since: ", (Vector2){120, 50}, 30, 1, GRAY);
        DrawTextEx(font, date, (Vector2){220, 50}, 30, 1, GRAY); // data ao lado do texto
        DrawTextEx(font, "Favorite color: ", (Vector2){120, 78}, 30, 1, GRAY);
        DrawTextEx(font, color, (Vector2){300, 78}, 30, 1, GRAY); // cor ao lado do texto

        // Área do chat
        DrawRectangleRounded((Rectangle){20, 120, 860, 400}, 0.05f, 8, Fade(LIGHTGRAY, 0.2f));

        // Caixa de texto
        DrawRectangleRounded(inputBox, 0.2f, 8, WHITE);
        DrawRectangleRoundedLines(inputBox, 0.2f, 8, GRAY); 

        // Texto digitado
        DrawTextEx(font, inputText.c_str(), {inputBox.x + 10, inputBox.y + 10}, 20, 1, DARKGRAY);

        EndDrawing();
    }

    // Cleanup
    UnloadTexture(avatar);
    UnloadFont(font);
    CloseWindow();
    return 0;
}
