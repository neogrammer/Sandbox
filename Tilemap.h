// Tilemap.h
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

struct TileSet {
    sf::Texture texture;
    std::vector<sf::IntRect> tiles; // Rectangles defining each tile in the tileset
};

class Tilemap : public sf::Drawable, public sf::Transformable {
public:
    Tilemap();
    ~Tilemap() = default;

    bool load(const std::string& tilesetFile, const std::vector<sf::IntRect>& tileRects,
        const std::vector<std::vector<int>>& tileLayout, unsigned int tileSize);

    void setTileset(const TileSet& tileset);
    void clear();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::VertexArray _vertices;
    sf::Texture _tilesetTexture;
    std::vector<std::vector<int>> _layout;
    unsigned int _tileSize = 0;
};
