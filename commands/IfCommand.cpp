//
// Created by Eldar on 12/20/2018.
//

#include "IfCommand.h"

void IfCommand::doCommand(vector<string> str) {

    // Check for condition, if true- perform each line and it's 'doCommand' method.
    if(checkCondition()){
        for (int i = 0; i < commands.size(); i++) {
            // Evaluate the vars each new iteration
            vector<string> afterReplace = ParsingUtils::replaceExistingVars(args.at(i));
            if (ParsingUtils::varMap.isVarExists(args.at(i)[0])) {
                vector<string> afterCalc=ParsingUtils::createParsedInput(afterReplace,2);
                commands.at(i)->doCommand(afterCalc);
            } else{
                commands.at(i)->doCommand(afterReplace);

            }
        }
    }
}