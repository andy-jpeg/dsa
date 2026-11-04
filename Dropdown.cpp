#include "Dropdown.h"

Dropdown::Dropdown(float x, float y, int size, float width, float height, const string& label, const std::vector<string>& opts, sf::Font& font, sf::Color& textColor, sf::Color& boxColor, sf::Color& outlineColor)
        : InputTextBox(x, y, size, width, height, label, font, textColor, boxColor, outlineColor), options(opts), isOpen(false), selectedIndex(0) {

    // options are passed through the main, and the first option listed is displayed in the box
    if (!options.empty()) {
        userInput = options[0];
        inputText.setString(userInput);
    }

    // gap logic from inputTextBox used here also for box displaying purposes
    float gap = 40.f;
    float halfWidth = (width - gap) / 2.0f;
    float inputX = x + halfWidth + gap;
    float optHeight = height;

    for (size_t i = 0; i < options.size(); ++i) {
        sf::RectangleShape optBox;
        // aligns all options under the rightmost box
        optBox.setPosition({inputX, y + height + (i * optHeight)});
        optBox.setSize({halfWidth, optHeight});
        optBox.setFillColor(sf::Color(40, 40, 50));
        optBox.setOutlineColor(outlineColor);
        optBox.setOutlineThickness(1.f);
        optionBoxes.push_back(optBox);

        // creates the text for each option
        sf::Text optText(font);
        optText.setString(options[i]);
        optText.setCharacterSize(size);
        optText.setFillColor(textColor);

        // aligns text in its respective option box
        optText.setPosition({inputX + 15.f, y + height + (i * optHeight) + (height - static_cast<float>(size)) / 2.0f - 2.f});
        optionTexts.push_back(optText);
    }
}

void Dropdown::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (const auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>()) {
        // if the box is clicked on
        if (mouseEvent->button == sf::Mouse::Button::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords({mouseEvent->position.x, mouseEvent->position.y});

            // checks to see if the box is clicked off of
            if (box.getGlobalBounds().contains(mousePos)) {
                isOpen = !isOpen;
            }

            else if (isOpen) {
                // goes through all the options and if one is clicked it is displayed !
                bool clickedInside = false;

                for (size_t i = 0; i < optionBoxes.size(); ++i) {
                    if (optionBoxes[i].getGlobalBounds().contains(mousePos)) {
                        selectedIndex = i;
                        userInput = options[i];
                        inputText.setString(userInput);
                        isOpen = false;
                        clickedInside = true;
                        break;
                    }
                }
                // makes sures if the box is clicked off of that the options are no longer shown
                if (!clickedInside) {
                    isOpen = false;
                }
            }
        }
    }
}

// draws only draws the base boxes
void Dropdown::draw(sf::RenderWindow& window) {
    InputTextBox::draw(window);
}

// helper method used to help overlay dropdown menu on top!
void Dropdown::drawOpenListOnly(sf::RenderWindow& window) {
    if (isOpen) {
        for (size_t i = 0; i < optionBoxes.size(); ++i) {
            window.draw(optionBoxes[i]);
            window.draw(optionTexts[i]);
        }
    }
}

string Dropdown::getInput() const {
    if (!options.empty()) return options[selectedIndex];
    return userInput;
}