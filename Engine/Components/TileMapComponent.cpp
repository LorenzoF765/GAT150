#include "TilemapComponent.h"
#include "Engine.h"

namespace  Engine
{
    void TilemapComponent::Initialize()
    {
        for (int i = 0; i < tiles.size(); i++)
        {
            int index = tiles[i];
            if (index == 0) continue;

            auto actor = Factory::Instance().Create<Actor>(tile_names[index]);
            if (actor)
            {
                int x = i % num_columns;
                int y = i / num_columns;

                actor->transform_.position = owner_->transform_.position + (Vector2{ x, y } *size);
                owner_->GetScene()->Add(std::move(actor));
            }
        }
    }
    void TilemapComponent::Update()
    {
    }
    bool TilemapComponent::Write(const rapidjson::Value& value) const
    {
        return true;
    }
    bool TilemapComponent::Read(const rapidjson::Value& value)
    {
        READ_DATA(value, num_columns);
        READ_DATA(value, num_rows);
        READ_DATA(value, size);
        READ_DATA(value, tile_names);
        READ_DATA(value, tiles);

        return true;
    }

}