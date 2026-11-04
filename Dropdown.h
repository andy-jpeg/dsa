#ifndef DSA_DROPDOWN_H
#define DSA_DROPDOWN_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "InputTextBox.h"
using namespace std;

class Dropdown : public InputTextBox {
protected:
    std::vector<std::string> options;
    std::vector<sf::RectangleShape> optionBoxes;
    std::vector<sf::Text> optionTexts;
    bool isOpen;
    int selectedIndex;

public:
    Dropdown(float x, float y, int size, float width, float height, const string& label, const std::vector<string>& opts, sf::Font& font, sf::Color& textColor, sf::Color& boxColor, sf::Color& outlineColor);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    void drawOpenListOnly(sf::RenderWindow& window);
    string getInput() const override;
};

#endif //DSA_DROPDOWN_H