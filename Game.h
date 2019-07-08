#ifndef GAME_H
#define GAME_H
#include "SFML-2.4.0/include/SFML/Window.hpp"
#include "SFML-2.4.0/Include/SFML/Graphics.hpp"
#include "PlayerPaddle.h"

class Game {
    public:
        static void Start();

    private:
        static bool IsExiting();
        static void GameLoop();

        static void ShowSplashScreen();
        static void ShowMenu();

        enum GameState{ Uninitialized, ShowingSplash,
     Pause, ShowingMenu, Playing, Exiting};

        static GameState _gameState;
        static sf::RenderWindow _mainWindow;
        static PlayerPaddle _player1;
};

#endif