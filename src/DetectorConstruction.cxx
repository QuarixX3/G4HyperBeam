#include "DetectorConstruction.h"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace HyperBeam {

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}
DetectorConstruction::~DetectorConstruction() {}

G4PhysicalVolume* DetectorConstruction::Construct() {

G4NistManager* nistManager = G4NistManager::Instance();

// world volume construction
G4Material* air = nistManager->FindOrBuildMaterial("G4_AIR");

G4Box* worldSolid = new G4Box("World", 25*cm, 25*cm, 50*cm);
//                                    half-x  half-y  half-z

// this connects the solid to the material
G4LogicalVolume* worldLogical = new G4LogicalVolume(worldSolid, air, "World");

// this places the volume in the geant environment
G4VPhysicalVolume* worldPhysical = new G4PVPlacement(
                                    nullptr,            // rotation (none)
                                    G4ThreeVector(),    // places at the origin (no argument)
                                    worldLogical,       // what to place in the world
                                    "World",            // name
                                    nullptr,            // mother volume (none)
                                    false,              // flag 1 (?)
                                    0                   // flag 2 (?)
                                    );

// beam exit construction
G4Material* aluminum = nistManager->FindOrBuildMaterial("G4_Al");

G4Tubs* windowSolid = new G4Tubs("Exit", 0, 5*mm, 25*um, 0, 360*deg);

G4LogicalVolume* windowLogical = new G4LogicalVolume(windowSolid, aluminum, "Exit");

new G4PVPlacement(
        nullptr,
        G4ThreeVector(0, 0, -49*cm),
        windowLogical,
        "Exit",
        worldLogical,
        false,
        0
        );

return worldPhysical;

}


