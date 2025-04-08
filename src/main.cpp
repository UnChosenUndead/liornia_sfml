#include <SFML/Graphics.hpp>
#include "game_objects/includes/Game.hpp"
int main()
{
    // Program entry point.
    Game game;
    while (!game.GetWindow()->IsDone())
    {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }
}
