
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

void BackgroundLayer::update(float dt) {
    _offset += _scrollSpeed * dt;
    if (_offset > _texture.getSize().x)
        _offset -= _texture.getSize().x;
    _sprite.setPosition({ _sprite.getPosition().x - _offset, _sprite.getPosition().y - _offset});
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
        tempSprite.setPosition({ _sprite.getPosition().x + _texture.getSize().x, 0.f });
        window.draw(tempSprite);
    }
}