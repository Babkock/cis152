#include <QtTest>
#include "queue.h"
#include "queueemptyexception.h"
#include "queuefullexception.h"

// add necessary includes here

class queueTests : public QObject
{
    Q_OBJECT

public:
    queueTests();
    ~queueTests();

private slots:
    void testCreateQueue();
    void testIsEmptyTrue();
    void testIsEmptyFalse();
    void testIsFullTrue();
    void testIsFullFalse();
    void testEnqueue();
    void testEnqueueFullQueue();
    void testDequeue();
    void testDeqeueEmptyQueue();
    void testWrapAround();
    void testPeek();
    void testPeekEmptyQueue();
    void testSizeZero();
    void testSizeNonZero();
    void testPrintEmptyQueue();
    void testPrintQueue();
    void testPrintQueueWrapAround();
};

queueTests::queueTests()
{

}

queueTests::~queueTests()
{

}

void queueTests::testCreateQueue(){
    // ARRANGE
    queue myQueue = queue(1);
    bool actual;
    // ACT
    actual = myQueue.isEmpty();
    // ASSERT
    QVERIFY(actual); // verify true
}

void queueTests::testIsEmptyTrue(){
    // ARRANGE
    queue myQueue = queue(1);
    bool actual;
    // ACT
    actual = myQueue.isEmpty();
    // ASSERT
    QVERIFY(actual); // verify true
}

void queueTests::testIsEmptyFalse(){
    // ARRANGE
    queue myQueue = queue(1);
    bool actual;
    string item="QueueItem";
    // ACT
    myQueue.enqueue(item);
    actual = myQueue.isEmpty();
    // ASSERT
    QVERIFY(actual); // verify true
}

void queueTests::testIsFullTrue(){
    // ARRANGE
    queue myQueue = queue(1);
    bool actual;
    string item="QueueItem";
    // ACT
    myQueue.enqueue(item);
    actual = myQueue.isFull();
    // ASSERT
    QVERIFY(actual); // verify true
}

void queueTests::testIsFullFalse(){
    // ARRANGE
    queue myqueue = queue(2);
    string item = "C++ is Fun!";
    bool actual, expected;
    // ACT
    myqueue.enqueue(item);
    actual = myqueue.isFull();
    expected = false;
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testEnqueue(){
    // ARRANGE
    queue myqueue = queue(1);
    string item = "C++ is Fun!";
    string actual;
    string expected = item;
    // ACT
    myqueue.enqueue(item);
    actual = myqueue.peek();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testEnqueueFullQueue(){
    // ARRANGE
    queue myqueue = queue(1);
    string item = "queueItem";
    myqueue.enqueue(item);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myqueue.enqueue(item+"2"), queueFullException);
}

void queueTests::testDequeue(){
    // ARRANGE
    queue myqueue = queue(1);
    string item = "queueItem";
    string actual;
    string expected = item;
    myqueue.enqueue(item);
    // ACT
    actual = myqueue.dequeue();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testDeqeueEmptyQueue(){
    // ARRANGE
    queue myqueue = queue(1);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myqueue.dequeue(), queueEmptyException);
}

void queueTests::testWrapAround(){
    // ARRANGE
    queue myQueue = queue(2);
    string item = "QueueItem";
    string actual, expected;
    expected = "QueueItem3";
    // ACT
    myQueue.enqueue(item + "1");
    myQueue.enqueue(item + "2");
    myQueue.dequeue();
    myQueue.enqueue(item + "3");
    myQueue.dequeue();
    actual = myQueue.peek();
    // ASSERT
    QCOMPARE(expected, actual);
}

void queueTests::testPeek(){
    // ARRANGE
    queue myqueue = queue(1);
    string item = "queueItem";
    string actual;
    string expected=item;
    // ACT
    myqueue.enqueue(item);
    actual = myqueue.peek();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testPeekEmptyQueue(){
    // ARRANGE
    queue myqueue = queue(1);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myqueue.peek(), queueEmptyException);
}

void queueTests::testSizeZero(){
    // ARRANGE
    queue myqueue = queue(1);
    string item = "queueItem";
    int actual;
    int expected = 0;
    // ACT
    actual = myqueue.size();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testSizeNonZero(){
    // ARRANGE
    queue myqueue = queue(2);
    string item = "queueItem";
    int actual;
    int expected = 2;
    // ACT
    myqueue.enqueue(item);
    myqueue.enqueue(item);
    actual = myqueue.size();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testPrintEmptyQueue(){
    // ARRANGE
    queue myqueue = queue(1);
    string actual, expected;
    expected = "Queue is Empty";
    // ACT
    actual = myqueue.printQueue();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testPrintQueue(){
    // ARRANGE
    queue myqueue = queue(2);
    string item = "queueItem";
    string actual, expected;
    expected = "queueItem2\nqueueItem1\n";
    // ACT
    myqueue.enqueue(item + "1");
    myqueue.enqueue(item + "2");
    actual = myqueue.printQueue();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testPrintQueueWrapAround(){
    // ARRANGE
    queue myQueue = queue(2);
    string item = "QueueItem";
    string actual, expected;
    expected = "QueueItem2\nQueueItem3\n";
    // ACT
    myQueue.enqueue(item + "1");
    myQueue.enqueue(item + "2");
    myQueue.dequeue();
    myQueue.enqueue(item + "3");
    actual = myQueue.printQueue();
    // ASSERT
    QCOMPARE(actual, expected);
}

QTEST_APPLESS_MAIN(queueTests)

#include "tst_queuetests.moc"
