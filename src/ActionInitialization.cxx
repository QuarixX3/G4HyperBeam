#include "ActionInitialization.h"
#include "PrimaryGeneratorAction.h"
#include "RunAction.h"
#include "SteppingAction.h"

namespace HyperBeam {

ActionInitialization::ActionInitialization() : G4VUserActionInitialization() {}
ActionInitialization::~ActionInitialization() {}

void ActionInitialization::Build() const {
        SetUserAction(new PrimaryGeneratorAction);

         RunAction* runAction = new RunAction();
         SetUserAction(runAction);

         SetUserAction(new SteppingAction(runAction));
}

void ActionInitialization::BuildForMaster() const {
         SetUserAction(new RunAction());
}

}
