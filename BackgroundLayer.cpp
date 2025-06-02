
// BackgroundLayer.cpp
#include "BackgroundLayer.h"
#include "SandboxError.h"
#include "Cfg.h"
BackgroundLayer::BackgroundLayer(const std::string& filename, float scrollSpeed)
    : _scrollSpeed(scrollSpeed), _offset(0.0f), _sprite{ Cfg::textures.get(Cfg::Textures::UNKNOWN) } {
    if (!_texture.loadFromFile(filename))
    {

        sbx::SandboxError("Unable to load texture file path : " + filename);
    }
    _sprite.setTexture(_texture);
}

void BackgroundLayer::update(float dt) {
    _offset += _scrollSpeed * dt;
    if (_offset > _texture.getSize().x)
        _offset -= _texture.getSize().x;
    _sprite.setPosition({ _sprite.getPosition().x - _offset, _sprite.getPosition().y - _offset});
}

void BackgroundLayer::draw(sf::RenderWindow& window) {
    window.draw(_sprite);
    sf::Sprite tempSprite = _sprite;
    tempSprite.setPosition({ _sprite.getPosition().x + _texture.getSize().x, 0.f });
    window.draw(tempSprite);
}