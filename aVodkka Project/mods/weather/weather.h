#pragma once

void set_weather_xmas()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("xmas");
}

void set_weather_snow()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("SNOW");
}

void set_weather_blizzard()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("BLIZZARD");
}

void set_weather_snowlight()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("SNOWLIGHT");
}

void set_weather_neutral()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("NEUTRAL"); // Black & White Sky
}

void set_weather_extrasunny()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("EXTRASUNNY");
}

void set_weather_clear()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("CLEAR");
}

void set_weather_clouds()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("CLOUDS");
}

void set_weather_foggy()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("FOGGY");
}

void set_weather_thunder()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("THUNDER");
}

void set_weather_overcast()
{
    *(unsigned int*)0x10953F8 = 0x60000000;
    *(unsigned int*)0x10953A4 = 0x60000000;
    *(unsigned int*)0x3D3EB0 = 0x60000000;
    GAMEPLAY::SET_WEATHER_TYPE_NOW_PERSIST("OVERCAST");
}