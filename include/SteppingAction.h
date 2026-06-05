#ifndef STEPPINGACTION_H
#define STEPPINGACTION_H 1

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "RunAction.h"

namespace HyperBeam {

        class SteppingAction : public G4UserSteppingAction {
                public:
                    SteppingAction(RunAction* runAction);
                    ~SteppingAction();

                    void UserSteppingAction(const G4Step* step) override;

                private:
                    RunAction* fRunAction;
        };

}

#endif
