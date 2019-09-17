from subprocess import call
import os
filenames= os.listdir (".")
folders = []
for filename in filenames: # loop through all the files and folders
    if os.path.isdir(os.path.join(os.path.abspath("."), filename)): # check whether the current object is a folder or not
        folders.append(filename)


test_folders = []
for folder in folders:
    if 'test_' in folder:
        test_folders.append(folder)

for test_folder in test_folders:
    execute_test = 'cd ' + test_folder
    print(execute_test)
    call(execute_test + '&& python start_test.py', shell=True)
    
