#!/bin/bash
astyle -C -xj --indent=spaces=4 *.cpp *.hpp
rm -f *.orig
