#!/usr/bin/python
from subprocess import call
import os
import shutil

generated_test_folder = 'tmp'
if os.path.isdir(generated_test_folder): #checking for folder and deleting it 
    shutil.rmtree(generated_test_folder)
os.mkdir(generated_test_folder)
path_to_executable = 'cd ../../build_pc/pc/'
simulation_time = "5"
current_path = os.path.dirname(os.path.abspath(__file__)) +'/ids_to_log.txt'
ids_to_log_file = open(current_path,'r')
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

current_path = os.path.dirname(os.path.abspath(__file__))
execute = './pc_program ' + simulation_time + ' ' + ids_to_log_str
print(execute)
call('cd ' + current_path + ' && ' + path_to_executable + '&&' + execute, shell=True)
print("Done")
