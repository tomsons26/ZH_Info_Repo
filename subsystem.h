class SubsystemInterface
{
#ifdef DEBUG
    /*0x4*/ float f1; // for update, set from global
    float f2; // for update, (time_after_update_call - time_before_update_call) / feq
    float f3; // for draw, set from global
    float f4; // for draw, (time_after_draw_call - time_before_draw_call) / feq
    bool b1; // for update, set if f2 > 0.00019999999
    bool b2; // for draw, set if f4 > 0.00019999999
#endif
    AsciiString m_name;
}