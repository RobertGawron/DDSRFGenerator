#include <stdint.h>

#include "dds_business_logic_wrapper.h"
#include "dds_scpi_gate.h"
#include "dds_forth_scripts_loader_sim.h"
#include "dds_lib_export_defs.h"
#include "dds_user_interface_sim.h"


MODULE_API void Lib_Simulation_Init(char* simulation_path)
{
    DDSForthScriptsLoaderSIM_SetForthScriptsPath(simulation_path);
    DDSBusinessLogicWrapper_Init();
    DDSSCPIGate_Init();
}


MODULE_API char* Lib_Simulation_OnReceiveSCPICommand(char* request)
{
    return DDSBusinessLogicWrapper_OnReceiveSCPICommand(request);
}


MODULE_API void Lib_Simulation_SendSCPIRequest(char* request)
{
    DDSSCPIGate_OnRequest(request);
}


MODULE_API char* Lib_Simulation_ReceiveSCPIResponse()
{
    return DDSSCPIGate_OnResponse();
}


MODULE_API void Lib_Simulation_KeyPress()
{
}


MODULE_API uint8_t Lib_Simulation_GetDisplayLength()
{
    return DDSUserInterface_DisplayWidth;
}


MODULE_API uint8_t Lib_Simulation_GetDisplayHeight()
{
    return DDSUserInterface_DisplayHeight;
}


MODULE_API uint8_t* Lib_Simulation_GetDisplayContent()
{
    return &DDSUserInterface_DisplayBuffer[0][0];
}
