#!/usr/bin/python
from subprocess import call

path_to_executable = 'cd ../../build_pc/pc/'
execute = './pc_program 2'
call(path_to_executable + '&&' + execute, shell=True)
print("Done")
