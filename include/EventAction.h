#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4AnalysisManager.hh"
#include "G4Timer.hh"

namespace HyperBeam {
        class HitsCollection;

        class RunAction : public G4UserRunAction {
                public :
                    RunAction(RunAction* runAction);
                    ~RunAction() override = default;

                    void BeginOfRunAction(const G4Event* event) override;
                    void EndOfRunAction(const G4Event* event) override;

                private;
                    RunAction* fRunAction = nullptr;

                    G4Timer fTimer;

                    void PrintTime();
                    };
}

#endif  
