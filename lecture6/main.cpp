#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "calculator.h"
/**
 * Add your test cases as you go.
 * TODO: introduce visitor interface.
 * TODO: replace operator() with evaluator visitor.
 * TODO: implement printer visitor which prints the terms into output stream.
 * TODO: provide operator<< to your printer implementation to print terms.
 */

using namespace calculator;

TEST_CASE("plus")
{
auto sys = symbol_table_t{};
auto a = sys.var("a", 2);
auto b = sys.var("b", 3);
auto c = sys.var("c");
auto state = sys.state();
auto os = std::ostringstream();

std::shared_ptr<term_t> t = std::make_shared<binary_t>(a, b, op_t::plus);
/*
SUBCASE("evaluate")
{
    auto v = eval(state, t); // function which constructs evaluator and calls it
    CHECK(v == 5);
}
SUBCASE("print")
{
    os << print(sys, t); // function which constructs a printable object which calls printer visitor
    CHECK(os.str() == "(a+b)");
}
 */
}
