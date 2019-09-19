#!/usr/bin/python
from subprocess import call
import os
import shutil
import time
from threading import Thread

def test():
    call('cd ' + current_path + ' && ' + path_to_executable + '&&' + execute, shell=True)
    print("Done simulating")


generated_test_folder = 'tmp'
if os.path.isdir(generated_test_folder): #checking for folder and deleting it 
    shutil.rmtree(generated_test_folder)
os.mkdir(generated_test_folder)
path_to_executable = 'cd ../../build_pc/pc/'
simulation_time = "15"
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

Thread(target=test).start()
time.sleep(0.2)
id_files = []
for id_to_log in ids:
    id_files.append(open('../../build_pc/pc/'+id_to_log+'.txt', 'r'))

output_file = open(generated_test_folder+'/output_file.simu', 'a')

length = len(id_files)
index = 1
line = ""
for line in id_files[1]:
    for id_file in id_files:
        output_file.write(id_file.readline())
    output_file.write('\n')
    line = ""
    index += 1