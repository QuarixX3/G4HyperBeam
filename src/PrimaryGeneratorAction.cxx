#include "PrimaryGeneratorAction.h"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

namespace HyperBeam {

PrimaryGeneratorAction::PrimaryGeneratorAction() {
        fGPS = new G4GeneralParticleSource();

G4SingleParticleSource* source = fGPS->GetCurrentSource();

G4ParticleTable* table = G4ParticleTable::GetParticleTable();
source->SetParticleDefinition(table->FindParticle("proton"));

source->GetEneDist()->SetEnergyDisType("Mono");
source->GetEneDist()->SetMonoEnergy(3.5*MeV);

source->GetPosDist()->SetPosDisType("Beam");
source->GetPosDist()->SetBeamSigmaInR(1.5*mm);
source->GetPosDist()->SetCentreCoords(G4ThreeVector(0, 0, 49*cm));

source->GetAngDist()->SetAngDistType("beam2d");
source->GetAngDist()->SetBeamSigmaInAngR(2*mrad);
// source->GetAngDist()->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
        fGPS->GeneratePrimaryVertex(event);
}


PrimaryGeneratorAction::~PrimaryGeneratorAction() {
        delete fGPS;
}

}
