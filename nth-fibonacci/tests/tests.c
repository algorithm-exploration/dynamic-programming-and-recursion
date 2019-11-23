void zerothFibinacciTest(Test *tc)
{
    const int actual = fib(0);
    const int expected = 0;
    AssertIntEquals(tc, expected, actual);
}

void firstFibinacciTest(Test *tc)
{
    const int actual = fib(1);
    const int expected = 1;
    AssertIntEquals(tc, expected, actual);
}

void secondFibinacciTest(Test *tc)
{
    const int actual = fib(2);
    const int expected = 1;
    AssertIntEquals(tc, expected, actual);
}

void thirdFibinacciTest(Test *tc)
{
    const int actual = fib(3);
    const int expected = 2;
    AssertIntEquals(tc, expected, actual);
}

void fifthFibinacciTest(Test *tc)
{
    const int actual = fib(5);
    const int expected = 5;
    AssertIntEquals(tc, expected, actual);
}

void tenthFibinacciTest(Test *tc)
{
    const int actual = fib(10);
    const int expected = 55;
    AssertIntEquals(tc, expected, actual);
}

void callWithNegativeN()
{
    fib(-1);
}

void negativeFibinacciTest(Test *tc)
{
    AssertRaises(tc, callWithNegativeN);
}


int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, zerothFibinacciTest);
    SUITE_ADD_TEST(tests, firstFibinacciTest);
    SUITE_ADD_TEST(tests, secondFibinacciTest);
    SUITE_ADD_TEST(tests, thirdFibinacciTest);
    SUITE_ADD_TEST(tests, fifthFibinacciTest);
    SUITE_ADD_TEST(tests, tenthFibinacciTest);
    SUITE_ADD_TEST(tests, negativeFibinacciTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
