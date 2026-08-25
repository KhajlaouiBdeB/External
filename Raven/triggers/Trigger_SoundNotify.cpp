#include "Trigger_SoundNotify.h"
#include "GameConfig.h"
#include "../Raven_Messages.h"
#include "../Raven_Scene.h"
#include "../config/Raven_Config.h"
#include "Messaging/MessageDispatcher.h"

//------------------------------ ctor -----------------------------------------
//-----------------------------------------------------------------------------

namespace Raven
{
    using namespace Common;
    Trigger_SoundNotify::Trigger_SoundNotify(Raven_Bot* source,
                                             double range)
        : Trigger_LimitedLifetime<Raven_Bot>(Game::FPS / RavenConfig.GetInt("Bot_TriggerUpdateFreq")),
          m_pSoundSource(source)
    {
        // set position and range
        SetPos(m_pSoundSource->Pos());

        SetBRadius(range);

        // create and set this trigger's region of fluence
        AddCircularTriggerRegion(Pos(), BRadius());
    }

    //------------------------------ Try ------------------------------------------
    //
    //  when triggered this trigger adds the bot that made the source of the sound
    //  to the triggering bot's perception.
    //-----------------------------------------------------------------------------
    void Trigger_SoundNotify::Try(Raven_Bot* pBot)
    {
        // is this bot within range of this sound
        if (isTouchingTrigger(pBot->Pos(), pBot->BRadius()))
        {
            Dispatcher->DispatchMsg(SEND_MSG_IMMEDIATELY,
                                    SENDER_ID_IRRELEVANT,
                                    pBot->ID(),
                                    Msg_GunshotSound,
                                    m_pSoundSource);
        }
    }
} // namespace Raven
