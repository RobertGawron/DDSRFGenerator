#!/bin/bash

cppcheck --enable=all --inline-suppr --force --quiet --error-exitcode=1 --suppress=missingIncludeSystem --check-config  ../Software/Common/BusinessLogic/  -I ../Software/Common/BusinessLogic/ -I ../Software/Common/Libraries/zForth/src/zforth/ -I ../Software/Common/Libraries/u8g2/csrc/ 2>C_Lint_Report.txt