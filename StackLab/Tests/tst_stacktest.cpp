#include <QtTest>
#include "stack.h"
#include "StackEmptyException.h"
#include "stackfullexception.h"

// add necessary includes here

class StackTest : public QObject
{
    Q_OBJECT

public:
    StackTest();
    ~StackTest();

private slots:
    void testCreateStack();
    void testIsEmptyTrue();
    void testIsEmptyFalse();
    void testIsFullTrue();
    void testIsFullFalse();
    void testPushStack();
    void testPushFullStack();
    void testPopStack();
    void testStackSizeZero();
    void testStackSizeNonZero();
    void testPopEmptyStack();
    void testPeekStack();
    void testPeekEmptyStack();
    void testPrintStackUp();
    void testPrintStackUpEmptyStack();
};

StackTest::StackTest()
{

}

StackTest::~StackTest()
{

}

void StackTest::testCreateStack()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     bool actual;
     // ACT
     actual = myStack.isEmpty();
     // ASSERT
     QVERIFY(actual); // verify true
 }

void StackTest::testIsEmptyTrue()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     bool actual, expected;
     // ACT
     actual = myStack.isEmpty();
     expected = true;
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testIsEmptyFalse()
 {
     // ARRANGE
     Stack myStack = Stack(2);
     string item = "StackItem";
     bool actual, expected;
     // ACT
     myStack.push(item + "1");
     actual = myStack.isEmpty();
     expected = false;
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testIsFullTrue()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     string item = "StackItem";
     bool actual, expected;
     // ACT
     myStack.push(item + "1");
     actual = myStack.isFull();
     expected = true;
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testIsFullFalse()
 {
     // ARRANGE
     Stack myStack = Stack(2);
     string item = "StackItem";
     bool actual, expected;
     // ACT
     myStack.push(item + "1");
     actual = myStack.isFull();
     expected = false;
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testPushStack()
 {
     // ARRANGE
     Stack myStack = Stack(2);
     string item = "StackItem";
     string actual;
     string expected = "StackItem2\nStackItem1\n";
     // ACT
     myStack.push(item + "1");
     myStack.push(item + "2");
     actual = myStack.printStackUp();
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testPushFullStack()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     string item = "StackItem";
     // ACT
      myStack.push(item + "1");
     // ASSERT
      QVERIFY_EXCEPTION_THROWN(myStack.push(item+"2"), StackFullException);
 }


void StackTest::testPopStack()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     string item = "StackItem";
     string actual;
     string expected = "StackItem1";
     // ACT
     myStack.push(item + "1");
     actual = myStack.pop();
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testStackSizeZero()
 {
     // ARRANGE
     Stack myStack = Stack(2);
     int actual, expected;
     expected = 0;
     // ACT
     actual = myStack.size();
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testStackSizeNonZero()
 {
     // ARRANGE
     Stack myStack = Stack(2);
     string item = "StackItem";
     int actual, expected;
     expected = 2;
     // ACT
     myStack.push(item + "1");
     myStack.push(item + "2");
     actual = myStack.size();
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testPopEmptyStack()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     // ACT
     // ASSERT
     QVERIFY_EXCEPTION_THROWN(myStack.pop(), StackEmptyException);
 }

void StackTest::testPeekStack() {
     // ARRANGE
     Stack myStack = Stack(1);
     string item = "StackItem";
     string actual, expected;
     // ACT
     myStack.push(item);
     expected = item;
     actual = myStack.peek();
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testPeekEmptyStack()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     // ACT
     // ASSERT
     QVERIFY_EXCEPTION_THROWN(myStack.peek(), StackEmptyException);
 }


void StackTest::testPrintStackUp()
 {
     // ARRANGE
     Stack myStack = Stack(2);
     string item = "StackItem";
     string actual, expected;
     expected = "StackItem2\nStackItem1\n";
     // ACT
     myStack.push(item + "1");
     myStack.push(item + "2");
     actual = myStack.printStackUp();
     // ASSERT
     QCOMPARE(actual, expected);
 }

void StackTest::testPrintStackUpEmptyStack()
 {
     // ARRANGE
     Stack myStack = Stack(1);
     // ACT
     // ASSERT
     QVERIFY_EXCEPTION_THROWN(myStack.printStackUp(),StackEmptyException);
 }


QTEST_APPLESS_MAIN(StackTest)

#include "tst_stacktest.moc"
