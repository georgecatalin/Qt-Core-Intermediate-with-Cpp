/* ***
 * QLinkedList<T> is one of Qt's generic container classes.
 * It stores a list of values a provides iterator-based access + constant time insertions and removals
 *
 * If you need a real linked list, with guaranteed insertion time in the middle of the list and iterators to items rather than indexes use QLinkedList.
 *  ***/

#include <QCoreApplication>
#include <QDebug>
#include <QLinkedList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<int> myList;

    for(int i=0;i<10;i++)
    {
        myList.append(i);
    }

    myList.removeFirst();
    myList.removeLast();
    myList.removeOne(4);

    if (myList.contains(3)) qInfo()<<"Your list contains \"3\"";

    qInfo()<<"This is it, alligator!";


    return a.exec();
}
