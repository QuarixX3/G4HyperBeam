#include "RunAction.h"
#include "G4Run.hh"
#include "G4SystemOfUnits.hh"
#include "G4Threading.hh"
#include <sstream>

namespace HyperBeam {

RunAction::RunAction() : G4UserRunAction(), fRootFile(nullptr), fTree(nullptr), fX(0.), fY(0.), fZ(0.), fEdep(0.),
                       fStepLength(0.), fTrackID(0), fParentID(0) {}

RunAction::~RunAction() {
    if (fRootFile) {
        fRootFile->Close();
        delete fRootFile;
        }
}

void RunAction::BeginOfRunAction(const G4Run*) {
        fRootFile = new TFile("proton_beam.root", "RECREATE");
        
        if (!fRootFile || fRootFile->IsZombie()) {
                G4Exception("RunAction::BeginOfRunAction", "ROOT001", FatalException, "Failed to create ROOT file");
        }

        fTree = new TTree ("Tree", "Beam Data");

        fTree->Branch("x", &fX, "x/D");
        fTree->Branch("y", &fY, "y/D");
        fTree->Branch("z", &fZ, "z/D");
        fTree->Branch("Edep", &fEdep, "edep/D");
        fTree->Branch("stepLength", &fStepLength, "steplength/D");
        fTree->Branch("TrackID", &fTrackID, "trackID/I");
        fTree->Branch("parentID", &fParentID, "parentID/I");
};

void RunAction::EndOfRunAction(const G4Run*) {
        if (fRootFile && fRootFile->IsOpen()) {
            // fTree->Write();
            fRootFile->cd();
            fTree->Write("", TObject::kOverwrite);
            // fRootFile->Close();
            // delete fRootFile;
            // fRootFile = nullptr;
            // fTree = nullptr;
            delete fTree;
            fTree = nullptr;
            fRootFile->Close();
            delete fRootFile;
            fRootFile = nullptr;
        }
};

}
