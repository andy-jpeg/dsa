#include "TextBox.h"

TextBox::TextBox(float x, float y, int size, float width, float height, const string& label, sf::Font& font, sf::Color& textColor, sf::Color& boxColor, sf::Color& outlineColor): labelText(font)  {
    box.setPosition({x, y});
    box.setSize({width, height});
    box.setFillColor(boxColor);
    box.setOutlineColor(outlineColor);
    box.setOutlineThickness(2.f);

    labelText.setFont(font);
    labelText.setString(label);
    labelText.setCharacterSize(size);
    labelText.setFillColor(textColor);
    labelText.setStyle(sf::Text::Bold);

    sf::FloatRect textRect = labelText.getLocalBounds();
    labelText.setOrigin({textRect.position.x + textRect.size.x / 2.0f,
                           textRect.position.y + textRect.size.y / 2.0f});
    labelText.setPosition({x, y});

    // specifically made for the title box, centers the text within the visual box
    if (width > 0 && height > 0) {
        labelText.setPosition({x + width / 2.0f, y + height / 2.0f});
    } else {
        labelText.setPosition({x, y});
    }

}




