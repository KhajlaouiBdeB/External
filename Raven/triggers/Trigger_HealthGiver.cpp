#include "Trigger_HealthGiver.h"
#include "GameConfig.h"
#include "../Raven_ObjectEnumerations.h"
#include "../config/Raven_Config.h"
#include "Graphics/GraphicsContext.h"
#include "misc/Stream_Utility_Functions.h"
#include <fstream>

///////////////////////////////////////////////////////////////////////////////
namespace Raven
{
    using namespace Common;
    Trigger_HealthGiver::Trigger_HealthGiver(std::ifstream& datafile)
        :

          Trigger_Respawning<Raven_Bot>(GetValueFromStream<int>(datafile))
    {
        Read(datafile);
    }

    void Trigger_HealthGiver::Try(Raven_Bot* pBot)
    {
        if (isActive() && isTouchingTrigger(pBot->Pos(), pBot->BRadius()))
        {
            pBot->IncreaseHealth(m_iHealthGiven);

            Deactivate();
        }
    }

    void Trigger_HealthGiver::Render()
    {
        if (isActive())
        {
            gfx.BlackPen();
            gfx.WhiteBrush();
            const int sz = 5;
            gfx.Rect(Pos().x - sz, Pos().y - sz, Pos().x + sz + 1, Pos().y + sz + 1);
            gfx.RedPen();
            gfx.Line(Pos().x, Pos().y - sz, Pos().x, Pos().y + sz + 1);
            gfx.Line(Pos().x - sz, Pos().y, Pos().x + sz + 1, Pos().y);
        }
    }

    void Trigger_HealthGiver::Read(std::ifstream& in)
    {
        double x, y, r;
        int GraphNodeIndex;

        in >> x >> y >> r >> m_iHealthGiven >> GraphNodeIndex;

        SetPos(Vector2D(x, y));
        SetBRadius(r);
        SetGraphNodeIndex(GraphNodeIndex);

        // create this trigger's region of fluence
        AddCircularTriggerRegion(Pos(), RavenConfig.GetDouble("DefaultGiverTriggerRange"));

        SetRespawnDelay((unsigned int)(RavenConfig.GetDouble("Health_RespawnDelay") * Game::FPS));
        SetEntityType(type_health);
    }
} // namespace Raven
