class ScriptList
{
    /*0x8*/ ScriptGroup *m_firstGroup; // confirmed
    Script *m_firstScript; // confirmed

    struct ScriptListReadInfo
    {
        int num_lists; // confirmed
        ScriptList *read_lists[16]; // confirmed
    };
};

class ScriptAction
{
    /*0x4*/ ScriptAction::ScriptActionType m_actionType; // confirmed
    int m_numParams; // confirmed
    Parameter *m_params[12]; // confirmed
    ScriptAction *m_nextAction; // confirmed
    bool m_hasWarnings; // confirmed
};

class Parameter
{
    /*0x4*/ ParameterType m_type; // confirmed
    bool m_initialized; // confirmed
    int m_int; // confirmed
    float m_real; // confirmed
    AsciiString m_string; // confirmed
    Coord3D m_coord; // confirmed
    BitFlags m_objStatus; // confirmed
};

class Condition
{
    /*0x4*/ ConditionType m_conditionType; // confirmed
    int m_numParms; // confirmed
    Parameter *m_parms[12]; // confirmed
    Condition *m_nextAndCondition; // confirmed
    int m_hasWarnings; // confirmed
    int m_customData; // confirmed
    int m_unkInt1; // doesn't seem to be used
};

class OrCondition
{
    /*0x4*/ OrCondition *m_nextOr; // confirmed
    Condition *m_firstAnd; // confirmed
};