#define countof(a) (sizeof(a)/sizeof((a)[0]))

void sampleInputTest(Test *tc)
{
    const int amount = 4;
    const int denominations[] = {1, 2, 3};
    const size_t actual = changePossibilities(amount, denominations, countof(denominations));
    const size_t expected = 4;
    AssertSizeEquals(tc, expected, actual);
}

void oneWayToMakeZeroCentsTest(Test *tc)
{
    const int amount = 0;
    const int denominations[] = {1, 2};
    const size_t actual = changePossibilities(amount, denominations, countof(denominations));
    const size_t expected = 1;
    AssertSizeEquals(tc, expected, actual);
}

void noWaysIfNoCoinsTest(Test *tc)
{
    const int amount = 1;
    const size_t actual = changePossibilities(amount, NULL, 0);
    const size_t expected = 0;
    AssertSizeEquals(tc, expected, actual);
}

void bigCoinValueTest(Test *tc)
{
    const int amount = 5;
    const int denominations[] = {25, 50};
    const size_t actual = changePossibilities(amount, denominations, countof(denominations));
    const size_t expected = 0;
    AssertSizeEquals(tc, expected, actual);
}

void bigTargetAmountTest(Test *tc)
{
    const int amount = 50;
    const int denominations[] = {5, 10};
    const size_t actual = changePossibilities(amount, denominations, countof(denominations));
    const size_t expected = 6;
    AssertSizeEquals(tc, expected, actual);
}

void changeForOneDollarTest(Test *tc)
{
    const int amount = 100;
    const int denominations[] = {1, 5, 10, 25, 50};
    const size_t actual = changePossibilities(amount, denominations, countof(denominations));
    const size_t expected = 292;
    AssertSizeEquals(tc, expected, actual);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, sampleInputTest);
    SUITE_ADD_TEST(tests, oneWayToMakeZeroCentsTest);
    SUITE_ADD_TEST(tests, noWaysIfNoCoinsTest);
    SUITE_ADD_TEST(tests, bigCoinValueTest);
    SUITE_ADD_TEST(tests, bigTargetAmountTest);
    SUITE_ADD_TEST(tests, changeForOneDollarTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
