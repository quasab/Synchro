#include "IncThread.h"

IncThread::IncThread(Counter *_counter):
    m_counter(_counter)
{
}

void IncThread::run()
{
    m_counter->increse();
}
