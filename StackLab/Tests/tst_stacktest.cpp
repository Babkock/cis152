/*
 * Array-Based Stack Implementation Lab
 * CIS 152 - Data Structures
 * Tanner Babcock
 * September 7, 2022
*/
#include <QtTest>
#include "stack.h"
#include "stackemptyexception.h"
#include "stackfullexception.h"
using namespace std;

class StackTest : public QObject
{
    Q_OBJECT
public:
    StackTest(void);
    ~StackTest();

private slots:
    void testCreateStack(void);
    void testIsEmptyTrue(void);
    void testIsEmptyFalse(void);
    void testIsFullTrue(void);
    void testIsFullFalse(void);
    void testPushStack(void);
    void testPushFullStack(void);
    void testPopStack(void);
    void testStackSizeZero(void);
    void testStackSizeNonZero(void);
    void testPopEmptyStack(void);
    void testPeekStack(void);
    void testPeekEmptyStack(void);
    void testPrintStackUp(void);
    void testPrintStackUpEmptyStack(void);
};

StackTest::StackTest(void)
{

}

StackTest::~StackTest()
{

}

void StackTest::testCreateStack(void) {
    // ARRANGE
    Stack myStack = Stack(1);
    bool actual;
    // ACT
    actual = myStack.isEmpty();
    // ASSERT
    QVERIFY(actual); // verify true
}

void StackTest::testIsEmptyTrue(void) {
    // ARRANGE
    Stack myStack = Stack(1);
    bool actual, expected;
    // ACT
    actual = myStack.isEmpty();
    expected = true;
    // ASSERT
    QCOMPARE(actual, expected);
}

void StackTest::testIsEmptyFalse(void) {
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

void StackTest::testIsFullTrue(void) {
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

void StackTest::testIsFullFalse(void) {
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

void StackTest::testPushStack(void) {
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

void StackTest::testPushFullStack(void) {
    // ARRANGE
    Stack myStack = Stack(1);
    string item = "StackItem";
    // ACT
    myStack.push(item + "1");
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myStack.push(item+"2"), StackFullException);
}

void StackTest::testPopStack(void) {
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

void StackTest::testStackSizeZero(void) {
    // ARRANGE
    Stack myStack = Stack(2);
    int actual, expected;
    expected = 0;
    // ACT
    actual = myStack.size();
    // ASSERT
    QCOMPARE(actual, expected);
}

void StackTest::testStackSizeNonZero(void) {
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

void StackTest::testPopEmptyStack(void) {
    // ARRANGE
    Stack myStack = Stack(1);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myStack.pop(), StackEmptyException);
}

void StackTest::testPeekStack(void) {
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

void StackTest::testPeekEmptyStack(void) {
    // ARRANGE
    Stack myStack = Stack(1);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myStack.peek(), StackEmptyException);
}

void StackTest::testPrintStackUp(void) {
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

void StackTest::testPrintStackUpEmptyStack(void) {
    // ARRANGE
    Stack myStack = Stack(1);
    // ACT
    // ASSERT
    QVERIFY_EXCEPTION_THROWN(myStack.printStackUp(),StackEmptyException);
}

QTEST_APPLESS_MAIN(StackTest)

#include "tst_stacktest.moc"
