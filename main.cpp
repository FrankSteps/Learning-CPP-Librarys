namespace ray {
    #include <raylib.h>
}

int main(){
    ray::InitWindow(200, 200, "Window");

    while(!ray::WindowShouldClose()){
        ray::BeginDrawing();
        ray::ClearBackground(ray::RAYWHITE);
        ray::DrawText("Hello, world!", 0, 0, 20, ray::BLACK);
        ray::EndDrawing();
    }

    ray::CloseWindow();
    return 0;
}