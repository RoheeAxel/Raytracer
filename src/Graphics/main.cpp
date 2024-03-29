/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-axel.rohee
** File description:
** main
*/

#include "MainWindow.hpp"

int main() {
    Graphics::MainWindow mainWindow(sf::Vector2f(1920, 1080), "Main Window");

    sf::Texture button1Texture;
    sf::Texture button2Texture;
    sf::Texture button4Texture;
    sf::Texture button5Texture;
    sf::Texture button6Texture;
    button1Texture.loadFromFile("assets/thread.png");
    button2Texture.loadFromFile("assets/cluster.png");
    button4Texture.loadFromFile("assets/load.png");
    button5Texture.loadFromFile("assets/play.png");
    button6Texture.loadFromFile("assets/download.png");
    Graphics::Button button1(button1Texture, sf::Vector2f(10, 5), Graphics::ButtonType::THREAD);
    Graphics::Button button2(button2Texture, sf::Vector2f(90, 10), Graphics::ButtonType::CLUSTER);
    Graphics::Button button4(button4Texture, sf::Vector2f(1780, 5), Graphics::ButtonType::LOAD);
    Graphics::Button button5(button5Texture, sf::Vector2f(1850, 5), Graphics::ButtonType::PLAY);
    Graphics::Button button6(button6Texture, sf::Vector2f(1710, 10), Graphics::ButtonType::DOWNLOAD);
    mainWindow.addButton(button1);
    mainWindow.addButton(button2);
    mainWindow.addButton(button4);
    mainWindow.addButton(button5);
    mainWindow.addButton(button6);
    mainWindow.run();
    return 0;
}
