
// BackgroundLayer.cpp
#include "BackgroundLayer.h"
#include "SandboxError.h"

BackgroundLayer::BackgroundLayer(Cfg::Textures tex_, float scrollSpeed)
    : _scrollSpeed(scrollSpeed), _offset(0.0f), _sprite{ Cfg::textures.get(tex_) } {
   /* if (!_texture.loadFromFile(filename))
    {

        sbx::SandboxError("Unable to load texture file path : " + filename);
    }*/
}

void BackgroundLayer::update(float dt) 
{
    auto xFrameDisp = -_scrollSpeed * dt;
    if (_sprite.getPosition().x + xFrameDisp < -1.f * _sprite.getTexture().getSize().x)
        _sprite.setPosition({ 0.f,0.f});
    else
    {
        _sprite.setPosition({ _sprite.getPosition().x + xFrameDisp, _sprite.getPosition().y });
    }
}

void BackgroundLayer::draw(sf::RenderWindow& window) {

    if (&_sprite.getTexture() == &Cfg::textures.get(Cfg::Textures::UNKNOWN))
    {
        return;
    }
    else
    {
        window.draw(_sprite);
        sf::Sprite tempSprite = _sprite;
        tempSprite.setPosition({ _sprite.getPosition().x + _sprite.getTexture().getSize().x, 0.f});
        window.draw(tempSprite);
    }
}

void BackgroundLayer::setScrollSpeed(float spdX_, float spdY_)
{
    _scrollSpeed = spdX_;
    (spdY_);
    return;
}

sf::Vector2f BackgroundLayer::getPosition()
{
    return _sprite.getPosition();
}

void BackgroundLayer::setPosition(sf::Vector2f pos_)
{
    _sprite.setPosition(pos_);
}

sf::Vector2u BackgroundLayer::getTextureSize()
{
    return _sprite.getTexture().getSize();
}
