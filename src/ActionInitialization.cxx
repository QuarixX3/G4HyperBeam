#include "ActionInitialization.h"
#include "PrimaryGeneratorAction.h"

namespace HyperBeam {

ActionInitialization::ActionInitialization() : G4VUserActionInitialization() {}
ActionInitialization::~ActionInitialization() {}

void ActionInitialization::BuildForMaster() const {
        // auto runAction = new RunAction;
        // SetUserAction(runAction);
}

void ActionInitialization::Build() const {
        SetUserAction(new PrimaryGeneratorAction);

        // auto runAction = new RunAction;
        // SetUserAction(runAction);

        // auto eventAction = new EventAction(runAction);
        // SetUserAction(eventAction);

        // SetUserAction(new SteppingAction(eventAction));
}

}
