const lest::test tests[] = {
    CASE("zeroth Fibonacci") {
        const int actual = fib(0);
        const int expected = 0;
        EXPECT(actual == expected);
    },
    CASE("first Fibonacci") {
        const int actual = fib(1);
        const int expected = 1;
        EXPECT(actual == expected);
    },
    CASE("second Fibonacci") {
        const int actual = fib(2);
        const int expected = 1;
        EXPECT(actual == expected);
    },
    CASE("third Fibonacci") {
        const int actual = fib(3);
        const int expected = 2;
        EXPECT(actual == expected);
    },
    CASE("fifth Fibonacci") {
        const int actual = fib(5);
        const int expected = 5;
        EXPECT(actual == expected);
    },
    CASE("tenth Fibonacci") {
        const int actual = fib(10);
        const int expected = 55;
        EXPECT(actual == expected);
    },
    CASE("negative fibonacci") {
        EXPECT_THROWS(fib(-1));
    }
};

int main(int argc, char** argv)
{
    return lest::run(tests, argc, argv);
}
