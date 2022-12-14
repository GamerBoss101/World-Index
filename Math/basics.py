
# This file contains the basic math functions that are used in the calculator.

def add(*arguments):
    return sum(arguments)

def subtract(*arguments):
    return arguments[0] - sum(arguments[1:])

def multiply(*arguments):
    result = 1
    for argument in arguments:
        result *= argument
    return result

def divide(*arguments):
    result = arguments[0]
    for argument in arguments[1:]:
        result /= argument
    return result
