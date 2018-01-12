from shutil import copyfile
import zipfile
import os

############################################################################
##This script hide files in the Image
## How it work: It search in the current directory files in pdf
## if you like, you can change the extension. Then it get the files and
## zip all them next it create an image and hide the zip into image
## after that it remove the zip 
## ps: if there isn't one image in the current directory it won't work, but
## you can fix, this is just a base 
## Anderson
############################################################################

directory = os.getcwd()
location = str(directory + "\\ocultador.zip")
fantasy_zip = zipfile.ZipFile(location,'w')
aux = 0
image = ""
for folder, subfolders, files in os.walk(directory):
	for file in files:
		if file.endswith('.pdf'):
			fantasy_zip.write(os.path.join(folder,file),os.path.relpath(os.path.join(folder,file),directory), compress_type = zipfile.ZIP_DEFLATED)
		elif file.endswith('.png'):
			if aux == 0:
				image = file
				aux = 1
			fantasy_zip.write(os.path.join(folder,file),os.path.relpath(os.path.join(folder,file),directory), compress_type = zipfile.ZIP_DEFLATED)
fantasy_zip.close()

os.system("copy /b " + image +" + ocultador.zip teste.png")
os.remove("ocultador.zip")
