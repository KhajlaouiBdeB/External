#include "CrudeTimer.h"

#include "raylib.h"
namespace Common
{
    CrudeTimer::CrudeTimer()
    {
        m_dStartTime = GetTime();
    }

    CrudeTimer* CrudeTimer::Instance()
    {
        static CrudeTimer instance;

        return &instance;
    }

    double CrudeTimer::GetCurrentTime()
    {
        return GetTime() - m_dStartTime;
    }
} // namespace Common
