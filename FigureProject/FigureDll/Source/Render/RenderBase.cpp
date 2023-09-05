#include "RenderBase.h"

RenderBase::RenderBase(const DrawModel& model, const Database& database)
    :_model(model), _database(database)
{

}

RenderBase::RenderBase(const DrawModel& model)
    :_model(model), _database(Database())
{

}

void RenderBase::update()
{
    for (auto dbentity : _database.GetObjects())
    {
        auto draw = _model.createDraw();
        dbentity->draw(draw);
    }
}
