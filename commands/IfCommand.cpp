//
// Created by Eldar on 12/20/2018.
//

#include "IfCommand.h"

void IfCommand::doCommand(vector<string> str) {

    if(checkCondition()){
        for (int i = 0; i < commands.size(); i++) {
            vector<string> afterReplace = ParsingUtils::replaceExistingVars(args.at(i));
            if (ParsingUtils::varMap.isVarExists(args.at(i)[0])) {
                vector<string> afterCalc=ParsingUtils::createParsedInput(afterReplace,1);
                commands.at(i)->doCommand(afterCalc);
            } else{
                commands.at(i)->doCommand(afterReplace);

            }
        }
    }
}