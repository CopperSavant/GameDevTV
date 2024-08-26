/*
* Name: Axe_Game.cpp
* Purpose: Move the circle past the square or DIE!!!!
* Author: Copper Savant
* Date: 8/20/2024
*/

#include "raylib.h"
int main ()
{
    // window dimensions
    int width{800};
    int height{450};

    // Make a window. width, height, title
    InitWindow(width, height, "Christopher's Window");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    //circle dimensions
    int circle_radius{25};
    // circle hit box
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    // axe dimensions
    int axe_length{50};
    int axe_height{50};
    // axe direction
    int direction{10};
    // axe hit box
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    // Collision
    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) &&
                        (u_axe_y <= b_circle_y) &&
                        (r_axe_x >= l_circle_x) &&
                        (l_axe_x <=r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        // required for double buffering or it flickers the screen black
        ClearBackground(WHITE);

        // If Collision with axe is true
        if(collision_with_axe)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        
        }
        else
        {
            // Game logic begins

            // update the circle edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            // update the axe edges
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // update collision with axe
            collision_with_axe = 
                            (b_axe_y >= u_circle_y) &&
                            (u_axe_y <= b_circle_y) &&
                            (r_axe_x >= l_circle_x) &&
                            (l_axe_x <=r_circle_x);

            DrawCircle(circle_x,circle_y,circle_radius,BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_height, RED);

            // move the axe
            axe_y += direction;
            if(axe_y > height || axe_y < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D)&& circle_x <= width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A)&& circle_x >=30)
            {
                circle_x -= 10;
            }
        
            // Game logics ends
        }
        
        EndDrawing();
    }
}
