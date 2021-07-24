import ctypes
import os.path


class DeviceUnderTest:
    def __init__(self):
        dll_name = "simulation.so"
        dllabspath = \
            os.path.dirname(os.path.abspath(os.path.abspath(__file__))) \
            + os.path.sep + ".." + os.path.sep + ".." \
            + os.path.sep + "Software" + os.path.sep + "Simulation" \
            + "build" + os.path.sep + dll_name

        self.dut = ctypes.CDLL(dllabspath)

        pathToSharedLibraryOfDUT = "../../Software/Simulation/build"
        self.dut.Lib_Simulation_Init(pathToSharedLibraryOfDUT.encode())

    def sendSCPI(self, command):
        self.dut.Lib_Simulation_SendSCPIRequest.argtypes = \
            [ctypes.POINTER(ctypes.c_char)]

        return self.dut.Lib_Simulation_SendSCPIRequest(command.encode())

    def receiveSCPI(self):
        self.dut.Lib_Simulation_ReceiveSCPIResponse.restype = ctypes.c_char_p
        return self.dut.Lib_Simulation_ReceiveSCPIResponse().decode()
