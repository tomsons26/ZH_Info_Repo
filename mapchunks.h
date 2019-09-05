class DataChunkTableOfContents
{
    Mapping *m_list; // confirmed
    int m_listLength; // confirmed
    unsigned int m_nextID; // confirmed
    bool m_headerOpened; // confirmed

    struct Mapping
    {
        /*0x4*/ Mapping *m_next; // confirmed
        AsciiString name; // confirmed
        unsigned int id; // confirmed
    };
};

class DataChunkInput
{
    ChunkInputStream *m_file; // confirmed
    DataChunkTableOfContents m_contents; // confirmed
    int m_fileposOfFirstChunk; // confirmed
    UserParser *m_parserList; // confirmed
    InputChunk *m_chunkStack; // confirmed
    void *m_currentObject; // confirmed
    void *m_userData; // confirmed

    struct InputChunk
    {
        /*0x4*/ InputChunk *next; // confirmed
        unsigned int id; // confirmed
        unsigned short version; // confirmed
        int chunk_start; // confirmed
        int data_size; // confirmed
        int data_left; // confirmed
    };

    struct UserParser
    {
        /*0x4*/ UserParser *next; // confirmed
        bool (*parser)(DataChunkInput &, DataChunkInfo *, void *); // confirmed
        AsciiString label; // confirmed
        AsciiString parent_label; // confirmed
        void *user_data; // confirmed
    };
};

class DataChunkOutput
{
    ChunkOutputStream *m_pOut; // confirmed
    FILE *m_tmp_file; // confirmed
    DataChunkTableOfContents m_contents; // confirmed
    OutputChunk *m_chunkStack; // confirmed

    struct OutputChunk
    {
        /*0x4*/ OutputChunk *next; // confirmed
        unsigned int id; // confirmed
        unsigned int version; // confirmed
    };
};

struct DataChunkInfo
{
    AsciiString label; // confirmed
    AsciiString parent_label; // confirmed
    unsigned __int16 version; // confirmed
    int data_size; // confirmed
};
