#include <QtTest>
#include "queue.h"
#include "queueemptyexception.h"
#include "queuefullexception.h"

// add necessary includes here

class queueTests : public QObject
{
    Q_OBJECT

public:
    queueTests(void);
    ~queueTests(void);
private slots:
    void testCreateQueue(void);
    void testIsEmptyTrue(void);
    void testIsEmptyFalse(void);
    void testIsFullTrue(void);
    void testIsFullFalse(void);
    void testEnqueue(void);
    void testEnqueueFullQueue(void);
    void testDequeue(void);
    void testDeqeueEmptyQueue(void);
    void testWrapAround(void);
    void testPeek(void);
    void testPeekEmptyQueue(void);
    void testSizeZero(void);
    void testSizeNonZero(void);
    void testPrintEmptyQueue(void);
    void testPrintQueue(void);
    void testPrintQueueWrapAround(void);
};

queueTests::queueTests(void) { }

queueTests::~queueTests(void) { }

void queueTests::testCreateQueue(void) {
    // ARRANGE
    queue myQueue = queue(1);
    bool actual;
    // ACT
    actual = myQueue.isEmpty();
    // ASSERT
    QVERIFY(actual); // verify true
}

void queueTests::testIsEmptyTrue(void) {
    // ARRANGE
    queue myQueue = queue(1);
    bool actual;
    // ACT
    actual = myQueue.isEmpty();
    // ASSERT
    QVERIFY(actual); // verify true
}

void queueTests::testIsEmptyFalse(void) {
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

void queueTests::testIsFullTrue(void) {
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

void queueTests::testIsFullFalse(void) {
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

void queueTests::testEnqueue(void) {
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

void queueTests::testEnqueueFullQueue(void) {
    // ARRANGE
    queue myqueue = queue(1);
    string item = "queueItem";
    myqueue.enqueue(item);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myqueue.enqueue(item+"2"), queueFullException);
}

void queueTests::testDequeue(void) {
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

void queueTests::testDeqeueEmptyQueue(void) {
    // ARRANGE
    queue myqueue = queue(1);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myqueue.dequeue(), queueEmptyException);
}

void queueTests::testWrapAround(void) {
    // ARRANGE
    queue myQueue = queue(3);
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

void queueTests::testPeek(void) {
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

void queueTests::testPeekEmptyQueue(void) {
    // ARRANGE
    queue myqueue = queue(1);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myqueue.peek(), queueEmptyException);
}

void queueTests::testSizeZero(void) {
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

void queueTests::testSizeNonZero(void) {
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

void queueTests::testPrintEmptyQueue(void) {
    // ARRANGE
    queue myqueue = queue(1);
    string actual, expected;
    expected = "Queue is Empty";
    // ACT
    actual = myqueue.printQueue();
    // ASSERT
    QCOMPARE(actual, expected);
}

void queueTests::testPrintQueue(void) {
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

void queueTests::testPrintQueueWrapAround(void) {
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
