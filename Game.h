#ifndef GAME_H
#define GAME_H
#include "SFML-2.4.0/include/SFML/Window.hpp"
#include "SFML-2.4.0/Include/SFML/Graphics.hpp"
#include "PlayerPaddle.h"
#include "GameBall.h"
#include "GameObjectManager.h"

class Game {
    public:
        static void Start();
        static sf::RenderWindow &GetWindow();
        const static int SCREEN_WIDTH = 1024;
        const static int SCREEN_HEIGHT = 768;

        static sf::Clock clock;

    private:
        static bool IsExiting();
        static void GameLoop();

        static void ShowSplashScreen();
        static void ShowMenu();

        enum GameState{ Uninitialized, ShowingSplash,
     Pause, ShowingMenu, Playing, Exiting};

        static GameState _gameState;
        static sf::RenderWindow _mainWindow;
        
        static GameObjectManager _gameObjectManager;
};

#endif