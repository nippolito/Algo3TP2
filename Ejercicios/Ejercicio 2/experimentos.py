# -*- coding: utf-8 -*-

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import random
import math

# from pylab import *
# rcParams['figure.figsize'] = 15,5



# Always display all the columns
# pd.set_option('display.width', 5000)
# pd.set_option('display.max_columns', 60)

def expNyM():
	df1 = pd.read_csv('ExpCompleto.csv')
	df2 = pd.read_csv('ExpNIgualM.csv')
	df3 = pd.read_csv('ExpMitadAristas.csv')

	enes = range(2, 451)

	# consumo = [(math.pow(n, 3) * math.log(100, 2)) for n in enes]

	NigualM = df2[df2['Tipo'] == 'NigualM']
	NigualM_count = NigualM.groupby('cantNod').mean()
	List1 = NigualM_count.Tiempo_ms.tolist()

	Completo = df1[df1['Tipo'] == 'Completo']
	Completo_count = Completo.groupby('cantNod').mean()
	List2 = Completo_count.Tiempo_ms.tolist()

	mitadAristas = df3[df3['Tipo'] == 'MitadAristas']
	mitadAristas_count = mitadAristas.groupby('cantNod').mean()
	List3 = mitadAristas_count.Tiempo_ms.tolist()

	dataf1 = pd.DataFrame({'T1': List1, 'T3': List2, 'T2': List3, 'CantVertices': enes})
	dataf1.astype(float)
	dataf1.plot(title='', x='CantVertices')
	# dataf1.plot(title='', x='CantVertices', logy=True, kind='scatter', colorbar=True)
	plt.ylabel('Tiempo en ms')
	plt.xlabel('Cantidad de nodos entrada')

	plt.show()

def expC():
	df1 = pd.read_csv('ExpMinC.csv')
	df2 = pd.read_csv('ExpMedC.csv')
	df3 = pd.read_csv('ExpMaxC.csv')

	enes = range(2, 451)

	# consumo = [(math.pow(n, 3) * math.log(100, 2)) for n in enes]

	NigualM = df1[df1['Tipo'] == 'MinC']
	NigualM_count = NigualM.groupby('cantNod').mean()
	List1 = NigualM_count.Tiempo_ms.tolist()

	Completo = df3[df3['Tipo'] == 'MaxC']
	Completo_count = Completo.groupby('cantNod').mean()
	List2 = Completo_count.Tiempo_ms.tolist()

	mitadAristas = df2[df2['Tipo'] == 'MedC']
	mitadAristas_count = mitadAristas.groupby('cantNod').mean()
	List3 = mitadAristas_count.Tiempo_ms.tolist()

	dataf1 = pd.DataFrame({'T1': List1, 'T3': List2, 'T2': List3, 'CantVertices': enes})
	dataf1.astype(float)
	dataf1.plot(title='', x='CantVertices')
	# dataf1.plot(title='', x='CantVertices', logy=True, kind='scatter', colorbar=True)
	plt.ylabel('Tiempo en ms')
	plt.xlabel('Maximo peso de arista')

	plt.show()	

# expNyM()
expC()









# df = pd.read_csv('ruta/archivo.csv') > lee el archivo
# df.head(n) > muestras los primeros n
# df > muestra todo el archivo
# df['LongEntrada'] > muestra los elementos de la columna LongEntrada. Podés seleccionar más columnas también
# df['LongEntrada'][:5] > muestra los elementos de la column LongEntrada hasta el 5
# df[10:15] > muestra los elementos del 10 al 15
# contador = df['LongEntrada'].value_counts() > define a la variable contador como el conteo de cuántos hay según cada LongEntrada
# var.plot(kind='bar') > te crea el plot en var, el tipo es una barra
# plt.show() > te muestra el último plot que creaste
# nes20 = df[df['Longitud_Entrada'] == 20] > cree una variable nes20 donde tengo solo los de long 20

"""	tiempoMasQue40 = df["Tiempo_en_ms"] > 40
	TMas40 = df[tiempoMasQue40]
	print TMas40['Longitud_Entrada'].value_counts()"""   # me muestra cuántos tienen tiempo mayor que 40 según cada n
""" a = TMas40['Longitud_Entrada'].value_counts()
	print a
	todo = df['Longitud_Entrada'].value_counts()
	asd = a / todo.astype(float)
	print asd"""

# df.groupby('Longitud_Entrada').mean() > devuelve la mediana de todos los valores con long_entrada == 1, == 2 ....