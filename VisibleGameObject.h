#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class VisibleGameObject {
    public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow &window);
    virtual void Update(float elapsedTime);

    virtual void setPosition(float x, float y);
    virtual sf::Vector2f GetPosition() const;
    virtual bool IsLoaded() const;

    protected:
    sf::Sprite &GetSprite();

    private:
    sf::Sprite _sprite;
    sf::Texture _image;
    std::string _filename;
    bool _isLoaded;
};

#endif