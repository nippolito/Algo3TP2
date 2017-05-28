import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import random


k = pd.read_csv("probarK.csv", delimiter=',')




indxM = []
for i in range(10,500):
	if i % 5 == 0:
		indxM.append(i)
#fb.plot()
#bp.plot()
plt.plot(k['y'],k['x'],'g.', label='N = 100 \nM=1000 \nCant.RP = 1000')

legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')
for label in legend.get_texts():
    label.set_fontsize('medium')

for label in legend.get_lines():
    label.set_linewidth(1.5)

plt.ylabel("Tiempo en segundos")

plt.xlabel("Cantidad de Rutas Premium Disponibles (K)")
plt.show()
