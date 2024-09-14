#ifndef DDS_FORTH_SCRIPTS_LOADER_SIM_H
#define DDS_FORTH_SCRIPTS_LOADER_SIM_H

// .so file with dut is in different directory than python
// scripts that loads it, therefore .so see its path
// as python script is seeing it. this is to fix it and have
// real path of the .so so that it can correctly load forth
// files from file system
void DDSForthScriptsLoaderSIM_SetForthScriptsPath(char* path);

#endif

