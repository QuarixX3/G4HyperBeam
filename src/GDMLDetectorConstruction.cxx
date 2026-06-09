#include "DetectorConstruction.h"
#include "G4GDMLParser.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4UserLimits.hh"

namespace HyperBeam {

DetectorConstruction::DetectorConstruction(const G4String& gdmlFile) : G4VUserDetectorConstruction(), fGDMLFile(gdmlFile) {}
DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
        fParser.Read(fGDMLFile);

        G4VPhysicalVolume* world = fParser.GetWorldVolume();

        G4UserLimits* stepLimit = new G4UserLimits(0.1*mm);
        world->GetLogicalVolume()->SetUserLimits(stepLimit);

        return world;

}

}
