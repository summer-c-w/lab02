/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2021
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 0.1
 * @date    2021-09-10
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "csc232.h"

#if EXECUTE_BLOCK
SCENARIO("Capturing standard output in a test", "[capture]")
{
    // This can be an ofstream as well or any other ostream
    std::stringstream buffer;
    // Save cout's buffer here
    std::streambuf *sbuf = std::cout.rdbuf();
    // Redirect cout to our stringstream buffer or any other ostream
    std::cout.rdbuf(buffer.rdbuf());

    GIVEN("something to send to standard output")
    {
        std::string message{"Hi there!"};

        WHEN("that object is inserted into the standard output stream")
        {
            std::cout << message << std::endl;

            THEN( "it is captured by this test" )
            {
                REQUIRE(buffer.str() == (message + "\n"));
                std::cout.rdbuf(sbuf);
            }
        }
    }

    GIVEN("a different object to insert into the stream")
    {
        int number{42};

        WHEN("that different object is inserted into the standard output stream")
        {
            std::cout << number;

            THEN("that different object is captured by this test too")
            {
                REQUIRE(buffer.str() == std::string{"42"});
                std::cout.rdbuf(sbuf);
            }
        }
    }
}
#endif

#if FINISHED_PART_1
namespace csc232 {
    class TestShape final : public Shape {
    public:
        double area() const override {
            return 0;
        }

        double perimeter() const override {
            return 0;
        }
    };
}
SCENARIO("Evaluate Code for Task 1", "[task1]") {
    GIVEN("The student has completed Task 1") {

        WHEN("An implementation of the Shape interface is implemented") {
            const csc232::Shape *shapePtr = new csc232::TestShape{};
            THEN("The Shape can be used as necessary") {
                REQUIRE(shapePtr->area() == 0);
            }
        }
    }
}
#else
SCENARIO("Bootstrap - If you see this, you haven't done anything yet!", "[bootstrap]")
{
    GIVEN("The student just opened this assignment")
    {
        WHEN("They run the tests target")
        {
            THEN("They receive this encouraging message ==> Great job!")
            {
                bool expected{true};
                bool actual{true};
                REQUIRE(expected == actual);
            }
            AND_THEN("They're encouraged to get started ==> Now tackle task 1!");
        }
    }
}
#endif

#if FINISHED_PART_2
SCENARIO("Evaluate Code for Task 2", "[task2]") {
    GIVEN("The student has completed Task 2") {
        WHEN("The Square implementation of the Shape interface is implemented") {
            const csc232::Shape *shapePtr = new csc232::Square{};
            THEN("The area of the square is found to be as required") {
                REQUIRE(shapePtr->area() == 1.0);
            }
            AND_THEN("The perimeter of the square is also found to be as required") {
                REQUIRE(shapePtr->perimeter() == 4.0);
            }
        }
    }
}
#endif

#if FINISHED_PART_3
SCENARIO("Evaluate Code for Task 3", "[task3]") {
    GIVEN("The student has completed Task 3") {
        WHEN("The Circle implementation of the Shape interface is implemented") {
            const csc232::Shape *shapePtr = new csc232::Circle{};
            THEN("The area of the circle is found to be as required") {
                constexpr double expected_area{M_PI};
                const double actual_area{shapePtr->area()};
                REQUIRE(expected_area == actual_area);
            }
            AND_THEN("The perimeter of the circle is found to be as required") {
                constexpr double expected_perimeter{2 * M_PI};
                const double actual_perimeter{shapePtr->perimeter()};
                REQUIRE(expected_perimeter == actual_perimeter);
            }
        }
    }
}
#endif
