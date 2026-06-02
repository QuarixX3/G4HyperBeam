#ifndef G4PRIMARYGENERATORACTION_H
#define G4PRIMARYGENERATORACTION_H 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"
#include "G4GeneralParticleSource.hh"

namespace HyperBeam {

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public:
        PrimaryGeneratorAction();
        ~PrimaryGeneratorAction();
        void GeneratePrimaries(G4Event* event) override;

    private:
        G4GeneralParticleSource* fGPS;
};

}

#endif
