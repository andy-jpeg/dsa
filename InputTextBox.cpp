#include "InputTextBox.h"
#include <cctype>

InputTextBox::InputTextBox(float x, float y, int size, float width, float height, const std::string& label, sf::Font& font, sf::Color& textColor, sf::Color& boxColor, sf::Color& outlineColor, bool numeric)
    : TextBox(x, y, size, width, height, label, font, textColor, boxColor, outlineColor), inUse(false), inputText(font), isNumeric(numeric) {

    // splits the total width into two equal boxes with a small gap
    float gap = 40.f;
    float halfWidth = (width - gap) / 2.0f;

    // label box is the leftmost box that prompts the user
    labelBox.setPosition({x, y});
    labelBox.setSize({halfWidth, height});
    labelBox.setFillColor(boxColor);
    labelBox.setOutlineColor(outlineColor);
    labelBox.setOutlineThickness(2.f);

    // centering text logic for the label box !
    sf::FloatRect labelBounds = labelText.getLocalBounds();
    labelText.setOrigin({labelBounds.position.x + labelBounds.size.x / 2.0f,
                           labelBounds.position.y + labelBounds.size.y / 2.0f});
    labelText.setPosition({x + halfWidth / 2.0f, y + height / 2.0f});

    // input box is the rightmost box that user interacts with (box is from the TextBox parent class)
    float inputFieldX = x + halfWidth + gap;
    box.setPosition({inputFieldX, y});
    box.setSize({halfWidth, height});
    box.setFillColor(boxColor);
    box.setOutlineColor(outlineColor);
    box.setOutlineThickness(2.f);

    // centering text logic for the input box !
    inputText.setCharacterSize(size);
    inputText.setFillColor(textColor);
    float verticalCenterOffset = (height - static_cast<float>(size)) / 2.0f;
    inputText.setOrigin({0.f, 0.f});
    inputText.setPosition({inputFieldX + 15.f, y + verticalCenterOffset - 2.f});
}

void InputTextBox::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (const auto* mouseEvent = event.getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseEvent->button == sf::Mouse::Button::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords({mouseEvent->position.x, mouseEvent->position.y});

            // if the box is clicked on its highlighted with a cursor!
            if (box.getGlobalBounds().contains(mousePos)) {
                inUse = true;
                box.setOutlineColor(sf::Color(220, 172, 220));
                inputText.setString(userInput + "|");
            }
            // if the box is clicked off of its unhighlighted!
            else {
                inUse = false;
                box.setOutlineColor(sf::Color(163, 69, 161));
                inputText.setString(userInput);
            }
        }
    }

    if (inUse) {
        if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>()) {
            // logic for storing user input (adding, deleting, etc)
            if (keyPressed->scancode == sf::Keyboard::Scancode::Backspace) {
                if (!userInput.empty()) {
                    userInput.pop_back();
                    inputText.setString(userInput + "|");
                }
                else {
                    inputText.setString("|");
                }

            }
            else if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {
                inUse = false;
                box.setOutlineColor(sf::Color(163, 69, 161));
                inputText.setString(userInput);
            }
        }

        else if (const auto* textEntered = event.getIf<sf::Event::TextEntered>()) {
            unsigned int unicode = textEntered->unicode;
            // specifically for the number of games
            if (isNumeric) {
                // max limit set on games that can be outputted (999)
                if (isdigit(static_cast<unsigned char>(unicode)) && userInput.size() < 4) {
                    userInput.push_back(static_cast<char>(unicode));
                    inputText.setString(userInput + "|");
                }
            }

            else {
                // specifically for company name
                // max limit set on name length (999)
                if ((isalpha(static_cast<unsigned char>(unicode)) || unicode == ' ') && userInput.size() < 1000) {
                    userInput.push_back(static_cast<char>(unicode));
                    inputText.setString(userInput + "|");
                }
            }
        }
    }
}

void InputTextBox::draw(sf::RenderWindow& window) {
    window.draw(labelBox);
    window.draw(box);
    window.draw(labelText);
    window.draw(inputText);
}

string InputTextBox::getInput() const {
    return userInput;
}