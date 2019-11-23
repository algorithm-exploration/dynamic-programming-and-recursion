#define countof(a) (sizeof(a)/sizeof((a)[0]))

void emptyStringTest(Test *tc)
{
    const char *expected[] = {""};

    Set *actual = getPermutations("");
    AssertPtrNotNull(tc, actual);
    if (actual == NULL) return;

    int result = setSize(actual) == countof(expected);
    AssertTrue(tc, result);

    if (result) {
        for (size_t i = 0; i < countof(expected); i++) {
            result = setContainsString(actual, expected[i]);
            AssertTrue(tc, result);
            if (!result) break;
        }
    }
    setFree(actual);
}

void oneCharacterStringTest(Test *tc)
{
    const char *expected[] = {"a"};

    Set *actual = getPermutations("a");
    AssertPtrNotNull(tc, actual);
    if (actual == NULL) return;

    int result = setSize(actual) == countof(expected);
    AssertTrue(tc, result);

    if (result) {
        for (size_t i = 0; i < countof(expected); i++) {
            result = setContainsString(actual, expected[i]);
            AssertTrue(tc, result);
            if (!result) break;
        }
    }
    setFree(actual);
}

void twoCharacterStringTest(Test *tc)
{
    const char *expected[] = {"ab", "ba"};

    Set *actual = getPermutations("ab");
    AssertPtrNotNull(tc, actual);
    if (actual == NULL) return;

    int result = setSize(actual) == countof(expected);
    AssertTrue(tc, result);

    if (result) {
        for (size_t i = 0; i < countof(expected); i++) {
            result = setContainsString(actual, expected[i]);
            AssertTrue(tc, result);
            if (!result) break;
        }
    }
    setFree(actual);
}

void threeCharacterStringTest(Test *tc)
{
    const char *expected[] = {"abc", "acb", "bac", "bca", "cab", "cba"};

    Set *actual = getPermutations("abc");
    AssertPtrNotNull(tc, actual);
    if (actual == NULL) return;

    int result = setSize(actual) == countof(expected);
    AssertTrue(tc, result);

    if (result) {
        for (size_t i = 0; i < countof(expected); i++) {
            result = setContainsString(actual, expected[i]);
            AssertTrue(tc, result);
            if (!result) break;
        }
    }
    setFree(actual);
}

int main()
{
    TestSuite *tests = TestSuiteNew();

    SUITE_ADD_TEST(tests, emptyStringTest);
    SUITE_ADD_TEST(tests, oneCharacterStringTest);
    SUITE_ADD_TEST(tests, twoCharacterStringTest);
    SUITE_ADD_TEST(tests, threeCharacterStringTest);

    TestSuiteRun(tests);
    TestSuiteDelete(tests);

    return 0;
}
