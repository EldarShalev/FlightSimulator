//
// Created by Eldar on 12/20/2018.
//

#include "IfCommand.h"

void IfCommand::doCommand(vector<string> str) {

    if(checkCondition()){
        for (int i=0;i<commands.size();i++){
            ParsingUtils::replaceExistingVars(args.at(i));
            commands.at(i)->doCommand(args.at(i));
        }
    }
}