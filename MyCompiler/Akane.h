#ifndef AKANE_H
#define AKANE_H

#include <iostream>
#include <string>

#include "Utility.h"
#include "GetToken.h"

namespace Opt {
    const std::string PRINT_LINE = "-printLine";
    const std::string PRINT_LINE_S = "-p";
    const std::string GEN_LIST = "-genList";
    const std::string GEN_LIST_S = "-g";
    const std::string EXECUTE = "-execute";
    const std::string EXECUTE_S = "-e";
    const std::string DISP_CODE = "-dispCode";
    const std::string DISP_CODE_S = "-d";
    const std::string VERBOSE = "-verbose";
    const std::string VERBOSE_S = "-v";
}

constexpr int MAX_LINE_LEN = 1024;

extern std::string SrcFileName;

extern bool usePRINT_LINE;
extern bool useGEN_LIST;
extern bool useEXECUTE;
extern bool useDISP_CODE;
extern bool useVERBOSE;

#endif