struct TextureLoadTaskListNode
{
    TextureLoadTaskListNode *succ; // confirmed
    TextureLoadTaskListNode *prev; // confirmed
};

class TextureLoadTaskListClass
{
    TextureLoadTaskListNode *m_head; // confirmed
    TextureLoadTaskListNode *m_tail; // confirmed
};

class SynchronizedTextureLoadTaskListClass : TextureLoadTaskListClass
{
    bool unused;
    FastCriticalSectionClass m_mutex; // confirmed
};

class TextureLoadTaskClass
{
    enum TaskType
    {
        TASK_NONE,
        TASK_THUMBNAIL,
        TASK_LOAD,
    };

    enum PriorityType
    {
        PRIORITY_BACKGROUND,
        PRIORITY_FOREGROUND,
    };

    enum StateType
    {
        STATE_NONE,
        STATE_LOAD_BEGUN,
        STATE_LOADED,
        STATE_LOAD_ENDED,
        STATE_4,
    };

    /*0x4*/ TextureLoadTaskListNode m_listNode; // confirmed
    TextureLoadTaskListClass *m_parent; // confirmed
    TextureBaseClass *m_texture; // confirmed
    w3dtexture_t m_d3dTexture; // confirmed
    WW3DFormat m_format; // confirmed
    unsigned m_width; // confirmed
    unsigned m_height; // confirmed
    unsigned m_mipLevelCount; // confirmed
    unsigned m_reduction; // confirmed
    Vector3 m_hsvAdjust; // confirmed
    uint8_t *m_lockedSurfacePtr[12]; // confirmed
    int m_lockedSurfacePitch[12]; // confirmed
    TaskType m_type; // confirmed
    PriorityType m_priority; // confirmed
    StateType m_loadState; // confirmed
};

class CubeTextureLoadTaskClass : TextureLoadTaskClass
{
    /*0xA4*/ void *m_lockedCubeSurfacePtr[12][6]; // confirmed
    void *m_lockedCubeSurfacePitch[12][6]; // confirmed
};

class VolumeTextureLoadTaskClass : TextureLoadTaskClass
{
    /*0xA4*/ void *m_lockedVolumeSlicePitch[12]; // confirmed
    void *m_volume;
};

class TextureBaseClass
{
    enum MipCountType
    {
        MIP_LEVELS_ALL,
        MIP_LEVELS_1,
        MIP_LEVELS_2,
        MIP_LEVELS_3,
        MIP_LEVELS_4,
        MIP_LEVELS_5,
        MIP_LEVELS_6,
        MIP_LEVELS_7,
        MIP_LEVELS_8,
        MIP_LEVELS_10, // TT Scripts has it this way, no 9?
        MIP_LEVELS_11,
        MIP_LEVELS_12,
        MIP_LEVELS_MAX,
    };

    enum PoolType
    {
        POOL_DEFAULT,
        POOL_MANAGED,
        POOL_SYSTEMMEM,
    };

    /*0x8*/ MipCountType m_mipLevelCount; // confirmed
    bool m_initialized; // confirmed
    bool m_unkBool1; // m_isLightmap?
    bool m_compressionAllowed; // confirmed
    bool m_isProcedural;
    bool m_allowReduction; // confirmed
    unsigned m_inactivationTime;
    unsigned m_someTimeVal;
    unsigned m_startTime;
    mutable unsigned m_lastAccess; // confirmed
    Vector3 m_hsvShift; // confirmed
    unsigned m_width; // confirmed
    unsigned m_height; // confirmed
    w3dbasetexture_t m_d3dTexture; // confirmed
    StringClass m_name; // confirmed
    StringClass m_fullPath; // confirmed
    unsigned m_id; // confirmed
    PoolType m_pool; // confirmed
    bool m_dirty; // confirmed
    TextureLoadTaskClass *m_textureLoadTask; // confirmed
    TextureLoadTaskClass *m_thumbnailLoadTask; // confirmed
};

class TextureFilterClass
{
    int TextureMinFilter; // confirmed, accessed weirdly tho... pointer?
    int TextureMagFilter; // confirmed, accessed weirdly tho... pointer?
    int MipMapFilter; // confirmed, accessed weirdly tho... pointer?
    uint32_t UAddressMode; // confirmed
    uint32_t VAddressMode; // confirmed
};

class TextureClass : TextureBaseClass
{
    /*0x58*/ m_format; // confirmed
    TextureFilterClass m_filter; // confirmed
};

class ZTextureClass : TextureBaseClass
{
    /*0x58*/ m_depthFormat; // confirmed
};

class CubeTextureClass : TextureClass
{
    // no members
};

class VolumeTextureClass : TextureClass
{
    /*0x70*/ m_depth; // confirmed
};

// classes used in by BaseHeightMap

class LightMapTerrainTextureClass : TextureClass
{
    // no members
};

class ScorchTextureClass : TextureClass
{
    // no members
};

class CloudMapTerrainTextureClass : TextureClass
{
    int m_xSlidePerSecond;
    int m_ySlidePerSecond;
    int m_curTick;
    int m_xOffset;
    int m_yOffset;
};

// classes used in by WorldHeightMap

class TerrainTextureClass : TextureClass
{
    // no members
};

class AlphaTerrainTextureClass : TextureClass
{
    // no members
};

class AlphaEdgeTextureClass : TextureClass
{
    // no members
};
