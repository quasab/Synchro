#ifndef INCTHREAD_H
#define INCTHREAD_H

#include <QThread>

#include "Counter.h"

class IncThread : public QThread
{

public:

    //! Конструктор.
    /*! \param _counter - счетчик.
     */
    IncThread(Counter *_counter);

public:

    //! Функция для обработки в потоке.
    void run();

private:

    //! Счетчик.
    Counter *m_counter;
};

#endif // INCTHREAD_H
