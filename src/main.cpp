#include <QList>
#include <QDebug>
#include <QElapsedTimer>

#include "IncThread.h"
#include "Counter.h"

#include <iostream>

int main()
{
    while (true)
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Without Mutex."<< std::endl;
        std::cout << "2) With Mutex" << std::endl;
        std::cout << "0) Exit." << std::endl;

        int menu = -1;

        std::cin >> menu;
        bool threadSafety = false;
        if (menu == 2)
        {
            threadSafety = true;
        }
        else if (menu == 1)
        {
            threadSafety = false;
        }
        else if (menu == 0)
        {
            return 0;
        }
        else
        {
            continue;
        }


        Counter counter(threadSafety);

        QList<IncThread*> threads;
        QMutex mutex;

        QElapsedTimer timer;
        timer.start();

        for (int i = 0; i < QThread::idealThreadCount(); ++i)
        {
            IncThread *thread = new IncThread(&counter);

            threads.append(thread);
        }


        for (int i = 0; i < threads.count(); ++i)
        {
            threads.at(i)->start();

        }

        for (int i = 0; i < threads.count(); ++i)
        {
            threads.at(i)->wait(10000);
        }

        qDeleteAll(threads);

        std::cout << "Counter = " << counter.value() << std::endl;
        std::cout << "Done in " << timer.elapsed() << "ms" << std::endl;
    }
}
