import requests
import sys
import os
import platform

def start_search():
	#Pega a url digitada
	#get the url typed
	url = sys.argv[1]
	file = ""
	#Checa se a url foi digitado o http caso o contrario adiciona
	#Check if the http was typed otherwise its add
	if url[0:7] == "http://":
		pass
	else:
		url = "http://" + url
	#Tenta abrir o arquivo como leitura
	#Try to open the file to read
	try:
		file = open(str(sys.argv[2]),'r')
	except:
		print("Fail to open file")
	#Pega cada linha e concatena com a url tenta enviar uma requisicao get
	#Get each file line and concatenates with the url try to send a get request
	for fileword in file:
		try:
			request_send = requests.get(url+"/"+fileword)
			#Se for bem sussedido pega o retorno e filtra o codigo de status
			#If sucessfull get the return status code
			code = request_send.status_code
		except:
			#Se der erro lanca a excessao mostrando o help
			#If it gives error throw a exception showing the help
			throwError()
		#Se retornar o codigo 200 e porque o caminho existe
		#If return the code 200 is because exists the path
		if code == 200:
			print(str(code) + "=>" +url+"/"+fileword)
			print("Found")
  	
	        
def throwError():
	#Pega o sistema operacional rodando
	#Get the OS running 
	currently_os = platform.system()
	#If the os equals Windows clear the screen with cls
	if currently_os == "Windows":
		os.system("cls")
	#If the os equals Linux clear the screen with clear
	if currently_os == "Linux":
		os.system("clear")

	print("...////-- FileSearch --\\\\\\\\...")
	print("command: python file_search.py url wordlistname")
	print("example: python file_search.py http://www.filesearch.com.br myword.txt")
	print("If print the code 200 is because the path exists")
	
#Se a quantidade de parametros for menor que 3 chama o Help
#If the parameters quantity is smaller that 3 call the Help
if len(sys.argv) != 3:
	throwError()
else:
	start_search()

