cmake_minimum_required(VERSION 3.5)
project(simulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(commands)
include_directories(expressions)

add_executable(FlightSimulator
        commands/BindCommand.cpp
        commands/BindCommand.h
        commands/Command.h
        commands/ConnectCommand.cpp
        commands/ConnectCommand.h
        commands/HeadingCommand.cpp
        commands/HeadingCommand.h
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
        expressions/Equals.h
        expressions/And.h
        expressions/Binary.h
        expressions/Divide.h
        expressions/Expression.h
        expressions/GreaterThan.h
        expressions/LessThan.h
        expressions/Minus.h
        expressions/Multiply.h
        expressions/Not.h
        expressions/Number.h
        expressions/Or.h
        expressions/Plus.h
        Global/CommandsMap.h
        main.cpp
        Utils.cpp
        Utils.h Parser.cpp Parser.h reader/DataReaderServer.cpp reader/DataReaderServer.h MyException.cpp MyException.h Global/VarMap.h Global/VarMap.cpp data/Var.h data/BoundedVar.h commands/IfCommand.cpp commands/IfCommand.h OperationPriority.cpp OperationPriority.h ShuntingYard.cpp ShuntingYard.h reader/ConnectReaderClient.cpp reader/ConnectReaderClient.h)
