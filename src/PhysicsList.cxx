#include "PhysicsList.h"
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsQGSP_BIC.hh"
#include "G4SystemOfUnits.hh"
#include "G4StepLimiterPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"

namespace HyperBeam {

PhysicsList::PhysicsList() : G4VModularPhysicsList() {

        SetVerboseLevel(1);
        SetDefaultCutValue(0.001*mm);
        G4ProductionCutsTable::GetProductionCutsTable()->SetEnergyRange(100*eV, 100*GeV);

        RegisterPhysics(new G4EmStandardPhysics_option4());

        RegisterPhysics(new G4HadronElasticPhysics());

        RegisterPhysics(new G4HadronPhysicsQGSP_BIC());

        RegisterPhysics(new G4StepLimiterPhysics());
}

PhysicsList::~PhysicsList() {}

}
