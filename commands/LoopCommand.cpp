//
// Created by Eldar on 12/15/2018.
//

#include "LoopCommand.h"

void LoopCommand::doCommand(vector<string> str) {

    while (checkCondition()) {
        for (int i = 0; i < commands.size(); i++) {
            vector<string> afterReplace = ParsingUtils::replaceExistingVars(args.at(i));
            vector<string> afterCalc=ParsingUtils::createParsedInput(afterReplace,1);
            commands.at(i)->doCommand(afterCalc);
        }
    }

}


