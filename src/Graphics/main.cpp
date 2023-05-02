/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** main
*/

#include "MainWindow.hpp"

int main() {
    sf::Vector2f mainWindowSize(1920, 1080);
    std::string mainWindowTitle = "Main Window";
    Graphics::MainWindow mainWindow(mainWindowSize, mainWindowTitle);
    std::string windowTitle = "Sub-Window";

    sf::Texture button1Texture;
    sf::Texture button2Texture;
    sf::Texture button3Texture;
    sf::Texture button4Texture;
    sf::Texture button5Texture;

    button1Texture.loadFromFile("assets/thread.png");
    button2Texture.loadFromFile("assets/cluster.png");
    button3Texture.loadFromFile("assets/settings.png");
    button4Texture.loadFromFile("assets/load.png");
    button5Texture.loadFromFile("assets/play.png");

    sf::Vector2f button1Position(10, 5);
    sf::Vector2f button2Position(90, 10);
    sf::Vector2f button3Position(170, 10);
    sf::Vector2f button4Position(1780, 5);
    sf::Vector2f button5Position(1850, 5);

    Graphics::Button button1(button1Texture, button1Position, Graphics::ButtonType::THREAD);
    Graphics::Button button2(button2Texture, button2Position, Graphics::ButtonType::CLUSTER);
    Graphics::Button button3(button3Texture, button3Position, Graphics::ButtonType::SETTINGS);
    Graphics::Button button4(button4Texture, button4Position, Graphics::ButtonType::LOAD);
    Graphics::Button button5(button5Texture, button5Position, Graphics::ButtonType::PLAY);

    mainWindow.addButton(button1);
    mainWindow.addButton(button2);
    mainWindow.addButton(button3);
    mainWindow.addButton(button4);
    mainWindow.addButton(button5);
    mainWindow.run();
    return 0;
}
