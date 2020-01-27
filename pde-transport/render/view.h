#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#include <string>
#include <SDL2/SDL.h>
#include "color.h"

/*
Author: Nicholas McDonald

Simple SDL Wrapper that acts like a canvas which you can draw stuff onto.

Drawing Helpers let you define the drawing behavior.

The render wrapper lets you plug in a lambda of drawing helpers for rendering.

*/


//Master Class
class View {
 public:
   std::string WINDOW_NAME = "Climate Simulator";

   //Rendering Variables
   SDL_Window* gWindow;
   SDL_Renderer* gRenderer;

   //Setup and Cleanup
   bool setup();
   void cleanup();

   //Drawing Helpers
   void drawPixel(glm::ivec2 pos, glm::vec3 color);
   void drawLine(glm::vec2 pos, glm::vec2 dir);

   //Renderer
   template<typename F, typename... Args>
   void render(F function, Args&&... args);
};
