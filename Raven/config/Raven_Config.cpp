#include "Raven_Config.h"
#include <stdexcept>

namespace Raven
{
    static Raven_Config g_instance;

    Raven_Config& Raven_Config::Instance()
    {
        return g_instance;
    }

    //-----------------------------------------------------------------------------
    //  No parameter is hardcoded here anymore (this used to be a 1:1 transcript
    //  of the original Params.lua). Every value is now owned by the client
    //  (see Source/Game/GameConfig.h/.cpp) and pushed in via SetNumber()/
    //  SetString() - Game::ApplyRavenConfig() - before any Raven_* object is
    //  constructed.
    //-----------------------------------------------------------------------------
    Raven_Config::Raven_Config()
    {
    }

    int Raven_Config::GetInt(const char* VariableName)
    {
        return (int)GetDouble(VariableName);
    }

    double Raven_Config::GetFloat(const char* VariableName)
    {
        return GetDouble(VariableName);
    }

    double Raven_Config::GetDouble(const char* VariableName)
    {
        std::map<std::string, double>::const_iterator it = m_Numbers.find(VariableName);

        if (it == m_Numbers.end())
        {
            throw std::runtime_error(std::string("Raven_Config: unknown parameter ") + VariableName);
        }

        return it->second;
    }

    std::string Raven_Config::GetString(const char* VariableName)
    {
        std::map<std::string, std::string>::const_iterator it = m_Strings.find(VariableName);

        if (it == m_Strings.end())
        {
            throw std::runtime_error(std::string("Raven_Config: unknown parameter ") + VariableName);
        }

        return it->second;
    }

    bool Raven_Config::GetBool(const char* VariableName)
    {
        return GetDouble(VariableName) != 0.0;
    }

    void Raven_Config::SetString(const char* VariableName, const std::string& Value)
    {
        m_Strings[VariableName] = Value;
    }

    void Raven_Config::SetNumber(const char* VariableName, double Value)
    {
        m_Numbers[VariableName] = Value;
    }
} // namespace Raven
