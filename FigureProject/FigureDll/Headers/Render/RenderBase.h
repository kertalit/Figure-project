#pragma once

#include "DrawModel.h"
#include "Database.h"

class RenderBase
{
public:
    RenderBase(const DrawModel& model, const Database& database);
    void update();
    virtual void Render() = 0;

protected:
    RenderBase(const DrawModel& model);
    DrawModel _model;
    
private:
    Database _database;
};

