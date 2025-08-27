namespace ray {
    #include <raylib.h>    
}

int screenWidth = 800;
int screenHeight = 600;
unsigned char alpha = 0;

int main() {
    ray::InitWindow(1024/2, 868/2, "Window");
    ray::Texture bg = ray::LoadTexture("image/cinema.jpeg");
    float scale = 0.5f;

    while (!ray::WindowShouldClose()) {
        if (alpha < 255){
            alpha++;
        }
        ray::BeginDrawing();
        ray::ClearBackground(ray::BLACK);
        ray::DrawTextureEx(bg, {0, 0}, 0.0f, scale, ray::Color{255, 255, 255, alpha});
        ray::EndDrawing();
        ray::WaitTime(0.01);
    }
    ray::UnloadTexture(bg);
    ray::CloseWindow();
    return 0;
}