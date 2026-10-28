#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "Heap.h"
using namespace std;

#include <bits/stdc++.h>

void setText(sf::Text &text, float x, float y) {

}

int main () {
    sf::Font font("../BoldPixels.ttf");

    // variables for visuals:
    sf::Color bgGrey(76, 69, 76);
    sf::Color lightPink(255, 192, 222);
    sf::Color pink(237, 150, 215);
    sf::Color lightPurple(163, 69, 161);

    sf::Text titleText(font);
    titleText.setString("Pick a game");
    titleText.setCharacterSize(36);
    titleText.setFillColor(lightPurple);
    titleText.setStyle(sf::Text::Bold);

    // creating main window frame
    sf::RenderWindow homeWindow(sf::VideoMode({800, 600}), "Pick a game");
    while (homeWindow.isOpen()) {

        // home window visuals
        homeWindow.clear(bgGrey);
        homeWindow.draw(titleText);
        homeWindow.display();

        while (const optional event = homeWindow.pollEvent()) {
            // ONLY close when if x is pressed
            if (event->is <sf::Event::Closed>()) {
                homeWindow.close();
            }
        }
    }

    return 0;
}
