#ifndef COUNTER_H
#define COUNTER_H

#include <QMutex>

class Counter
{
public:

    //! Конструктор класса.
    Counter(bool _threadSafety = false);

public:

    //! Увеличивает счетчик.
    void increse();
    //! Получает значение счетчика.
    /*! \return значение счетчика.
     */
    int value() const;

private:

    //! Мутекс.
    QMutex m_mutex;
    //! Счетчик.
    int m_counter;
    //! Признак использования мутекса.
    bool m_threadSafety;
};

#endif // COUNTER_H
