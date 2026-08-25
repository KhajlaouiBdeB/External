#include "Raven_UserOptions.h"

namespace Raven
{
    static Raven_UserOptions g_instance;

    Raven_UserOptions& Raven_UserOptions::Instance()
    {
        return g_instance;
    }

    Raven_UserOptions::Raven_UserOptions()
        : m_bShowGraph(false), m_bSmoothPathsQuick(false), m_bSmoothPathsPrecise(false), m_bShowBotIDs(false), m_bShowBotHealth(true), m_bShowTargetOfSelectedBot(false), m_bOnlyShowBotsInTargetsFOV(false), m_bShowScore(false), m_bShowNodeIndices(false), m_bShowOpponentsSensedBySelectedBot(true), m_bShowWeaponAppraisals(false)
    {
    }
} // namespace Raven
