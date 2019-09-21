from subprocess import call
import os
filenames= os.listdir(os.path.dirname(os.path.abspath(__file__)))
folders = []
for filename in filenames: # loop through all the files and folders
    if os.path.isdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), filename)): # check whether the current object is a folder or not
        folders.append(filename)

print(os.path.isdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'test_somname2')))
print(folders)
test_folders = []
for folder in folders:
    if 'test_' in folder:
        test_folders.append(folder)

for test_folder in test_folders:
    execute_test = 'cd ' + os.path.dirname(os.path.abspath(__file__))+'/'+test_folder
    print(execute_test)
    call(execute_test + '&& python3 start_test.py', shell=True)
    
