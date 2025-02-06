typedef void* Void;
typedef int Any;
typedef unsigned int uint;
typedef int Hash;
typedef int BOOL;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int ScrHandle;

#ifndef TYPES_H        // Verifica se TYPES_H n�o foi definido
#define TYPES_H        // Define TYPES_H

// Defini��o do tipo Vector3
typedef struct {
    float x;
    float y;
    float z;
} Vector3;

// Defini��o da estrutura opd_s
struct opd_s {
    int32_t sub;
    int32_t toc;
};

#endif // TYPES_H      // Fecha a defini��o do include guard


