#include "SteppingAction.h"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"

namespace HyperBeam {
    SteppingAction::SteppingAction(RunAction* runAction) : G4UserSteppingAction(), fRunAction(runAction) {}

    SteppingAction::~SteppingAction() {}

    void SteppingAction::UserSteppingAction(const G4Step* step) {
//        if (step->GetTotalEnergyDeposit() == 0.) 
//                return;

    G4String particleName = step->GetTrack()->GetDefinition()->GetParticleName();
    if (particleName != "proton") return;

    G4ThreeVector pos = step->GetPostStepPoint()->GetPosition();

    G4double edep = step->GetTotalEnergyDeposit() / MeV;
    G4double stepLen = step->GetStepLength() / mm;

    G4Track* track = step->GetTrack();
    G4int trackID = track->GetTrackID();
    G4int parentID = track->GetParentID();

    fRunAction->fX = pos.x() / mm;
    fRunAction->fY = pos.y() / mm;
    fRunAction->fZ = pos.z() / mm;
    fRunAction->fEdep = edep;
    fRunAction->fStepLength = stepLen;
    fRunAction->fTrackID = trackID;
    fRunAction->fParentID = parentID;

    // fRunAction->GetTree()->Fill();
    TTree* tree = fRunAction->GetTree();

    if(tree) {
    tree->Fill();
    }

}

}
