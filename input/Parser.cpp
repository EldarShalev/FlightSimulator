//
// Created by Eldar on 16-Dec-18.
//

#include "Parser.h"

/**
 * Parse each row.
 * @param input a given input from lexer.
 */
void Parser::parse(vector<string> input) {
    // Step zero: if input is valid and not empty
    if (input.empty()) {
        return;
    }
    // Step One: if we need to create a var, lets create it and continue to look for set command
    if (input[0] == "var") {
        input = createVar(input);
    }

    // Step Two: Then check for bind command
    if (input.size() >= 3 && input[2] == "bind") {
        bind(input);
        return; //No more commands on this line
    }

    // Step three - check if we got while or if
    if (input[0] == "while" || input[0] == "if") {
        createCondition(input);
        return;
    }


    if (!(loopConditionFound)) {
        // Step Four :- replace all existing vars with their values, unless its the first argument - then its an assignment and we don't need to replace it, so we are skipping it
        vector<string> args1 = ParsingUtils::replaceExistingVars(input);
        input = args1;
    }
    // Step Five : - find the command, there should only be 1 per line, unless its var (or bounded var)
    for (int i = 0; i < input.size(); ++i) {
        if (commandsMap->getCommand(input[i]) != NULL) {
            Command *cmd = commandsMap->getCommand(input[i]);
            if (loopConditionFound) {
                if (input[input.size() - 1] == "}") {
                    vector<string> args(input.begin(), input.end() - 1);
                    input = args;
                    conditionCommand->addCommand(cmd, input);
                    conditionCommand->close();

                } else {
                    conditionCommand->addCommand(cmd, input);
                }
            } else if (input.size() - i - 2 > 1) { //more then 1 argument left
                vector<string> newInput = ParsingUtils::createParsedInput(input, i);
                cmd->doCommand(newInput);
            } else {
                cmd->doCommand(input);
            }
            return; //No more commands on this line
        }
    }


    // If we found the bracket to finish the loop
    if (input[0] == "}") {
        conditionCommand->close();
    }
    if (!conditionCommand->isOpen()) {
        loopConditionFound = false;
        conditionCommand->doCommand(input);
        conditionCommand = NULL;
    }
}


/**
 * Creating Var.
 * @param input1.
 * @return vector of string without the word var in the first place.
 */
vector<string> Parser::createVar(vector<string> input1) {
    Command *d = commandsMap->getCommand(input1[0]);
    vector<string> arg(input1.begin() + 1, input1.begin() + 2);
    d->doCommand(arg);
    input1.erase(input1.begin()); //remove the keyword var
    return input1;
}

/**
 * Seeking for bing command
 * @param input1 given line.
 */
void Parser::bind(vector<string> input1) {
    vector<string> bindPathVector(input1.begin() + 3, input1.end());
    string joinedPath;
    Utils::buildPathFromVector(bindPathVector, joinedPath);
    // build command args: x = bind /path/to/file
    vector<string> args(input1.begin(), input1.begin() + 3);
    args.push_back(joinedPath);
    Command *d = commandsMap->getCommand(input1[1]); // set command
    d->doCommand(args);
}


/**
 * Create condition- loop or If
 * @param input a given input parsed line.
 */
void Parser::createCondition(vector<string> input) {
    if (input.at(0) == "while") {
        createWhileCondition(input);
    } else if (input.at(0) == "if") {
        createIfCondition(input);
    }

}

void Parser::createWhileCondition(vector<string> input) {
    // if this is the first condition we found, set the member.
    if (!loopConditionFound) {
        conditionCommand = commandsMap->getCmdCommand("while");
        conditionCommand->setCondition(input);
        conditionCommand->open();
        loopConditionFound = true;
    } else {
        ConditionCommand *cmd1 = new LoopCommand();
        cmd1->setCondition(input);
        cmd1->open();
        conditionCommand->addCommand(cmd1, input);
        conditionCommand->addConditionCommandToNested(cmd1);
    }

}

void Parser::createIfCondition(vector<string> input) {
    // if this is the first condition we found, set the member.
    if (!loopConditionFound) {
        conditionCommand = commandsMap->getCmdCommand("if");
        conditionCommand->setCondition(input);
        conditionCommand->open();
        loopConditionFound = true;
    } else {
        ConditionCommand *cmd1 = new IfCommand();
        cmd1->setCondition(input);
        cmd1->open();
        conditionCommand->addCommand(cmd1, input);
        conditionCommand->addConditionCommandToNested(cmd1);

    }
}


/**
 * Destructor
 */
Parser::~Parser() {
    delete commandsMap;
    delete conditionCommand;
}