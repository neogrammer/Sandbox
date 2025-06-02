// Tilemap.cpp
#include "Tilemap.h"

Tilemap::Tilemap() : _vertices(sf::PrimitiveType::Triangles) {}

bool Tilemap::load(const std::string& tilesetFile, const std::vector<sf::IntRect>& tileRects,
    const std::vector<std::vector<int>>& tileLayout, unsigned int tileSize) {
    if (!_tilesetTexture.loadFromFile(tilesetFile))
        return false;

    _tileSize = tileSize;
    _layout = tileLayout;
    _vertices.clear();

    unsigned int width = tileLayout[0].size();
    unsigned int height = tileLayout.size();

    _vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
    _vertices.resize(width * height * 6);

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            int tileIndex = tileLayout[y][x];
            if (tileIndex < 0 || tileIndex >= static_cast<int>(tileRects.size()))
                continue; // skip invalid

            // 6 vertices per tile (2 triangles)
            sf::Vertex* tri = &_vertices[(x + y * width) * 6];

            sf::Vector2f topLeft = sf::Vector2f(x * tileSize, y * tileSize);
            sf::Vector2f topRight = sf::Vector2f((x + 1) * tileSize, y * tileSize);
            sf::Vector2f bottomRight = sf::Vector2f((x + 1) * tileSize, (y + 1) * tileSize);
            sf::Vector2f bottomLeft = sf::Vector2f(x * tileSize, (y + 1) * tileSize);

            sf::IntRect texRect = tileRects[tileIndex];
            sf::Vector2f texTL = sf::Vector2f(texRect.position);
            sf::Vector2f texTR = sf::Vector2f(texRect.position.x + texRect.size.x, texRect.position.y);
            sf::Vector2f texBR = sf::Vector2f(texRect.position + texRect.size);
            sf::Vector2f texBL = sf::Vector2f(texRect.position.x, texRect.position.y + texRect.size.y);

            // First triangle (top-left, top-right, bottom-right)
            tri[0].position = topLeft;
            tri[0].texCoords = texTL;

            tri[1].position = topRight;
            tri[1].texCoords = texTR;

            tri[2].position = bottomRight;
            tri[2].texCoords = texBR;

            // Second triangle (bottom-right, bottom-left, top-left)
            tri[3].position = bottomRight;
            tri[3].texCoords = texBR;

            tri[4].position = bottomLeft;
            tri[4].texCoords = texBL;

            tri[5].position = topLeft;
            tri[5].texCoords = texTL;
        }
    }

    return true;
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform(); // apply transform
    states.texture = &_tilesetTexture;
    target.draw(_vertices, states);
}

void Tilemap::setTileset(const TileSet& tileset) {
    _tilesetTexture = tileset.texture;
}

void Tilemap::clear() {
    _vertices.clear();
    _layout.clear();
}