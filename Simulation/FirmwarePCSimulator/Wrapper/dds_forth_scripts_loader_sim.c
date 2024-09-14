#include "dds_forth_scripts_loader.h"
#include "dds_forth_scripts_loader_sim.h"
#include "zforth.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
// simulation build loads scripts directly from file system to make
// modifications easier - no need to recompile each time when
// the script was modified

#define SCRIPT_PATH_NAME_MAX_LENGTH 128
#define SCRIPT_CONTENT_MAX 3000

char buffer[SCRIPT_CONTENT_MAX];

typedef struct DDSForthScriptsLoader_Scripts_t
{
    char** scriptName;
    char scriptsPath[SCRIPT_PATH_NAME_MAX_LENGTH];
    const uint8_t scriptsAmount;
} DDSForthScriptsLoader_Scripts_t;

char* scripts[] =
{
    "core.fs"
    , "scpi.fs"
};


static DDSForthScriptsLoader_Scripts_t DDSForthScriptsLoader_Scripts =
{
    scripts,
    {0},
    sizeof(scripts) / sizeof(scripts[0])
};


void DDSForthScriptsLoaderSIM_SetForthScriptsPath(char* path)
{
    strncpy(DDSForthScriptsLoader_Scripts.scriptsPath, path, SCRIPT_PATH_NAME_MAX_LENGTH);
}


void DDSForthScriptsLoader_Init()
{
}


void DDSForthScriptsLoader_Load()
{
    // TODO reading files can give a lot of errors, but those
    // aren't checked in this method

    char scriptPathName[SCRIPT_PATH_NAME_MAX_LENGTH];

    for(uint8_t i = 0u; i < DDSForthScriptsLoader_Scripts.scriptsAmount; i++)
    {
        snprintf(scriptPathName, SCRIPT_PATH_NAME_MAX_LENGTH, "%s%s",
                 DDSForthScriptsLoader_Scripts.scriptsPath,
                 DDSForthScriptsLoader_Scripts.scriptName[i]);

        FILE * f = fopen(scriptPathName, "r");
        if(f)
        {
            while(fgets(buffer, sizeof(buffer), f))
            {
                zf_eval(buffer);
                //printf("file: %s buff _%s_\n", scriptPathName, buffer);
            }
            fclose(f);
        }
        else
        {
            printf("unable to load file %s\n", scriptPathName);
        }
    }
}