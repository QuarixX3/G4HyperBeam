#ifndef RUNACTION_H
#define RUNACTION_H 1

#include "G4UserRunAction.hh"
#include "TFile.h"
#include "TTree.h"

namespace HyperBeam {

        class RunAction : public G4UserRunAction {
                    public:
                        RunAction();
                        ~RunAction();

                        void BeginOfRunAction(const G4Run*) override;
                        void EndOfRunAction(const G4Run*) override;

                        TTree* GetTree() const { return fTree; }

                        Double_t fX, fY, fZ;
                        Double_t fEdep;
                        Double_t fStepLength;
                        Int_t fTrackID;
                        Int_t fParentID;

                    private:
                        TFile* fRootFile;
                        TTree* fTree;
        };

}

#endif
