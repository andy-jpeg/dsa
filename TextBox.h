#ifndef DSA_TEXTBOX_H
#define DSA_TEXTBOX_H
#include <SFML/Graphics.hpp>
using namespace std;

class TextBox {
    protected:
    sf::RectangleShape box;
    sf::Text labelText;

    public:
    TextBox(float x, float y, int size, float width, float height, const string& label, sf::Font& font, sf::Color& textColor, sf::Color& boxColor, sf::Color& outlineColor);
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) {};
    virtual void draw(sf::RenderWindow& window);

    virtual ~TextBox() = default;

};

#endif //DSA_TEXTBOX_H