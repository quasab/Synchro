#include "Counter.h"
#include <QMutexLocker>
#include <QThread>

#include <QDebug>

Counter::Counter(bool _threadSafety):
    m_counter(0),
    m_threadSafety(_threadSafety)
{
}

void Counter::increse()
{
    if (m_threadSafety)
    {
        m_mutex.lock();
    }

    QThread::msleep(10);
    m_counter++;

    if (m_threadSafety)
    {
        m_mutex.unlock();
    }
}

int Counter::value() const
{
    return m_counter;
}
