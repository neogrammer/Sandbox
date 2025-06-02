
// PlayState.cpp
#include "SideScrollerPlayState.h"

SideScrollerPlayState::SideScrollerPlayState(sf::RenderWindow& tv_) : GameState{ GStateType::SandboxSideScroller, tv_ } {}

SideScrollerPlayState::~SideScrollerPlayState() {}

void SideScrollerPlayState::load() {
    // Load different layers with varying scroll speeds
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/1.png", 20.0f);
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/2.png", 20.0f);
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/3.png", 20.0f);
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/5.png", 20.0f);
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/5.png", 20.0f);
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/7.png", 20.0f);
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/8.png", 20.0f);
    _backgroundLayers.emplace_back("assets/textures/sandbox_play_state/10.png", 20.0f);

    // Add more layers as needed
}

void SideScrollerPlayState::update(float dt) {
    for (auto& layer : _backgroundLayers) {
        layer.update(dt);
    }
}

void SideScrollerPlayState::draw(sf::RenderWindow& window) {
    for (auto& layer : _backgroundLayers) {
        layer.draw(window);
    }
}