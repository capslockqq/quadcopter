#!/usr/bin/python
from subprocess import call
import os
import shutil

generated_test_folder = 'tmp'
if os.path.isdir(generated_test_folder): #checking for folder and deleting it 
    shutil.rmtree(generated_test_folder)
os.mkdir(generated_test_folder)
path_to_executable = 'cd ../../build_pc/pc/'
path_to_test_folder = os.getcwd() + '/' + generated_test_folder
simulation_time = "15"

ids_to_log_file = open('ids_to_log.txt','r')
lines = ids_to_log_file.readlines()

ids = []
for line in lines: 
    if line.find(':--:') > -1:
        line = line[:line.find(':--:')]
    line.rstrip('\n')
    line.replace('\n', '')
    ids.append(line)
ids_to_log_str = ""
for id_to_log in ids:
    ids_to_log_str += id_to_log + ' '
execute = './pc_program ' + simulation_time + ' ' + ids_to_log_str
print(execute)
call(path_to_executable + '&&' + execute, shell=True)
print("Done")
