#ifndef GAME_CPP
#define GAME_CPP

#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "SFML-2.4.0/include/SFML/System.hpp"
#include "SFML-2.4.0/include/SFML/Graphics.hpp"
#include "SFML-2.4.0/include/SFML/Window.hpp"
#include "SFML-2.4.0/include/SFML/Audio.hpp"

void Game::Start()
{
    if (_gameState != Uninitialized)
    {
        return;
    }

    _mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");

    PlayerPaddle *player1 = new PlayerPaddle();
    player1->setPosition((1024 / 2) - 45, 700);

    GameBall *ball = new GameBall();
    ball->setPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

    _gameObjectManager.Add("Paddle1", player1);
    _gameObjectManager.Add("Ball", ball);
    _gameState = Game::ShowingSplash;

    while (!IsExiting())
    {
        GameLoop();
    }

    _mainWindow.close();
}

bool Game::IsExiting()
{
    if (_gameState == Game::Exiting)
    {
        return true;
    }
    else
    {
        return false;
    }
}

sf::RenderWindow &Game::GetWindow()
{
    return _mainWindow;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
    _mainWindow.pollEvent(currentEvent);

    switch (_gameState)
    {
    case Game::ShowingMenu:
    {
        ShowMenu();
        break;
    }
    case Game::ShowingSplash:
    {
        ShowSplashScreen();
        break;
    }
    case Game::Playing:
    {
        _mainWindow.clear(sf::Color(0, 0, 0));
        _gameObjectManager.UpdateAll();
        _gameObjectManager.DrawAll(_mainWindow);
        _mainWindow.display();
        if (currentEvent.type == sf::Event::Closed)
        {
            _gameState = Game::Exiting;
        }
        if (currentEvent.type == sf::Event::KeyPressed)
        {
            if (currentEvent.key.code == sf::Keyboard::Escape)
            {
                ShowMenu();
            }
        }
    }
    break;
    }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(_mainWindow);
    _gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(_mainWindow);

    switch (result)
    {
    case MainMenu::Exit:
        _gameState = Game::Exiting;
        break;
    case MainMenu::Play:
        _gameState = Game::Playing;
        break;
    }
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
sf::Clock Game::clock;

#endif