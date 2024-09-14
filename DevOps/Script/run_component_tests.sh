#!/bin/bash

cd ../Software/Common/BusinessLogic && mkdir build && cd build && cmake -DCMAKE_SYSTEM_NAME=Generic -DCMAKE_C_COMPILER=gcc ../ && make -j12 && cd ../../../../Test/ComponentTest && py.test --html=BusinessLogic_Test_Report.html --self-contained-html test_buisness_logic.py