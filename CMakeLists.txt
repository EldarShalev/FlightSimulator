cmake_minimum_required(VERSION 3.5)
project(simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(commands)
include_directories(expressions)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
add_executable(FlightSimulator
        commands/Command.h
        commands/ConnectCommand.cpp
        commands/ConnectCommand.h
        commands/LoopCommand.cpp
        commands/LoopCommand.h
        commands/OpenServerCommand.cpp
        commands/OpenServerCommand.h
        commands/PrintCommand.cpp
        commands/PrintCommand.h
        commands/SetCommand.cpp
        commands/SetCommand.h
        commands/SleepCommand.cpp
        commands/SleepCommand.h
        commands/CreateCommand.cpp
        commands/CreateCommand.h
        commands/IfCommand.cpp
        commands/IfCommand.h
        expressions/Equals.h
        expressions/And.h
        expressions/Binary.h
        expressions/Divide.h
        expressions/Expression.h
        expressions/GreaterThan.h
        expressions/LessThan.h
        expressions/Minus.h
        expressions/Multiply.h
        expressions/NotEquals.h
        expressions/Number.h
        expressions/Or.h
        expressions/Plus.h
        maps/CommandsMap.h
        maps/VarMap.h
        maps/VarMap.cpp
        main.cpp
        reader/DataReaderServer.cpp
        reader/DataReaderServer.h
        reader/ConnectReaderClient.cpp
        reader/ConnectReaderClient.h
        reader/ConnectionsHandler.cpp
        reader/ConnectionsHandler.h
        reader/ConnectionsManager.cpp
        reader/ConnectionsManager.h
        data/MyException.h
        data/Var.h
        data/BoundedVar.h
        data/Semaphore.h
        input/Utils.cpp
        input/Utils.h
        input/Parser.cpp
        input/Parser.h
        input/OperationPriority.cpp
        input/OperationPriority.h
        input/ShuntingYard.cpp
        input/ShuntingYard.h
        input/LexicalAnalyzer.cpp
        input/LexicalAnalyzer.h expressions/Negative.h expressions/Unary.h input/ParsingUtils.cpp input/ParsingUtils.h commands/ConditionCommand.cpp commands/ConditionCommand.h)
