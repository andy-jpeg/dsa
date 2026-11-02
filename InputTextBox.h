#ifndef DSA_INPUTTEXTBOX_H
#define DSA_INPUTTEXTBOX_H
#include <SFML/Graphics.hpp>
#include "TextBox.h"
using namespace std;

class InputTextBox : public TextBox {
    protected:
    string userInput;
    bool inUse;
    bool isNumeric;
    sf::RectangleShape labelBox;
    sf::Text inputText;

    public:
    InputTextBox(float x, float y, int size, float width, float height, const std::string& label, sf::Font& font, sf::Color& textColor, sf::Color& boxColor, sf::Color& outlineColor, bool numeric = true);
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    virtual string getInput() const;

};

#endif //DSA_INPUTTEXTBOX_H