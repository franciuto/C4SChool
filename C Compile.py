import os

filename = input("Source code name: ").strip().lower()
while not filename in os.listdir():
	filename = input("File not found!!\n Source code name:").strip().lower()
	

output_name = input("Output name: ").strip().lower()

method = input("Compilation method:\n1. Direct\n2. Step by step\nChoose option: ")

global show_warnings
show_warnings = input("Show warnings (y/n): ").strip().lower()
show_warnings = show_warnings == "y"


command = (f'gcc {filename}')

def run (command, output, arguments = ""):
	command += f' -o {output} {arguments}'
	if show_warnings:
		command += " -Wall -Wextra"
	
	execution = os.system(command)
	if execution == 0:
		print("Compilation done!")
	else:
		print(execution)

match method:
	case "1":
		run(command, output_name)
	case "2":
		run(command,f'{output_name}.i',"-E")
		run(command,f'{output_name}.s',"-S")
		run(command,f'{output_name}.o',"-c")
		run(command, output_name)

windows = input("Vuoi compilare anche per windows (y/n): ").strip().lower()
windows = windows == "y"
if windows:
	run(f'x86_64-w64-mingw32-gcc {filename}', f'{output_name}.exe')