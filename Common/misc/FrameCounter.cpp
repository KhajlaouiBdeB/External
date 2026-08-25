#include "framecounter.h"

namespace Common
{
    FrameCounter* FrameCounter::Instance()
    {
        static FrameCounter instance;

        return &instance;
    }
} // namespace Common
