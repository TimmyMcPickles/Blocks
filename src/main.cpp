#include "raylib.h"
#include <cmath>
#include <iostream>

//#pragma region imgui
//#include "../thirdparty/imgui-docking/imgui/imgui.h"
//#include "../thirdparty/rlImGui/rlImGui.h"
//#include "../thirdparty/imgui-docking/imgui/imguiThemes.h"
//#pragma endregion

typedef enum gameState{
    START = 0,
    PAUSE = 1,
    END = 2
} gameState;

int main(void)
{
    // Initialization
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	gameState currentState = START;
	int frameCounter = 0;

	SetTargetFPS(60);
	// Main loop
	while (!WindowShouldClose())
	{
	    // Update
	switch (currentState)
	{
		case START:
		{
		  if(IsKeyPressed(KEY_SPACE))
			{
			    currentState = PAUSE;
			}
		}break;

		case PAUSE:
		{
			 if (IsKeyPressed(KEY_SPACE)){
				currentState = START;
			}
		}break;
		case END:
		{
		    if (IsKeyPressed(KEY_ESCAPE)){
						currentState = END;
						}
		}break;
		default: break;
	}

		//Draw
	BeginDrawing();
	   ClearBackground(WHITE);

		switch(currentState){
		case START:
		  {
		    DrawText("Title screen", 20, 20, 40, BLACK);
			DrawText("Press [SPACE] to pause, and [ESC] to end.", 290, 220, 20, BLACK);
		  }break;
		case PAUSE:
		  {
			DrawRectangle(0,0,screenWidth, screenHeight, GRAY);
			DrawText("PAUSE",20, 20, 40, RED);
		  }break;
		case END:
		  {
			DrawRectangle(0, 0, screenWidth, screenHeight, GRAY);
			DrawText("END!!!", 20, 20, 40, WHITE);
		  }break;
		default: break;
		}
		EndDrawing();
	}
	// De-Initialization
	CloseWindow();

	return 0;
}
