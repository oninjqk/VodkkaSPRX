#pragma once


void TPtoWaypoint()
{
    int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);
    if (UI::DOES_BLIP_EXIST(WaypointHandle))
    {
        Vector3 WaypointPos = UI::GET_BLIP_COORDS(WaypointHandle);
        WaypointPos.z += 25.0f;
        int Handle = PLAYER::PLAYER_PED_ID();
        if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
            Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        ENTITY::SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z, 0, 0, 0, 1);
    }
    else drawNotification("~b~Mark Waypoint.");
}


void Move2MetersForward()
{
    Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 2.0, 0.0);
    int Handle = PLAYER::PLAYER_PED_ID();
    if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
        Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
    ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
}


void Move2MetersUp()
{
    Vector3 Coords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), 0.0, 0.0, 2.0);
    int Handle = PLAYER::PLAYER_PED_ID();
    if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))
        Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
    ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, Coords.x, Coords.y, Coords.z, 0, 0, 1);
}

void toNearestCar()
{
    Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
    int VehID = VEHICLE::GET_CLOSEST_VEHICLE(coords.x, coords.y, coords.z, 100.0f, 0, 71);
    PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
}


void TPtoMazeBank()
{
    Vector3 Coords;
    Coords.x = -74.94243f;
    Coords.y = -818.63446f;
    Coords.z = 326.174347f;
    ChangeCoords(Coords);
}


void TPtoMainAirport()
{
    Vector3 Coords;
    Coords.x = -1208.71f;
    Coords.y = -3026.39f;
    Coords.z = 13.94f;
    ChangeCoords(Coords);
}


void TPtoControlTower()
{
    Vector3 Coords;
    Coords.x = -982.42f;
    Coords.y = -2636.51f;
    Coords.z = 89.52f;
    ChangeCoords(Coords);
}

void TPtoMountChilliad()
{
    Vector3 Coords;
    Coords.x = 496.75f;
    Coords.y = 5591.17f;
    Coords.z = 795.03f;
    ChangeCoords(Coords);
}

void TPtoFortZancudo()
{
    Vector3 Coords;
    Coords.x = -2012.8470f;
    Coords.y = 2956.5270f;
    Coords.z = 32.8101f;
    ChangeCoords(Coords);
}

void TPtoLSCustoms()
{
    Vector3 Coords;
    Coords.x = -373.01;
    Coords.y = -124.91;
    Coords.z = 38.31;
    ChangeCoords(Coords);
}

void TPtoMaskShop()
{
    Vector3 Coords;
    Coords.x = -1338.16;
    Coords.y = -1278.11;
    Coords.z = 4.87;
    ChangeCoords(Coords);
}

void TPtoClothesStore()
{
    Vector3 Coords;
    Coords.x = -718.91;
    Coords.y = -158.16;
    Coords.z = 37.00;
    ChangeCoords(Coords);
}


void TPtoAmmunation()
{
    Vector3 Coords;
    Coords.x = 247.3652;
    Coords.y = -45.8777;
    Coords.z = 69.9411;
    ChangeCoords(Coords);
}



void TPtoOutsideGarage()
{
    Vector3 Coords;
    Coords.x = -795.46f;
    Coords.y = 308.89f;
    Coords.z = 85.71f;
    ChangeCoords(Coords);
}



void TPtoInsideFIBBuilding()
{
    Vector3 Coords;
    Coords.x = 135.5220f;
    Coords.y = -749.0003f;
    Coords.z = 260.0000f;
    ChangeCoords(Coords);
}


void TPtoInsideFortTower()
{
    Vector3 Coords;
    Coords.x = -2356.0940;
    Coords.y = 3248.645;
    Coords.z = 101.4505;
    ChangeCoords(Coords);
}


void TPtoCarImpound()
{
    Vector3 Coords;
    Coords.x = 391.4746;
    Coords.y = -1637.9750;
    Coords.z = 29.3153;
    ChangeCoords(Coords);
}


void TPtoMorsMutualImpound()
{
    Vector3 Coords;
    Coords.x = -222.1977;
    Coords.y = -1185.8500;
    Coords.z = 23.0294;
    ChangeCoords(Coords);
}


void TPtoSandyShoresAirfield()
{
    Vector3 Coords;
    Coords.x = 1741.4960f;
    Coords.y = 3269.2570f;
    Coords.z = 41.6014f;
    ChangeCoords(Coords);
}


void TPtoWaterfallHangout()
{
    Vector3 Coords;
    Coords.x = -597.9525f;
    Coords.y = 4475.2910f;
    Coords.z = 25.6890f;
    ChangeCoords(Coords);
}



void invalid_water()
{
    freeze_host_bug(10800.0f, 1000.0f, -100.0f);
    print("~b~Trying To Freeze The Session HOST...", 1500);
}



void invalid_hight()
{
    freeze_host_bug(10800.0f, 1000.0f, 900.0f);
    print("~b~Trying To Freeze The Session HOST...", 1500);
}
