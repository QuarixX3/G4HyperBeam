#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsQGSP_BIC.hh"
#include "G4SystemOfUnits.hh"
#include "PhysicsList.h"

PhysicsList::PhysicsList() : G4VModularPhysicsList() {

        SetVerboseLevel(1);
        SetDefaultCutValue(0.1*mm);

        RegisterPhysics(new G4EmStandardPhysics());

        RegisterPhysics(new G4HadronElasticPhysics());

        RegisterPhysics(new G4HadronPhysicsQGSP_BIC());
}

PhysicsList::~PhysicsList() {}
