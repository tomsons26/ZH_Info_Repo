// this contains common type definitions that are thoughought the code

// renamed to Utf8String in Thyme codebase
class AsciiString
{
    AsciiStringData *data;
    struct AsciiStringData
    {
#ifdef DEBUG
        char *debug_ptr;
#endif
        uint16_t ref_count;
        uint16_t num_chars_allocated;
        // string data is stored immediately after the header.
    };
}

class UnicodeString
{
    UnicodeStringData *data;
    struct UnicodeStringData
    {
#ifdef DEBUG
        wchar_t *debug_ptr;
#endif
        uint16_t ref_count;
        uint16_t num_chars_allocated;
        // string data is stored immediately after the header.
    };
};

// size is variable based on bit count, account for at least a dword when mapping these
template<int bits>
class BitFlags
{
    std::bitset<bits> m_bits;
};