#!/usr/bin/python
from subprocess import call
import os
import shutil
import time
from threading import Thread
from os import path
def test():
    call('cd ' + current_path + ' && ' + path_to_executable + '&&' + execute, shell=True)
    print("Done simulating")

basepath = os.path.dirname(os.path.abspath(__file__))
generated_test_folder = 'tmp'
if os.path.isdir(basepath+'/'+generated_test_folder): #checking for folder and deleting it 
    shutil.rmtree(basepath+'/'+generated_test_folder)
os.mkdir(basepath+'/'+generated_test_folder)
path_to_executable = 'cd ../../build_pc/pc/'
simulation_time = "3"
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
filepath = path.abspath(path.join(basepath, "..", "..", "build_pc/pc/"))

execute = './pc_program ' + simulation_time + ' ' + ids_to_log_str
#call('cd ' + current_path + ' && ' + path_to_executable + ' && ' + 'make', shell=True)
Thread(target=test).start()
id_files = []
for id_to_log in ids:
    id_files.append(open(filepath+'/'+id_to_log+'.txt', 'r'))

output_file = open(basepath+'/'+generated_test_folder+'/output_file.txt', 'a')

length = len(id_files)
index = 1
number_of_id_file = 1
line_data = ""
while True:
    for id_file in id_files:
        line_read = id_file.readline()
        append = ";" if number_of_id_file < len(id_files) else ""
        line_data += line_read[:line_read.find(';')] + append
        number_of_id_file += 1
    number_of_id_file = 1
    if not line_read: break
    output_file.write(line_data)
    output_file.write('\n')
    line_data = ""
    index += 1
