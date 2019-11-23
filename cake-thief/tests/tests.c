#define countof(a) (sizeof(a)/sizeof((a)[0]))

void oneCakeTest(Test *tc)
{
    const CakeType cakeTypes[] = { {2, 1} };
    const unsigned int weightCapacity = 9;
    const unsigned long long expected = 4;
    const unsigned long long actual = maxDuffelBagValue(
        cakeTypes, countof(cakeTypes), weightCapacity);
    AssertUnsignedLongLongEquals(tc, expected, actual);
}

void twoCakesTest(Test *tc)
{
    const CakeType cakeTypes[] = { {4, 4}, {5, 5} };
    const unsigned int weightCapacity = 9;
    const unsigned long long expected = 9;
    const unsigned long long actual = maxDuffelBagValue(
        cakeTypes, countof(cakeTypes), weightCapacity);
    AssertUnsignedLongLongEquals(tc, expected, actual);
}

void onlyTakeLessValuableCakeTest(Test *tc)
{
    const CakeType cakeTypes[] = { {4, 4}, {5, 5} };
    const unsigned int weightCapacity = 12;
    const unsigned long long expected = 12;
    const unsigned long long actual = maxDuffelBagValue(
        cakeTypes, countof(cakeTypes), weightCapacity);
    AssertUnsignedLongLongEquals(tc, expected, actual);
}

void lotsOfCakesTest(Test *tc)
{
    const CakeType cakeTypes[] = {
        {2, 3}, {3, 6}, {5, 1},
        {6, 1}, {7, 1}, {8, 1}
    };
    const unsigned int weightCapacity = 7;
    const unsigned long long expected = 12;
    const unsigned long long actual = maxDuffelBagValue(
        cakeTypes, countof(cakeTypes), weightCapacity);
    AssertUnsignedLongLongEquals(tc, expected, actual);
}

void valueToWeightRatioIsNotOptimalTest(Test *tc)
{
    const CakeType cakeTypes[] = { {51, 52}, {50, 50} };
    const unsigned int weightCapacity = 100;
    const unsigned long long expected = 100;
    const unsigned long long actual = maxDuffelBagValue(
        cakeTypes, countof(cakeTypes), weightCapacity);
    AssertUnsignedLongLongEquals(tc, expected, actual);
}

void zeroCapacityTest(Test *tc)
{
    const CakeType cakeTypes[] = { {1, 2} };
    const unsigned int weightCapacity = 0;
    const unsigned long long expected = 0;
    const unsigned long long actual = maxDuffelBagValue(
        cakeTypes, countof(cakeTypes), weightCapacity);
    AssertUnsignedLongLongEquals(tc, expected, actual);
}

void cakeWithZeroValueAndWeightTest(Test *tc)
{
    const CakeType cakeTypes[] = { {0, 0}, {2, 1} };
    const unsigned int weightCapacity = 7;
    const unsigned long long expected = 3;
    const unsigned long long actual = maxDuffelBagValue(
        cakeTypes, countof(cakeTypes), weightCapacity);
    AssertUnsignedLongLongEquals(tc, expected, actual);
}

void callWithCakeWithNonZeroValueAndZeroWeight(void)
{
    const CakeType cakeTypes[] = { {0, 5} };
    const unsigned int weightCapacity = 5;
    maxDuffelBagValue(cakeTypes, countof(cakeTypes), weightCapacity);
}

void cakeWithNonZeroValueAndZeroWeightTest(Test *tc)
{
    AssertRaises(tc, callWithCakeWithNonZeroValueAndZeroWeight);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, oneCakeTest);
    SUITE_ADD_TEST(tests, twoCakesTest);
    SUITE_ADD_TEST(tests, onlyTakeLessValuableCakeTest);
    SUITE_ADD_TEST(tests, lotsOfCakesTest);
    SUITE_ADD_TEST(tests, valueToWeightRatioIsNotOptimalTest);
    SUITE_ADD_TEST(tests, zeroCapacityTest);
    SUITE_ADD_TEST(tests, cakeWithZeroValueAndWeightTest);
    SUITE_ADD_TEST(tests, cakeWithNonZeroValueAndZeroWeightTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
