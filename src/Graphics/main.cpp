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

    Graphics::Button button1(button1Texture, sf::Vector2f(10, 5), Graphics::ButtonType::THREAD);
    Graphics::Button button2(button2Texture, sf::Vector2f(90, 10), Graphics::ButtonType::CLUSTER);
    Graphics::Button button3(button3Texture, sf::Vector2f(170, 10), Graphics::ButtonType::SETTINGS);
    Graphics::Button button4(button4Texture, sf::Vector2f(1780, 5), Graphics::ButtonType::LOAD);
    Graphics::Button button5(button5Texture, sf::Vector2f(1850, 5), Graphics::ButtonType::PLAY);

    mainWindow.addButton(button1);
    mainWindow.addButton(button2);
    mainWindow.addButton(button3);
    mainWindow.addButton(button4);
    mainWindow.addButton(button5);
    mainWindow.run();
    return 0;
}

// #include <SFML/Graphics.hpp>
// #include "ClusterWindow.hpp"

// int main() {
//     sf::RenderWindow window(sf::VideoMode(1920, 1080), "Thread Window Test");

//     sf::Font font;
//     if (!font.loadFromFile("assets/font.ttf")) {
//         return 1;
//     }
//     Graphics::ClusterWindow thread_window(sf::Vector2f(200, 150), sf::Vector2f(400, 270), font);

//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             } else {
//                 thread_window.handleEvent(event);
//             }
//         }
//         window.clear(sf::Color::White);
//         if (thread_window.getInputClose() == false) {
//             thread_window.draw(window, sf::BlendAlpha);
//         }
//         window.display();
//     }
//     return 0;
// }
