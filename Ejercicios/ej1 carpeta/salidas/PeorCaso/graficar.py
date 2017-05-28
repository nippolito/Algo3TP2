import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import random


r = pd.read_csv("MuchasR.csv", delimiter=',')
rs = pd.read_csv("MuchasRS.csv", delimiter=',')
ls = pd.read_csv("limiteSup.csv", delimiter= ',')
li = pd.read_csv("limiteInf.csv", delimiter= ',')

plt.plot(r['y'],r['x'],'g.', label='Crecimiento en funcion del crecimiento de M')
plt.plot(rs['y'],rs['x'],'b.', label='Crecimiento en funcion del crecimiento de Cantidad de Rutas Premium')

legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')
for label in legend.get_texts() :
    label.set_fontsize('medium')

for label in legend.get_lines():
    label.set_linewidth(1.5)

#plt.plot(ls['y'],ls['x'],'r-')

plt.plot(li['y'],li['x'],'')



plt.ylabel("Tiempo en segundos")
plt.show()
