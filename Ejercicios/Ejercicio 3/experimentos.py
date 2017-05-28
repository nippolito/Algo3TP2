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

def expPeter():
	df1 = pd.read_csv('Muestreo_Ej3_2.csv')
	df2 = pd.read_csv('Muestreo_Ej3_Agm_2.csv')
	df3 = pd.read_csv('Muestreo_Ej3_AgmOp_2.csv')
	df4 = pd.read_csv('Muestreo_Ej3Op_2.csv')
	dfcomplej = pd.read_csv('FuncionComplej_2.csv')

	enes = range(2, 300)

	# consumo = [(math.pow(n, 3) * math.log(100, 2)) for n in enes]

	Ej3Comun = df1[df1['Tipo'] == 'Original']
	Ej3Comun_count = Ej3Comun.groupby('cantNod').mean()
	List1 = Ej3Comun_count.Tiempo.tolist()

	Ej3Op = df4[df4['Tipo'] == 'Optimizada']
	Ej3Op_count = Ej3Op.groupby('cantNod').mean()
	List2 = Ej3Op_count.Tiempo.tolist()

	Ej3Agm = df2[df2['Tipo'] == 'OriginalConAGM']
	Ej3Agm_count = Ej3Agm.groupby('cantNod').mean()
	List3 = Ej3Agm_count.Tiempo.tolist()

	Ej3AgmOp = df3[df3['Tipo'] == 'OptimizadaConAGM']
	Ej3AgmOp_count = Ej3AgmOp.groupby('cantNod').mean()
	List4 = Ej3AgmOp_count.Tiempo.tolist()

	complej = dfcomplej[dfcomplej['Tipo'] == 'FuncionComplej']
	complej_count = complej.groupby('cantNod').mean() / 8
	ListComp = complej_count.Tiempo.tolist()

	dataf1 = pd.DataFrame({'S1': List1, 'S2': List2, 'S3': List3, 'S4': List4, 'O(n^2 log(n))': ListComp, 'CantVertices': enes})
	dataf1.astype(float)
	dataf1.plot(title='', x='CantVertices', logy=True)
	# dataf1.plot(title='', x='CantVertices', logy=True, kind='scatter', colorbar=True)
	plt.ylabel('Tiempo en ms')
	plt.xlabel('Cantidad de nodos entrada')

	plt.show()

def expPeterdos():
	df1 = pd.read_csv('Muestreo_Ej3_2.csv')
	df2 = pd.read_csv('Muestreo_Ej3_Agm_2.csv')
	df3 = pd.read_csv('Muestreo_Ej3_AgmOp_2.csv')
	df4 = pd.read_csv('Muestreo_Ej3Op_2.csv')
	dfcomplej = pd.read_csv('FuncionComplej_2.csv')

	enes = range(2, 300)

	# consumo = [(math.pow(n, 3) * math.log(100, 2)) for n in enes]

	Ej3Comun = df1[df1['Tipo'] == 'Original']
	Ej3Comun_count = Ej3Comun.groupby('cantNod').mean()
	List1 = Ej3Comun_count.Tiempo.tolist()

	Ej3Op = df4[df4['Tipo'] == 'Optimizada']
	Ej3Op_count = Ej3Op.groupby('cantNod').mean()
	List2 = Ej3Op_count.Tiempo.tolist()

	Ej3Agm = df2[df2['Tipo'] == 'OriginalConAGM']
	Ej3Agm_count = Ej3Agm.groupby('cantNod').mean()
	List3 = Ej3Agm_count.Tiempo.tolist()

	Ej3AgmOp = df3[df3['Tipo'] == 'OptimizadaConAGM']
	Ej3AgmOp_count = Ej3AgmOp.groupby('cantNod').mean()
	List4 = Ej3AgmOp_count.Tiempo.tolist()

	complej = dfcomplej[dfcomplej['Tipo'] == 'FuncionComplej']
	complej_count = complej.groupby('cantNod').mean() / 8
	ListComp = complej_count.Tiempo.tolist()

	# dataf1 = pd.DataFrame({'S1': List1, 'O(n^2 log(n))': ListComp, 'CantVertices': enes})
	# dataf1.astype(float)
	# dataf1.plot(title='', x='CantVertices', logy=True)
	# # dataf1.plot(title='', x='CantVertices', logy=True, kind='scatter', colorbar=True)
	# plt.ylabel('Tiempo en ms')
	# plt.xlabel('Cantidad de nodos entrada')

	dataf2 = pd.DataFrame({'S1': List1, 'S2': List2, 'CantVertices': enes})
	dataf2.astype(float)
	dataf2.plot(title='', x='CantVertices')
	# dataf1.plot(title='', x='CantVertices', logy=True, kind='scatter', colorbar=True)
	plt.ylabel('Tiempo en ms')
	plt.xlabel('Cantidad de nodos entrada')

	dataf2 = pd.DataFrame({'S3': List3, 'S4': List4, 'CantVertices': enes})
	dataf2.astype(float)
	dataf2.plot(title='', x='CantVertices')
	# dataf1.plot(title='', x='CantVertices', logy=True, kind='scatter', colorbar=True)
	plt.ylabel('Tiempo en ms')
	plt.xlabel('Cantidad de nodos entrada')

	plt.show()


expPeterdos()








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